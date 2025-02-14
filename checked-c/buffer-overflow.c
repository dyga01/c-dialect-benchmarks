#include <stdio.h>
#include <time.h>

void buffer_overflow() {
    array_ptr<char> buffer : count(10) = malloc<char>(10);
    clock_t start = clock();

    for (int i = 0; i <= 10; i++) { // Checked C will detect this!
        buffer[i] = 'A';
    }

    clock_t end = clock();
    printf("Buffer Overflow executed in %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    buffer_overflow();
    return 0;
}