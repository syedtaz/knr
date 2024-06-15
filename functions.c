#include <stdio.h>

int plus_one(int n) {
    return n + 1;
}

int main(void) {
    int i = 10;
    int j = plus_one(i);
    printf("i plus one is = %d\n", j);
}
