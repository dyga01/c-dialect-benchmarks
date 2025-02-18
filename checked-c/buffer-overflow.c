#include <stdio_checked.h>
#include <string_checked.h>
#include <time_checked.h>
#include <checkedc.h>

#define SIZE 10

void buffer_overflow() {
    array_ptr<char> buffer : count(SIZE) = malloc<SIZE * sizeof(char)>();
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    for (int i = 0; i < SIZE; i++) {  // Prevents out-of-bounds access
        buffer[i] = 'A';  
    }

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Buffer Overflow executed in %.12lf seconds\n", elapsed);

    free(buffer);
}

int main() {
    buffer_overflow();
    return 0;
}