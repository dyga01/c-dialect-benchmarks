#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 10

void buffer_overflow() {
    char buffer[SIZE];
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    for (int i = 0; i <= SIZE; i++) {  // Out-of-bounds access!
        buffer[i] = 'A';  
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Buffer Overflow executed in %.12lf seconds\n", elapsed);
}

int main() {
    buffer_overflow();
    return 0;
}