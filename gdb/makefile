CC=gcc # for c

gdbrec: gdbrec.c
	$(CC) -o gdbrec -g3 gdbrec.c

gdbdiv: gdbdiv.c
	$(CC) -o gdbdiv -g3 gdbdiv.c

gdbunde: gdbunde.c
	$(CC) -o gdbunde -g3 gdbunde.c

PHONY: clean all

all: gdbrec gdbdiv gdbunde

clean:
	rm -f gdbrec gdbdiv gdbunde core