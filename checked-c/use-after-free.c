#include <stdio_checked.h>
#include <stdlib_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

void use_after_free(void) {
    _ptr<int> ptr = malloc<int>(sizeof(int));
    if (ptr == NULL) return;
    
    *ptr = 42;
    
    free<int>(ptr);  // Memory is freed
    
    // This should cause a failure in Checked C
    int value = *ptr;  // Attempting to use after free
    
    printf("Use-After-Free executed\n");
}

int main(void) {
    use_after_free();
    return 0;
}