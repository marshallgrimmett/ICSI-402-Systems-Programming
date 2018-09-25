## 2d linked list
1. create a list of airlines (LIST1)
   - an airline will have a list of flights (LIST2) pertaining to it
2. for each record in file
    - check if the airline is in the list
      - if not, add a new airline to LIST1
    - add the record to LIST2 of the airline in LIST1
3. sort the records by departure date
    - go through each airline in LIST1 and sort
4. for each airline in LIST1
    - create a text file
    - add each record in LIST2
    - close file

#### cons: might be hard to implement
#### time: 3 loops

---

## simpler solution?
1. read binary file records into single array
    - size could be determined by the size of the file divided by the size of each record
2. sort array by departure date (there might be a date library we could use)
3. for each record
    - open file in 'a' mode (ex. if airline is AA, open file AA.txt)
    - append record to the file
    - close file

#### cons: each record has to call fopen and fclose, which is slow
#### time: 3 loops, maybe 2 if the first step can put the binary file directly into an array

---

## less overhead from fopen/fclose
1. read binary file records into single array
    - size could be determined by the size of the file divided by the size of each line
2. sort array by departure date
3. for each record
    - check if file is open (ex. if airline is AA, check if file AA.txt is open)
      - if not open, open it and add filename to an array
    - append record to the file
4. close all open files

#### cons: multiple files open might be memory intensive?
#### time: 3 loops, maybe 2
