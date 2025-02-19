#include <stdio.h>
#include <string.h>

#define SIZE 10

void buffer_overflow() {
    char buffer[SIZE];

    for (int i = 0; i <= SIZE; i++) {  // Out-of-bounds access!
        buffer[i] = 'A';  
    }

    printf("Buffer Overflow executed\n");
}

int main() {
    buffer_overflow();
    return 0;
}