// cache.c — SCORE7 cache helpers
//
// IMPORTANT: cache op must be an immediate constant. Do NOT try to pass it as a
// function parameter to inline asm.

#include "score7_constants.h"
#include "cpu/cache.h"

#ifndef SCORE_CACHE_LINE_SIZE
#define SCORE_CACHE_LINE_SIZE 128u
#endif

// Fill bubble pipeline
#define SCORE_CACHE_BUBBLE() \
    __asm__ volatile ("nop\nnop\nnop\nnop\nnop\n" ::: "memory")

#define SCORE_CACHE_OP_ADDR(OP_IMM, ADDR) do { \
    __asm__ volatile ("cache " OP_IMM ", [%0, 0]\n" :: "r"(ADDR) : "memory"); \
    SCORE_CACHE_BUBBLE(); \
} while (0)

#define SCORE_CACHE_OP_NA(OP_IMM) do { \
    __asm__ volatile ("cache " OP_IMM ", [r0, 0]\n" ::: "memory"); \
    SCORE_CACHE_BUBBLE(); \
} while (0)

static inline uintptr_t align_down(uintptr_t x, uintptr_t a) { return x & ~(a - 1u); }
static inline uintptr_t align_up(uintptr_t x, uintptr_t a)   { return (x + (a - 1u)) & ~(a - 1u); }

// D-Cache Drain Write Buffer: cache 0x1A, [NA]
void cache_wb_drain(void)            { SCORE_CACHE_OP_NA("0x1A"); }

// I-cache invalidate all: cache 0x10, [NA]
void icache_invalidate_all(void)     { SCORE_CACHE_OP_NA("0x10"); }

// D-cache invalidate all: cache 0x18, [NA]
void dcache_invalidate_all(void)     { SCORE_CACHE_OP_NA("0x18"); }

// D-cache writeback all: cache 0x1E, [NA]
void dcache_writeback_all(void)      { SCORE_CACHE_OP_NA("0x1E"); }

// D-cache flush all (writeback + invalidate): cache 0x1F, [NA]
void dcache_flush_all(void)          { SCORE_CACHE_OP_NA("0x1F"); }

static inline void icache_invalidate_line(const volatile void *va) { SCORE_CACHE_OP_ADDR("0x02", va); }
static inline void dcache_invalidate_line(const volatile void *va) { SCORE_CACHE_OP_ADDR("0x0A", va); }
static inline void dcache_writeback_line(const volatile void *va)  { SCORE_CACHE_OP_ADDR("0x0D", va); }
static inline void dcache_flush_line(const volatile void *va)      { SCORE_CACHE_OP_ADDR("0x0E", va); }

void icache_invalidate_range(const volatile void *addr, size_t len)
{
    if (!len) return;

    uintptr_t a = (uintptr_t)addr;
    uintptr_t start = align_down(a, SCORE_CACHE_LINE_SIZE);
    uintptr_t end   = align_up(a + (uintptr_t)len, SCORE_CACHE_LINE_SIZE);

    uintptr_t p = start;
    for (p = start; p < end; p += SCORE_CACHE_LINE_SIZE) {
        icache_invalidate_line((const void *)p);
    }
}

void dcache_invalidate_range(const volatile void *addr, size_t len)
{
    if (!len) return;

    uintptr_t a = (uintptr_t)addr;
    uintptr_t start = align_down(a, SCORE_CACHE_LINE_SIZE);
    uintptr_t end   = align_up(a + (uintptr_t)len, SCORE_CACHE_LINE_SIZE);

    uintptr_t p = start;
    for (p = start; p < end; p += SCORE_CACHE_LINE_SIZE) {
        dcache_invalidate_line((const void *)p);
    }
}

void dcache_writeback_range(const volatile void *addr, size_t len)
{
    if (!len) return;

    uintptr_t a = (uintptr_t)addr;
    uintptr_t start = align_down(a, SCORE_CACHE_LINE_SIZE);
    uintptr_t end   = align_up(a + (uintptr_t)len, SCORE_CACHE_LINE_SIZE);

    uintptr_t p = start;
    
    for (p = start; p < end; p += SCORE_CACHE_LINE_SIZE) {
        dcache_writeback_line((const void *)p);
    }
}

void dcache_flush_range(const volatile void *addr, size_t len)
{
    if (!len) return;

    uintptr_t a = (uintptr_t)addr;
    uintptr_t start = align_down(a, SCORE_CACHE_LINE_SIZE);
    uintptr_t end   = align_up(a + (uintptr_t)len, SCORE_CACHE_LINE_SIZE);

    uintptr_t p = start;
    for (p = start; p < end; p += SCORE_CACHE_LINE_SIZE) {
        dcache_flush_line((const void *)p);
    }
}

// Helper func to "sync" cache
void cache_sync(const volatile void *addr, size_t len)
{
    cache_wb_drain();
    dcache_flush_range(addr, len);
    cache_wb_drain();
    icache_invalidate_range(addr, len);
    cache_wb_drain();
}

// 
void cache_flush_all(void)
{
    cache_wb_drain();
    dcache_flush_all();
    cache_wb_drain();
    icache_invalidate_all();
    cache_wb_drain();
}
