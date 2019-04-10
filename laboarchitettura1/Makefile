CFLAGS = -O3 -Wall
CLIBS  = -lm

all: problema1 problema2 problema3 problema4

problema1: problema1.o
	gcc $(CLIBS) $@.o -o $@

problema2: problema2.o
	gcc $(CLIBS) $@.o -o $@

problema3: problema3.o
	gcc $(CLIBS) $@.o -o $@

problema4: problema4.o problema4_funzioni.o
	gcc $@.o $@_funzioni.o -o $@

.c.o:
	gcc $(CFLAGS) -c $<

.o: .c

clean:
	/bin/rm -f *.o problema1 problema2 problema3 problema4
