.SUFFIXES: .c .o

CC = gcc
CFLAGS = -g
CREATE_OBJECTS = create.o createFunctions.o
FILE_CONVERTER_OBJECTS = fileConverter.o fileConverterFunctions.o createFunctions.o

.c.o:
	$(CC) $(CFLAGS) -c $<

fileConverter: $(FILE_CONVERTER_OBJECTS)
	$(CC) $(FILE_CONVERTER_OBJECTS) -o fileConverter

create: $(CREATE_OBJECTS)
	$(CC) $(CREATE_OBJECTS) -o create

clean:
	rm -f *.o core
