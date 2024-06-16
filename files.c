#include "stdio.h"

int main(void) {
    FILE *fp = fopen("artifacts/hello", "r");
    char s[1024];
    int linecount = 1;

    while (fgets(s, sizeof(s), fp) != NULL) {
        printf("%d: %s", linecount, s);
        linecount += 1;
    }

    fclose(fp);
}
