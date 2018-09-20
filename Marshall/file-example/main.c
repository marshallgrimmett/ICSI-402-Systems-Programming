#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    perror("Exactly 2 arguments are allowed.");
    return -1;
  }

  FILE *fp = fopen(argv[1], "r");
  // printf("%s \n", argv[1]);

  if (fp == NULL) {
    perror("Error reading the file.");
    return -1;
  }

  printf("%c \n", (char)getc(fp));

  fseek(fp, 5, SEEK_SET);
  printf("offset 5: %c \n", (char)getc(fp));

  fseek(fp, 3 + SEEK_CUR, SEEK_SET);
  printf("offset 8: %c \n", (char)getc(fp));

  fseek(fp, -4, SEEK_CUR);
  printf("offset 4: %c \n", (char)getc(fp));

  fclose(fp);

  return 0;
}