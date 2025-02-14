#include <stdio.h>
#include <time.h>
#include <stdlib_checked.h>

void null_pointer_dereference() {
    _Ptr<int> ptr = NULL;

    clock_t start = clock();
    if (ptr) {  // Checked C forces null check
        int value = *ptr;
    }
    clock_t end = clock();

    printf("Null Pointer Dereference executed in %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    null_pointer_dereference();
    return 0;
}