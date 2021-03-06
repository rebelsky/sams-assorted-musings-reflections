The joy of code: Finding repeated words
=======================================

In [a recent musing](grammarly-repeated-words), I wrote about the problem
of identifying repeated words in my writing.  I claimed that it took me
about ten minutes to write a short script to do so.  Let's see how.

I started by reflecting on the steps I'd have to use.

1. I know from experience that my life will be easier if I have one word
per line.  That means changing any sequences of "non-word characters"
into newlines.

2. That technique is likely to create some blank lines.  I also have
blank lines in my original essay.  I should delete those lines.

3. I don't want to differentiate between "The" and "the", so I should
turn all uppercase letters into lowercase.

4. It is likely easier to count if I put the words into alphabetical
order.  Doing so ensures that I can look for neighboring lines that
are the same.

5. I should then do the central goal of this project: counting the
number of times each word appears, and presenting a list of
(word/count) pairs [1].

6. So that I can tell which words I use most, I should then put that
list in order by count.

I also came up with a few other steps that are likely to be useful, but
not strictly necessary [2].

So, let's see how we do all of those steps, using this musing as an
example.

I didn't mention "I need to start with the contents of the musing", but
that's really where I have to start.  So, let's see ...

<pre>
$ cat joc-counting-repeats.md
The joy of code: Finding repeated words
=======================================

In [a recent musing](grammarly-repeated-words), I wrote about the problem
of identifying repeated words in my writing.  I claimed that it took me
about ten minutes to write a short script to do so.  Let's see how.

I started by thinking about the steps I'd have to use.

1. I know from experience that my life will be easier if I have one word
...
</pre>

Next, I need to insert a newline for the "non-word" characters.  I tend
to use `sed`, the stream editor, for non-interactive editing.  I'll
start by identifying "word" characters.  Those will be the lowercase
letters, the uppercase letters [3], and the apostrophe [4,5].  In
`sed`, I identify a set of characters by surrounding it with square
brackets.  I negate that set by putting a caret after the open bracket.
So I'll use `[^a-zA-Z']`.  I want one or more copies, so I add a
`+` at the end.  I want to replace that pattern with a newline, which
is represented as `\n`.  Okay, here goes.

<pre>
$ cat joc-counting-repeats.md \
   | sed -re "s/[^a-zA-Z']+/\n/g" 
The
joy
of
code
Finding
repeated
words



In
a
recent
musing
grammarly
repeated
words
I
wrote
...
</pre>

As I predicted, I ended up with a bunch of blank lines.  I didn't think
to get rid of the link, so the words in the link [6] appear in this list
I should fix that problem.  I'll do so after I get the basic set of 
instructions working.

Let's get rid of the blank lines.  The `grep` program extracts lines
from a file.  The `-v` flag represents "anything but".  The pattern
`^$` is a blank line [7].

<pre>
$ cat joc-counting-repeats.md \
   | sed -re "s/[^a-zA-Z']+/\n/g" \
   | grep -v '^$' 
The
joy
of
code
Finding
repeated
words
In
a
recent
musing
grammarly
repeated
words
I
wrote
about
the
problem
of
...
</pre>

Next, I want to turn uppercase letters into lowercase.  While I could
use `sed`, the `tr` program works nicely for single-letter substitutions.
I'll use that.

<pre>
$ cat joc-counting-repeats.md \
   | sed -re "s/[^a-zA-Z']+/\n/g" \
   | grep -v '^$' \
   | tr [:upper:] [:lower:] 
the
joy
of
code
finding
repeated
words
in
...
</pre>

That worked as well as I expected.  Getting the words in alphabetical
order is simple, as *nix has a built-in `sort` command.

<pre>
$ cat joc-counting-repeats.md \
   | sed -re "s/[^a-zA-Z']+/\n/g" \
   | grep -v '^$' \
   | tr [:upper:] [:lower:] \
   | sort
'
'
'
'
'
a
a
a
a
a
...
a
about
about
about
about
about
about
about
about
add
after
after
all
all
all
alphabetical
alphabetical
...
</pre>

Whoops!  It appears that I left in some single quotation marks [8].  I wonder
why [9].  In any case, I don't really want them.  I'll add removing them to
my list of future work.

Now I want to count.  We've now hit the first tool that I don't regularly
use.  Let's see ... a Web search tells me that `uniq -c` counts repeated
lines, but only if they appear in sequence.  Let's try.

<pre>
$ cat joc-counting-repeats.md \
   | sed -re "s/[^a-zA-Z']+/\n/g" \
   | grep -v '^$' \
   | tr [:upper:] [:lower:] \
   | sort \
   | uniq -c
     12 '
     32 a
     16 about
      3 add
      4 after
      6 all
      4 alphabetical
      3 also
      1 an
      7 and
      2 any
      2 anything
      2 apostrophe
      2 appear
      2 appears
</pre>

Getting rid of the tick is definitely on my goal list!  What next?  I want
these in order from most frequently occurring to least frequently occurring.
That sounds like another job for `sort`.  This time, I'm sorting numbers,
and want them from largest to smallest, so I add the `-nr` flag [10].

<pre>
$ cat joc-counting-repeats.md \
   | sed -re "s/[^a-zA-Z']+/\n/g" \
   | grep -v '^$' \
   | tr [:upper:] [:lower:] \
   | sort \
   | uniq -c \
   | sort -nr
     58 i
     48 the
     34 a
     26 to
     23 of
     22 that
     19 in
     17 about
     16 words
     15 '
     14 pre
...
</pre>

You know what I just realized?  By putting in the sample output, I'm 
changing my word counts significantly.  Oh well, I guess that's how
things go when you're writing an example late at night [11].  

In any case, I am now done with the base program.  I've gotten the counts
of the individual words that appear in this musing [12].  If I were taking
my editing seriously, I could now see where they appear to decide if I
want to make changes to avoid too much unnecessary repetition [14].

I'll leave the other minor [15] extensions to another day.

---

[1] I might also do count/word pairs, depending on how I feel.

[2] If I were releasing this program as a tool for others, I would work
on making it a bit more precise.

[3] Maybe I should convert all uppercase to lowercase before I do
anything else.  Oh well, I did say that I wanted to do this quickly,
and that I could improve it before releasing it to others.

[4] I'd like to support words like "wouldn't" and "it's".

[5] Some people call the `'` symbol "tick".  That's certainly easier
to pronounce than apostrophe.

[6] "grammarly", "repeated", and "words'.

[7] In this case, the caret represents the start of the line and the
dollar sign represents the end of the line.

[8] a.k.a. "ticks".

[9] Upon reflection, it's because the term `'^$'` appears in multiple
examples.

[10] The `n` is for "numeric".  The "r" is for "reverse".

[11] It could be an interesting exercise to see how long it would take
me to reach a fixed point.

[12] More precisely, in a sequence of versions of this musing.

[14] You should read [the prior musing](grammarly-repeated-words) for
my thoughts on repeated words.

[15] Or perhaps not so minor. 

---
