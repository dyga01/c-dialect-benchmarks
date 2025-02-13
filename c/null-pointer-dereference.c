#include <stdio.h>
#include <time.h>

void null_pointer_dereference() {
    int* ptr = NULL;

    clock_t start = clock();

    int value = *ptr;  // Crash! Dereferencing NULL.

    clock_t end = clock();
    printf("Null Pointer Dereference executed in %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    null_pointer_dereference();
    return 0;
}
