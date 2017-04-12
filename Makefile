CC ?= cc

CFLAGS = -Wall -pedantic -O3
LDFLAGS =

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

EXE = bin/mls

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $+ -o $@

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(EXE) $(OBJ)

.PHONY: all clean
