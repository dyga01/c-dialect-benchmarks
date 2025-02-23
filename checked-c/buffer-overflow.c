#include <stdio_checked.h>
#include <string_checked.h>
#include <stdchecked.h>

#define SIZE 10

#pragma CHECKED_SCOPE ON

void buffer_overflow(void) {
    _Checked char buffer[SIZE];  // Declare array with bounds checking

    // This loop will attempt to access out-of-bounds memory
    for (int i = 0; i <= SIZE; i++) {  // This will still be flagged as an error in Checked C
        buffer[i] = 'A';  
    }

    printf("Buffer Overflow executed\n");
}

int main(void) {
    buffer_overflow();
    return 0;
}