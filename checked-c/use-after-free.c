#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void use_after_free() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    free(ptr);  // Memory freed

    int value = *ptr;  // UAF! Accessing freed memory.

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Use-After-Free executed in %.12lf seconds\n", elapsed);
}

int main() {
    use_after_free();
    return 0;
}