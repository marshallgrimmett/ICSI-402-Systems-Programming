.SUFFIXES: .c .o

CC = gcc
CFLAGS = -g
OBJECTS = main.o functions.o

.c.o:
	$(CC) $(CFLAGS) -c $<

sample: $(OBJECTS)
	$(CC) $(OBJECTS) -o sample

main.o:

functions.o:

clean:
	rm -f *.o core