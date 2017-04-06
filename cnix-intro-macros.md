An introduction to C macros
===========================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

As we saw in [our exploration of the C preprocessor](cnix-c-preprocessor),
the preprocessor can manipulate the text of your program in a variety
of useful ways.  However, we have left off one of the most useful:
Macros.  A C macro looks much like a function definition; it has a name,
parameters, and a body.  And, as you might expect, when we use a macro,
the actual parameters [1] get substituted for the formal parameters
[2].  The difference is that with macros, the preprocessor substitutes
the *text* of the actuals for the formals; with procedure, the call
substitutes the *value* of the actuals for the formals.

That difference will make more sense if we look concretely, rather than
abstractly.  So let's start with a simple macro definition.  As we
just noted, macros have a name, parameters, and a body.  We do not
type the parameters to macros because they accept *any* text.  We
also do not regularly put brackets around the body of a macro.  To
make it clear that we are defining a macro, we use the same `#define`
that we use for constants.

Here's a very simple macro which doubles its parameter.

<pre>
#define TWICE(X) X+X
</pre>

As you can tell, the name is `TWICE`, the parameter is `X`, and
the body is `X+X`.  Let's define a similar procedure.

<pre>
int twice(x)
{
  return x+x;
} // twice(x)
</pre>

Here's a simple `main` that uses both the macro and the procedure.

<pre>
int
main (int argc, char *argv[])
{
  printf ("TWICE(3) is %d\n", TWICE(3));
  printf ("twice(3) is %d\n", twice(3));
  return 0;
} // main
</pre>

If we compile and run the program, we get the expected result.

<pre>
TWICE(3) is 6
twice(3) is 6
</pre>

However, if we just run the preprocessor, we see that the two lines
actually represent somewhat different instructions.

<pre>
int
main (int argc, char *argv[])
{
  printf ("TWICE(3) is %d\n", 3 +3);
  printf ("twice(3) is %d\n", twice(3));
  return 0;
}
</pre>

What happens if we have a more complex expression that we want to double?
Let's see.

<pre>
int
main (int argc, char *argv[])
{
  int x = 5;
  printf ("TWICE(x+3) is %d\n", TWICE(x+3));
  printf ("twice(x+3) is %d\n", twice(x+3));
  return 0;
} // main
</pre>

What happens when we run the preprocessor?

<pre>
int
main (int argc, char *argv[])
{
  int x = 5;
  printf ("TWICE(x+3) is %d\n", x+3 +x+3);
  printf ("twice(x+3) is %d\n", twice(x+3));
  return 0;
}
</pre>

Again, we see different instructions, but instructions that we expect
to have similar results.

<pre>
TWICE(x+3) is 16
twice(x+3) is 16
</pre>

Does it matter whether we use the macro or the procedure?  Not a lot
when we are just doubling numbers.  If we consider the first example,
you should note that it is likely to be faster to add two numbers than
it is to do a procedure call [3].  Let's see for ourselves with a quick
experiment [4].

<pre>
#define REPETITIONS 1000000000

int
main (int argc, char *argv[])
{
  long x;   // For doing pointless computations
  int i;    // Counter variable for loops

  struct timeval start;         // The start of a computation
  struct timeval finish;         // The end of a computation

  long elapsed;                 // Elapsed time in microseconds


  // Compute how long a lot of calls to TWICE take
  x = 0;
  gettimeofday(&start, NULL);
  for (i = 0; i < REPETITIONS; i++)
    {
      x += TWICE(3);
    }
  gettimeofday(&finish, NULL);
  elapsed = 1000000 * (finish.tv_sec - start.tv_sec)
          + (finish.tv_usec - start.tv_usec);
  printf ("Using the macro, we spent %ld microseconds.\n", elapsed);
  printf ("Our result is %ld.\n\n", x);

  // Compute how long a lot of calls to TWICE take
  x = 0;
  gettimeofday(&start, NULL);
  for (i = 0; i < REPETITIONS; i++)
    { 
      x += twice(3);
    }
  gettimeofday(&finish, NULL);
  elapsed = 1000000 * (finish.tv_sec - start.tv_sec)
          + (finish.tv_usec - start.tv_usec);
  printf ("Using the procedure, we spent %ld microseconds.\n", elapsed);
  printf ("Our result is %ld.\n\n", x);

  return 0;
} // main
</pre>

Here's some sample output from my desktop machine, which is a few years
old.

<pre>
Using the macro, we spent 2386196 microseconds.
Our result is 6000000000.

Using the procedure, we spent 3090000 microseconds.
Our result is 6000000000.
</pre>

It looks like the macro takes about 80% as much time as the procedure
call.  That's not a huge gain, but it's something.  However, I will
note that a good optimizer can make things much faster in both cases.
Here's the output from the program, on the same machine, when compiled
with `-O3`.

<pre>
Using the macro, we spent 1 microseconds.
Our result is 6000000000.

Using the procedure, we spent 1 microseconds.
Our result is 6000000000.
</pre>

Yeah, compilers are way too smart these days.

So, why would you ever to use a macro rather than a procedure, other
than for speedup?  Well, it turns out that there are some things that
are difficult to do with procedures.  For example, what if we wanted
to do the timing above for an arbitrary line of code?  We can write
a macro!  (Note that we can use backslashes to continue the macro
to a new line.)

<pre>
#define REPETITIONS 1000000000

#define TIME(LINE) \
  { \
    struct timeval start; \
    struct timeval finish; \
    int i; \
    long elapsed; \
    gettimeofday(&start, NULL); \
    for (i = 0; i < REPETITIONS; i++) \
      { \
        LINE; \
      } \
    printf ("We spent %ld microseconds.\n", elapsed); \
  }

int
main (int argc, char *argv[])
{
  long x;   // For doing pointless computations

  x = 0;
  printf ("Using the macro\n");
  TIME (x += TWICE(3));
  printf ("Our result is %ld.\n\n", x);

  x = 0;
  printf ("Using the procedure\n");
  TIME (x += twice(3));
  printf ("Our result is %ld.\n\n", x);

  return 0;
} // main
</pre>

What happens if we run that through the preprocessor?  Let's see!

<pre>
int
main (int argc, char *argv[])
{
  long x;

  x = 0;
  printf ("Using the macro\n");
  { struct timeval start; struct timeval finish; int i; long elapsed; gettimeofday(&start, ((void *)0)); for (i = 0; i < 1000000000; i++) { x += 3 +3; } printf ("We spent %ld microseconds.\n", elapsed); };
  printf ("Our result is %ld.\n\n", x);

  x = 0;
  printf ("Using the procedure\n");
  { struct timeval start; struct timeval finish; int i; long elapsed; gettimeofday(&start, ((void *)0)); for (i = 0; i < 1000000000; i++) { x += twice(3); } printf ("We spent %ld microseconds.\n", elapsed); };
  printf ("Our result is %ld.\n\n", x);

  return 0;
}
</pre>

Pretty cool [5]!  Presumably, you've been told to DRY [6] out your code.
Macros clearly help.

Because they involve textual substitution, macros have many
subtleties and can lead to unexpected behavior when you think about
them only as procedures.  Let's consider a variant of our first program.

<pre>
int
main (int argc, char *argv[])
{
  printf ("4*TWICE(3) is %d\n", 4*TWICE(3));
  printf ("4*twice(3) is %d\n", 4*twice(3));
  return 0;
} // main
</pre>

What do you expect the output to be?  Let's check.

<pre>
4*TWICE(3) is 15
4*twice(3) is 24
</pre>

Why didn't we get the same answer for the two similar expressions?
Let's look at what the code looks like after preprocessing.

<pre>
int
main (int argc, char *argv[])
{
  printf ("4*TWICE(3) is %d\n", 4*3 +3);
  printf ("4*twice(3) is %d\n", 4*twice(3));
  return 0;
}
</pre>

Whoops!  Because the *text* of the macro call was expanded, we ended
up with an expression with a slightly different meaning than we had
intended.  However, that's easy to fix.  We can just parenthesize the
body of the macro.

<pre>
#define TWICE(X) (X+X)

int
main (int argc, char *argv[])
{
  printf ("4*TWICE(3) is %d\n", 4*TWICE(3));
  printf ("4*twice(3) is %d\n", 4*twice(3));
  return 0;
} // main
</pre>

Now, what happens when we preprocess this code?

<pre>
int
main (int argc, char *argv[])
{
  printf ("4*TWICE(3) is %d\n", 4*(3 +3));
  printf ("4*twice(3) is %d\n", 4*twice(3));
  return 0;
}
</pre>

Ah! That looks much better.  Is the output right?

<pre>
4*TWICE(3) is 24
4*twice(3) is 24
</pre>

Yes, it is.

Are we done with subtleties and uses of macros?  Certainly not.  Getting a
reasonable understand of macros will take a few different sections.
But we should look at a few more.  As a starting point, let's define a
macro that squares its parameter.

<pre>
#define SQUARE(X) (X*X)

int
square (int x)
{
  return x*x;
} // square

int
main (int argc, char *argv[])
{
  printf ("square(5) is %d\n", square(5));
  printf ("SQUARE(5) is %d\n", SQUARE(5));
  return 0;
} // main
</pre>

Can you predict the result of preprocessing and the output we
get when we run this program?  

Have you thought about it?

Really?

Are you sure?

Okay, here's the result of preprocessing.

<pre>
int
square (int x)
{
  return x*x;
}

int
main (int argc, char *argv[])
{
  printf ("square(5) is %d\n", square(5));
  printf ("SQUARE(5) is %d\n", (5*5));
  return 0;
}
</pre>

Here's the output.

<pre>
square(5) is 25
SQUARE(5) is 25
</pre>

I hope that's what you expected.  Now, let's consider a slight variant.
What happens if we try to square a floating-point number?

<pre>
int
main (int argc, char *argv[])
{
  printf ("square(617.312) is %lf\n", square(617.312));
  printf ("SQUARE(617.312) is %lf\n", SQUARE(617.312));
  return 0;
} // main
</pre>

Well, when we try to compile, we get a warning.

<pre>
example.c: In function ‘main’:
example.c:15:3: warning: format ‘%lf’ expects argument of type ‘double’, but argument 2 has type ‘int’ [-Wformat=]
   printf ("square(617.312) is %lf\n", square(617.312));
   ^
</pre>

That suggests we've made a bad decision, since C doesn't like it when
you use one type in place of another without an explicit cast.  So
let's put in the explicit cast [7].

<pre>
int
main (int argc, char *argv[])
{
  printf ("square(617.312) is %lf\n", (double) square(617.312));
  printf ("SQUARE(617.312) is %lf\n", SQUARE(617.312));
  return 0;
} // main
</pre>

What happens when we compile and run now?  We get no warnings.   That's
a good sign.  What about the output?

<pre>
square(617.312) is 380689.000000
SQUARE(617.312) is 381074.105344
</pre>

Since `square` was intended to take integers, the `617.312` got rounded to
`617` before squaring.  However, the macro worked fine.  That's a clear
advantage of macros: You can write just one macro, and it will work with
multiple types.  Our `SQUARE` macro will return an `int` when given an
`int`, a `double` when given a `double`, a `long` when given a `long`,
and so on and so forth.

That was another advantage of macros.  Are there other problems?  
Think about the previous example using `TWICE`.  We've parenthesized
here to avoid that problem, but are there similar ones?

Are there?

Have you really thought about the question?

Yes, I realize that the answer is coming up in a minute, but you'll
do better if you think it through.

Are you ready?

Okay, let's consider the following program.

<pre>
int
main (int argc, char *argv[])
{
  printf ("square(3+5) is %d\n", square(3+5));
  printf ("SQUARE(3+5) is %d\n", SQUARE(3+5));
  return 0;
} // main
</pre>

What will the output be?

No, I won't put in the annoying series of questions this time.  I'll
be confident that you've thought about it.

<pre>
square(3+5) is 64
SQUARE(3+5) is 23
</pre>

Whoops!  What went wrong?  Let's check with the preprocessor.

<pre>
int
main (int argc, char *argv[])
{
  printf ("square(3+5) is %d\n", square(3+5));
  printf ("SQUARE(3+5) is %d\n", (3+5*3+5));
  return 0;
}
</pre>

Ah!  It's the same problem, just backwards [8].  Think about how
to fix it.

Have you come up with an idea?

Here's mine.

<pre>
#define SQUARE(X) ((X)*(X))
</pre>

That's right.  When in doubt, add more parentheses [9].  Does
this solve our problem?  Let's check.

<pre>
square(3+5) is 64
SQUARE(3+5) is 64
</pre>

Provided our goal was to get the behavior of `SQUARE` to match the
behavior of `square`, it looks like we got what we wanted.  

Let's consider one more "fun" [10] set of examples.  What happens if
we pass an expression with side effects to the macro?

<pre>
#define SQUARE(X) ((X)*(X))

int
main (int argc, char *argv[])
{
  int a = 2;
  int b = 2;
  printf ("square(a++) is %d\n", square(a++));
  printf ("a is now %d\n", a);
  printf ("SQUARE(b++) is %d\n", SQUARE(b++));
  printf ("b is now %d\n", b);
  return 0;
} // main
</pre>

What will the output be?

No, really, think about it.

Here we go ...

<pre>
square(a++) is 4
a is now 3
SQUARE(b++) is 6
b is now 4
</pre>

Did you know that `6` is a square?  Let's do one more example.

<pre>
int
main (int argc, char *argv[])
{
  int a = 2;
  int b = 2;
  printf ("square(++a) is %d\n", square(++a));
  printf ("a is now %d\n", a);
  printf ("SQUARE(++b) is %d\n", SQUARE(++b));
  printf ("b is now %d\n", b);
  return 0;
} // main
</pre>

Can you predict the output?  

This is what I get on my desktop.

<pre>
square(++a) is 9
a is now 3
SQUARE(++b) is 16
b is now 4
</pre>

Let's make it even more fun.

<pre>
int 
main (int argc, char *argv[])
{
  int a;
  
  a = 2;
  printf ("a is %d\n", a);
  printf ("square(square(a++)) is %d\n", square(square(a++)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("SQUARE(SQUARE(a++)) is %d\n", SQUARE(SQUARE(a++)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("SQUARE(square(a++)) is %d\n", SQUARE(square(a++)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("square(SQUARE(a++)) is %d\n", square(SQUARE(a++)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("SQUARE(square(++a)) is %d\n", SQUARE(square(++a)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("square(SQUARE(++a)) is %d\n", square(SQUARE(++a)));
  printf ("a is now %d\n", a);

  return 0;
} // main
</pre>

What's the output?  On my computer, it's as follows.

<pre>
a is 2
square(square(a++)) is 16
a is now 3
a is 2
SQUARE(SQUARE(a++)) is 120
a is now 6
a is 2
SQUARE(square(a++)) is 36
a is now 4
a is 2
square(SQUARE(a++)) is 36
a is now 4
a is 2
SQUARE(square(++a)) is 144
a is now 4
a is 2
square(SQUARE(++a)) is 256
a is now 4
</pre>

Fascinating, isn't it?  I'll leave it to you to figure out why we got
these results [11].

---

[1] The actual parameters are those in the call to the the macro or 
procedure.  We often call these "actuals".

[2] The formal parameters are those in the definition of the macro or
procedure.  We often refer to these as "formals".

[3] In fact, the optimizer is likely to turn `3+3` into `6`, eliminating
the computation altogether.

[4] If this were not a quick experiment, we would write better code.
We would certainly write less repetitious code.

[5] I admit it: I'm strange; I really do find this cool.

[6] DRY is the TLA for Don't Repeat Yourself.

[7] Why don't we need to cast the actual to an `int`?  Because the
C compiler decides that's an "obvious" cast.

[8] I guess that means it's not the same problem.

[9] And you thought Scheme had too many parens!

[10] I think it's fun; you may not.

[11] "Computers are sentient and malicious!" is a perfectly reasonable
response [12].

[12] I suppose "Sam is sentient and malicious!" is also a reasonable
response.

---

*Version 1.0 of 2017-04-05.*
