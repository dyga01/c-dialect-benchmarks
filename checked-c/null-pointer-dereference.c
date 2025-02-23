#include <stdio_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

void null_pointer_dereference(void) {
    _Checked int* ptr = NULL;  // Declare pointer with Checked C qualifiers

    // Intentional null pointer dereference
    int value = *ptr;  // Dereferencing NULL will still result in a runtime crash

    printf("Null Pointer Dereference executed\n");
}

int main(void) {
    null_pointer_dereference();
    return 0;
}