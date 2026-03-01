CC=gcc
CFLAGS=-Wall -pedantic -std=c11
objects=main.o

all: debug release

debug:
	$(CC) $(CFLAGS) -g -o ./bin/$@/main ./src/*.c

release: $(objects)
	$(CC) $(CFLAGS) -O3 -o ./bin/$@/main $^

%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-rm -f bin/debug/*
	-rm -f bin/release/*
