#include <stdio.h>
#include <stdlib.h>

void use_after_free() {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    
    free(ptr);  // Memory freed
    int value = *ptr;  // UAF! Accessing freed memory.

    printf("Use-After-Free executed\n");
}

int main() {
    use_after_free();
    return 0;
}