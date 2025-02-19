#include <stdio.h>

void null_pointer_dereference() {
    int* ptr = NULL;
    int value = *ptr;  // Crash! Dereferencing NULL.
    printf("Null Pointer Dereference executed\n");
}

int main() {
    null_pointer_dereference();
    return 0;
}