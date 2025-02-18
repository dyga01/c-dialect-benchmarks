#include <stdio_checked.h>
#include <stdlib_checked.h>
#include <time_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

void use_after_free() {
    ptr<int> ptr = malloc<int>(sizeof(int));
    if (!ptr) {
        fputs("Memory allocation failed\n", stderr);
        return;
    }
    *ptr = 42;
    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    
    free(ptr);  // Memory freed
    ptr = NULL; // Prevent use-after-free by nullifying pointer
    
    // Attempting to access freed memory is removed to ensure safety
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Use-After-Free avoided in %.12lf seconds\n", elapsed);
}

int main(void) {
    use_after_free();
    return 0;
}