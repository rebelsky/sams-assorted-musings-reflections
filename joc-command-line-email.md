The joy of code: Command-line email
===================================

As I've written before, one of the wonderful things about work on
the command line on a *nix [1] system is that you can easily string
commands together to achieve more powerful results.  As an
example, suppose I have a text file containing lines of the form

<pre>
username        Assignment      Grade
</pre>

For example, my grade on homework 5 might be recorded as

<pre>
rebelsky        hw05    88
</pre>

If I wanted to see all the grades on the first exam, I can write an
expression something like the following.

<pre>
$ grep exam01 grades
rebelsky        exam01  77
smith123        exam01  95
jones123        exam01  40
...
</pre>

As this example suggests, the `grep` command searches for text. 

If, in contrast, I want the grades on exam1, sorted in decreasing order,
I can write an expression like the following [2].

<pre>
$ grep exam01 grades | sort -k3 -n -r
smithabc        exam01  100
jonesqrs        exam01  99
skyrebel        exam01  99
skyrebel2       exam01  98
smith123        exam01  97
...
</pre>

In this case, the `sort` command puts things in order.  The `-k3` means
to use column 3 [3].  The `n` means to sort numerically.  And the `-r`
means to sort in reverse order (from largest to smallest rather than
smallest to largest).

What if I just want the names of top five exam scorers?  I can
use the `cut` command to select just that column, and the `head`
command to take the first five rows..

<pre>
$ grep exam01 grades | sort -k3 -n -r | cut -f 1 | head -5
smithabc
jonesqrs
skyrebel
skyrebel2
smith123
</pre>

Whoops!  That was a longer digression than I'd planned.  Anyway,
as the examples suggest, I tend to store my grades in a protected
file of the form above.  I use commands like the above when I need
some quick pieces of information and more complex scripts when
I need more sophisticated calculations.  For example, here's the
output of my `makereport` script.

<pre>
$ makereport "Skyreb, Elizabeth" skyrebel
Estimated Grade Report for Skyreb, Elizabeth [skyrebel]

This is an experimental grade report and is not guaranteed to be accurate.
Estimated grades are based on current status in the course.  Final grades
may therefore be much different.

SUMMARY REPORT
--------------

Homework ......... (15.0%): 89 (3.4 on a 4-point scale)
Labs ............. (10.0%): 100 (10/11; up to 2 missing labs permitted)
Quizzes .......... (10.0%): 95.0 (69.5-4-8.5)/6) [dropped two lowest]
Project .......... (10.0%): [Not available]
Exams ............ (40.0%): 81.0 (on 2 exams)
Final ....................: [Not available]
Best individual .. (10.0%): 95.0
Participation .... ( 5.0%): [Not available]
Extra Credit .............: 5 units

Estimated numeric grade: 74.8/85 = 88.0
Estimated numeric grade with 5 units of extra credit: 89.2

DETAILED INFORMATION
--------------------

Homework: 89
        hw01    check   
        hw02    check   
        hw05    check   
        hw06    check+  

Labs: 100 (10/11)
        lab05   1       
        lab06   1       
        lab07   1       
        lab09   1       Wrote helper in 6a
        lab10   1       did in Klinge's class
        lab11   1       strange answer
        lab12   1       particularly nice answer
        lab15   0       did not submit
        lab16   1       particularly nice answer
        lab17   1       no examples
        lab18   1       particularly nice answer, w/ documentation

Quizzes: 95.0 (69.5-4-8.5))/6) [dropped two lowest]
        quiz01  10      
        quiz02  10      
        quiz03  4       
        quiz04  9       
        quiz05  10      
        quiz06  9       
        quiz07  9       
        quiz08  8.5     

Exams: 81.0
        exam01  77      006008
        exam02  85      242000,pro

Absences
        skyrebel        absent  0.5     2017-02-01 (alarm clock failure)
        skyrebel        absent  0       2017-03-01 (alarm clock failure)
        skyrebel        absent  1       2017-03-07

Extra: 5
        1       academic,2017-02-09,Convo
        1       academic,2017-02-27,Standing Rock
        1       peer,2017-02-18,Orchestra
        1       peer,2017-02-04,Swimming
        1       academic,2017-01-31,CS Table
</pre>

Now, once I've generated one of these reports, it would be nice to send
it to the student.  Conveniently, our Unix systems provide a simple
interface to mail called, not surprisingly `mail`.  This command takes
a variety of command-line flags, such as the subject, people to carbon copy,
and, obviously, the recipient.  That means I can type commands like
the following.

<pre>
$ makereport "Skyreb, Elizabeth" skyrebel | \
   mail -s "[CSC 151] Estimated Grades for E. SkyReb" \
        -c rebelsky@grinnell.edu \
        skyrebel@grinnell.edu
</pre>

Of course, I have a script to generate commands and run like that, taking
the userid/name combinations from another file.  That means I can easily
generate and send grades whenever I need or want to [4].

At times in the past, I've also used `chron` to schedule useful scripts
to run regularly (say, once each day) and to send me results.  When I
was an annoying undergraduate [6], I used that capability to send a
regular reminder to my boss to give me a promised raise [7].

When I speak to non-*nix people (e.g., Microsoft aficionados), I find
that we have a very different sense of email.  I get questions like "Why
would you want a command-line email option? [9]" and "Can't you just do 
that with Outlook? [10]"

I miss the days before spammers took over the Internet mail system, and
it was easy to just telnet to port 25 to send mail.  Oh well; at least
I have outgoing email capabilities from my College *nix box [11].

---

[1] Unix, Linux, FreeBSD, MacOS, etc.

[2] My son who uses R find that he writes similar expressions in R.

[3] It appears that the designers of `sort` failed to understand
0-based indexing.  Alternately, they may have assumed that their
users would prefer 1-based indexing.

[4] It turns out the workflow is really useful when a student asks
me "What happens if I get *X* [5] on the final?"

[5] No, they don't ask about a grade of "X".  Rather, they ask questions
like "What happens if I get a B on the final?"

[6] Is that redundant?

[7] Yes, I waited a reasonable amount of time [8] before starting the
reminder emails.

[8] I know that you were thinking "Sam probably waited an hour or so",
but I actually waited about a month before sending the autospam.

[9] See above for some answers.

[10] Not in my experience.

[11] Admittedly, today I discovered that ITS accidentally broke those
capabilities [12].  This musing is part of my attempt to document why I so
value the ability to send mail from the command line.

[12] I will say that whoever is stuck helping me with the problem is
working really hard on it.  It can't be fun, and I appreciate their
hard work [14,15].

[14] Believe it or not, but those comments were completely serious.  I
know that figuring out what's going on with mail systems can be hard,
and I think we have a relatively new postmaster.

[15] It appears that they were up until one am fixing the relay.  I 
*really* appreciate their hard work.

---

*Version 1.0.1 of 2017-04-05.*
