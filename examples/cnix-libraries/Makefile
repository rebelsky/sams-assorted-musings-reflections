# Makefile
#   A simple Makefile for our basic C project 

# +-----------+------------------------------------------------------
# | Variables |
# +-----------+

CC = gcc
CFLAGS = -Wall -g
LDLIBS = -L. -lmathlib

# More readable versions of the automatic variables
.TARGET = $@
.IMPSRC = $<
.ALLSRC = $^

# +---------+--------------------------------------------------------
# | Targets |
# +---------+

# Our tests
test: ./test-gcd
	./test-gcd

# The library
libmathlib.a: mathlib-gcd.o mathlib-str2long.o
	ar -rv $(.TARGET) $(.ALLSRC)

# Our application
gcd: gcd.o libmathlib.a
	$(CC) $(.IMPSRC) $(LDLIBS) -o $(.TARGET)

# Our tests
test-gcd: test-gcd.o libmathlib.a
	$(CC) $(.IMPSRC) $(LDLIBS) -o $(.TARGET)

# +-------------------------+----------------------------------------
# | Additional Dependencies |
# +-------------------------+

*.o: mathlib.h
