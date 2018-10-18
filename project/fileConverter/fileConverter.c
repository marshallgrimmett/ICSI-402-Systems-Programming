#include <stdio.h>

void fileConverter(char *fileName, char *newDir);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid number of arguments.");
    return -1;
  }
  fileConverter(argv[1], argv[2]);
  return 0;
}


/*

AA43 DFW DTW 2016-01-06 11:00
AA43 DFW DTW 2016-01-17 11:00
AA44 SEA JFK 2015-02-05 7:45
AA197 ORD BOS 2012-03-12 11:50
AA1 JFK LAX 2016-07-02 9:00
OO7435 DTW PLN 2016-11-22 21:55
F9612 DEN MIA 2014-12-19 22:15
DL801 GEG MSP 2016-08-31 9:00
DL1087 ATL DAB 2016-04-10 12:05
DL828 IAH SLC 2012-06-02 7:45

*/