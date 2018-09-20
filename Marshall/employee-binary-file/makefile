.SUFFIXES: .c .o

CC = gcc
CFLAGS = -g
OBJECTS = main.o funct.o

.c.o:
	$(CC) $(CFLAGS) -c $<

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog

main.o:

funct.o:

clean:
	rm -f *.o core