CC = gcc
CFLAGS = -g -Wall -O0

all: bin bin/employees

bin:
	mkdir bin

bin/employees: employees.o tree.o treedump.o
	$(CC) $(CFLAGS) -o $@ $^

doc:
	mkdir doc

.PHONY: clean
clean:
	rm *.o
