---
title: Thinking in C
number: 176
tags: [Don't embarrass me, don't embarrass yourself: Thoughts on thinking in C and Unix](index-cnix)
blurb: 
version: 1.3
released: 2017-01-02
current: 2022-01-23
---
The philosopher Benjamin Whorf suggests that
the language we speak influences how we think.
Even though most linguists and philosophers [dispute the Whorfian
hypothesis](http://www.linguisticsociety.org/content/does-language-i-speak-influence-way-i-think),
there's some pretty clear evidence that the *programming
language* you speak significantly affects how you think about problem
design.  The paradigm of the language clearly has an effect; John Backus'
paper from his Turing Award lecture, "[Can Programming Be Liberated
from the von Neumann Style? A Functional Style and Its Algebra of
Programs](http://www.thocp.net/biographies/papers/backus_turingaward_lecture.pdf)",
provides one elegant example: Imperative and functional programmers
write inner product very differently, and the functional approach is
much more amenable to parallelization.  There's also some evidence
that [object-oriented programmers think very differently about
conditionals](https://sourcemaking.com/refactoring/replace-conditional-with-polymorphism).

Note that these differences are not differences of syntax.  Rather,
different capabilities in different kinds of languages lead people
to develop and express solutions to problems in very different ways.

At Grinnell, we teach three different paradigms and three different
languages in our introductory sequence so that our students can
approach problems from multiple perspectives.  We teach Scheme in the
first course to get students accustomed to higher-order programming,
anonymous procedures, recursion, and the benefits of side-effect-free
approaches.  We teach C in the second course not only to help students
think imperatively but also for the additional ways of thinking that
C encourages [1].  We teach Java [2] or C# [3,4] in the third course to
develop models of object-oriented thinking and to give students the
experience of working with a language that does not trust the programmer
[5].  We've found that not only do these three approaches give students
the background to think about problems in multiple ways, they also
prepare students to master almost any modern programming language [6].

But we're here to consider thinking in C.  So, how do C programmers
think?  From my perspective, there are four key characteristics of a
C programmer.

First, C is an imperative programming language. Hence, C programmers
think imperatively.  How do imperative programmers think?  They design
programs in which they explicitly sequence operations that affect the
state of the system.  That means that *they emphasize sequence
and state when designing programs*.

Now, there are a wide variety of imperative programming languages,
programming languages that support imperative programming [9].  C
differs from most of them in that it gives you more direct access
to the underlying machine.  The second characteristic of C programmers
is that *they pay attention to the underlying machine*.  They think
about the representation of different types and about ways they can
take advantage of the different representations.  They are willing
to work in terms of individual bits.  As an example of this, in the
C implementation of Racket, one bit [11] is used to indicate whether
a value is a comparatively small integer (representable in 31 bits
or less) or a reference to a value structure [12].

One of the key ways in which C programmers think about the underlying
machine is that *they understand pointers and how memory is used*.  They
worry about the stack and the heap, about allocation and deallocation,
about array overflows, and more.

Why would someone work in C rather than some other imperative
language, particularly given the need to handle all of the joys [14] of
memory management in C?  Well, because you have more direct access to the
underlying machine, you can write very efficient code.  And that's another
hallmark of C programmers: *They pay close attention to efficiency*,
and they consider how their code uses resources.  A Python programmer
concatenates two strings and doesn't consider the cost.
A C programmer reflects on the associated costs and then looks for ways
to ameliorate them.

Finally, C programmers are Unix programmers.  *They tend to program
with the associated tools and techniques of the Unix environment.*
We'll consider those tools and techniques soon.

I find that a short comment in Kernighan and Ritchie's _The C Programming
Language_ (p. 106) shows much of what it means to think like a C
programmer.  They note that `strcpy` would most likely be written as

    void strcpy(char *s, char *t)
    {
      while (*s++ = *t++)
        ;
    }

Inexperienced C programmers find this vague.  Experienced C programmers
find it perfectly clear.  Of course, experienced C programmers would
probably write it as follows:

    char *
    strcpy(char *t, char *s)
    {
      while (*t++ = *s++)
        ;
      return t;
    }

Why the extra `return`? It helps avoid the [Shlemiel the painter
problem](https://www.joelonsoftware.com/2001/12/11/back-to-basics/).
Why swap the names of the parameters?  So that we can think
of `t` as "target" and `s` as "source".  Why the different
formatting?  Because real C programmers follow [GNU coding
standards](http://www.gnu.org/prep/standards/html_node/) [15].

In any case, C programmers (a) think about computation in terms of
manipulating state; (b) pay attention to underlying issues, including
representation and memory; (c) understand the costs of their code, and
try to optimize based on those costs; and (d) take advantage of the Unix
programming environment.  There's a bit more associated with all of that,
but those are the key ways one "thinks in C".  We may discover more in
the rest of this work.

---

[1] This essay is on thinking in C.  We'll consider those additional
ways in more detail later in the essay.

[2] Java is not an acronym.  It should not be written in all capital
letters.  People who write Java as "JAVA" should not be trusted.

[3] "C#" is usually pronounced "C sharp".  However, if you prefer, you
can pronounce it "C hashtag" or "C octothorpe" or even "C mesh".

[4] When I first wrote this, in 2017, we were considering switching
our third class to C#.  However, we're still teaching it in Java.  It's
probably worth revisiting that question.

[5] When I teach our third course, I encourage students to remember that
"Java is your nanny".

[6] I originally wrote "Any other modern programming language".  But C
is about forty-five years old, Scheme is about forty years old [7],
and Java is about twenty-five years old.

[7] Scheme's general approach and syntax are close variants of LISP [8],
which is close to sixty years old.

[8] LISP is also written "Lisp".  It is not quite an acronym.  The original
name stood for "LISt Processor".  At some point, some folks started thinking
of it as "LIst and Symbolic Processor".  But now it's just Lisp.

[9] Some people refer to imperative programming as "procedural programming".
I worry that the term has confusing similarity to "functional programming",
particularly since we often treat "procedure" and "function" as the same
term [10].

[10] Some computer scientists suggest that a function's primary purpose is to compute and return a value, while a procedure's purpose is to affect the state of the system.  In that model, procedures don't usually return values.  However, like many close distinctions in computing (e.g., argument vs. parameter), the subtlete differences are lost in common usage.

[11] I think it's the low-order bit, but I'm not sure.  I can't find
the documentation at this moment.

[12] At least that used to be the case.  I don't know if it still holds.
I haven't played with Racket innards for some time.

[14] In case you couldn't tell, "joys" was intended sarcastically.
However, Bill Joy was almost certainly a C programmer.

[15] We will cover coding standards in a future essay.
