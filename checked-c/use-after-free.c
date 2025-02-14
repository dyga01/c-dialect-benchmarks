#include <stdlib_checked.h>
#include <stdio.h>
#include <time.h>

void use_after_free() {
    _Ptr<int> ptr = malloc<int>(sizeof(int));
    *ptr = 42;
    free(ptr);

    clock_t start = clock();
    int value = *ptr;  // Checked C prevents access to freed memory!
    clock_t end = clock();

    printf("Use-After-Free executed in %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    use_after_free();
    return 0;
}
