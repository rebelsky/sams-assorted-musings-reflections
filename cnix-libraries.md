Building C libraries
====================

*Why are we considering libraries in the middle of an extended discussion
of Make?  Because real C programmers build libraries, and before we 
get to the end of Make, you should know how to use libraries in your
C projects.*

As you may recall, in our [simple C project](cnix-simple-c-project),
we had developed a simple set of utility functions [1], an application
that used that set of utilitity functions [2], and a reasonably robost
test suite.  What form did our set of utility functions take?  At least
at first, it was just a `.o` file, which we linked in the standard way.

    $ cc -g -Wall   -c -o gcd.o gcd.c
    $ cc -g -Wall   -c -o mathlib-gcd.o mathlib-gcd.c
    $ cc -o gcd gcd.o mathlib-gcd.o

But once we end up with a lot of files for our utility functions, that's
going to make our instructions much more complicated.  In addition,
other folks who want to use the utilities are likely to want to be able
to remember just one file name, rather than each of the component pieces.

Fortunately, the C ecosystem [3] permits you to combine lots of object
code into a single file, which is typically referred to as a "library".
Back when I was a young programmer [4], there was only one kind of
library.  Now there are at least two: static libraries (the kind I learned
about) and shared libraries (the kind most people use).  You use the two
kinds of libraries in similar ways, but you create them in different ways.

Static libraries end with a `.a` suffix, for "archive".  Conveniently,
you create archive files with the `ar` command.  We will typically use
the parameters `r` (for "add, **r**eplacing if necessary) and `v` (for
"**v**erbose") [5].

    $ ar -rv libmathlib.a mathlib-gcd.o

Now, how do we tell the C compiler to use the library?  The `-lNAME` flag
says to include a library and the `-LDIR` flag tells the compiler where
to look for libraries.  (Libraries, like header files, can be stored in
lots of places.)  For the name of the library, you don't use the initial
`lib` [6].  And the library is in the current directory, so you can write
the following.

    $ cc gcd.o -o gcd -L. -lmathlib

You've encountered something similar when you use the standard C math
library: You write `-lm` when you want the math library.  You don't need
the `-L.` because the math library is in a standard directory somewhere.

What does our Makefile look like after all of this?  It's a bit longer [7],
but probably usefully so.

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
    	$<
    
    # The library
    libmathlib.a: mathlib-gcd.o
    	ar -rv $(.TARGET) $(.ALLSRC)
    
    # +-------------------------+----------------------------------------
    # | Additional Dependencies |
    # +-------------------------+
    
    *.o: mathlib.h
    gcd: libmathlib.a
    test-gcd: libmathlib.a

Let's make sure that it works.


Yup.  Everything looks good.

Are we done?  Twenty years ago, we would have been done [8].  But we
should really think about how to make shared libraries.

You make shared  libraries by passing the `-shared` flag to your
C compiler [9].  You must also build the `.o` files using `-fPIC`
(for position-independent code)

    $ gcc -shared -o libmathlib.so mathlib-gcd.o

---

[1] That library consists of exactly one function, `int gcd(int,int)`.

[2] More precisely, I asked *you* to develop that application.

[3] Or at least the Unix C ecosystem.

[4] Yes, I learned C from the first edition of K&R.

[5] No, we are not making a recreational vehicle.

[6] There's probably a good reason, but don't ask me.

[7] I've also added some BSD-style aliases for the automatic variables
to make BD happy.

[8] Or maybe thirty; I've forgotten how long ago shared object files
came into common usage.

[9] Or at least to gcc; I don't use enough other compilers to know for
sure.

---

*Version 1.0 of 2017-01-11.*
