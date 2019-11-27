#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t size_ptr = 0;
    void *new_ptr = NULL;

    if (size <= 0)
        return NULL;

    new_ptr = malloc(size);

    if (!new_ptr)
        return NULL;

    if (!ptr)
        return new_ptr;

    size_ptr = malloc_size(ptr);

    mx_memcpy(new_ptr, ptr, (size_ptr > size ? size: size_ptr));
    free(ptr);

    return new_ptr;
}
