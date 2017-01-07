CFLAGS = -g -Wall

# +------------------+-----------------------------------------------
# | Standard Targets |
# +------------------+

default: all

all: gcd

test: test-gcd
	./test-gcd

clean: 
	rm -f gcd test-gcd *.o

# +-------------+----------------------------------------------------
# | Executables |
# +-------------+

gcd: gcd.o mathlib-gcd.o
	$(CC) -o $@ $^

test-gcd: test-gcd.o mathlib-gcd.o
	$(CC) -o $@ $^

# +---------------------+--------------------------------------------
# | Header Dependencies |
# +---------------------+

# I should probably use makedepend to generate these.

mathlib-gcd.o: mathlib.h
gcd.o: mathlib.h
test-gcd.o: mathlib.h
