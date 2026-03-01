CC=gcc
CFLAGS=-Wall -pedantic
OBJDIR=bin/${MODE}
objects=main.o my_barrier.o

all: debug release
	
debug: CFLAGS += -g
debug: MODE =debug
debug: $(objects)
	$(CC) $(CFLAGS) -o bin/$@/main 

release: CFLAGS += -O3
release: MODE =release
release: $(objects)
	$(CC) $(CFLAGS) -o bin/$@/main $(objects)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o bin/${MODE}/intermediates/$@

.PHONY: clean
clean:
	rm -fr bin/debug/* bin/release/*
