CC = gcc
CFLAGS = -g
OBJECTS = main.o file1.o

prog: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o sample.o

main: main.o
	$(CC) $(CFLAGS) main.c -o sample.o

file1: file1.o
	$(CC) $(CFLAGS) file1.c -o sample.o