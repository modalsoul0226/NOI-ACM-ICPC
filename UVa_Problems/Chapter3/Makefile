SRCS = $(wildcard *.c)
LIBS = -lm
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f $(PROGS)