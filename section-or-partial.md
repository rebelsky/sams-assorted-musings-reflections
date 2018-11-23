Should I replace `section` with `partial`?
==========================================

*Topics/tags: [CSC 151](index-151), functional programming, Racket, teaching, technical*

As you may recall from [a recent musing](compose-or-pipe), I'd been
working on a reading on higher-order procedures intended for the new
version of CSC 151.  Higher-order procedures are procedures that take
other procedures as input, produce procedures as output, or both.  They
are a core aspect of functional programming and also one of the things
that distinguish Grinnell's CSC 151 from other introductory CS courses [1].
While reflecting on that issue, I'd put the reading aside for a bit
after writing that musing.  I've come back to it recently.

The second major question I had in approaching higher-order procedures
from a new perspective was how to deal with what we call "sectioning".
Sectioning is an approach in which you take an extant procedure and
fill in one or more of its parameters with constants.  For example,
to create a one-parameter procedure that subtracts 2 from its parameter,
you section the two-parameter subtraction operation using the value 2
for the second (or "right") parameter.

In early versions of the course [2,3], we taught students about
`left-section` and `right-section`, which can be defined as follows.

    (define left-section
      (lambda (proc left)
        (lambda (right)
          (proc left right))))
    (define right-section
      (lambda (proc right)
        (lambda (left)
          (proc left right))))

In both cases, we've defined a procedure (`lambda`) of two parameters
(`proc` and either `left` or `right`) that returns another procedure
(the second `lambda`) that takes another parameter and applies `proc`
appropriately.  With those defined, we might define `sub2` as follows.

    (define sub2 (right-section - 2))

Why would we ever teach students to program this way?  In part, because
it's an important way of thinking about programming and about the use of
functions.  In part, because it permits some more concise and efficient
ways of approaching the world.  For example, functional programmers,
when asked to subtract 2 from each element of a list, are likely to
write an expression like the following (using the more concise `r-s`
for `right-section`).

    (map (r-s - 2) lst)

I appreciate higher-order programming enough that, when I worked with a
team to design the new media-computation version of CSC 151, I looked for
ways to move higher-order concepts earlier in the course.  Certainly,
what we called the "functional model of image making" ("an image is
a function from (x,y) position to color") is one example.

At some point, I was inspired to think about more general versions
of these operations, ones that supported procedures of more than two
parameters.  I don't recall all the issues that led me to consider
the issue, but I know that a draft of John Stone's [_Algorithms for
Functional Programming_](https://www.springer.com/us/book/9783662579688)
was one key factor.

And so I sat down to write the general `section` in Racket.  At some
point, I realized that Sebastian Egner had described something similar
in [SRFI 26](https://srfi.schemers.org/srfi-26/srfi-26.html) [4].  Egner
called has procedure `cut`, rather than `section`, but it does more or
less the same thing.  He uses a symbol, `<>`, that he calls "slot"
(and we call "diamond") for missing parameter.  Using our variant of
this notation, one might define `sub2` as follows.

    (define sub2 (section - <> 2))

I think that's the important history: We started with `left-section`
and `right-section` and, at some point, we added the general `section`.
That brings us to these past few weeks, when I was working on the
reading on higher-order procedures for the new course.  I'd generally
introduced sectioning and composition in the context of another higher
order procedure, such as `image-variant` in the media-computation version
and `map` in the data-science version.  This time, I'm trying to 
introduce them as just another basic way to write procedures.

One thing I realized as I was writing new text is that many students
get confused that the procedure in section appears in an odd position.
They're used to the procedure appearing immediately after an open
parenthesis.  So I've been thinking about an alternative, which I call
"partial expressions" and denote `Px`.  Here's how we'd define
`sub2` with that model.

    (define sub2 (Px (- __ 2)))

As you might be able to tell, I've also replaced the diamond with
a different symbol, `__`.  I made that choice after talking with a
colleague; we both agreed it made the "missing piece" seem a bit clearer.
But is this form better than `section`?  I'm not sure.  I'm not thrilled
with the name `Px` as an alternative to `section`.  I tried `partial`,
but I didn't like that much, either.  I couldn't think of a good symbol
like the `o` I use for composition.  I'm also not as happy as I thought
I'd be about the form.  I'm wondering whether students will find
it clearer.  But I still have a few months to think about the issue.

There's another possible advantage of this model; students can put the
parameter" marker within a nested operation, which wasn't as natural
in the cut model.  For example, we can write a procedure that counts
the number of words in a string as follows.

    (define num-words (Px (length (string-split __ " "))))

Is that better than the lambda equivalent?

    (define num-words (lambda (str) (length (string-split str " "))))

The partial version is certainly shorter.  But this example makes me
realize that it's less clear that `Px` is taking a procedure as one
of its parameters.  On the other hand, a colleague has suggested that
students are often confused why the diamonds can only appear at the
top level of a section.  So maybe this is a better approach.

Fortunately, as I said, I have another two months to think about all
of this [6,7].

---

[1] The CS education literature is filled with debates about "objects early"
and "objects late".  I always say that we're a "hop early" curriculum.  Now
I realize that I could add, "which allows our students to get a jump on
important concepts".

[2] I can trace it back to the first time I taught CSC 151, in Fall 2000.
That reading lives on at <http://www.cs.grinnell.edu/~rebelsky/Courses/CS151/2000F/Readings/hop.html>.

[3] We still cover them in current versions, just in a different context.
There are early readings on using higher-order procedures and then a later
reading on writing higher-order procedures.  The details appear there.

[4] SRFI stands for something like "Scheme Request for Implementation".
The SRFIs represent suggested extensions to Scheme.

[5] There's some other history that's less important.  I'll leave that
for another musing.

[6] I also have two months to talk to colleagues and upper-level students
about it.  I wonder what they'll say.

[7] Unfortunately, I have a bunch of other stuff to think about, too.

---

*Version 1.0 of 2018-11-21.*
