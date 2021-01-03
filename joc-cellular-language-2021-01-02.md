---
title: The joy of code: Experiments in cellular language generation
number: 1120
tags: [The joy of code](index-joc), CSC-151, technical, long, end-notable
blurb: Maybe I should read the research literature.
version: 1.0
released: 2021-01-02 
current: 
---
When I woke up yesterday morning, after I skimmed my email I decided
to read a bit of _The New York Times_ [1].  I found [an article
about Conway's Game of
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
letters.  But it may also be more simple---we're down to one
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

Then I began to think about mutation and probability.  Perhaps
instead of selecting absolutely (the most frequent or the next-most
frequent), we could select statistically.  That is, we look at the
distribution of letters that fall between the predecessor and
successor and choose according to that distribution [5].

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
each letter (plus "everything else") and one column for each letter
(plus "everything else").  

What will we store in that array?  It may vary depending on where in
the process we are.  While we're gathering the statistical data, I'll
want to store a table of letter frequencies.  It's probably most
efficient to represent that table as a vector.  When we're running
the automaton, we may want a table of probabilities (not quite the
same as frequencies), just "the most probable character", or a table
of "next most probable" (for my original plans).

It's time to start coding!  At least in my world, it's time to start
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
to their plain (and not quite equivalent) versions.  Or I can check
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
what family members are for!  When asked what verb he would use for adding
an accent or tilde to a letter, middle son says "diacriticize, since
they are diacritics".  My procedure will therefore be called
`dediacriticize` [15].

```racket
;;; (dediacriticize str) -> str
;;;   str : string
;;; Attempt to remove all diacritics from str.
;;; The term "diacriticize" suggested by Middle Son Rebelsky.
;;; Inspired by Greg Hendershott's `ascii-ize`, available at
;;;   https://stackoverflow.com/questions/51633087/how-to-remove-accents-from-a-string-in-racket
```

On to the tests [16].  Here's what seems like a reasonable (and perhaps
even a reasonably comprehensive) set [17,18].

```racket
(check-equal? (dediacriticize "") "" "empty-string")
(check-equal? (dediacriticize "alphabet") "alphabet" "no diacritics")
(check-equal? (dediacriticize "DiAcRiTiCiSe") "DiAcRiTiCiSe"
              "nodiacritics, mixed case, British-esque spelling")
(check-equal? (dediacriticize "åáàãÅÁÀÃ") "aaaaAAAA" "Some a's")
(check-equal? (dediacriticize "éèëêÉÈËÊ") "eeeeEEEE" "Some e's")
(check-equal? (dediacriticize "íìïîÍÌÏÎ") "iiiiIIII" "Some i's")
(check-equal? (dediacriticize "òóöôÓÒÖÔ") "ooooOOOO" "Some o's")
(check-equal? (dediacriticize "úùüûÚÙÜÛ") "uuuuUUUU" "Some u's")
(check-equal? (de-diacriticize "ñÑ") "nN" "N with tilde")
```

Now I can write it.

```racket
(define dediacriticize
  (let ([str->bytelist (o bytes->list string->bytes/utf-8 string-normalize-nfd)])
    (lambda (str)
      (list->string (map integer->char
                         (filter (section < <> 128)
                                 (str->bytelist str)))))))
```

For the Schemer's out there who don't use [the Grinnell `csc151`
library](https://github.com/grinnell-cs/csc151) [19], `o` is
function composition and `section` is much like the `cut` from [SRFI
26: Notation for Specializing Parameters without
Currying](https://srfi.schemers.org/srfi-26/srfi-26.html).  

In any case, it passes the tests, so I can move on.

Now, `dediacriticize` [20] is supposed to deal with strings.  I was 
hoping for a procedure to deal with characters.  Do I want to
stringify a character and then extract the potentially modified 
character from the string each time I call `char->index`?  Probably
not.  But we can still use `dediacriticize` on a string before we
send its individual characters to `char->index`, whether explicitly
or implicitly.

I suppose that means we should move on to the third approach.
Instead of checking whether a character is alphabetic in the Unicode
sense [21,22], we should check if it's alphabetic in the ASCII [23]
sense.  Conveniently, ASCII has the alphabet in direct sequence.
Did [EBCDIC](https://en.wikipedia.org/wiki/EBCDIC) [24]?  I don't
tend to look much at EBCDIC, but [the _Wikipedia_
page](https://en.wikipedia.org/wiki/EBCDIC) suggests that it did
not.  What about [SHSEAE](https://en.wikipedia.org/wiki/Huffman_coding)
[26]?  Huffman-encoded letters are not supposed to correspond to
integers, only bit strings.  Plus, I just invented it as part of
this musing [27].

In any case, computing has mostly moved on from the days of multiple
encodings to just a few, and the two primary ones in use follow the
"letters fall in sequence" policy, so we can use that.

```racket
(define char->index
  (let ([offset (- (char->integer #\a) 1)])
    (lambda (ch)
      (if (or (char<=? #\a ch #\z)
              (char<=? #\A ch #\Z))
          (- (char->integer (char-downcase ch)) offset)
          0))))
```

The tests still pass, so I'm happy [29].

Wow, that was a long detour.  Where were we?  Ah, that's right, we
were looking at how to store values in a table indexed by a pair
of letters, or a pair of single-letter strings, or something like
that.  How should we implement that table?  There seem to be three
basic options: We can implement it with a hash table (`hash`, in
Scheme), a two-dimensional array (vector of vectors in Scheme, at
least the last time I checked), or a one-dimensional array with a
slightly more complicated indexing scheme [30].

If I was a better Racket programmer, or if we still had the part of
CSC 151 in which we teach Racket structs, I'd use structs.  But we
don't currently have time to teach structs [31].  So I'll do without
them.

Okay, what should I call this strange structure?  I know, an
AlphabeTable, which I'll probably write as `alphabetable` [32].
What are the operations?  Before I decide that, I should probably
decide whether alphabetables are mutable or immutable [33].  It's
Scheme/Racket.  Let's make them immutable.  So the essential operations are
just "create" and "lookup".  I suppose I also need a 
predicate.

```racket
;;; (alphabetable init) -> alphabetable?
;;;   init : function? [of the form (lambda (ch1 ch2) ...)]
;;; Create a new AlphabeTable, filling each cell with the result
;;; of (init row col).  For the "non-letter", we use a space.

;;; (at table pred succ) -> any?
;;;   table : alphabetable?
;;;   pred : char?
;;;   succ : char?
;;; Look up the value with given predecessor and successor.

;;; (alphabetable? val) -> boolean?
;;;   val : any?
;;; Determine if a structure appears to be an AlphabeTable.
```

Ah, I love data-structure design.  And I love that the somewhat
funny name of `at` naturally emerged from the naming scheme and my
preference to write shorter names for frequently-used procedures [34].

What next?  Tests.  I don't love writing tests nearly as much.
After all, I have thirty-five years of experience writing in Lisp
variants.  I get things right, right [35]?  In this case, it's
hard to test procedures in isolation, so I will be testing them
in combination.

```racket
(check-true (alphabetable? (alphabetable (lambda (row col) 0)))
            "AlphabeTable with only 0's")
(check-true (alphabetable? (alphabetable string))
            "AlphabeTable with simple strings")

(let ([sample (alphabetable (lambda (row col) "sample"))])
  (check-equal? (at sample #\a #\a) "sample" "eh eh")
  (check-equal? (at sample #\a #\z) "sample" "eh zed")
  (check-equal? (at sample #\z #\a) "sample" "zed eh")
  (check-equal? (at sample #\Z #\z) "sample" "Zed zed")
  (check-equal? (at sample #\i #\q) "sample" "eye queue")
  (check-equal? (at sample #\Q #\I) "sample" "queue eye")
  (check-equal? (at sample #\. #\.) "sample" "dot dot")
  (check-equal? (at sample #\. #\-) "sample" "dot dash")
  (check-equal? (at sample #\m #\-) "sample" "em dash")
  (check-equal? (at sample #\space #\Y) "sample" "spacey"))

(let ([sample (alphabetable string)])
  (check-equal? (at sample #\a #\a) "aa" "eh eh")
  (check-equal? (at sample #\a #\z) "az" "eh zed")
  (check-equal? (at sample #\z #\a) "za" "zed eh")
  (check-equal? (at sample #\Z #\z) "zz" "Zed zed")
  (check-equal? (at sample #\i #\q) "iq" "eye queue")
  (check-equal? (at sample #\Q #\I) "qi" "queue eye")
  (check-equal? (at sample #\. #\.) "  " "dot dot, non-letters -> space")
  (check-equal? (at sample #\. #\-) "  " "dot dash, non-letters -> space")
  (check-equal? (at sample #\m #\-) "sample" "em dash")
  (check-equal? (at sample #\space #\Y) "sample" "spacey"))
```

Perhaps I shouldn't make stupid jokes in my tests.  Oh well, it keeps
me interested.

On to the implementation.  I think I'll use a one-dimensional vector,
storing the table in [row-major
order](https://en.wikipedia.org/wiki/Row-_and_column-major_order).  If
you don't know what row-major order is, check [the _Wikipedia_ page](https://en.wikipedia.org/wiki/Row-_and_column-major_order) [36].

Let's see: To index into that structure, I need row number times 27 plus 
column number.

```racket
(define at
  (lambda (table pred succ)
    (vector-ref table (+ (char->index succ)
                         (* 27 (char->index pred))))))
```

And for the type predicate, we only need to see if it's a vector of
the right size [39].

```racket
(define alphabetable?
  (lambda (val)
    (and (vector? val)
         (= (vector-length val) (* 27 27)))))
```

Creating the table is going to be a bit harder.  I'm going to need
to iterate the locations in the table, calling the initializer at
each point.

At this point, some readers may be asking themselves something like
the following.

> Why not just represent your table as the `init` function and use
  that for `at`?

That is, they may be suggesting something like the following.

```racket
(define alphabetable-w/hack
  (lambda (init)
    init))

(define at
  (lambda (table pred succ)
    (table pred succ)))

(define alphabetable
  procedure?)
```

Fortunately, that does not pass the tests.  Here are some examples of failure.

```racket
. FAILURE
name:       check-equal?
location:   cellular-language.rkt:124:2
message:    "queue eye"
actual:     "QI"
expected:   "qi"

. FAILURE
name:       check-equal?
location:   cellular-language.rkt:113:2
message:    "dot dash, non-letters -> space"
actual:     ".-"
expected:   "  "
```

As is often the case in test-driven design, the tests have specified
(or implied) certain characteristics of the procedures' behavior.  In
particular, all letters are treated as the lowercase version of the 
letters and all non-letters are treated as space.

But we can fix that, right?  We just convert all non-letters to space and
all letters to lowercase.

```racket
(define alphabetable-w/new-hack
  (lambda (init)
    (let* ([offset (- (char->integer #\a) 1)]
           [convert
            (lambda (ch)
              (let ([num (char->index ch)])
                (if (zero? num)
                    #\space
                    (integer->char (+ num offset)))))])
      (lambda (pred succ) (init (convert pred) (convert succ))))))
```

That passes all of the tests.

So why not just use that implementation?  Because although our
AlphabeTable may be immutable, it may contain mutable structures.
Remember: Our original goal was a table of tallies, tallies
that we planned to update.  I suppose we need another test.

```racket
(let ([sample (alphabetable vector)])
  (let ([ab (at sample #\a #\b)])
    (vector-set! ab 0 "eh")
    (vector-set! ab 1 "bee")
    (check-equal? (at sample #\A #\B) '#("eh" "bee") "mutated/1")))
```

Now the hacky implementation fails.

```racket
. FAILURE
name:       check-equal?
location:   cellular-language.rkt:133:4
message:    "mutated/1"
actual:     '#(#\a #\b)
expected:   '#("eh" "bee")
```

I suppose I could write tests more relevant to that particular use case,
but that test is enough for now.

Okay, back to the primary, vector-based, implementation.  As I think
I wrote, the challenge is making sure that I get the initialization
right.  Here goes.

```racket
(define alphabetable
  (lambda (init)
    (let* ([vec (make-vector (* 27 27) (void))]
           [offset (- (char->integer #\a) 1)]
           [convert
            (lambda (num)
              (if (zero? num)
                  #\space
                  (integer->char (+ num offset))))])
      (letrec ([kernel
                (lambda (row col)
                  (when (< row 27)
                    (cond
                      ; If we finished one row, move on to the next
                      [(>= col 27)
                       (kernel (+ row 1) 0)]
                      ; Otherwise, fill in the table and move on
                      [else
                       (vector-set! vec 
                                    (+ col (* 27 row)) 
                                    (init (convert row) (convert col)))
                       (kernel row (+ col 1))])))])
        (kernel 0 0)
        (vector->immutable-vector vec)))))
```

It appears that the stupid detour was a bit helpful, at least in writing a
`convert` procedure.

Here's a quick experiment.

```racket
'#("  " " a" " b" " c" " d" " e" " f" " g" " h" " i" " j" " k" " l" " m"
   " n" " o" " p" " q" " r" " s" " t" " u" " v" " w" " x" " y" " z"
   "a " "aa" "ab" "ac" "ad" "ae" "af" "ag" "ah" "ai" "aj" "ak" "al" "am" 
   "an" "ao" "ap" "aq" "ar" "as" "at" "au" "av" "aw" "ax" "ay" "az"
   "b " "ba" "bb" "bc" "bd" "be" "bf" "bg" "bh" "bi" "bj" "bk" "bl" "bm"
   "bn" "bo" "bp" "bq" "br" "bs" "bt" "bu" "bv" "bw" "bx" "by" "bz" 
   "c " "ca" "cb" "cc" "cd" "ce" "cf" "cg" "ch" "ci" "cj" "ck" "cl" "cm"
   "cn" "co" "cp" "cq" "cr" "cs" "ct" "cu" "cv" "cw" "cx" "cy" "cz"
   "d " "da" "db" "dc" "dd" "de" "df" "dg" "dh" "di" "dj" "dk" "dl" "dm"
   "dn" "do" "dp" "dq" "dr" "ds" "dt" "du" "dv" "dw" "dx" "dy" "dz"
   "e " "ea" "eb" "ec" "ed" "ee" "ef" "eg" "eh" "ei" "ej" "ek" "el" "em"
   "en" "eo" "ep" "eq" "er" "es" "et" "eu" "ev" "ew" "ex" "ey" "ez"
   "f " "fa" "fb" "fc" "fd" "fe" "ff" "fg" "fh" "fi" "fj" "fk" "fl" "fm"
   "fn" "fo" "fp" "fq" "fr" "fs" "ft" "fu" "fv" "fw" "fx" "fy" "fz"
   "g " "ga" "gb" "gc" "gd" "ge" "gf" "gg" "gh" "gi" "gj" "gk" "gl" "gm"
   "gn" "go" "gp" "gq" "gr" "gs" "gt" "gu" "gv" "gw" "gx" "gy" "gz"
   "h " "ha" "hb" "hc" "hd" "he" "hf" "hg" "hh" "hi" "hj" "hk" "hl" "hm"
   "hn" "ho" "hp" "hq" "hr" "hs" "ht" "hu" "hv" "hw" "hx" "hy" "hz"
   "i " "ia" "ib" "ic" "id" "ie" "if" "ig" "ih" "ii" "ij" "ik" "il" "im"
   "in" "io" "ip" "iq" "ir" "is" "it" "iu" "iv" "iw" "ix" "iy" "iz"
   "j " "ja" "jb" "jc" "jd" "je" "jf" "jg" "jh" "ji" "jj" "jk" "jl" "jm"
   "jn" "jo" "jp" "jq" "jr" "js" "jt" "ju" "jv" "jw" "jx" "jy" "jz"
   "k " "ka" "kb" "kc" "kd" "ke" "kf" "kg" "kh" "ki" "kj" "kk" "kl" "km"
   "kn" "ko" "kp" "kq" "kr" "ks" "kt" "ku" "kv" "kw" "kx" "ky" "kz" 
   "l " "la" "lb" "lc" "ld" "le" "lf" "lg" "lh" "li" "lj" "lk" "ll" "lm"
   "ln" "lo" "lp" "lq" "lr" "ls" "lt" "lu" "lv" "lw" "lx" "ly" "lz"
   "m " "ma" "mb" "mc" "md" "me" "mf" "mg" "mh" "mi" "mj" "mk" "ml" "mm"
   "mn" "mo" "mp" "mq" "mr" "ms" "mt" "mu" "mv" "mw" "mx" "my" "mz"
   "n " "na" "nb" "nc" "nd" "ne" "nf" "ng" "nh" "ni" "nj" "nk" "nl" "nm"
   "nn" "no" "np" "nq" "nr" "ns" "nt" "nu" "nv" "nw" "nx" "ny" "nz"
   "o " "oa" "ob" "oc" "od" "oe" "of" "og" "oh" "oi" "oj" "ok" "ol" "om"
   "on" "oo" "op" "oq" "or" "os" "ot" "ou" "ov" "ow" "ox" "oy" "oz"
   "p " "pa" "pb" "pc" "pd" "pe" "pf" "pg" "ph" "pi" "pj" "pk" "pl" "pm"
   "pn" "po" "pp" "pq" "pr" "ps" "pt" "pu" "pv" "pw" "px" "py" "pz"
   "q " "qa" "qb" "qc" "qd" "qe" "qf" "qg" "qh" "qi" "qj" "qk" "ql" "qm"
   "qn" "qo" "qp" "qq" "qr" "qs" "qt" "qu" "qv" "qw" "qx" "qy" "qz"
   "r " "ra" "rb" "rc" "rd" "re" "rf" "rg" "rh" "ri" "rj" "rk" "rl" "rm"
   "rn" "ro" "rp" "rq" "rr" "rs" "rt" "ru" "rv" "rw" "rx" "ry" "rz"
   "s " "sa" "sb" "sc" "sd" "se" "sf" "sg" "sh" "si" "sj" "sk" "sl" "sm"
   "sn" "so" "sp" "sq" "sr" "ss" "st" "su" "sv" "sw" "sx" "sy" "sz"
   "t " "ta" "tb" "tc" "td" "te" "tf" "tg" "th" "ti" "tj" "tk" "tl" "tm"
   "tn" "to" "tp" "tq" "tr" "ts" "tt" "tu" "tv" "tw" "tx" "ty" "tz"
   "u " "ua" "ub" "uc" "ud" "ue" "uf" "ug" "uh" "ui" "uj" "uk" "ul" "um"
   "un" "uo" "up" "uq" "ur" "us" "ut" "uu" "uv" "uw" "ux" "uy" "uz"
   "v " "va" "vb" "vc" "vd" "ve" "vf" "vg" "vh" "vi" "vj" "vk" "vl" "vm"
   "vn" "vo" "vp" "vq" "vr" "vs" "vt" "vu" "vv" "vw" "vx" "vy" "vz"
   "w " "wa" "wb" "wc" "wd" "we" "wf" "wg" "wh" "wi" "wj" "wk" "wl" "wm"
   "wn" "wo" "wp" "wq" "wr" "ws" "wt" "wu" "wv" "ww" "wx" "wy" "wz"
   "x " "xa" "xb" "xc" "xd" "xe" "xf" "xg" "xh" "xi" "xj" "xk" "xl" "xm"
   "xn" "xo" "xp" "xq" "xr" "xs" "xt" "xu" "xv" "xw" "xx" "xy" "xz" 
   "y " "ya" "yb" "yc" "yd" "ye" "yf" "yg" "yh" "yi" "yj" "yk" "yl" "ym"
   "yn" "yo" "yp" "yq" "yr" "ys" "yt" "yu" "yv" "yw" "yx" "yy" "yz"
   "z " "za" "zb" "zc" "zd" "ze" "zf" "zg" "zh" "zi" "zj" "zk" "zl" "zm"
   "zn" "zo" "zp" "zq" "zr" "zs" "zt" "zu" "zv" "zw" "zx" "zy" "zz")
```

Maybe I didn't need that quick experiment.  Maybe I should have trusted
my tests.  Oh well.  I like checking visually once in a while.

Okay, now on to the core part.  We'll build a table of tallies.

```racket
;;; (gather-info str) -> alphabetable-of vector?
;;;   str : string?
;;; Gather neighbor info from a string.  Return a table of
;;; how often each character appears surrounded by the others.
;;; In particular, if `info` is the result of `(gather-info str)`,
;;; then `(vector-ref (at info l r) ch)` should ell you how many 
;;; times `ch` is surrounded by `l` and `r` in `str`.  The start
;;; of string and the end of string are treated as the non-letter
;;; character (space).
```

I'm getting lazy, so I'm going to try a very simple test.

```racket
(let ([info (gather-info "cat")])
  (check-equal? (at info #\c #\t)
                '#(0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)
                "the 'a' in 'cat'")
  (check-equal? (at info #\space #\a)
                '#(0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)
                "the 'c' in 'cat'")
  (check-equal? (at info #\a #\space)
                '#(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0)
                "the 't' in 'cat'")
  (check-equal? (at info #\q #\q)
                '#(0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0)
                "something that does not appear"))
```

Now on to the implementation [41].

```racket
(define gather-info
  (let ([vector-increment-at!
          (lambda (vec pos)
            (vector-set! vec 
                         pos
                         (+ 1 (vector-ref vec pos))))])
    (lambda (str)
      (let ([info (alphabetable (lambda (row col) (make-vector 27 0)))]
            [len (string-length str)])
        (letrec ([kernel
                   (lambda (i prev current)
                     (let ([next (if (>= i len)
                                     #\space
                                     (string-ref str i))])
                       (vector-increment-at! (at info prev next)
                                             (char->index current))
                       (when (< i len)
                         (kernel (+ i 1) current next))))])
          (kernel 1 #\space (string-ref str 0))
          info)))))
```
                                  
In procedures like this, I miss named let.  But I agree with my colleagues
that it's just one more thing that adds a bit of cognitive load to students
who are already cognitively loaded.

In any case, *Whoo!  Passed the test on the first try!*  I wonder if that
means I need to write better tests.  Remarkably, we're getting close.

Next up, let's write a procedure to find the letter that occurs most
frequently between two letters.  Basically, we want something that takes
the vector as a parameter and then returns the most-frequently occurring
value in the vector.

```racket
;;; (index-of-max vec) -> integer?
;;;   vec : vector-of real?, nonempty-vector?
;;; Find the index of the largest value in the vec
(define index-of-max
  (lambda (vec)
    (letrec ([kernel
              (lambda (i hypothesis)
                (cond
                  [(< i 0)
                   hypothesis]
                  [(> (vector-ref vec i)
                      (vector-ref vec hypothesis))
                   (kernel (- i 1) i)]
                  [else
                   (kernel (- i 1) hypothesis)]))])
      (let ([last (- (vector-length vec) 1)])
        (kernel (- last 1) last)))))
```

Whoops!  I wrote the initial code before the tests.  But I'll write some tests
before I try to run it.

```racket
(check-equal? (index-of-max '#(1)) 0 "edge case: one element")
(check-equal? (index-of-max '#(0 1 2 3 4 5)) 5 "edge case: last element")
(check-equal? (index-of-max '#(9 1 2 3 4 5 6 7)) 0 "edge case: first element")
(check-equal? (index-of-max '#(1 0 0 0 0)) 0 "systematic/0")
(check-equal? (index-of-max '#(0 1 0 0 0)) 1 "systematic/1")
(check-equal? (index-of-max '#(0 0 1 0 0)) 2 "systematic/2")
(check-equal? (index-of-max '#(0 0 0 1 0)) 3 "systematic/3")
(check-equal? (index-of-max '#(0 0 0 0 1)) 4 "systematic/4")
```
            
I had to fix a few syntax errors, but otherwise it's correct.  Or at least
it passes the tests.

We're getting closer all the time [43].  

Next up, writing a procedure I should have written a long time ago.
If I have `char->index`, I should have `index->char`.  

```racket
;;; (index->char index) -> char?
;;;   index : integer?
;;; Convert an index (created by char->index) back to a character.
;;; Pre: 0 <= index < 27
(define index->char
  (let ([offset (- (char->integer #\a) 1)])
    (lambda (index)
      (if (zero? index) 
          #\space
          (integer->char (+ offset index))))))
```

Damn!  Forgot those tests.

```racket
(check-equal? (index->char 0) #\space)
(check-equal? (index->char 1) #\a)
(check-equal? (index->char 26) #\z)
```

That's the same as the stupid `convert` procedure in `alphabetable`.
It's also similar to the `convert` procedure in the hacking approach
to `alphabetable`, but I suppose that doesn't matter.

Let's build a table from that.

```racket
;;; (info->most-freq info) -> alphabetable of char?
;;;   info -> alphabetable of vector?
;;; Given the table produced by `gather-info`, returns a table that
;;; gives the letter that appears most frequently between any two
;;; letters.  If no letter has appeared between those letters,
;;; returns space.
```

Amazingly, our tests are going to look much like the tests for
`gather-info`.

```racket
(let* ([most-frequent (info->most-freq (gather-info "cat"))])
  (check-equal? (at most-frequent #\c #\t) 
                #\a
                "the 'a' in 'cat'")
  (check-equal? (at most-frequent #\space #\a)
                #\c
                "the 'c' in 'cat'")
  (check-equal? (at most-frequent #\a #\space)
                #\t
                "the 't' in 'cat'")
  (check-equal? (at most-frequent #\q #\q)
                #\space
                "something that does not appear"))
```

Do I need something more sophisticated?  Probably not, at least if the
implementation is as straightforward as I expected.  Here's my first
version.

```racket
(define info->most-freq
  (lambda (info)
    (alphabetable (lambda (pred succ)
                    (let ([frequencies (at info pred succ)])
                      (index->char (index-of-max frequencies)))))))
```

Unfortunately, that failed one of my tests.

```racket
. FAILURE
name:       check-equal?
location:   cellular-language.rkt:260:2
message:    "something that does not appear"
actual:     #\z
expected:   #\space
```

I suppose I could change `index-of-max` to give back 0 if all of the
indices have equal probability.  It wouldn't take much of a change.
But we might later change where the space appears.  So let's write
something a bit more explicit.

```racket
(define info->most-freq
  (lambda (info)
    (alphabetable (lambda (pred succ)
                    (let* ([frequencies (at info pred succ)]
                           [index (index-of-max frequencies)])
                      (if (zero? (vector-ref frequencies index))
                          #\space
                          (index->char index)))))))
```

That gets me thinking.  What happens if there are multiple "most-frequent"
letters?  Currently, my `index-of-max` procedure is biased toward the
ones that come later.  Should it perhaps return a list of indices, rather
than a single index?  Then we could choose randomly among those.  You
know what?  That's a task for another day [44].

When I write procedures like `info->most-freq`, I'm tempted to look at
the output.  Then I realize that it's a *lot* of output.  And I remember,
"That's why I write tests."

On to the automaton.  We'll start with a string to update and a frequency
table built from some source.  We'll then compute the next generation of
the string based on the frequency table.

```racket
;;; (next-gen-by-freq most-freq str) -> string?
;;;   most-freq : alphabetical-of char?
;;;   str : string?
;;; Computes the "next generation" of a string by replacing each
;;; character in the string by the letter that most frequently appears
;;; between the surrounding characters.
```

Our world is now complicated enough that unit tests no longer make
much sense.  I suppose I could try building the frequency table from 
`"cat"` and think carefully about what happens.  `"cat"` should stay as
`"cat"`.  What about `"cut"`?  The "u" should become "a", which gets us
closer to "cat".  But the "c" and the "t" should each become a space, 
since nothing has ever appeared between space and "u" or between "u"
and space.  Strangely enough, I'm pretty sure that " a " switches
to "c t" and then we'll cycle.

```racket
(let* ([cat-table (info->most-freq (gather-info "cat"))])
  (check-equal? (next-gen-by-freq cat-table "cat")
                "cat"
                "cat")
  (check-equal? (next-gen-by-freq cat-table "cut")
                " a "
                "cut")
  (check-equal? (next-gen-by-freq cat-table " a ")
                "c t"
                "cycle/1")
  (check-equal? (next-gen-by-freq cat-table "c t")
                " a "
                "cycle/2"))
```

The morals of this set of tests?  One should start with a larger
language corpus.  Also, one can write tests for procedures expected
to have complicated output.  And writing those tests help you think
through the algorithm.

How will I implement this procedure?  I expect that the pattern will
look much like my procedure for gathering information from a string.
That is, I'll iterate through the string, doing something at each
position.  In this case, we'll gather the next letter for that position.

```racket
(define next-gen-by-freq
  (lambda (most-freq str)
    (let ([len (string-length str)])
      (letrec
          ([kernel
            (lambda (i prev current so-far)
              (if (>= i len)
                  (list->string (reverse (cons (at most-freq prev #\space)
                                               so-far)))
                  (let ([next (string-ref str i)])
                    (kernel (+ i 1)
                            current
                            next
                            (cons (at most-freq prev next)
                                  so-far)))))])
        (kernel 1 #\space (string-ref str 0) null)))))
```

Okay, now it's time to build a table from something more significant,
such as [the text version of Gutenberg edition of the text of Jane Eyre](https://www.gutenberg.org/files/1260/1260-0.txt).

```racket
(define jane-eyre-info
  (gather-info (dediacriticize (file->string "1260.txt"))))
(define jane-eyre-most-freq
  (info->most-freq jane-eyre-info))
```

So, what appears between "c" and "t" in Jane Eyre?

```racket
> (at jane-eyre-info #\c #\t)
'#(6 215 0 0 0 17 0 0 3 124 0 0 0 0 0 46 0 0 0 3 1 54 0 0 0 0 0)
```

"a" appears most frequently.  But also spaces "e", "h", "i", "o",
and some other letters.  There's a reason I want the generations
to change a bit more slowly.  But that's the next step.

On to the experiments that were my initial goal.  Should I start
with random text and then see whether it moves toward real text, or
should I start with real text and see how it changes?  Perhaps both.
Let's write or copy some utilities.  (Some of these are procedures
I've written before.)

```racket
;;; (generations-by-freq most-freq str n) -> string?
;;;   most-freq : alphabetable-of char?
;;;   str : string?
;;;   n : non-negative-integer?
;;; Display a sequence of n generations for a particular string.
;;; Returns the last generation
(define generations-by-freq
  (lambda (most-freq str n)
    (display str) (newline)
    (if (zero? n)
        str
        (generations-by-freq most-freq
                             (next-gen-by-freq most-freq str)
                             (- n 1)))))
```

Let's try one example.

```racket
> (generations-by-freq jane-eyre-most-freq 
                       "once upon a time there was a sam" 
                       10)
once upon a time there was a sam
a ce  pef  s  ve there  as    os
 nhed h d    ehe thered  s   t f
atcad  a    htre thered
 nhes   s  t ehe thered
atcid       htre thered
 n en      t ehe thered
a cadd      htre thered
 n en      t ehe thered
a cadd      htre thered
 n en      t ehe thered
" n en      t ehe thered         "
```

Wow!  That reached a cycle pretty quickly.  And I don't like those
sequences of spaces.  So, what should I do?  I think it makes sense to
clean up the input text a bit more, changing sequences of spaces to
single spaces.  I'm not going to worry too much about efficiency.

```racket
;;; (cleanup str) -> string
;;;   str : string
;;; Convert str to something a bit simpler for use in building tables
;;; of neighboring info.
(define cleanup
  (lambda (str)
    (letrec 
      ([kernel 
        (lambda (ch chars so-far)
          (if (null? chars)
              (if (equal? ch #\space)
                  (list->string (reverse so-far))
                  (list->string (reverse (cons ch so-far))))
              (let ([next (index->char (char->index (car chars)))])
                (kernel next
                        (cdr chars)
                        (if (and (equal? ch #\space) (equal? next #\space))
                            so-far
                            (cons ch so-far))))))])
     (let ([tmp (string->list (dediacriticize str))])
       (kernel (car tmp) (cdr tmp) null)))))
```

Tests?  What tests.  Let's try experiments.

```racket
> (cleanup "a  Beta zea üéa   ...  ")
"a beta zea uea"
```

Yeah, that's good enough.  What's the effect on redefining `jane-eyre-info`?

```racket
> (define jane-eyre-info2 (time (gather-info (cleanup (file->string "1260.txt")))))
cpu time: 1415 real time: 1451 gc time: 802
```

About half a second of extra work.  Not too bad.  How about my language
automaton?

```racket
> (generations-by-freq jane-eyre-most-freq "once upon a time there was a sam" 10)
once upon a time there was a sam
a ce s ef isw ve there has i h s
inhe ihod a tehe there his itiii
atce t af ish re there win it tn
inhe i os attehe there win in ao
atce i af ish re there win an ts
inhe i os attehe there win as ao
atce i af ish re there win as ts
inhe i os attehe there win as ao
atce i af ish re there win as ts
inhe i os attehe there win as ao
```

Yeah, that reaches a fixed cycle much too quickly.  At least there
aren't so many sequences of spaces.  So let's try the "next most
frequent" approach.  I was going to write, "I'm giving up on tests
during my broader experiments", but quickly realized that I was
writing strange enough code that I wanted tests [46].

Lets start by finding the "successors" of a letter, the letters
that appear slightly more frequently between the neighbors.

```racket
;;; (indices-of-successor vec index) -> list-of integer?
;;;   vec : vector-of integer?
;;;   index : integer?
;;; Given an index, determine the indices of the next larger value.
(define indices-of-successors
  (lambda (vec index)
    (let* ([base (vector-ref vec index)]
           [iom (index-of-max vec)]
           [max-val (vector-ref vec iom)])
      (if (= base max-val)
          (list index)
          (letrec
              ([kernel
                (lambda (i estimate indices)
                  (if (< i 0)
                      indices
                      (let ([current (vector-ref vec i)])
                        (cond
                          ; Another equivalent index
                          [(= current estimate)
                           (kernel (- i 1) estimate (cons i indices))]
                          ; A better index
                          [(< base current estimate)
                           (kernel (- i 1) current (list i))]
                          ; Anything else
                          [else
                           (kernel (- i 1) estimate indices)]))))])
            (kernel (- (vector-length vec) 1)
                    max-val
                    null))))))

(let ([sample (vector 10 20 10 30 40 0 10 40)])
  (check-equal? (sort (indices-of-successors sample 5) <=)
                '(0 2 6))
  (check-equal? (indices-of-successors sample 0)
                '(1))
  (check-equal? (indices-of-successors sample 2)
                '(1))
  (check-equal? (indices-of-successors sample 6)
                '(1))
  (check-equal? (indices-of-successors sample 1)
                '(3))
  (check-equal? (sort (indices-of-successors sample 3) <=)
                '(4 7))
  (check-equal? (indices-of-successors sample 4)
                '(4))
  (check-equal? (indices-of-successors sample 7)
                '(7)))
```

For a reasonably long text, it's unlikely that any letter will
have multiple successors.  But I'd rather be safe than sorry, even
though it may introduce some unpredictability.

Should I build a table next?  If I'm going to process a lot of letters,
it's worth it.  But if I'm only going to process a few (e.g., during
development), it's not worth my time or the computer's time.  So let's
move on to a simple "successor" procedure.

```racket
;;; (successor info pred char succ) -> char?
;;;    info : alphabetable of vector?
;;;    pred : char?
;;;    char : char?
;;;    succ : char?
;;; Given the table produced by `gather-info`, finds a letter that appears
;;; slightly more frequently than `char` between `pred` and `succ`.
(define successor
  (lambda (info pred char succ)
    (let ([data (at info pred succ)])
      (index->char (random-elt (indices-of-successors data (char->index char)))))))
```

Here's a bit of experimentation.

```racket
> (at jane-eyre-info #\space #\space)
'#(0 4461 4 29 4 33 13 1 1 7059 6 0 1 7 0 16 3 0 0 21 7 7 3 1 1 5 0)
> (successor jane-eyre-info #\space #\y #\space)
#\j
> (successor jane-eyre-info #\space #\j #\space)
#\m
> (successor jane-eyre-info #\space #\j #\space)
#\u
> (successor jane-eyre-info #\space #\j #\space)
#\u
> (successor jane-eyre-info #\space #\j #\space)
#\m
> (successor jane-eyre-info #\space #\j #\space)
#\t
> (successor jane-eyre-info #\space #\t #\space)
#\f
> (successor jane-eyre-info #\space #\f #\space)
#\o
> (successor jane-eyre-info #\space #\o #\space)
#\s
> (successor jane-eyre-info #\space #\s #\space)
#\c
> (successor jane-eyre-info #\space #\c #\space)
#\e
> (successor jane-eyre-info #\space #\e #\space)
#\a
> (successor jane-eyre-info #\space #\a #\space)
#\i
> (successor jane-eyre-info #\space #\i #\space)
#\i
```

You may be asking why so many different characters appear between spaces.
But that's not what this represents.  Remember, a space just
represents "any non-letter".  Given "M.D.", we'll find that both "m"
and "d" appear between "spaces".

Since I'm about to write something that looks a whole lot like
`next-gen-by-freq`, it's time to generalize.

```racket
;;; (next-gen table next-char str) -> string?
;;;   next-char : (char? char? char?) -> char
;;;   str : string?
;;; Computes the "next generation" of a string by replacing each
;;; character in the string by the letter produces by
;;; `(next-char pred char succ)`.
(define next-gen
  (lambda (next-char str)
    (let ([len (string-length str)])
      (letrec
          ([kernel
            (lambda (i prev current so-far)
              (if (>= i len)
                  (list->string (reverse (cons (next-char table
                                                          prev
                                                          current
                                                          #\space)
                                               so-far)))
                  (let ([next (string-ref str i)])
                    (kernel (+ i 1)
                            current
                            next
                            (cons (next-char prev current next)
                                  so-far)))))])
        (kernel 1 #\space (string-ref str 0) null)))))
```

If I did that right, I can redefine `next-gen-by-freq` much more
concisely.

```racket
(define next-gen-by-freq
  (lambda (most-freq str)
    (next-gen (lambda (pred char succ)
                (at most-freq pred succ))
              str)))
```

Yup, that passes my tests.  Let's see if it gives the same effects as before.

```racket
> (generations-by-freq jane-eyre-most-freq "once upon a time there was a sam" 10)
once upon a time there was a sam
a ce s ef isw ve there has i h s
inhe ihod a tehe there his itiii
atce t af ish re there win it tn
inhe i os attehe there win in ao
atce i af ish re there win an ts
inhe i os attehe there win as ao
atce i af ish re there win as ts
inhe i os attehe there win as ao
atce i af ish re there win as ts
inhe i os attehe there win as ao
"inhe i os attehe there win as ao"
```

Oh, I guess it's time to generalize `generations-by-freq`.

```racket
;;; (generations next-char str n) -> string?
;;;   next-char : (char char char) -> char
;;;   str : string?
;;;   n : non-negative-integer?
;;; Display a sequence of n generations for a particular string.
;;; Returns the last generation
(define generations
  (lambda (next-char str n)
    (display str) (newline)
    (if (zero? n)
        str
        (generations next-char
                     (next-gen next-char str)
                     (- n 1)))))
```

Sometimes I wonder why I don't just start with the more general code.

Okay, it's time to try out our new mechanism.

```racket
> (generations (section successor jane-eyre-info <> <> <>)
               "once upon a time there was a sam"
               10)
once upon a time there was a sam
i ce s af iff ke there has i mul
i ge c iu ort ce there hes i sep
inve ekvv aud ge there hin i wal
aeeevaeanrnde ve there wen i her
zujydriedsscsrye there rar ighed
v buo eneoyrcbas thereat y atgad
debixlumvwfnmyus ther cs j sdsit
siuumtass  osilr thedooy uamrg s
mfllowe eczpkonc thap cpozlaem c
edt oknvoz pc  zet ahoesug yhwue
"edt oknvoz pc  zet ahoesug yhwue"
```

No cycles!  But also not very good language.  Let's run it a bit longer.

```racket
> (generations (section successor jane-eyre-info <> <> <>)
               "once upon a time there was a sam"
               10000)
...
kwgeba as xeta mrdrencored f adp
iasuhinaseaoxm butri oeved o anr
kuthyecoghwuuy bueab zbred s adq
vasabnfoneesbi bmfecugoeed c asr
niloauiamnldrb uuyifeeiind ecawc
vpslrfegloyouajvzwectwusndrorepa
eogsfuubratopnmvebssaelaouoav mh
zgfebeipl   leatifypjpgfqkeeaert
pgpaxlpnoclufect ns iuue unvjoad
eicaa mcairlkiskeoo vlkl o g eut
ao ui ilyiaat lwfwknuobiosnpllbt
zaljgfotfpwws ifk  fwtf clskguyy
oeduggurtoelo oeiieiunzaphuurmzp
"oeduggurtoelo oeiieiunzaphuurmzp"
i```

No cycles!  But, um, not very good language.  I wonder whether this ever
settles down into something "reasonable".    Time for yet another procedure.

```racket
;;; (nth-gen next-char str n) -> string?
;;;   next-char : (char char char) -> char
;;;   str : string?
;;;   n : non-negative-integer?
;;; Display a sequence of n generations for a particular string.
;;; Returns the last generation
(define nth-gen
  (lambda (next-char str n)
    (if (zero? n)
        str
        (nth-gen next-char
                 (next-gen next-char str)
                 (- n 1)))))
```

How does it work?

```
> (nth-gen (section successor jane-eyre-info <> <> <>)
               "once upon a time there was a sam"
               10000)
"ugtrod snhsarelkmiruxgus audytre"
> (nth-gen (section successor jane-eyre-info <> <> <>)
               "once upon a time there was a sam"
               10000)
"iyiiip ilnrinqop fe widclnd micx"
```

Hmmm ... Why am I getting different answers?  Oh, that's right.  Because
there is some randomness in my procedure.  Let's try a few more generations.

```racket
> (time (nth-gen (section successor jane-eyre-info <> <> <>)
                 "once upon a time there was a sam"
                 100000))
cpu time: 10385 real time: 10425 gc time: 487
"e zgp zbg rmwanli vwsiueywkvijyr"
> (time (nth-gen (section successor jane-eyre-info <> <> <>)
                 "once upon a time there was a sam"
                 100000))
cpu time: 10466 real time: 10510 gc time: 482
"r ngoso s elsnu alar to hgie orr"
```

Clearly, my idea is not a good one.  And it may be that it's now worth
the time to build the table.  But before that, I want to play a bit more.

```racket
> (time (nth-gen (section successor jane-eyre-info <> <> <>)
                 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                 100000))
cpu time: 17672 real time: 17770 gc time: 770
"hinoy wss fagaqsmaivoaogarueapaoaebalovummatoaxuaexoii"
```

Um.  Funny.  But slow.  Okay, on to improving the speed.  First, we'll
build a table of successors.

```racket
;;; (info->successors info) -> alphabetable of char?
;;;   info -> alphabetable of vector?
;;; Given the table produced by `gather-info`, returns a table that
;;; gives the letter that appears a bit more frequently between any two
;;; letters.
(define info->successors
  (lambda (info)
    (alphabetable (lambda (pred succ)
                    (let ([successors (make-vector 27 #\nul)])
                      (letrec
                          ([kernel
                            (lambda (i)
                              (when (>= i 0)
                                (vector-set! successors
                                             i
                                             (successor info pred (index->char i) succ))
                                (kernel (- i 1))))])
                        (kernel (- (vector-length successors) 1))
                        successors))))))
```

Note: While we use randomness in generating the table, applying the
table should be predictable.  If I were more concerned about efficiency,
I'd avoid using successor to compute the elements.  But how fast (or slow)
is this?

```racket
> (define jane-eyre-successors (time (info->successors jane-eyre-info)))
cpu time: 59 real time: 58 gc time: 0
```

That's fast enough that it's not worth any more of my time.

Does an entry in the table have the form I expect?

```racket
> (at jane-eyre-successors #\space #\space)
'#(#\w #\i #\y #\e #\y #\a #\o #\p #\v #\i #\u #\w #\p #\f #\l #\s #\d #\w #\x #\c #\f #\f #\b #\p #\v #\j #\l)
```

Yup.  Okay, on to some experiments.  First, is it now consistent?

```racket
> (nth-gen (lambda (pred char succ)
             (vector-ref (at jane-eyre-successors pred succ) (char->index char)))
           "once upon a time there was a sam"
           100)
"cegcaacf  t lbz goon o eu hudt x"
> (nth-gen (lambda (pred char succ)
             (vector-ref (at jane-eyre-successors pred succ) (char->index char)))
           "once upon a time there was a sam"
           100)
"cegcaacf  t lbz goon o eu hudt x"
```

Yes.  I'm not sure if that's a good thing or a bad thing.

Next, is it faster?

```racket
> (time (nth-gen (lambda (pred char succ)
                   (vector-ref (at jane-eyre-successors pred succ) (char->index char)))
                 "once upon a time there was a sam"
                 100000))
cpu time: 1275 real time: 1299 gc time: 159
"ae oeoelnaspirbin rw pndsnraitsc"
```

Yup, about ten times as fast.

Do we get any better language after longer time periods?

``racket
> (time (nth-gen (lambda (pred char succ)
                   (vector-ref (at jane-eyre-successors pred succ) (char->index char)))
                 "once upon a time there was a sam"
                 1000000))
cpu time: 12776 real time: 12975 gc time: 1686
"jvp favewre at b dolasgahbemd ez"
> (time (nth-gen (lambda (pred char succ)
                   (vector-ref (at jane-eyre-successors pred succ) (char->index char)))
                 "once upon a time there was a sam"
                 10000000))
cpu time: 123361 real time: 126002 gc time: 12237
"ruwupir awr mt geb ie ixebonef i"
```

Um, no.  So, what's the primary issue?  Is it that the whole approach
is flawed?  Possibly.  Is it that I need more context for each letter?
Probably.  Is it that I need even more iterations?  Possibly, but that
makes it less tenable as an approach.  Should I try longer strings?
That shouldn't make much of a difference.  Shorter?  That seems silly.

```racket
> (time (nth-gen (lambda (pred char succ)
                   (vector-ref (at jane-eyre-successors pred succ) (char->index char)))
                 "cat"
                 1000000))
cpu time: 1347 real time: 1360 gc time: 198
"rub"
```

Cool!  Let's go a bit further.

```racket
> (generations (lambda (pred char succ)
                 (vector-ref (at jane-eyre-successors pred succ) 
                             (char->index char)))
               "rub"
               20)
rub
gay
rrn
vst
o t
s f
c o
eos
zbe
gle
brd
o y
s j
c u
eqf
ewf
wia
wlx
uac
zlu
ulc
"ulc"
```

Oh.  Never mind.  Ending in a real word was just a coinkydink.

What else could I do to extend the project?  I could try some
randomness, but I don't think that will help all that much.  Perhaps
a better text?  More context (that is, longer predecessor and
successor text) is probably the way to go.  More context probably
means a sparser table, and a switch to hash tables from vectors.
Or I could read the research literature and find a better strategy.

At this point, I think those are activities for another day and
certainly for another musing.

---

**_Postscript_**: As part of this project, I got to 

* write utility code, including utility code---such as `dediacriticize`---that
  may end up in the `csc151` library;
* muse;
* make some bad jokes and some especially bad jokes;
* experiment with ideas;
* go off on tangents;
* write in an educational mode without wondering whether I was
  presenting material in the clearest light;
* and more.

It was a good project for my happiness level!  Perhaps evean a great
project.  If only I'd gotten useful results.  But I often enjoy the
journey as much as the destination---or the process as much as the
result.

But you know what?  I had more fun in the old image-based 151.

---

**_Postscript_**: Spell-checking this musing was a nightmare, particularly
when I got to th3 list of about 676 two-letter pairs.

---

[1] There I go, violating my [resolutions](new-years-resolutions-2020-12-31)
already, reading _The Times_ rather than a novel or other extended work.

[2] Should it be "Game of Life" or "game of life"?  I've chosen the former
because it's a particular game of life.  I see that The _Times_ also
capitalizes it as a proper noun [3].

[3] I continue to worry why people have given up on capitalizing
Internet.  There's one.  It's not an internet, although such things
also exist.

[4] Unfortunately, a bunch of that focus got cut in the move from
forty-two class periods to thirty-five.

[5] Reminder to self: The lab on randomness should have a "select
problematically" exercise.

[6] That's the character "a" (eh) in Scheme/Racket, the language we
use in 151 and one of my favorite languages for exploratory programming.

[7] Yes, that's "b" (bee).

[8] Most computer scientists start their counting at 0.  In Scheme/Racket,
vectors [9], lists, and strings are indexed starting at 0.

[9] Another name for arrays.

[10] There are more than six, so perhaps I should call them the "*N* P's"
[11]. 

[11] Welcome to Dad Jokes for Computer Scientists..

[12] And umlauted and dieresed [14] and such.

[14] What do you use as the verb for "add dieresis"?

[15] I'm sure the spell checkers are going to have a wonderful time
with this musing.

[16] That's right.  This time I remembered to follow the test-first
methodology I suggest to my students.

[17] Typing all of those on the Mac was thrilling.

[18] If you have others, please let me know.

[19] I keep wanting to rename it to something like "loudSmile".

[20] Wow, I'm going to get sick of typing that name.

[21] The purpose of `char-alphabetic?`.

[22] Unicode is the standard encoding of characters into integers or, as
my colleague JDS puts it, the collating sequence.

[23] American Standard Code for Information Interchange, another
collating sequence.  Also a subset of Unicode.

[24] Extending Binary Coded Decimal Interchange Code [25] Another
collating sequence, albeit one used much less frequently.

[25] It never hurts to repeat "Code".

[26] Standard Huffman Statistical Encoding of American English.

[27] Remember the days when you could just create a new Wikipedia page
as part of your work?  Sadly [28], those days are long gone.

[28] Or happily.

[29] Ah, the wonders of unit testing.

[30] No, not Indexing Scheme.  Also not Indexing Racket.  Please try 
to keep up.

[31] Have I mentioned that I don't particularly like terms?  If not,
don't worry, that will be an upcoming musing.

[32] More fun for my spelling checker.  More confusion for my readers.

[33] No, the "table" in "mutable" and "immutable" does not mean
"table".  They don't even rhyme.

[34] I am being completely serious.  I had not anticipated calling the
lookup procedure "`at`".  But it's the natural name.

[35] No.

[36] Are you surprised that I regularly reference _Wikipedia_?  You
shouldn't be.  _Wikipedia_ is generally reliable for computing-related
topics [37].

[37] Arguably, it is generally reliable for most non-controversial
topics [38].

[38] At times, I wonder whether I should boycott _Wikipedia_ because
of [its treatment of Tito Rajarshi
Mukhopadhyay](https://neuroclastic.com/2019/09/30/wikipedia-org-article-on-tito-mukhopadhyay/).  I'll need to reflect on that issue again.

[39] I'm going to assume that we'll mostly call this code in good faith.

[40] Output reformatted for readability.

[41] Yes, I am writing this code in a document->test->develop cycle,
although I do have to force myself back into that cycle from time to time.

[42] Jeopardy!  What is the question?

[43] Queue Beatles' earworm.

[44] Or perhaps for an assignment, if I build one based on all of this.

[45] Or is that now macBook, given that they've switched to macOS?

[46] And needed tests.
