CC=gcc
CFLAGS=-Wall -pedantic -std=c11
LDFLAGS=-lm
INTDIR=bin/intermediates
objects=main.o

.PHONY: all
all: debug release

debug: CFLAGS += -g
debug: $(objects)
	@mkdir -p bin/$@
	$(CC) $(CFLAGS) -o bin/$@/main $^ $(LDFLAGS)
	@mkdir -p $(INTDIR)/debug
	@mv *.o $(INTDIR)/debug

release: CFLAGS += -O3
release: $(objects)
	@mkdir -p bin/$@
	$(CC) $(CFLAGS) -o bin/$@/main $^ $(LDFLAGS)
	@mkdir -p $(INTDIR)/release
	@mv *.o $(INTDIR)/release

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf bin/intermediates bin/debug bin/release
