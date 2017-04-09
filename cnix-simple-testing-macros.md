Simple macros for testing C programs
====================================

Good programmers test their code.  Many languages have fairly standardized
testing frameworks.  For example, Java has JUnit, Racket has RackUnit,
and Ruby has Minitest, Cucumber, RSpec, and more [1].  Because C was
developed so long before the advent of test-driven development or even
the xUnit series of test frameworks, there is less standardization in C.
As we saw in [an earlier essay](cnix-assert), one can do simple testing
using the `assert` macro.  However, `assert` may be of limited value
since it tells you only that an assertion failed.  It then becomes up to
you to trace why.

As a next step, we might develop our own simple testing framework.  We'll
focus on the basics: We often want to check whether an expression has a
particular value.  For example, if we've written a `square` procedure, we 
might want to check that the square of 5 is 25.  Let's write a simple
macro, `CHECK_EQUAL_INT(EXPECTED, ACTUAL)`, that evaluates `ACTUAL`,
checks whether it equals `EXPECTED`, and issues an error message if
they are not equal.

Let's see ... we could write that as follows.

<pre>
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  if (EXPECTED != ACTUAL) \
    { \
      fprintf (stderr, "Expected %d, got %d\n", EXPECTED, ACTUAL); \
    }
</pre>

Of course, we need a procedure to test.  Let's see ... what would be 
useful?  It's surprisingly hard to choose a procedure that I want to
implement incorrectly.  But here's one: Let's write a procedure to round 
integers to the nearest multiple of ten.  Here's an incorrect implementation.

<pre>
/**
 * Find the multiple of ten closest to n.
 */
int
nmo10 (int n)
{
  return n - (n % 10);
} // nmo10
</pre>

Here are a few tests.

<pre>
  CHECK_EQUAL_INT(0, nmo10 (3));
  CHECK_EQUAL_INT(10, nmo10 (12));
  CHECK_EQUAL_INT(20, nmo10 (18));
  CHECK_EQUAL_INT(20, nmo10 (22));
</pre>

Which of these does it pass?  Let's see.

<pre>
$ ./a.out
Expected 20, got 10
</pre>

Well, that's nice.  We got one error.  But we don't know which one it is.
I suppose it would be useful to print out the expression as well as its
value.  But how?  Fortunately, the gcc macro system lets us put an
octothorpe [2] before a parameter and get a string.  Hence, we can
update our macro slightly for clearer output.

<pre>
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  if (EXPECTED != ACTUAL) \
    { \
      fprintf (stderr, \
               "For '%s', expected %d, got %d\n", \
               #ACTUAL, EXPECTED, ACTUAL); \
    }
</pre>

What's our output now?

<pre>
$ ./a.out
For 'nmo10 (18)', expected 20, got 10
</pre>

Much nicer!  Can we do anything to make it even nicer?  Let's compare this
output to what we get from assert.  First, we'll rewrite our tests as
assertions.

<pre>
  assert (0 == nmo10 (3));
  assert (10 == nmo10 (12));
  assert (20 == nmo10 (18));
  assert (20 == nmo10 (22));
</pre>

Next, we'll compile and run the program.

<pre>
$ ./a.out
a.out: example.c:24: main: Assertion `20 == nmo10 (18)' failed.
</pre>

Let's see ... `assert` also showed us the problematic check,
but didn't tell us what we got for `nmo10 (18)`.  That makes
our macro a bit more useful.  On the other hand, `assert` did
give us a file and line number.  We should find a way to add
those.  A quick Web search gives us [useful documentation for GCC
macros](https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html).
In particular, we can quickly learn that the macros `__FILE__` and
`__LINE__` are available to us.  We can add those to our output.

<pre>
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  if (EXPECTED != ACTUAL) \
    { \
      fprintf (stderr, \
               "%s, line %d: For '%s', expected %d, got %d\n", \
               __FILE__, __LINE__, #ACTUAL, EXPECTED, ACTUAL); \
    }
</pre>

We might also add a few more tests.

<pre>
  CHECK_EQUAL_INT (0, nmo10 (0));
  CHECK_EQUAL_INT (0, nmo10 (3));
  CHECK_EQUAL_INT (10, nmo10 (9));
  CHECK_EQUAL_INT (10, nmo10 (12));
  CHECK_EQUAL_INT (20, nmo10 (18));
  CHECK_EQUAL_INT (20, nmo10 (22));
  CHECK_EQUAL_INT (1000, nmo10 (998));
  CHECK_EQUAL_INT (1000, nmo10 (1000));
  CHECK_EQUAL_INT (1000, nmo10 (1005));
</pre>

Is our improved output better?

<pre>
$ ./a.out
example.c, line 25: For 'nmo10 (9)', expected 10, got 0
example.c, line 27: For 'nmo10 (18)', expected 20, got 10
example.c, line 29: For 'nmo10 (998)', expected 1000, got 990
</pre>

Yes, that's much better.  We know where the error is.  We know that
we expected and what we actually got.  We know what the expression is.
We couldn't want much more than that.  

Now that we have a reasonable testing macro, we should follow the 
policies of test-driven design and fix our errors.    What was that
incorrect definition?

<pre>
int
nmo10 (int n)
{
  return n - (n % 10);
} // nmo10
</pre>

Hmmm ... Ah!  I've got it.  If I'm subtracting the remainder when
dividing by 10, I'll always round down.  That's easy enough to fix.
I'll just check whether the remainder is less than five.

<pre>
int
nmo10 (int n)
{
  if ((n % 10) < 5)
    return n - (n % 10);
  else
    return 10 + n - (n % 10);
} // nmo10
</pre>

This should pass our tests, right?

<pre>
$ ./a.out
example.c, line 34: For 'nmo10 (1005)', expected 1000, got 1010
</pre>

Ah!  That's interesting.  "Nearest multiple of 10" is ambiguous for
multiples of 5.  In writing the tests, I assumed we'd round down.  In
writing the code, I assumed we should round up [3].  Which is correct?
Arguably, either, as long as we document correctly [4].  Let's round
up, which means we should change our test.

<pre>
  CHECK_EQUAL_INT (1010, nmo10 (1005));
</pre>

Does our program pass now?

<pre>
$ ./a.out
$
</pre>

No output means that it passes.  Does that mean our program is correct?
Let's think about our tests.  Have we checked all of the edge cases?
We've tested using some large numbers.  We might check even larger
numbers.  We have tested using 0 [5].  Wait! We haven't tested using
negative numbers.  We definitely should.

<pre>
  CHECK_EQUAL_INT (0, nmo10 (0));
  CHECK_EQUAL_INT (0, nmo10 (3));
  CHECK_EQUAL_INT (10, nmo10 (9));
  CHECK_EQUAL_INT (10, nmo10 (12));
  CHECK_EQUAL_INT (20, nmo10 (18));
  CHECK_EQUAL_INT (20, nmo10 (22));
  CHECK_EQUAL_INT (1000, nmo10 (998));
  CHECK_EQUAL_INT (1000, nmo10 (1000));
  CHECK_EQUAL_INT (1010, nmo10 (1005));
  CHECK_EQUAL_INT (731230, nmo10 (731227));
  CHECK_EQUAL_INT (731230, nmo10 (731231));
  CHECK_EQUAL_INT (731230, nmo10 (731234));
  CHECK_EQUAL_INT (0, nmo10 (-1));
  CHECK_EQUAL_INT (0, nmo10 (-3));
  CHECK_EQUAL_INT (0, nmo10 (-5));
  CHECK_EQUAL_INT (-10, nmo10 (-7));
  CHECK_EQUAL_INT (-10, nmo10 (-9));
  CHECK_EQUAL_INT (-10, nmo10 (-10));
  CHECK_EQUAL_INT (-10, nmo10 (-11));
  CHECK_EQUAL_INT (-731230, nmo10 (-731227));
  CHECK_EQUAL_INT (-731230, nmo10 (-731231));
  CHECK_EQUAL_INT (-731230, nmo10 (-731234));
</pre>

These will pass, right?

<pre>
$ ./a.out
example.c, line 41: For 'nmo10 (-7)', expected -10, got 0
example.c, line 42: For 'nmo10 (-9)', expected -10, got 0
example.c, line 45: For 'nmo10 (-731227)', expected -731230, got -731220
</pre>

It looks like our code is wrong for some negative numbers, but not all of
them.  Why?  Oh, yeah, when you use `%` to compute a remainder and you
give it a negative number, it gives you a negative remainder.  

We'll leave fixing `nmo10` as an exercise for the reader.  Instead, we'll
look at a few more changes we might make to the `CHECK_EQUAL_INT` macro.

First, we should make it possible to turn off testing.  We have two options.
We could require that `TEST` be defined for the tests to run.  Or we
could require that `NOTEST` [6] be defined to turn off the tests.  Let's
use the latter strategy.

<pre>
#ifdef NOTEST
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL)
#else
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  if (EXPECTED != ACTUAL) \
    { \
      fprintf (stderr, \
               "%s, line %d: For '%s', expected %d, got %d\n", \
               __FILE__, __LINE__, #ACTUAL, EXPECTED, ACTUAL); \
    }
#endif
</pre>

The preprocessor should now give us different results depending on how
we compile.

<pre>
$ cc -E example.c
...
int
main (int argc, char *argv[])
{
  if (0 != nmo10 (0)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 30, "nmo10 (0)", 0, nmo10 (0)); };
  if (0 != nmo10 (3)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 31, "nmo10 (3)", 0, nmo10 (3)); };
...
$ cc -E -DNOTEST example.c
...
int
main (int argc, char *argv[])
{
  ;
  ;
  ;
...
</pre>

That's not bad.  The semicolons on lines by themselves worry
me slightly.  Here's one strategy I was taught: `do { } while (0)` is
a statement that does nothing, which means that the compiler eliminates
it.  At the same time, it does "consume" the semicolon at the end.
Let's make that change.  We'll make it in the primary macro, too, since
it's odd to have a semicolon after a close brace.

<pre>
#ifdef NOTEST
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) do { } while (0)
#else
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  do \
    { \
      if (EXPECTED != ACTUAL) \
        { \
          fprintf (stderr, \
                   "%s, line %d: For '%s', expected %d, got %d\n", \
                   __FILE__, __LINE__, #ACTUAL, EXPECTED, ACTUAL); \
        } \
    } \
  while (0)
#endif
</pre>

We should examine the effects of that change.

<pre>
$ cc -E example.c
...
int
main (int argc, char *argv[])
{
  do { if (0 != nmo10 (0)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 34, "nmo10 (0)", 0, nmo10 (0)); } } while (0);
  do { if (0 != nmo10 (3)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 35, "nmo10 (3)", 0, nmo10 (3)); } } while (0);
  do { if (10 != nmo10 (9)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 36, "nmo10 (9)", 10, nmo10 (9)); } } while (0);
...
$ cc -E -DNOTEST example.c
...
int
main (int argc, char *argv[])
{
  do { } while (0);
  do { } while (0);
  do { } while (0);
...
</pre>

Better.  Surprisingly, as I was checking some of my sources while writing this
musing, I did learn that [some folks suggest a different approach](http://stackoverflow.com/questions/1644868/c-define-macro-for-debug-printing/1644898#1644898) [7].  In particular, you want the compiler to see the testing statement no matter what, just so you know that it's syntactically correct.  But you set things up in such a way that a smart compiler will eliminate them so that there's no code executed.  We'll set a global constant to 0 or 1, depending on whether
or not we want the test to run.

<pre>
#ifdef NOTEST
#define __TESTING__ 0
#else
#define __TESTING__ 1
#endif

#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  do \
    { \
      if (__TESTING__) \
        { \
          if (EXPECTED != ACTUAL) \
            { \
              fprintf (stderr, \
                       "%s, line %d: For '%s', expected %d, got %d\n", \
                       __FILE__, __LINE__, #ACTUAL, EXPECTED, ACTUAL); \
            } \
        } \
    } \
  while (0)
</pre>

Here's a bit more output.

<pre>
$ cc -E example.c
...
int
main (int argc, char *argv[])
{
  do { if (1) { if (0 != nmo10 (0)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 40, "nmo10 (0)", 0, nmo10 (0)); } } } while (0);
  do { if (1) { if (0 != nmo10 (3)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 41, "nmo10 (3)", 0, nmo10 (3)); } } } while (0);
  do { if (1) { if (10 != nmo10 (9)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 42, "nmo10 (9)", 10, nmo10 (9)); } } } while (0);
...
$ cc -E -DNOTEST example.c
...
int
main (int argc, char *argv[])
{
  do { if (0) { if (0 != nmo10 (0)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 40, "nmo10 (0)", 0, nmo10 (0)); } } } while (0);
  do { if (0) { if (0 != nmo10 (3)) { fprintf (stderr, "%s, line %d: For '%s', expected %d, got %d\n", "example.c", 41, "nmo10 (3)", 0, nmo10 (3)); } } } while (0);
...
</pre>

Aren't you glad that you don't have to read preprocessed C with any
regularity?  

We still have a bit more work to do for this macro.  As we saw in [our initial
exploration of macros](cnix-intro-macros), we should worry about side
effects in the expressions passed to our macros, since we might end
up calling an expression twice.  Here's an example in which someone
misunderstands the purpose of postfix `++` in their tests.

<pre>
int
main (int argc, char *argv[])
{
  int x = 0;
  CHECK_EQUAL_INT (1, x++);
  CHECK_EQUAL_INT (1, x);

  return 0;
} // main
</pre>

Logically, the first test should fail and the second test should succeed.
However, that's not what happens.

<pre>
$ ./example
example.c, line 59: For 'x++', expected 1, got 1
example.c, line 60: For 'x', expected 1, got 2
</pre>

What happened?  `x++` got called twice, once in the comparison and once
in the call to `printf`.  We really want it called once, no matter what.
One way to address that issue is to add local variables.  Let's do so.

<pre>
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  do \
    { \
      if (__TESTING__) \
        { \
          int expected = EXPECTED; \
          int actual = ACTUAL; \
          if (expected != actual) \
            { \
              fprintf (stderr, \
                       "%s, line %d: For '%s', expected %d, got %d\n", \
                       __FILE__, __LINE__, #ACTUAL, expected, actual); \
            } \
        } \
    } \
  while (0)
</pre>

That change should fix our problem.

<pre>
$ ./example
example.c, line 42: For 'x++', expected 1, got 0
</pre>

Yup.  That fixed it.  We've gone about as far as I normally go in
writing a testing macro.  It was a lot of work, but it's work we're
going to do once and then use in a wide range of code [8].

---

Are we done?  Although we're done with the definition of
`CHECK_EQUAL_INT`, we are not done with our framework.  If we were making
a full-fledged testing framework, even a simple one, we'd want to do a
few more things.

We should add support for more types: strings, longs, doubles,
etc.  Floating-point types will present a small UI challenge, since
we'll want to think about how to deal with approximation.  For strings,
we may also want to consider whether we want to support both exact
equality and case-insensitive equality.

We should find a way to make our program return 1 if any test failed
and 0 if all the tests pass.  We could change the definition of
`CHECK_EQUAL_INT` so that it exits immediately upon failure.  But
most programmers find it useful to see *all* of their errors, not just
the first one.

We should provide access to the number of tests and the number of failed
tests, primarily so that we can report those to the programmer.  We also
want access to those so that the test program knows what to return.

But each of those tasks requires some effort.  We'll leave them as topics
for a future section or exercise.

---

[The Hemingway Editor](http://www.hemingwayapp.com/) tells me that
this piece is comprehensible to people with a Grade 2 education.  I knew
that the CS10K initiative was getting programming into our schools, but
I didn't realize that it was so early.  I must also admit that if I were
to choose a language for 2nd graders, I'd choose Scratch rather than C.

---

[1] Ruby definitely has an interesting developer community.

[2] hash, pound, `#`

[3] Yes, I really did make that pair of inconsistent decisions.

[4] Some implementations of rounding of decimal numbers round 0.5 to the
nearest even number.  So `round(1.5) => 2`, but `round(4.5) => 4`.  We
won't worry about being that sensible.

[5] As long as 0 is a valid input to your procedure, you should test with
zero.

[6] "NOTEST" is intended to represent "NO TEST" not "NOT EST".
Even though I reside in the midwest, I have no opposition to Eastern
Standard Time.

[7] While I don't always trust StackOverflow, some advice on StackOverflow
can be good.

[8] As importantly, once you've done the work to write these kinds of
macros once, you find it much easier to do so again in the future.  And,
as was the case when I wrote this piece, sometimes you learn new things
doing it again.

---

*Version 1.0 of 2017-04-08.*
