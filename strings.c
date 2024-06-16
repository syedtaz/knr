#include <stdio.h>
#include <string.h>

int main(void) {
  char s[] = "hello world!\n";
  char t[sizeof(s)];
  strcpy(t, s);
  t[0] = 'z';
  printf("%s", s);
  printf("%s", t);
}
