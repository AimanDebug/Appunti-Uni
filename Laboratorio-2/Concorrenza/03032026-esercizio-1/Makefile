CC=gcc
CFLAGS=-Wall -pedantic -std=c11
LDFLAGS=-lm
objects=main.o

debug: CFLAGS += -g
debug: MODE=debug
debug: build

release: CFLAGS += -O3
release: MODE=release
release: build

build: $(objects) | create_bin_dir
	$(CC) $(CFLAGS) -o bin/$(MODE)/main $^ $(LDFLAGS)
	@mv *.o bin/intermediates/$(MODE)/

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf bin

.PHONY: create_bin_dir
create_bin_dir:
	@mkdir -p bin/debug
	@mkdir -p bin/release
	@mkdir -p bin/intermediates/debug/../release
