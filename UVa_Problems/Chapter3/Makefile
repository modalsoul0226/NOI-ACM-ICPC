SRCS = $(wildcard *.c)
LIBS = -lm
DEFS = -DLOCAL
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS) $(DEFS)

clean:
	rm -f $(PROGS)