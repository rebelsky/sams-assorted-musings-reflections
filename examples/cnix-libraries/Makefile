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

dist: mathlib-gcd.c mathlib-str2long.c Makefile mathlib.h test-gcd.c
	rm -rf mathlib-0.1
	mkdir mathlib-0.1
	cp $^ mathlib-0.1
	tar cvzf mathlib-0.1.tgz mathlib-0.1
	rm -rf mathlib-0.1

PROJECT = mathlib
VERSION = 0.1
PROJDIR = $(PROJECT).$(VERSION)
TARBALL = $(PROJECT).$(VERSION).tgz
SOURCES = mathlib-gcd.c mathlib-str2long.c
HEADERS = mathlib.h
TESTING = test-gcd.c
MORESRC = Makefile
PRJDIST = $(SOURCES) $(HEADERS) $(TESTING) $(MORESRC)

dist2: $(PRJDIST)
	rm -rf $(PROJDIR)
	mkdir $(PROJDIR)
	cp $^ $(PROJDIR)
	tar cvzf $(TARBALL) $(PROJDIR)
	rm -rf $(PROJDIR)

# +-------------------------+----------------------------------------
# | Additional Dependencies |
# +-------------------------+

*.o: mathlib.h
