#include <stdio_checked.h>
#include <string_checked.h>
#include <time_checked.h>
#include <stdchecked.h>
#include <stdlib_checked.h>

#define SIZE 10

#pragma CHECKED_SCOPE ON

void buffer_overflow(void) { // Add void to the function prototype
    nt_array_ptr<char> buffer : count(SIZE) = _Assume_bounds_cast<nt_array_ptr<char>>(malloc(SIZE * sizeof(char)));
    if (!buffer) {
        fputs("Memory allocation failed\n", stderr);
        return;
    }
    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    
    // Safe bounded loop
    for (int i = 0; i < SIZE; i++) {
        buffer[i] = 'A';  
    }
    
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Buffer Overflow executed in %.12lf seconds\n", elapsed);
    
    free(buffer);
}

int main(void) {
    buffer_overflow();
    return 0;
}