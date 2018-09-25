.SUFFIXES: .c .o

CC = gcc
CFLAGS = -g
OBJECTS = create.o createFunctions.o link.o symlink.o

.c.o:
	$(CC) $(CFLAGS) -c $<

create: $(OBJECTS)
	$(CC) $(OBJECTS) -o create

create.o:

createFunctions.o:

link.o:

symlink.o:

clean:
	rm -f *.o core