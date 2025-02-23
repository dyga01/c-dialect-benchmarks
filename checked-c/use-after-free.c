#include <stdio_checked.h>
#include <stdlib_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

void use_after_free(void) {
    _Checked int* ptr = (_Checked int*)malloc(sizeof(int));  // Allocating memory
    if (!ptr) {
        fputs("Memory allocation failed\n", stderr);
        return;
    }

    *ptr = 42;
    
    free(ptr);  // Memory freed
    int value = *ptr;  // UAF! Accessing freed memory.

    printf("Use-After-Free executed\n");
}

int main(void) {
    use_after_free();
    return 0;
}