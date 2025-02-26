#include <stdio_checked.h>
#include <stdlib_checked.h>
#include <stdchecked.h>

#pragma CHECKED_SCOPE ON

#define SIZE 10

void buffer_overflow(void) {
    _Array_ptr<char> buffer : count(SIZE) = calloc<char>(SIZE, sizeof(char));
    if (buffer == NULL) return;

    // This will cause a bounds check failure in Checked C
    for (int i = 0; i <= SIZE; i++) {  // Out-of-bounds access!
        buffer[i] = 'A';
        //printf("%x\n", buffer[i]);
    }

    printf("Buffer Overflow executed\n");
    //free<char>(buffer);
}

int main(void) {
    buffer_overflow();
    return 0;
}