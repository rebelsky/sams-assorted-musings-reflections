---
title: The joy of code: A Racket library for regular expressions
number: 1122
tags: [The joy of code](index-joc), [CSC-151](index-151)
blurb: Why not just use regular regular expressions?
version: 0.1
released: 
current: 2021-01-11
---
One of the many changes I made to CSC-151 when I started designing
a digital humanities version of the course was to add regular
expressions.  The decision was both good and bad.  It was good in
that regular expressions are core to much text-based dighum work.
It was bad in that the traditional regular expression syntax was
not designed for normal human beings. 

When things had to be cut for Fall Term 2, regular expressions were
one of the first things I cut.  But I didn't feel good about it.  I
still don't.

Hence, I decided to write a "more natural" library for regular
expressions during winter break.  I'm a bit torn in writing this
library.  In part, it's that I'm not sure that I'm the right person
to write the library.  In part, it's that the students will still
need to learn the traditional regexp syntax at some point.  With
thirty-five classes, I'm not sure that I can spare two days for
regular expressions.  

But that's a somewhat separate topic.  To start, I'm just going to
think about the design of the library.  From my perspective, we do
a few basic things with regular expressions.

* We check whether a regular expression matches a string (or part of 
  a string).
* We identify all the parts of a string that a regular expression
  matches.  We might also identify the first part of the string that
  matches.
* We replace parts of a string using regular expressions.  We might
  also replace only the first match.

How do we build regular expressions?

* Any string is a regular expression that matches itself.
* Sets
* Anti-sets
* Concatenation
* Any-of
* Named
* Start of string
* End of string
* ...

How should students build regular expressions?

How should we represent regular expressions?  In the past, I would
have used lists, vectors, or functions with local state.  But I've
become enamored of [Racket
structures](https://docs.racket-lang.org/guide/define-struct.html).
I don't know them well enough, but here's a place to start.

Why use structs?

What else do I need?  Perhaps a form of polymorphism.  Some control
over how they display.

Polymorphism with generics (racket/generic).

Problem: Concatenation and any-of should be variable-arity (variadic).
Solution?

On to replacements.

One of the complicating factors of replacements is that they may
need to refer back to the pattern.  For example, if we have names
in the "Surname, Given" form and want to transform those to
"Given Surname" form, we'll need to match a sequence of letters,
a comma, a space, and a sequence of letters.  We then want to replace
that with the second sequence of letters, a space, and then the first
sequence of letters.  In the traditional world of regular expressions,
we use a backslash and a number to indicate which sequence to use.
Here's a lovely Racket example.

```racket
> (regexp-replace #px"([A-Za-z]*), ([A-Za-z]*)" "Rebelsky, Samuel" "\\2 \\1")
"Samuel Rebelsky"
```

Those extra backslashes confuse students.  And keeping track of parens
is a pain.

