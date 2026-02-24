// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// $Log:$
//
// DESCRIPTION:
//	DOOM graphics stuff for X11, UNIX.
//
//-----------------------------------------------------------------------------

static const char
rcsid[] = "$Id: i_x.c,v 1.6 1997/02/03 22:45:10 b1 Exp $";

#include "config.h"
#include "v_video.h"
#include "d_event.h"
#include "i_video.h"
#include "z_zone.h"
#include "tables.h"     // gammatable
#include "doomgeneric.h"
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define SRC_W   320
#define SRC_H   200
#define DST_W   320
#define DST_H   240

// HyperScan RGB565 framebuffer
#define FBADDR  0xA0F69000u

// Doom's 8-bit screen buffer (paletted)
byte *I_VideoBuffer = NULL;

boolean screensaver_mode = false;
boolean screenvisible = true;
float mouse_acceleration = 2.0f;
int mouse_threshold = 10;
int usemouse = 0;
int usegamma = 0;

// 256-entry palette mapped to RGB565 (pre-gamma-corrected)
static uint16_t palette565[256];

// dst_y -> src_y (nearest-neighbor vertical scale)
static uint16_t ymap[DST_H];
static bool ymap_init = false;
static void init_ymap(void)
{
	int y = 0;
    for (y = 0; y < DST_H; y++) {
        uint32_t sy = (uint32_t)y * (uint32_t)SRC_H / (uint32_t)DST_H;
        if (sy >= SRC_H) sy = SRC_H - 1;
        ymap[y] = (uint16_t)sy;
    }
    ymap_init = true;
}

static inline void row_cmap8_to_565(uint16_t *dst, const uint8_t *src)
{
	int x = 0;
	
    // SRC_W is 320, divisible by 8
    for (x = 0; x < SRC_W; x += 8) {
        dst[x+0] = palette565[src[x+0]];
        dst[x+1] = palette565[src[x+1]];
        dst[x+2] = palette565[src[x+2]];
        dst[x+3] = palette565[src[x+3]];
        dst[x+4] = palette565[src[x+4]];
        dst[x+5] = palette565[src[x+5]];
        dst[x+6] = palette565[src[x+6]];
        dst[x+7] = palette565[src[x+7]];
    }
}

static void BuildRGB565Palette(const uint8_t *pal)
{
	int i = 0;
    for (i = 0; i < 256; i++) {
        // palette is 256*3 bytes (r,g,b). Apply gamma via gammatable.
        uint8_t r8 = gammatable[usegamma][*pal++];
        uint8_t g8 = gammatable[usegamma][*pal++];
        uint8_t b8 = gammatable[usegamma][*pal++];
        uint16_t r5 = (uint16_t)(r8 >> 3);
        uint16_t g6 = (uint16_t)(g8 >> 2);
        uint16_t b5 = (uint16_t)(b8 >> 3);
        palette565[i] = (uint16_t)((r5 << 11) | (g6 << 5) | b5);
    }
}

void I_GetEvent(void);

void I_InitGraphics(void)
{
    // Doom renders 8-bit indices into I_VideoBuffer
    I_VideoBuffer = (byte *)Z_Malloc(SCREENWIDTH * SCREENHEIGHT, PU_STATIC, NULL);
    screenvisible = true;
    if (!ymap_init) {
        init_ymap();
    }
    extern void I_InitInput(void);
    I_InitInput();
}

void I_ShutdownGraphics(void)
{
    if (I_VideoBuffer) {
        Z_Free(I_VideoBuffer);
        I_VideoBuffer = NULL;
    }
}

void I_StartFrame(void)
{
}

void I_StartTic(void)
{
    I_GetEvent();
}

void I_UpdateNoBlit(void)
{
}

void I_FinishUpdate(void)
{
	int y = 0;
    if (!I_VideoBuffer) return;
    const uint8_t *src = (const uint8_t *)I_VideoBuffer;
    volatile uint16_t *fb = (volatile uint16_t *)(uintptr_t)FBADDR;
    for (y = 0; y < DST_H; y++) {
        const int sy = ymap[y];
        const uint8_t *src_row = src + (sy * SRC_W);
        uint16_t *dst_row = (uint16_t *)(uintptr_t)(fb + (y * DST_W));
        row_cmap8_to_565(dst_row, src_row);
    }
}

void I_ReadScreen(byte *scr)
{
    memcpy(scr, I_VideoBuffer, SCREENWIDTH * SCREENHEIGHT);
}

void I_SetPalette(byte *palette)
{
    BuildRGB565Palette((const uint8_t *)palette);
}

// If something calls this, keep a simple (slow) implementation.
// Often not used in normal gameplay.
int I_GetPaletteIndex(int r, int g, int b)
{
	int i = 0;
    int best = 0;
    int best_diff = 0x7fffffff;
    for (i = 0; i < 256; i++) {
        uint16_t c = palette565[i];
        int rr = (c >> 11) & 0x1F;
        int gg = (c >> 5)  & 0x3F;
        int bb = (c >> 0)  & 0x1F;
        
        // Compare in 5/6/5 space
        // This is only used rarely so correctness > speed here
        int dr = (r >> 3) - rr;
        int dg = (g >> 2) - gg;
        int db = (b >> 3) - bb;
        int diff = dr*dr + dg*dg + db*db;
        if (diff < best_diff) {
            best_diff = diff;
            best = i;
            if (diff == 0) break;
        }
    }
    return best;
}

void I_BeginRead(void) {}
void I_EndRead(void) {}
void I_SetWindowTitle(char *title)
{
    DG_SetWindowTitle(title);
}
void I_GraphicsCheckCommandLine(void) {}
void I_SetGrabMouseCallback(grabmouse_callback_t func) {}
void I_EnableLoadingDisk(void) {}
void I_BindVideoVariables(void) {}
void I_DisplayFPSDots(boolean dots_on) {}
void I_CheckIsScreensaver(void) {}
