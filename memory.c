#include <stdlib.h>
#include <stdio.h>

char *readline(FILE *fp)
{
  int offset = 0;
  int bufsize = 4;

  char *buf;
  int c;

  buf = malloc(bufsize);

  if (buf == NULL)
  {
    return NULL;
  }

  while (c = fgetc(fp), c != '\n' && c != EOF)
  {
    if (offset == bufsize - 1)
    {
      bufsize *= 2;

      char *newbuf = realloc(buf, bufsize);

      if (newbuf == NULL)
      {
        free(buf);
        return NULL;
      }

      buf = newbuf;
    }

    buf[offset] = c;
    offset += 1;
  }

  if (c == EOF && offset == 0)
  {
    free(buf);
    return NULL;
  }

  if (offset < bufsize - 1)
  {
    char *newbuf = realloc(buf, offset + 1);

    if (newbuf != NULL)
    {
      buf = newbuf;
    }
  }

  buf[offset] = '\0';
  return buf;
}

int main(void)
{
  FILE *fp = fopen("artifacts/hello", "r");
  char *line;

  while ((line = readline(fp)) != NULL) {
    printf("%s\n", line);
    free(line);
  }

  fclose(fp);
}
