#include <stdio.h>

void increment(int* p) {
    *p += 1;
}

int main(void) {
    int i = 10;
    int *p = &i;
    increment(p);
    printf("i is now %d\n", i);
}
