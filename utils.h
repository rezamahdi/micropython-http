/**
 * \file this file contains some utilities
 */

#ifndef _MP_HTTP_UTILS_H
#define _MP_HTTP_UTILS_H

#include <py/dynruntime.h>
#include <py/obj.h>

void *malloc(size_t n);
void *realloc(void *ptr, size_t n);
void *calloc(size_t n, size_t m);
void free(void *ptr);

void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
/**
 * this struct provides a simple buffer
 */
typedef struct buffer {
	char *base; /**< base pointer to contents */
	size_t size; /**< size of content */
} buffer;

void buffer_new(buffer *buff);
void buffer_free(buffer *buff);

/******************************************************************************
 * micropython code
 ******************************************************************************/

typedef struct {
	mp_obj_base_t base;
	buffer buff;
} mp_buffer;


#endif
