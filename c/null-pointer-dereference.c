#include <stdio.h>
#include <time.h>

void null_pointer_dereference() {
    int* ptr = NULL;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    int value = *ptr;  // Crash! Dereferencing NULL.

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Null Pointer Dereference executed in %.12lf seconds\n", elapsed);
}

int main() {
    null_pointer_dereference();
    return 0;
}