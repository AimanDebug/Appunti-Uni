CC=gcc
CFLAGS=-Wall -pedantic
objects=main.o

main: $(objects)
	$(CC) $(CFLAGS) -lm -o ./bin/$@ $(objects)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
