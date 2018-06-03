LIBS  = -lm
CFLAGS = -Wall -g -std=gnu99

# Compile all c files under this dir.
SRC=$(wildcard *.c)

test: $(SRC) 
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f test