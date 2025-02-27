#include <stdio_checked.h>
#include <stdlib_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

void null_pointer_dereference(void) {
    _Ptr<int> pointer = NULL;
    // This should cause a failure in Checked C
    int value = *pointer;  // Attempting to dereference NULL pointer
    
    printf("Null Pointer Dereference executed\n");
}

int main(void) {
    null_pointer_dereference();
    return 0;
}