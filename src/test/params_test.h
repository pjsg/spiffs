/*
 * params_test.h
 *
 *  Created on: May 26, 2013
 *      Author: petera
 */

#ifndef PARAMS_TEST_H_
#define PARAMS_TEST_H_

// total emulated spi flash size
#define PHYS_FLASH_SIZE       (16*1024*1024)
// spiffs file system size
#define SPIFFS_FLASH_SIZE     (2*1024*1024)
// spiffs file system offset in emulated spi flash
#define SPIFFS_PHYS_ADDR      (4*1024*1024)

// test using filesystem magic
#ifndef SPIFFS_USE_MAGIC
#define SPIFFS_USE_MAGIC    1
#endif

// test using filesystem magic length
#define SPIFFS_USE_MAGIC_LENGTH   1

#define SPIFFS_GC_MAX_RUNS  256

#ifdef SECTOR_BITS
#define SECTOR_SIZE         (1<<SECTOR_BITS)
#else
#define SECTOR_SIZE         65536
#endif
#ifdef BLOCK_SECTOR_BITS
#define LOG_BLOCK           (SECTOR_SIZE<<BLOCK_SECTOR_BITS)
#else
#define LOG_BLOCK           (SECTOR_SIZE*2)
#endif
#ifdef PAGE_BITS
#define LOG_PAGE            (1<<PAGE_BITS)
#else
#define LOG_PAGE            (SECTOR_SIZE/256)
#endif

#define DEFAULT_NUM_FD            8
#define DEFAULT_NUM_CACHE_PAGES   8

#define ASSERT(c, m) real_assert((c),(m), __FILE__, __LINE__);

typedef signed int s32_t;
typedef unsigned int u32_t;
typedef signed short s16_t;
typedef unsigned short u16_t;
typedef signed char s8_t;
typedef unsigned char u8_t;

#define SPIFFS_DBG(...) //printf(__VA_ARGS__)
#define SPIFFS_GC_DBG(...) //printf(__VA_ARGS__)
#define SPIFFS_CACHE_DBG(...) //printf(__VA_ARGS__)
#define SPIFFS_CHECK_DBG(...) //printf(__VA_ARGS__)

#ifndef SPIFFS_HAL_CALLBACK_EXTRA
#define SPIFFS_HAL_CALLBACK_EXTRA       1
#endif

#define SPIFFS_FILEHDL_OFFSET           1
#if SPIFFS_FILEHDL_OFFSET
#define TEST_SPIFFS_FILEHDL_OFFSET      0x1000
#endif

// Enable/disable

void real_assert(int c, const char *n, const char *file, int l);

#endif /* PARAMS_TEST_H_ */
