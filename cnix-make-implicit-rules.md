Implicit rules in Make
======================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

As I hope you recall, we are an on ongoing journey to explore how to
use Make to make your program construction more efficient.  We started
by looking at [a sample C project](cnix-sample-project) and thinking
about the relationships between the files in that project.  We continued
by learning [how to write basic rules in Make](cnix-make-intro), using
the basic pattern of

    TARGET: DEPENDENCIES
            INSTRUCTIONS

While the Makefile we created using that approach was clear, it was also
repetitious.  Next, we learned how to use [variables](cnix-make-variables)
to eliminate some of that repetition [1].  Here's one of the improved 
Makefiles we created along the way.

    # Makefile
    #   A simple Makefile for our basic C project 
    
    # +-----------+------------------------------------------------------
    # | Variables |
    # +-----------+
    
    CC = gcc
    CFLAGS = -g -Wall
    
    # +---------+--------------------------------------------------------
    # | Targets |
    # +---------+
    
    # Our application
    gcd: gcd.o mathlib-gcd.o
            $(CC) -o $@ $^
    
    # Our tests
    test: ./test-gcd
            $<
    test-gcd: test-gcd.o mathlib-gcd.o
            $(CC) -o $@ $^
    
    # The components
    mathlib-gcd.o: mathlib-gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o $@ $<
    gcd.o: gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o $@ $<
    test-gcd.o: test-gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o $@ $<

However, as we noted, this Makefile is still a bit repetitious.  The designers
of Make [2] wanted to make it easier to avoid that repetition, and introduced
what they call "implicit" rules.  Implicit rules involve *patterns*.  In
particular, the symbol `%` matches an arbitrary string of characters,
and can appear on both the left-hand-side and right-hand-side of a rule.
For example, here's how I'd write that to create a `.o` file, I need
a `.c` file with the same prefix.

    %.o: %.c
            INSTRUCTIONS

Let's try it out by updating our Makefile once again.

    # Makefile
    #   A simple Makefile for our basic C project 
    
    # +-----------+------------------------------------------------------
    # | Variables |
    # +-----------+
    
    CC = gcc
    CFLAGS = -g -Wall
    
    # +----------------+-------------------------------------------------
    # | Implicit Rules |
    # +----------------+
    
    # Generating .o files
    %.o: %.c mathlib.h
            $(CC) $(CFLAGS) -c -o $@ $<
    
    # Generating executables
    %: %.o mathlib-gcd.o
            $(CC) -o $@ $^
    
    # +---------+--------------------------------------------------------
    # | Targets |
    # +---------+
    
    # Our tests
    test: ./test-gcd
            $<

This new Makefile is more concise, although those new implicit rules are
a bit hard to read.  Does this work, even though we don't mention most
things explicitly?  Let's see.

    $ touch *.c
    $ make test-gcd.o
    gcc -g -Wall   -c -o test-gcd.o test-gcd.c
    $ make gcd
    gcc -g -Wall   -c -o gcd.o gcd.c
    gcc -g -Wall   -c -o mathlib-gcd.o mathlib-gcd.c
    gcc -o gcd gcd.o mathlib-gcd.o
    $ make foo.o
    make: *** No rule to make target 'foo.o'.  Stop.
    $ make test
    gcc -o test-gcd test-gcd.o mathlib-gcd.o
    test-gcd

Yes, it works pretty well.  It also knows what it can and cannot make.
We're doing well.

Now, here's the really cool thing.  The designers of Make realized that
there are a number of common patterns.  For example, almost everyone
converts a `.c` file to a `.o` file with an instruction almost identical
to ours.  And so they included all of those patterns in a "default
database".  You can read that database with `make -p`.  Here's a sampling.

    $ make -p
    # default
    OUTPUT_OPTION = -o $@
    ...
    # default
    LINK.o = $(CC) $(LDFLAGS) $(TARGET_ARCH)
    ...
    # default
    COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
    ...
    %.o: %.c
    #  recipe to execute (built-in):
            $(COMPILE.c) $(OUTPUT_OPTION) $<
    ...
    %: %.o
    #  recipe to execute (built-in):
            $(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

So, we can even remove the rules for generating the `.o` files from our
Makefile, and it will still work.  We should, however, still indicate
that the `.o` files depend on `mathlib.h`.

    # Makefile
    #   A simple Makefile for our basic C project 
    
    # +-----------+------------------------------------------------------
    # | Variables |
    # +-----------+
    
    CC = clang
    CFLAGS = -Wall -g
    
    # +----------------+-------------------------------------------------
    # | Implicit Rules |
    # +----------------+
    
    # Generating executables
    %: %.o mathlib-gcd.o
            $(CC) -o $@ $^
    
    # +---------+--------------------------------------------------------
    # | Targets |
    # +---------+
    
    # Our tests
    test: ./test-gcd
            $<
    
    # +-------------------------+----------------------------------------
    # | Additional Dependencies |
    # +-------------------------+
    
    *.o: mathlib.h

As we hoped, this revised file continues to work well.

    $ touch *.c
    $ make mathlib-gcd.o
    clang -Wall -g   -c -o mathlib-gcd.o mathlib-gcd.c
    $ make test
    clang -Wall -g   -c -o test-gcd.o test-gcd.c
    clang -o test-gcd test-gcd.o mathlib-gcd.o
    test-gcd
    $ touch mathlib.h
    $ make test
    clang -Wall -g   -c -o test-gcd.o test-gcd.c
    clang -Wall -g   -c -o mathlib-gcd.o mathlib-gcd.c
    clang -o test-gcd test-gcd.o mathlib-gcd.o
    test-gcd

Can we get rid of the other implicit rule in our Makefile?  Let's try
dropping it altogether and making no other changes.

    $ touch *.c
    $ make test
    clang -Wall -g   -c -o test-gcd.o test-gcd.c
    clang   test-gcd.o   -o test-gcd
    test-gcd.o: In function `main':
    /home/rebelsky/Web/musings/examples/cnix-make-variables/test-gcd.c:24: undefined reference to `gcd'
    /home/rebelsky/Web/musings/examples/cnix-make-variables/test-gcd.c:25: undefined reference to `gcd'
    /home/rebelsky/Web/musings/examples/cnix-make-variables/test-gcd.c:26: undefined reference to `gcd'
    /home/rebelsky/Web/musings/examples/cnix-make-variables/test-gcd.c:29: undefined reference to `gcd'
    /home/rebelsky/Web/musings/examples/cnix-make-variables/test-gcd.c:30: undefined reference to `gcd'
    test-gcd.o:/home/rebelsky/Web/musings/examples/cnix-make-variables/test-gcd.c:31: more undefined references to `gcd' follow
    clang: error: linker command failed with exit code 1 (use -v to see invocation)
    <builtin>: recipe for target 'test-gcd' failed
    make: *** [test-gcd] Error 1

Whoops!  I guess now.  Why not?  Well, let's look at the instruction that
`make` used to create `test-gcd`.

    clang   test-gcd.o   -o test-gcd

What did we use successfully?

    clang -o test-gcd test-gcd.o mathlib-gcd.o

What's different?  The order of arguments and the fact that we included
`mathlib-gcd.o` and Make didn't.  The order of arguments shouldn't 
matter [3].  But it's hard to use the `gcd` function if we don't have
the code for it.  Can we force Make to include that?  Well, let's look
at the default rule again.

    %: %.o
    #  recipe to execute (built-in):
            $(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

It looks to me like we could define `$(LDLIBS)` [4] to use `mathlib-gcd.o`
as a library [5].  Let's try.

    # Makefile
    #   A simple Makefile for our basic C project 
    
    # +-----------+------------------------------------------------------
    # | Variables |
    # +-----------+
    
    CC = clang
    CFLAGS = -Wall -g
    LDLIBS = mathlib-gcd.o
    
    # +---------+--------------------------------------------------------
    # | Targets |
    # +---------+
    
    # Our tests
    test: ./test-gcd
            $<
    
    # +-------------------------+----------------------------------------
    # | Additional Dependencies |
    # +-------------------------+
    
    *.o: mathlib.h

That's nice and concise.  Will it work?

    $ touch *.c
    $ make test
    clang -Wall -g   -c -o test-gcd.o test-gcd.c
    clang   test-gcd.o  mathlib-gcd.o -o test-gcd
    test-gcd

Is this what we want?  Not quite.  You'll note that it did not remake
`mathlib-gcd.o`, even though the source had changed.  Can you figure out
why?

What should you take as the morals of this section?  First, that implicit
rules let you write much more concise Makefiles.  Second, that you need 
some experience to read implicit rules, since they are not as clear as
more explicit rules [6].  Third, that there are a large number of built-in
rules that you can leverage.  Finally, that sometimes you still have to
write your own implicit and explicit rules, since the built-in implicit
rules won't do quite what you want.

You just have a few more things to learn about Make and then you'll know
enough that, with practice, you can be a competent user of Make, or at
least a competent reader of Makefiles.

---

[1] Some programmers would say we wanted to "DRY" out our code.  DRY stands
for "Don't Repeat Yourself".

[2] Or at least of GNU Make.

[3] Fingers crossed.

[4] Or `$(LOADLIBES)`.

[5] Okay, we really should turn `mathlib-gcd.o` into a separate library.
But we'll do that later.

[6] Don't worry!  With some practice, you'll find that the implicit
rules are pretty clear.

---

*Version 1.0 released 2017-01-09.*

*Version 1.0.2 of 2021-04-22.*
