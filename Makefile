CC=clang
CFLAGS=-std=gnu99 -g -Wall -Wno-multichar $(UFLAGS)

.PHONY: clean test

nt: lib.o

minilisp: minilisp.c

clean:
	rm -f minilisp *~

test: minilisp
	@./test.sh

%.dump: %.o
	objdump -d -Mintel $<
