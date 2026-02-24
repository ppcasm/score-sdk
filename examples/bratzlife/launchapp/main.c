/*
 * MGA BratzLife example (Sunplus S+Core SDK)
 * by ppcasm (ppcasm@gmail.com)
 *
 * This is just a testing file for now
 *
 *
 */

#include <string.h>
#include "tv/tv.h"
#include "cpu/cache.h"
#include "sdcard/sdcard.h"
#include "irq/interrupts.h"
#include "score7_registers.h"
#include "score7_constants.h"

/* BratzLife firmware: global FS manager object */
/*
#define FS_GLOBAL     ((void *)0xA0219624u)

typedef int (*fn_open_t)(void *fs, const char *path, const char *mode, int flags);
typedef unsigned long long (*fn_write_t)(int fd, const void *buf, int len,
                                         int p3, int p4, int p5, int p6);
typedef void (*fn_read_t)(int fd, void *buf, int len,
                          int p3, int p4, int p5, int p6);
typedef void (*fn_close_t)(void *fs, int fd);

#define SD_OPEN   ((fn_open_t)0xA007F7E8u)
#define SD_WRITE  ((fn_write_t)0xA007F148u)
#define SD_READ   ((fn_read_t)0xA007F0ECu)
#define SD_CLOSE  ((fn_close_t)0xA007F8D0u)

static int fs_open(const char *path, const char *mode)
{
    return SD_OPEN(FS_GLOBAL, path, mode, 0);
}

static void fs_close(int fd)
{
    SD_CLOSE(FS_GLOBAL, fd);
}
*/
/* Returns 1 on success */
/*
static int fs_write_chunk(int fd, const void *buf, int len)
{
    return (SD_WRITE(fd, buf, len, 0, 1, 0, 0) == 1ULL);
}

static void fs_read_chunk(int fd, void *buf, int len)
{
    SD_READ(fd, buf, len, 0, 1, 0, 0);
}
*/
/*
 * Write 'len' bytes from 'buf' to a file
 *
 * Returns:
 *   0   success
 *  -1   open failed
 *  -2   write failed
 */
 /*
int sd_write_file(const char *path, const void *buf, U32 len)
{
    enum { CHUNK = 4096 };

    const unsigned char *p = (const unsigned char *)buf;
    U32 remaining = len;

    int fd = fs_open(path, "w");
    if (fd == 0) {
        return -1;
    }

    while (remaining) {
        U32 n = (remaining > (U32)CHUNK) ? (U32)CHUNK : remaining;

        if (!fs_write_chunk(fd, p, (int)n)) {
            fs_close(fd);
            return -2;
        }

        p += n;
        remaining -= n;
        COMPILER_BARRIER();
    }

    fs_close(fd);
    return 0;
}
*/
/*
 * Read exactly 'len' bytes from a file into 'out_buf'
 *
 * Returns:
 *   0   success
 *  -1   open failed
 */
/*
int sd_read_file(const char *path, void *out_buf, U32 len)
{
    enum { CHUNK = 512 };

    unsigned char *p = (unsigned char *)out_buf;
    U32 remaining = len;

    int fd = fs_open(path, "r");
    if (fd == 0) {
        return -1;
    }

    while (remaining) {
        U32 n = (remaining > (U32)CHUNK) ? (U32)CHUNK : remaining;

        fs_read_chunk(fd, p, (int)n);

        p += n;
        remaining -= n;
        COMPILER_BARRIER();
    }

    fs_close(fd);
    return 0;
}
*/
/*
 * Dump memory range [addr, addr + len) to a file
 *
 * Returns:
 *   0   success
 *  -1   open failed
 *  -2   write failed
 */
//int sd_dump_memory(const char *path, const void *addr, U32 len)
//{
//    return sd_write_file(path, addr, len);
//}

unsigned short *fb = (unsigned short *) 0xA0400000;

//volatile unsigned int vblank_count = 0;
volatile unsigned int acc = 0;
volatile unsigned int sec = 0;
void inc_vblank(void) {
	*P_IRQ_STATUS = 0x00000001u;
	acc += 1001;
	if(acc >= 60000) {
		acc -= 60000;
		sec++;
	}
    //vblank_count++;
    //if(vblank_count % 60000 == 0) {
    //    sec++;
    //}
}

int main(void)
{
	cache_flush_all();
	//printf("OKAY");
    tv_init(RESOLUTION_640_480, COLOR_RGB565, 0xA0400000, 0xA0400000, 0xA0400000);
    
    /* Example: dump 8MB from 0xA0000000 */
    //(void)sd_dump_memory("dev0:\\dump.bin", (const void *)0xA0000000u, 8u * (1024u * 1024u));

    /* Example: read 16 bytes from a file into a small buffer */
    //{
    //    unsigned char buf[16];
    //    memset(buf, 0, sizeof(buf));
    //    (void)sd_read_file("rom0:\\Data\\Audio\\Intro.sp4", buf, (U32)sizeof(buf));

        /* show first word */
    //    tv_printhex((unsigned short *)TESTFB, 4, 6,
    //                (U32)buf[0] | ((U32)buf[1] << 8) | ((U32)buf[2] << 16) | ((U32)buf[3] << 24));
    //}
    attach_isr(INT_PPU_VBLANK_START, inc_vblank);
    enable_isr(INT_PPU_VBLANK_START);
    
    while (1) {
    	//printf("OKAY");
        //tv_init(RESOLUTION_640_480, COLOR_RGB565, 0x80400000, 0x80400000, 0x80400000);
        //tv_print(fb, 3, 4, "Seconds:");

//        tv_printhex(fb, 4, 4, vblank_count);
        tv_printhex(fb, 4, 3, sec);
    }

    return 0;
}
