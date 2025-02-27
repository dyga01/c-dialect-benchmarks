#include <stdio_checked.h>
#include <stdlib_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

void use_after_free(void) {
    _Ptr<int> pointer = (_Ptr<int>)malloc<int>(sizeof(int));
    *pointer = 42;
    
    free<int>(pointer);  // Memory freed
    int value = *pointer;  // UAF! Checked C should detect this
    
    printf("Use-After-Free executed\n");
}

int main(void) {
    use_after_free();
    return 0;
}