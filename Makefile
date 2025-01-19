CC = gcc
CFLAGS = -Wall -Werror -std=c99
TARGET = class_db

all: $(TARGET)

$(TARGET): main.o btree.o repl.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o btree.o repl.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

btree.o: btree.c btree.h
	$(CC) $(CFLAGS) -c btree.c

repl.o: repl.c repl.h btree.h
	$(CC) $(CFLAGS) -c repl.c

clean:
	rm -f *.o $(TARGET)
