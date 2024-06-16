#include <stdio.h>

void write_to_file(char *filename)
{
  unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};
  FILE *fp = fopen(filename, "wb");
  fwrite(bytes, sizeof(unsigned char), 6, fp);
  fclose(fp);
}

void read_from_file(char *filename)
{
  unsigned char c;
  FILE *fp = fopen(filename, "rb");

  while (fread(&c, sizeof(unsigned char), 1, fp) > 0) {
    printf("%d\n", c);
  }
}

int main(void) {
  char *filename = "build/output.bin";
  write_to_file(filename);
  read_from_file(filename);
}
