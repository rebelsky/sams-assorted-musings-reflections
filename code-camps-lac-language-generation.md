Programs for simple language generation
=======================================

*Topics/tags: [Code camps](index-code-camps), [the joy of code](index-joc), language, technical*

In recent offerings of CSC 151, one of the "fun" activities
we often include when we introduce randomness is a [simple sentence
generator](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/readings/randomness).
Students seem to enjoy it a lot; if you choose good words, randomly
generated simple sentences are fun and funny.

Basic sentence generation (or, more generally, text generation) is also
one of the strategies folks use for writing Twitter 'bots.  In many cases,
people use a language like [Tracery](http://tracery.io/).

Hence, in designing the [Language and Code](code-camp-language-and-code)
camp, one of the topics I wanted to include was text generation.  It
seemed like something the campers might enjoy doing and sharing.  But
I didn't want to have students use Tracery; part of the goal is to have
them do everything in Racket.  So my first step was to identify appropriate
support structures.

As best I can tell, Tracery uses a simple context-free grammar at the
core of its approach.  You specify parts of speech ("nonterminals", in
traditional CS parlance) and how to build them.  For example, I might
say that a simple sentence is a noun, a transitive verb, and another
noun.  A noun, of course, is a person, place or thing.

These kinds of rules require two different operations:

* You need to be able to join things together, as in the simple-sentence
  example.  Fortunately, Racket includes `string-append` as a basic
  operation.
* You need to be able to choose between one or more ways of making something.
  Since rules might be recursive, the choice operation must delay
  evaluation.  I decided to write [a `one-of` macro](joc-one-of-macro)
  for just that purpose.

To build a generator in Racket, you write procedures that correspond
to the different nonterminals.  For example, I might write a procedure
called `(noun)` or one called `(transitive-verb)`.  To handle some
complexities, it's also possible to have these procedures take parameters.
However, at the start, we're just having students write zero-parameter
procedures [1].

Next, we looked for examples.  I wrote some examples for my students.
They, in turn, wrote examples for the code camp students.  I'm going to
focus on my examples.

While sentence generation is my go-to approach, I decided to start
with haiku-like poetry.  I like the structure of haiku.  It's also
easy to model in different forms.  Here's a start.

    (define (haiku)
      (string-append (capitalize (five-syllables)) "\n"
                     (capitalize (seven-syllables)) "\n"
                     (capitalize (five-syllables)) "\n"))

How do we define `five-syllables` and the rest?  There are a variety
of ways to put together something with five syllables.  We'll just
use three of them.

    (define (five-syllables)
      (one-of (string-append (two-syllable-word) " "
                             (one-syllable-word) " "
                             (two-syllable-word))
              (string-append (three-syllable-word) " "
                             (two-syllable-word))
              (string-append (one-syllable-word) " "
                             (three-syllable-word) " "
                             (one-syllable-word))))

Among other things, We could also have added a choice of
`(five-syllable-word)` or a collection of five one-syllable words.
Next, we can provide some options for one-syllable words, two-syllable
words, and three-syllable words.

    (define (one-syllable-word)
      (one-of "sleep"
              "mouse"
              "thrice"
              ...))

    (define (two-syllable-word)
      (one-of "thinking"
              "dreaming"
              "sleeping"
              ...))

    (define (three-syllable-word)
      (one-of "happiness"
              "forgetful"
              "sleepiness"
              ...))

Putting it together, we can now generate mediocre Haiku.

     > (display (haiku))
     Yellow thrice dreaming
     Sleeping expected language
     Scavenger vastness
     > (display (haiku))
     Arrow mouse resides
     Thrice thinking thrice happy mouse
     Resides hot arrow

From my perspective, the really fun part is that we can serve these haiku
on the Web.  Here's the primary code from the followup sample we gave to
the students [3].

    (define (haiku-page request)
      `(html
        (head (title "Your daily haiku"))
        (body
         (h1 "Your daily haiku")
         (p ,(capitalize (five-syllables)))
         (p ,(capitalize (seven-syllables)))
         (p ,(capitalize (five-syllables))))))
    (serve-procedure "" haiku-page)
    (start-server)

And that's all we need for a haiku server.  I think that's cool.  It's not
clear that the code camp kids do, too.  Let's hope that the more they use
it, the more that they'll like it.  I'm also hopeful that it will make a
nice exercise or assignment for the new digital-humanities-oriented CSC 151.

I also put together a more complicated "story writing" example, one in which
we can carry subjects and objects from sentence to sentence.  Let's see ....

    (define (paragraph)
      (one-of (stuff-with-subject (noun))
              (stuff-with-subject-and-object (noun) (noun))))


    (define (stuff-with-subject subject)
      (one-of (string-append (sentence-with-subject subject) 
                             "  "
                             (one-of (stuff-with-subject subject)
                                     (stuff-with-subject subject)
                                     ""))
              (stuff-with-subject-and-object subject (noun))))

    (define (stuff-with-subject-and-object subject object)
      (string-append (sentence-with-subject-and-object subject object) 
                     "  "
                     (one-of (stuff-with-subject subject)
                             (stuff-with-subject subject)
                             (stuff-with-subject object)
                             (stuff-with-subject-and-object subject object)
                             (stuff-with-subject-and-object subject object)
                             (stuff-with-subject-and-object object subject)
                             "")))

    (define (sentence-with-subject subject)
      (string-append (capitalize subject)
                     " "
                     (intransitive-verb)
                     "."))

    (define (sentence-with-subject-and-object subject object)
      (string-append (capitalize subject)
                     " "
                     (transitive-verb)
                     " "
                     object
                     "."))

If you pay close attention to the code, you'll see that I've duplicated
some alternatives.  That's intended to provide greater odds of those
alternatives being selected.  I suppose that I could write a variant
of `one-of` that takes percentages as an extra parameter.  But that's
a task for another day.

I'm not thrilled by the results.  Here's one example.

> The worm ignored Sam. The worm watched Sam. Sam illustrated the worm. Sam napped. Sam saw the hippo.

There are a host of problems.  Repeating the subject again and again with
a limited number of sentence forms is, well, not very interesting.  It
doesn't help that I also have a limited number of words.  And, well, the
code doesn't support adjectives or a host of other things.

But it's a start.  I remain hopeful that I can challenge Grinnell students
to turn it into something a bit more acceptable.  Or perhaps I'll just
send them to the InterWeb to find a better grammar.  We shall see.

---

[1] I don't love having students write procedures with side-effects.
It seems impure to me [2].

[2] Literally.

[3] We did a mashup of page generation and language generation.

---

*Version 1.0 of 2018-07-24.*
