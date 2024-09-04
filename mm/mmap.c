// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

	int NR_mmap = __NR_mmap;  // __NR_mmap este 9 in acest caz
    long ret;         		  // Outputul

    if (addr == NULL) {
        ret = syscall(NR_mmap, addr, length, prot, flags, fd, offset);
    } else {
        // Înlocuiește NULL cu MAP_FAILED pentru a permite kernelului să aleagă adresa.
        ret = syscall(NR_mmap, MAP_FAILED, length, prot, flags, fd, offset);
    }

    if (ret < 0) {
		errno = -ret;
        return MAP_FAILED;
    }

    return (void *)ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */

	long ret = syscall(__NR_mremap, old_address, old_size, new_size, flags);

    if (ret == -1)
	{
        errno = -ret;
        return MAP_FAILED;
    }

    return (void *)ret;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */

    long ret = syscall(__NR_munmap, addr, length);

    if (ret < 0)
	{
        errno = -ret;
        return -1;
    }

    return 0;
}
