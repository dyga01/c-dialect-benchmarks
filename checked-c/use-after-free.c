#include <stdio_checked.h>
#include <time_checked.h>
#include <checkedc.h>

void use_after_free() {
    ptr<int> ptr = malloc<int>(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    *ptr = 42;
    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    free(ptr);  // Memory freed
    ptr = NULL; // Prevents use-after-free

    if (ptr != NULL) {
        int value = *ptr;  // This is now safe
        printf("Value: %d\n", value);
    } else {
        printf("Use-After-Free prevented!\n");
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Use-After-Free executed in %.12lf seconds\n", elapsed);
}