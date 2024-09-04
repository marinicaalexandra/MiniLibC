# include <stdio.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <string.h>

int puts(const char *str) {
    ssize_t b_final = write(1, str, strlen(str));
    ssize_t newline_final = write(1, "\n", 1);

    if (b_final < 0 || newline_final < 0) {
        return -1;  // Întoarcem valoare negativă în caz de eroare
    }

    return b_final + newline_final;
}
