#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void use_after_free() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    
    clock_t start = clock();

    free(ptr);  // Memory freed

    int value = *ptr;  // UAF! Accessing freed memory.

    clock_t end = clock();
    printf("Use-After-Free executed in %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    use_after_free();
    return 0;
}
