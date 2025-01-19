CC = gcc
CFLAGS = -Wall -Werror -std=c99
TARGET = class_db

all: $(TARGET)

$(TARGET): src/main.o src/btree.o src/repl.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o btree.o repl.o

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

src/btree.o: src/btree.c src/btree.h
	$(CC) $(CFLAGS) -c src/btree.c

src/repl.o: src/repl.c src/repl.h src/btree.h
	$(CC) $(CFLAGS) -c src/repl.c

clean:
	rm -f *.o $(TARGET)
