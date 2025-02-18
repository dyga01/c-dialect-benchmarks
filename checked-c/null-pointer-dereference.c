#include <stdio_checked.h>
#include <stdlib_checked.h>
#include <time_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

void null_pointer_dereference() {
    ptr<int> ptr = NULL;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    
    if (ptr) {
        int value = *ptr;  // Safe: only dereference if not NULL
        (void)value; // Avoid unused variable warning
    } else {
        fputs("Error: Attempted to dereference a NULL pointer\n", stderr);
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Null Pointer Dereference avoided in %.12lf seconds\n", elapsed);
}

int main(void) {
    null_pointer_dereference();
    return 0;
}
