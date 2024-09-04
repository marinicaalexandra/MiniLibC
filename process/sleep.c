#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    if (nanosleep(&req, &rem) == -1) {
        return rem.tv_sec + (rem.tv_nsec > 0 ? 1 : 0);
    } else {
        return 0;
    }
}
