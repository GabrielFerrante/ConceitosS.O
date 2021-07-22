CC = g++
CFLAGS  = -g -Wall
LDFLAGS =

src = $(wildcard *.cc)
obj = $(src:.cc=.o)

default: simulador

simulador: $(obj)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) simulador
