---
title: The joy of code: Cellular language generation
number: 1118
tags: [The joy of code](index-joc), CSC-151, technical
blurb: Maybe I should read the research literature.
version: 0.1
released: 
current: 2021-01-01
---
When I woke up this morning, after I skimmed my email I decided to
read a bit of _The New York Times_ [1].  I found [an article about
Conway's Game of
Life](https://www.nytimes.com/2020/12/28/science/math-conway-game-of-life.html)
[2].  I had not realized that someone had found a way to simulate
the Game of Life at a larger scale in the Game of Life, although
that's not the subject of this musing.

When I finished the musing, I found myself wondering whether the
Game of Life would be an interesting assignment for CSC-151, our
first course in the CS major.  We've been doing some image-making
in Racket.  I've been working on data abstraction as an important
learning outcome for the course.  The ability to represent the Life
"board" in multiple ways (as a hash table, as a vector of vectors,
or as a vector with a more complex indexing scheme) would be an
opportunity to think about abstraction and to explore the costs
(real time, programmer time) of each implementation.  So I opened
my phone and started to take notes about what I might ask and what
initial framework I might supply.

But as I thought about it, I realized that while cellular automata
are fun, they do seem to stray a bit from the topical focus of the
class, which is supposed to be much more about language analysis
and generation [4].  That's not to say that language is the primary
focus of the course; rather, our goal is to introduce students to
aspects of computational thinking, grounding that thinking in
programming.  But we try to draw many of the examples from the world
of language, just as we used to draw many examples from the world
of image making.

So I began to wonder about cellular automata for language generation.
If I was a responsible academic, I'd probably go out and look for
articles on the subject.  But I'll admit that I prefer to approach
most subjects by exploring them independent of the current research
and then go look for research papers.  I like the opportunity to
play freely.  After all, the ability to play in code is one of the
primary reasons I chose CS as a field.

In Conway's Game of Life, the state of a cell in one generation
depends on its state in the previous as well as the state of the
eight neighboring cells in that generation.  A simple set of rules
govern that transition, from live to dead, from dead to alive, or
steady-state.  At first glance, it seems like language generation
likely needs to be more complex, especially if we keep letters as
letters.  But it may also be more simple, since we're down to one
dimension (predecessors and successors) rather than two (horizontal
and vertical neighbors).

The first approach that popped into my head began with the gathering
of statistical information from a text or texts.  I believe most
language generation techniques begin that way.  Given any pair of
predecessor and successor, we could look at the probability of each
letter appearing between the predecessor and successor.  At each
round, each letter is replaced by the next most probable letter to
appear in that position.  Of course, as each is replaced, its neighbors
are also replaced.  The evolution should be predictable, which we
often want in cellular automata.  But will it generate language?

Before I sat down and tried to implement this model using a one-character
predecessor and a one-character successor, I began to think about options.
I suppose if I had come downstairs first, I might have just started
implementing.  But I needed a shower.  So I began to wonder whether a
more extreme version of the policy might work.  That is, in each generation,
the letter at a particular position becomes the most frequent letter
that appeared between the surrounding letters (or surrounding sequences 
of letters, if we're getting fancy).  I worry about going to such extremes
so quickly, but it could be a good starting point for students.

Then I began to think about mutation and probability.  Perhaps instead
of selecting absolutely (most frequent or next most frequent), we could
select statistically.  That is, we look at the distribution of letters
that fall between the predecessor and successor and choose according
to that distribution [5].

And, of course, there's the question of what to do if no letters
ever appear between a particular pair of predecessor and successor,
at least not in the text we've chosen.  One possibility would be to
choose randomly between all letters.  Another would be to use our
single non-letter.

That led to the question of what to do if two letters have equal
probability, a question that strangely holds in the deterministic
model (given the same situation, we make the same change) rather
than in the probabilistic model (we make a probabilistic choice at
each round, which means that we make different changes in the same
situation).

Most of those questions can wait until I have a basic implementation.
So let's move on to that implementation.

*Warning!  Technical material forthcoming.  Feel free to skim or
skip.  I'll try to put something else in italics to mark the end
of each technical section.*

Conceptually, we have a two-dimensional array of information, with
one dimension corresponding to the predecessor and one to the
successor.  In the basic case, that's a 27x27 array, one row for
each letter (plus "everything else") and row column for each letter
(plus "everything else").  

What will we store in that array?  It may vary depending on where in
the process we are.  While we're gathering the statistical data, I'll
want to store a table of letter frequencies.  It's probably most
efficient to represent that table as a vector.  When we're running
the automaton, we may want a table of probabilities (not quite the
same as frequencies), just "the most probable character", or a table
of "next most probable" (for my original plans).

It's time to start coding!  At least in my world it's time to start
coding.  As I said, I program as a way of exploring ideas.  Let's see.
If I'm going to use vectors to store things, I need a way to convert
characters to indices.  We'll use 1 for `#\a` [6], 2 for `#\b` [7],
up through 26 for `#\z`.  We'll use 0 for everything else [8].

```racket
;;; (char->index ch) -> integer?
;;;   ch : char?
;;; Convert a character into an index for use in vectors.
;;; #\a is 1, #\b is 2, ... #\z is 26.  Everything else is 0.
;;; Assumes an English/American alphabet.
(define char->index
  (let ([offset (- (char->integer #\a) 1)])
    (lambda (ch)
      (if (char-alphabetic? ch)
          (- (char->integer (char-downcase ch)) offset)
          0))))
```

Longtime Grinnell CS folk may notice that we are no longer using
the traditional Six-P style documentation.  PM and I had a long conversation
and decided that I was expecting too much mathematical sophistication from
students in asking for semi-formal preconditions and postconditions.  While
I'll miss the Six P's [10], I accepted that he was probably right.

As I tell my students, one should not write code without writing
documentation first (done) and tests first (whoops).  That's okay,
I had the tests in the back of my mind.  Here's what I was thinking
about.

```racket
(check-= (char->index #\a) 1 0 "lowercase a")
(check-= (char->index #\B) 2 0 "uppercase b")
(check-= (char->index #\z) 26 0 "lowercase z")
(check-= (char->index #\space) 0 0 "space")
(check-= (char->index #\.) 0 0 "period")
```

What happens if I choose an alphabetic character that does not traditionally
appear in English?  Let's see.

```racket
> (char->index #\ñ)
145
```

Whoops.  That will crash the program if I use that as a vector index
into a length-27 vector.  At this point, I have a variety of options.
I can accept that it will crash and hope that I never get "invalid
input".  I can try to figure a way to convert accented [12] letters
to their plain (and not quite equivalent) versions.  Of I can check
to ensure that the letter falls within the valid US alphabetic
characters.

The first option does not seem reasonable.  One of the standard texts
I use in the class is _Jane Eyre_.  I don't want the program to crash
on the author's name.  

I'm not sure I've ever looked for a mechanism to "de-accent" letters
in Racket.  Let me check [the documentation]
(https://docs.racket-lang.org/reference/characters.html) and [the
_Guide_](https://docs.racket-lang.org/reference/characters.html).
Nope, not much of help there.  Fortunately, Greg Hendershott, who
is active on the Racket-users list, has posted [an answer to a
similar
question](https://stackoverflow.com/questions/51633087/how-to-remove-accents-from-a-string-in-racket).
I'm going to write my own version, relying primarily on the kinds of
things I ask my students to do.

First the documentation.  What should I call the procedure?  That's
what family are for!  When asked what verb he would use for adding
an accent or tilde to a letter, middle son says "diacriticize, since
they are diacritics".  My procedure will therefore be called
`de-diacriticize` [15].

```racket
;;; (de-diacriticize str) -> str
;;;   str : string
;;; Attempt to remove all diacritics from str.
;;; Procedure name suggested by Middle Son Rebelsky.
```

On to the tests [16].  
---

[1] There I go, violating my [resolutions](new-years-resolutions-2020-12-31)
already, reading _The Times_ rather than a novel or other extended work.

[2] Should it be "Game of Life" or "game of life"?  I've chosen the former
because it's a particular game of life.  I see that The _Times_ also
capitalizes it as a proper noun [3].

[3] I continue to worry why people have given up on capitalizating
Internet.  There's one.  It's not an internet, although such things
also exist.

[4] Unfortunately, a bunch of that focus got cut in the move from
forty-two class periods to thirty-five.

[5] Reminder to self: The lab on randomness should have a "select
probabalistically" exercise.

[6] That's the character "a" (eh) in Scheme/Racket, the language we
use in 151 and one of my favorite languages for exploratory programming.

[7] Yes, that's "b" (bee).

[8] Most computer scientists start their counting at 0.  In Scheme/Racket,
vectors [9], lists, and strings are indexed starting at 0.

[9] Another name for arrays.

[10] There are more than six, so perhaps I should call them the "*N* Ps"
[11]. 

[11] Welcome to Dad Jokes for Computer Scientists..

[12] And umlauted and dieresed [14] and such.

[14] What do you use as the verb for "add dieresis"?

[15] I'm sure the spell checkers are going to have a wonderful time
with this musing.

[16] That's right.  This time I remembered to follow the test-first
methodology I suggest to my students.

