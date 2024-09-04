// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr;

    ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        return NULL;
    }

    int a = mem_list_add(ptr, size);
    if ( a )
        munmap(ptr, size);

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
    void *ptr = mmap(0, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        return NULL;
    }

    memset(ptr, 0, total_size); // initializez zona alocata cu zero prin memset

	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
    struct mem_list *item = mem_list_find(ptr);
    int dim = item->len;

    if (item != NULL) {
        if (mem_list_del(ptr) == 0) {
            munmap(ptr, dim);
        }
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

    struct mem_list *old_mem = mem_list_find(ptr);
    if (old_mem == NULL) {
        return NULL;
    }

    void *new_ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_ptr == MAP_FAILED) {
        return NULL;
    }

    memcpy(new_ptr, ptr, old_mem->len);

    mem_list_del(ptr);
    munmap(ptr, old_mem->len);

    mem_list_add(new_ptr, size);
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
    size_t total_size = nmemb * size;
    void *new_ptr = realloc(ptr, total_size);
    return new_ptr;
}
