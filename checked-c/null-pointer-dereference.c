#include <stdio_checked.h>
#include <stdlib_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

void null_pointer_dereference(void) {
    _ptr<int> ptr = NULL;
    // This will cause a null check failure in Checked C
    int value = *ptr;  // Attempting to dereference NULL
    
    printf("Null Pointer Dereference executed\n");
}

int main(void) {
    null_pointer_dereference();
    return 0;
}