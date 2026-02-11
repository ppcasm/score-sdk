/*

This is part of the MGA BratzLife examples from the Sunplus S+Core SDK by ppcasm (ppcasm@gmail.com)

*/

#include "tv/tv.h"
#include <stdio.h>
#include "sdcard/sdcard.h"
#include "score7_registers.h"
#include "score7_constants.h"

unsigned short *fb = (unsigned short *) 0xA0400000;

typedef unsigned char  u8;
typedef unsigned long  u32;

static inline u32 mmio_read(u32 addr) {
    return *(volatile u32*)addr;
}
static inline void mmio_write(u32 addr, u32 v) {
    *(volatile u32*)addr = v;
}

static void delay_ticks(u32 ticks) {
    volatile u32 i;
    for (i = 0; i < ticks; i++) { /* spin */}
}

#define I2C_OUT   0x88200024u   /* bit7 = SDA, bit6 = SCL */
#define I2C_IN    0x88200068u   /* bit7 sampled SDA */

#define SDA_BIT   0x80u
#define SCL_BIT   0x40u

static inline void sda_set(int high) {
    u32 v = mmio_read(I2C_OUT);
    if (high) v |= SDA_BIT;
    else v &= ~SDA_BIT;
    mmio_write(I2C_OUT, v);
}

static inline void scl_set(int high) {
    u32 v = mmio_read(I2C_OUT);
    if (high) v |= SCL_BIT;
    else v &= ~SCL_BIT;
    mmio_write(I2C_OUT, v);
}

static inline int sda_read(void) {
    return (mmio_read(I2C_IN) & SDA_BIT) ? 1 : 0;
}

static void i2c_start(void)
{
    /* DATA high, then SCL high, then DATA low, then SCL low */
    sda_set(1);
    delay_ticks(10);

    scl_set(1);
    delay_ticks(0x32);

    sda_set(0);
    delay_ticks(0x32);

    scl_set(0);
    delay_ticks(0x14);
}

static void i2c_stop(void)
{
    /* DATA low, then SCL high, then DATA high */
    sda_set(0);
    delay_ticks(10);

    scl_set(1);
    delay_ticks(0x32);

    sda_set(1);
    delay_ticks(0x28);
}

/* ACK convention: *ack = 1 means ACK received, 0 means NACK */
static void i2c_write_byte(u8 *ack, u8 byte)
{
    u32 bit;

    /* 8 bits, MSB-first */
    for (bit = 0; bit < 8; bit++) {
        if (((u32)byte << bit) & 0x80u) sda_set(1);
        else sda_set(0);

        delay_ticks(10);

        scl_set(1);
        delay_ticks(0x32);

        scl_set(0);
        /* Might need to add a delay here */
    }

    delay_ticks(0x14);

    /* Release SDA high so target can pull low for ACK */
    sda_set(1);
    delay_ticks(0x32);

    /* Clock high and sample ACK */
    scl_set(1);
    delay_ticks(0x1e);

    if (ack) {
        /* ACK is active-low on the sampled SDA bit */
        *ack = (sda_read() == 0) ? (u8)1 : (u8)0;
    }

    scl_set(0);
    delay_ticks(0x14);
}

/* Reads one byte MSB-first (val = val*2; if (in&0x80) val++) */
static u8 i2c_read_byte(void)
{
    u8 val = 0;
    u32 bit;

    /* Release SDA so target can drive it */
    sda_set(1);

    for (bit = 0; bit < 8; bit++) {
        delay_ticks(10);

        /* SCL low */
        scl_set(0);
        delay_ticks(0x32);

        /* SCL high */
        scl_set(1);
        delay_ticks(0x14);

        val <<= 1;
        if (sda_read()) val |= 1;

        delay_ticks(0x14);
    }

    /* Drop SCL at end */
    scl_set(0);
    delay_ticks(0x14);

    return val;
}

/* NACK=0 => ACK (drive SDA low), NACK=1 => NACK (drive SDA high) */
static void i2c_send_ack_nack(u8 nack)
{
    sda_set(nack ? 1 : 0);

    delay_ticks(0x1e);

    scl_set(1);
    delay_ticks(0x32);

    scl_set(0);
    delay_ticks(0x14);
}

/*
 * devaddr_w: Write address byte (e.g. 0xA0 for 24Cxx with A2..A0=0)
 * offset:    Word/byte address inside EEPROM
 * ack:       Out param; 1=ACK received at the last critical step, 0 otherwise
 *
 * Returns 0xFF on any NACK along the chain, just like bratzlife firmware does
 */
u8 eeprom_read_byte(u8 *ack, u8 devaddr_w, u8 offset)
{
    u8 v;

    if (ack) *ack = 0;

    /* START + SLA+W */
    i2c_start();
    i2c_write_byte(ack, devaddr_w);
    if (!ack || *ack == 0) return 0xFF;

    /* Send offset */
    i2c_write_byte(ack, offset);
    if (*ack == 0) return 0xFF;

    /* Repeated START + SLA+R */
    i2c_start();
    i2c_write_byte(ack, (u8)(devaddr_w + 1));
    if (*ack == 0) return 0xFF;

    /* Read data, then NACK, then STOP */
    v = i2c_read_byte();
    i2c_send_ack_nack(1); /* NACK after single-byte read */
    i2c_stop();

    return v;
}

/*
 * Write one byte, then "ACK-poll" until the EEPROM accepts SLA+W again.
 *
 * Returns 1 on success, 0 if any of the initial phases NACK.
 *
 * Notes:
 *  - devaddr_w should be the write address byte (ex: 0xA0)
 *  - This matches the decompiled logic: do the 3-byte write, STOP,
 *    then loop START+SLA+W until ACK is seen.
 */
u8 eeprom_write_byte(u8 *ack, u8 devaddr_w, u8 offset, u8 data)
{
    u8 ok = 0;

    if (ack) *ack = 0;

    /* START + SLA+W */
    i2c_start();
    i2c_write_byte(ack, devaddr_w);
    if (!ack || *ack == 0) {
        /* decompiled version didn't always STOP on failure, but we should */
        i2c_stop();
        return 0;
    }

    /* Offset */
    i2c_write_byte(ack, offset);
    if (*ack == 0) {
        i2c_stop();
        return 0;
    }

    /* Data */
    i2c_write_byte(ack, data);
    if (*ack == 0) {
        i2c_stop();
        return 0;
    }

    /* STOP ends the write cycle start */
    i2c_stop();

    /* ACK polling: keep trying SLA+W until it ACKs */
    while (!ok) {
        i2c_start();
        i2c_write_byte(ack, devaddr_w);
        if (ack && *ack) {
            ok = 1;
        }
        i2c_stop();
    }

    if (ack) *ack = ok;
    return ok;
}

int main(){

    unsigned int i;
    u8 ack;
    u8 value;
    u8 buf[64];
    char printbuf[512];

    int nExitCode = 0;

    tv_init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);

    tv_print(fb, 24, 2, "MGA BratzLife EEPROM Dumper");

    // Demo: read first 16 bytes
    for(i=0;i<16;i++) {
        buf[i] = eeprom_read_byte(&ack, 0xA0, (u8)i);
        if (ack) {
            sprintf(printbuf, "OFFSET: %d | HEX: %02x | CHAR: %c", i, buf[i], buf[i]);
            tv_print(fb, 24, 3+i, printbuf);
        } else {
            // NACK occurred somewhere
            tv_print(fb, 24, 3+i, "NACK");
        }
    }

    /*
    // Demo: write a byte then read it back

    u8 ok;
    ok = eeprom_write_byte(&ack, 0xA0, 0x00, 0x41); // write 'A' at offset 0
    sprintf(printbuf, "WRITE ok=%d ack=%d", ok, ack);
    tv_print(fb, 28, 3, printbuf);

    value = eeprom_read_byte(&ack, 0xA0, (u8)0x00);
    sprintf(printbuf, "READBACK: %02x (ack=%d)", value, ack);
    tv_print(fb, 28, 4, printbuf);

    */
    
    while(1){

    }

    return nExitCode;
}
