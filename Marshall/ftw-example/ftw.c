#include <stdio.h>
#include <ftw.h>

int fn(const char *fpath, const struct stat *sb, int typeflag);

int main() {
  int nopenfd = 10;
  const char *dirpath = ".";
  ftw(dirpath, &fn, nopenfd);
  return 0;
}

int fn(const char *fpath, const struct stat *sb, int typeflag) {
  if (FTW_NS) {
    return 0;
  }
  printf("filename: %s", fpath);
  printf("mode: %hu", sb->st_mode);
  return 0;
}