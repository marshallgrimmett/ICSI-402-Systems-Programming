## simple solution?
1. read binary file records into single array
  - size could be determined by the size of the file divided by the size of each record
2. sort array by departure date (there might be a date library we could use)
3. for each record
  - open file in 'a' mode (ex. if airline is AA, open file AA.txt)
  - append record to the file
  - close file

## less overhead from fopen/fclose
1. read binary file records into single array
  - size could be determined by the size of the file divided by the size of each line
2. sort array by departure date
3. for each record
  - check if file is open (ex. if airline is AA, check if file AA.txt is open)
    - if not open, open it and add filename to an array
  - append record to the file
4. close all open files
