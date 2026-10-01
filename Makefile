CC = gcc
CFLAGS = -g -Wall -O0 -std=c23

all: bin bin/employees

bin:
	mkdir bin

bin/employees: employees.o tree.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm *.o
