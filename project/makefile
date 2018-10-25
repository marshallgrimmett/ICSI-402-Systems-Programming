.SUFFIXES: .c .o

CC = gcc
CFLAGS = -g
NAIVE_INTERFACE_OBJECTS = naiveInterface.o naiveInterfaceFunctions.o
CREATE_OBJECTS = create.o createFunctions.o
FILE_CONVERTER_OBJECTS = fileConverter.o fileConverterFunctions.o createFunctions.o
INDEXER_OBJECTS = indexer.o indexerFunctions.o
SRCH_INDX_OBJECTS = srchindx.o srchindxFunctions.o

.c.o:
	$(CC) $(CFLAGS) -c $<

all: naiveInterface create fileConverter indexer srchindx

naiveInterface: $(NAIVE_INTERFACE_OBJECTS)
	$(CC) $(NAIVE_INTERFACE_OBJECTS) -o naiveInterface

create: $(CREATE_OBJECTS)
	$(CC) $(CREATE_OBJECTS) -o create

fileConverter: $(FILE_CONVERTER_OBJECTS)
	$(CC) $(FILE_CONVERTER_OBJECTS) -o fileConverter

indexer: $(INDEXER_OBJECTS)
	$(CC) $(INDEXER_OBJECTS) -o indexer

srchindx: $(SRCH_INDX_OBJECTS)
	$(CC) $(SRCH_INDX_OBJECTS) -o srchindx

clean:
	rm -f *.o core
