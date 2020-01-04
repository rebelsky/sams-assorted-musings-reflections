---
title: The joy of code: Concise Perl
number: 
tags: the joy of code
blurb: 
version 0.2
released: 
current: 2020-01-03
---
The other day, I was writing some Perl code to parse the Liquid
variable declarations that can go at the top of Markdown files.
These have the form of a variable name, a colon, and a value.
Originally, I expected to deal with only a few variables, and so
I wrote the following.

    if ($line =~ m/^num: *(.*)$/) {
      $num = $1;
    }
    elsif ($line =~ m/^title: *(.*)$/) {
      $title= $1;
    }
    elsif ($line =~ m/^tags: *(.*)$/) {
      $tags = $1;
    }

No, it's not particularly sophisticated code.  But it was easy to
write and it got the job done.  If you haven't seen Perl before,
but understand a bit of programming, it shouldn't be hard to
understand.  Scalar variables are prefixed by dollar signs.  `=~`
effectively means to apply the expression at the right to the left
and return true or false [1].  The `m/.../` is pattern matching
using regular expressions.  And, as is typically with pattern
matching, `$1` represents that expression matched within the
parentheses.  If you don't know regular exprssions, I'm sorry, but
I'm not in the mood to explain them more.

Where was I?  Oh, yearh.  I wrote the code above.  It took me about
a minute, which is longer than it took me to write my mediocre
explanation.  It worked for the purposes I'd planned.

Eventually, I decided to expand the program, which meant that I had more
variables I wanted to support.  I could have used the technique of
"copy, paste, change" to add those variables, but that makes me ill
[2].  I thought about using a hash table instead of separate
variables.

Then I realized that *it's Perl*.  The original Perl was written by and
for people who like quick hacks.  So I tried the following and, lo and
behold, it worked.

    if ($line =~ m/^([a-z]*): *(.*)$/) {
      ${$1} = $2;
    }

In essence, 

> If you see a string of letters, a colon, some spaces, and more
stuff, take the string of letters, which is stored in variable `$1`,
use that as a variable name, and then assign the "more stuff", which
is stored in variable `$2` to that variable.

Isn't the beautiful?  Or perhaps hideous?  

---

Whoops.  I did not completely check my script.  It seems to have worked
fine with values like `2020-01-03` (a date), `1.0.1` (a version), and
972 (a number).  But it didn't work with text variables.  I'm not sure
why.  I was able to make the following work.

    $bar = "foo";
    ${$bar} = "quux";
    print "$foo"; // quux

I guess I did not understand Perl as much as I thought.  

I could try to figure out why, or I could just use a hash.  I chose the
latter.  It wasn't as cool as my original code, but it got the job done.

---

Postscript: I wonder what happens if I use a line without a variable
name as input.  'Eh, who cares.  It's not like anyone else is going to
use my script.

---

[1] It's Perl, so it's quite possible that is interperable as true
is returned instead of that exact value.

[2] I also believe that if I tell my students to avoid copy/paste/change,
then I should, too."
