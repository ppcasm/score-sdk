#ifndef _CACHE_H_
#define _CACHE_H_

#include "score7_constants.h"

#ifndef SCORE_CACHE_LINE_SIZE
#define SCORE_CACHE_LINE_SIZE 16u
#endif

/* Drain write buffer */
void cache_wb_drain(void);

/* Invalidate entire instruction cache */
void icache_invalidate_all(void);

/* Invalidate entire data cache */
void dcache_invalidate_all(void);

/* Write-back entire data cache (dirty lines → memory, keep valid) */
void dcache_writeback_all(void);

/* Flush entire data cache (dirty lines → memory, then invalidate) */
void dcache_flush_all(void);

/* Invalidate instruction cache lines covering [addr, addr+len) */
void icache_invalidate_range(const volatile void *addr, size_t len);

/* Invalidate data cache lines covering [addr, addr+len) */
void dcache_invalidate_range(const volatile void *addr, size_t len);

/* Write-back (write-out) data cache lines covering [addr, addr+len) */
void dcache_writeback_range(const volatile void *addr, size_t len);

/* Flush (write-back + invalidate) data cache lines covering [addr, addr+len) */
void dcache_flush_range(const volatile void *addr, size_t len);

/* Attempt to "sync" cache */
void cache_sync(const volatile void *addr, size_t len);

/* Prepare CPU-written buffer for peripheral/DMA read */
void cache_prepare_dma_read(const volatile void *addr, size_t len);

/* Prepare CPU to read buffer after peripheral/DMA write */
void cache_prepare_dma_write(const volatile void *addr, size_t len);

/* Flush D-cache and invalidate I-cache entirely */
void cache_flush_all(void);

#endif /* _CACHE_H_ */
