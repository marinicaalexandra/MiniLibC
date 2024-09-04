#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

int nanosleep(struct timespec *req, struct timespec *rem){
    int ret = syscall(__NR_nanosleep, req, rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}
