#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 10

void buffer_overflow() {
    char buffer[SIZE];
    clock_t start = clock();

    for (int i = 0; i <= SIZE; i++) {  // Out-of-bounds access!
        buffer[i] = 'A';  
    }

    clock_t end = clock();
    printf("Buffer Overflow executed in %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    buffer_overflow();
    return 0;
}
