---
title: Preconditions for strcpy
number: 1130
tags: [Don't embarrass me, don't embarrass yourself: Thoughts on thinking in C and Unix](index-cnix)
blurb: Attempts to understand memory usage.
version: 1.0
released: 2021-04-01
current: 
---
As you may recall, I often use the K&R explanation of `strcpy` to explain
what it means to think like a C programmer [1]

    void strcpy(char *s, char *t)
    {
      while (*s++ = *t++)
        ;
    }

Why does this code require a special kind of thinking?  Well, among
other things, it requires you to understand how pointers and
dereferncing work, how post-increment works with pointers, precedence,
that strings are zero-terminated, and that assignment expressions
return the value assigned.

Here's the next question: Given two strings (character pointers),
`u` and `v`, how do we know whether we can safely call `strcpy(u,v)`?
Computer scientists often refer to these as the *preconditions* of
`strcpy`.

There are at least two aspects to that question.  First, what
expectations do we place on those strings and second, how do we
determine whether or not those expectations are met?

The basic expectations seem fairly obvious, at least to me.  The
source (conveniently called `t`) should be a null-terminated string.
The target (conveniently called `s`) should have sufficient space
allocated to it to hold all of `t`, including the null terminator.
For example, if we are calling `strcpy(u,v)` and `strlen(v)` is 12,
then we should have at least `13*sizeof(char)` free space in the 
memory associated with `u`, starting at `u`.

Of course, this is C, so things are a bit complicated.  We can't really
say that "`u`'s size is at least `13*sizeof(char)`", since `u` may
not have its own size.  Consider, for example, the following code that
allocates some space and has `u` point to the middle of it.

        char *str = malloc(128);
        char *u = str + 64;

We can copy strings of up to length 63 [2] to `u`.

But let's ignore that complication.  Suppose we just have strings
allocated in the "normal" ways, either with `malloc`, as above, or
by declaring them as a fixed length.  Suppose that we only pass
around pointers to the start of allocated space.  Is there a way
to programatically check whether a call to `strcpy(u,v)` will be
safe?

When I ask students that, they usually give one of three answers.
"We can use `sizeof`",  "We can use `strlen`", or  "I'm not sure".
Unfortunately, the last answer is probably the most correct.  `sizeof`
works fine in a few situations.  `strlen` only works well when the
allocated space is terminated with a zero and has no intervening zeros.
Let's see ...

    void
    helper (char *name, char *str)
    {
      printf ("helper: sizeof(%s) = %d\n", name, (int) sizeof (str));
      printf ("helper: strlen(%s) = %d\n", name, (int) strlen (str));
      printf ("\n");
    } // helper (char *, char *)
    
    int
    main (int argc, char *argv[])
    {
      char *s1 = malloc(128);
      char s2[64];
      char *s3 = "this is a string";
    
      printf ("sizeof(s1) = %d\n", (int) sizeof (s1));
      printf ("strlen(s1) = %d\n", (int) strlen (s1));
      helper ("s1", s1);
    
      printf ("sizeof(s2) = %d\n", (int) sizeof (s2));
      printf ("strlen(s2) = %d\n", (int) strlen (s2));
      helper ("s2", s2);
    
      printf ("sizeof(s3) = %d\n", (int) sizeof (s3));
      printf ("strlen(s3) = %d\n", (int) strlen (s3));
      helper ("s3", s3);
    
    
      return 0;
    } // main(int, char*[])

Can you predict the output?  Let's look at the first two lines, at least
on my MacBook.

    sizeof(s1) = 8
    strlen(s1) = 0

Hmmm ... Where does the 8 come from?  It appears we're using eight bytes
per pointer. And the 0?  Well, I guess `malloc` is giving me space
that happens to start with 0.  I don't think it's guaranteed to do
so [3].

Okay, what will the next outputs be?  Those are from the first call
to `helper`.

    helper: sizeof(s1) = 8
    helper: strlen(s1) = 0

That makes sense.  `s1` is still a pointer.  It still points to
a chunk of memory that starts with zero.

How about the next case, `s2`.  Let's check the first two output lines.
8 and 0 again, right?

    sizeof(s2) = 64
    strlen(s2) = 6

Whoops.  I guess not.  Why not?  Let's start with the size.  It
turns out that within the same scope, `sizeof` can usually tell the
size of an array [4].  What about the length?  Where does the `6` come 
from?  I have no idea.  It's remarkably consistent on my Mac, although
if I try to print out `s2`, I get a variety of results.  On one of the
virtual MathLAN Linux workstations, I consistently get a strlen of
1.  In any case, it appears to bear no relation to the 64.

What do you think the output from the helper will be?  Will we see
64 and 6 again (or 64 and 1), or will we see 8 and 0 again, or what?

    helper: sizeof(s2) = 8
    helper: strlen(s2) = 6

I get a strlen of 1 on the Linux workstation.  And if I take a
minute to think about it, the outputs do make sense.  Within `helper`,
all the compiler knows is that `s2` is a character pointer.  Those
require 8 bytes on the machines I use.  And the length of strings
doesn't change.

On to the third case.  Remember that?  It's a constant string.  We
won't be able to copy into `s3`, but it would be nice to know something
about it.  

Have you made your prediction?  I have.  It a character pointer, so
it requires eight bytes.  The string has sixteen characters (if I 
count correctly), so the string length will be sixteen.

    sizeof(s3) = 8
    strlen(s3) = 16

What about the last two lines of output?  I think we have enough data
to use.  The size of any char pointer is 8 bytes, at least on the
architectures and compilers I'm using.  The length of a string
doesn't change.  But let's see.

    helper: sizeof(s3) = 8
    helper: strlen(s3) = 16

So far, so good.  Or perhaps so far, so bad.  We're having trouble
getting any information on the size of a chunk of allocated memory.
Is it still worth checking one more situation?  Why not.  Let me
add one more declaration.

      char *s4 = s2;

What will `sizeof(s4)` report?  Recall that `sizeof(s2)` was 64.

Do you have an answer?

Are you sure?

Well, it turns out that `sizeof(s4)` is 8.  It's a character pointer.
The standard C compiler will not trace assignments in computing sizes.
I'm still not completely sure why it does for array declarations.

---

Where were we?  Oh, that's right.  We were trying to ensure that
we could safely call `strcpy` on two strings and asking whether we
could check that safety programatically.  Guess what?  We can't, at
least not easily.  Why not?  Because C doesn't give you easy access to
the size of the chunk of memory associated with a pointer.  Can it?
Not necessarily.  Not with changing a lot of other assumptions.  In
the end, C expects the programmer to be smart enough to keep track of
how much memory they have available.

Isn't that fun?

So what are your options as a C programmer?  You can be careful about
how you code.  You can carry about sizes along with pointers, either
as separate variables, or in structs.  But you have to accept that
not all the information you'd like is available programatically, and
so you either write code carefully or risk crashes.

---

**_Postscript_**: These days, I assume there are some good static
analyzers that can help answer questions like this.  I should find
time to look into them.  But not today.  And not tomorrow.  And,
after all, this is a course/book/whatever about traditional modes
of thinking in C.

---

[1] Perhaps I should say "Think like a C language designer".
   
[2] I think that appropriately acknowledges the string terminator.

[3] Not at least in my quick tests.  Maybe I'll write about those
separately.

[4] It may always be able to tell the size of an array.  I'm just
hedging my bets.
