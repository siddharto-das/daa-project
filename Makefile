CC = gcc
CFLAGS = -g -Wall -O0

all: bin bin/employees

bin:
	mkdir bin

bin/employees: employees.o tree.o treedump.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean test

clean:
	rm *.o

test: bin/employees
	sh ./t/test.sh ./bin/employees ./t/*.t
