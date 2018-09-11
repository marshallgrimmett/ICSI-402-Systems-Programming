.SUFFIXES: .c .o

CC = gcc
CFLAGS = -g
OBJECTS = main.o file1.o

.c.o:
	$(CC) $(CFLAGS) -c $<

sample: $(OBJECTS)
	$(CC) $(OBJECTS) -o sample

main.o: globals.h

funct.o: externs.h

clean:
	rm -f *.o core