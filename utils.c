
#include "utils.h"
#include <unistd.h>

#if !defined(__linux__)
void *memcpy(void *dst, const void *src, size_t n) {
    return mp_fun_table.memmove_(dst, src, n);
}
void *memset(void *s, int c, size_t n) {
    return mp_fun_table.memset_(s, c, n);
}
#endif

void *memmove(void *dest, const void *src, size_t n) {
    return mp_fun_table.memmove_(dest, src, n);
}

void *malloc(size_t n) {
    void *ptr = m_malloc(n);
    return ptr;
}
void *realloc(void *ptr, size_t n) {
    mp_printf(&mp_plat_print, "UNDEF %d\n", __LINE__);
    return NULL;
}
void *calloc(size_t n, size_t m) {
    void *ptr = m_malloc(n * m);
    // memory already cleared by conservative GC
    return ptr;
}

void free(void *ptr) {
    m_free(ptr);
}
