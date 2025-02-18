#include <stdio_checked.h>
#include <time_checked.h>
#include <checkedc.h>

void null_pointer_dereference() {
    ptr<int> ptr = NULL;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    if (ptr != NULL) {
        int value = *ptr;
        printf("Value: %d\n", value);
    } else {
        printf("Null Pointer Dereference prevented!\n");
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Null Pointer Dereference executed in %.12lf seconds\n", elapsed);
}