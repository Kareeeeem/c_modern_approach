CC = gcc
CFLAGS = -g -Wall -Wextra -std=c99

.PHONY: clean

bin/justify: justify.o word.o line.o | bin
	$(CC) $(CFLAGS) -o $@ $^

justify.o: justify.c word.h line.h
	$(CC) $(CFLAGS) -c $<

word.o: word.c word.h
	$(CC) $(CFLAGS) -c $<

line.o: line.c line.h
	$(CC) $(CFLAGS) -c $<

bin:
	mkdir bin

clean:
	rm -f bin/justify
	rm -f *.o
