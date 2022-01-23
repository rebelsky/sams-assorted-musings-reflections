---
title: Thinking in Unix
number: 179
tags: [Don't embarrass me, don't embarrass yourself: Thoughts on thinking in C and Unix](index-cnix)
blurb: 
version: 1.3
released: 2017-01-04
current: 2021-01-23
---
We've just considered what it means to [think in C](cnix-thinking-in-c).
Unix is an operating system [1].  How does one "think" in an operating
system?  I suppose, like a C programmer, one could pay attention to
underlying representation issues, such as file structures.  But that's
not what I mean when I say that one "thinks in Unix".

Rather, thinking in Unix refers to a series of programming and
software development practices typically associated with the Unix
operating, most often with the Unix command-line interface.  Various
lists of these practices appear around the Interweb.  Here are mine.

*Unix programmers know a variety of small tools, and achieve powerful
results by combining those tools appropriately.*  What tools?  I think
each Unix programmer ends up relying on a different set, but most include
`grep`, `head`, `tail`, `wc`, `sort`, `cat` [2,3], and such in their
toolkits [5].  How do they combine them?  Well, because most Unix tools use
human-readable sequences of characters (a.k.a. "text files") as input
and output, one can combine tools using pipes or by taking the output
of one command as the command-line arguments of another [6].

*Unix programmers realize that there are a variety of ways to solve
problems and look for the most efficient ones.*  Of course, there
are many models of efficiency.  For a one-off task, efficient use of
programmer time is the most relevant.  At the other extreme, for a large
number of related tasks, building a general tool might be the most
efficient approach.

*Unix programmers don't do things by hand when they can do them by
code.*  That is, Unix programmers know that they can be much more
efficient if they write small programs for tedious tasks (and then
chain them together, as above).  How does one do things by code?
Sometimes, it's just a matter of chaining together tools.  Sometimes,
it's writing Makefiles to automate tasks.  Sometimes, it's writing
a short script in a scripting language (e.g., Perl, Python, Ruby,
PHP, Bash).  And sometimes, it even involves writing a nicely
efficient C program.

*Unix programmers know enough of a shell (most typically bash [7], but
sometimes tcsh) to tie everything together.*  Unix programmers know about
pipes and other forms of file redirection, about environment variables,
about command line parameters, and so on and so forth.

*Unix programmers share.*  'nuff said [8].

As we proceed through this series of essays [9], we'll consider most of
these issues in more depth.  We'll visit a variety of useful tools,
look a little at scripting, and then spend some time making Makefiles,
considering tasks to automate, and such.  It should be fun!

---

**Exercises**

Here are some tasks that can be solved in a variety of ways [10].  Think
about how you'd solve them (or, better yet, solve them).  We'll discuss
the strengths and weaknesses (and time constraints) of various approaches.
You can use existing tools, write C programs, write scripts, or anything
else within reason [11].

* Given a DOS-formatted text file, one in which lines end with `\r\n` rather 
  than just `\n`, convert it to a standard text file, one in which lines
  end with just `\n`.
* Given a standard text file, convert all uppercase letters to lowercase.
* Given a standard text file, remove all blank spaces at the end of lines.  
* Make a list of all misspelled words in a text file.
* Given a CSV file in which each line has the form<br>
  `LastName,FirstName,Assignment,NumericGrade` <br>
  find the five highest grades on homework 2.  (You can choose to
  output the whole lines, the numbers, or the names.)
* Given a similar file, find the five lowest grades.
* Bonus (optional): Find the average of the five highest grades on 
  homework 2.
* Given an HTML file, find the URLs of all images.  In case you don't
  know HTML, those will typically look like <br>
  `<img ... src="*URL*" ...>`
  + The `img` can have any capitalization (`img`,
    `IMG`, `Img`,  `iMg`, etc.)
  + There can be other text between the `img` and the
    `src`.  (That text cannot include a greater than sign.)
  + You may find it easier to start this problem by assuming that there's only o
ne image tag on a line.

---

[1] Well, more precisely, an operating system, a set of standard utilities,
and some other stuff.

[2] Carolyn Jacobson suggested the inclusion of `cat`.  Thanks, Carolyn.

[3] And, no, the `cat` command is not responsible for the introduction
of lolcats [4], nor does it create one.  It is short for "conCATenate". 
The `cat` command permits users to view and join files.

[4] Remember lolcats?  At one point, they were a big thing.  It seems
like few of my students know of them anymore.

[5] Assignment for my students: Find six other Unix utilities that are
likely to be useful.

[6] Don't worry if you don't know how to use pipes.  Don't worry if you
don't know how to use the output of a command as the parameters of another
command.  We'll cover it.

[7] Perhaps zsh these days.

[8] Well, maybe not, since I haven't indicated what Unix programmers
share.  They share code.  They share ideas.  They share tools.  They
share libraries.  Perhaps most importantly, they share a joy in
programming.

[9] Or this book, or this course.

[10] Note that most of these tasks were developed as part of one of
the sections of my "Thinking in C and Unix" course.

[11] You cannot, for example, open a file in Microsoft Word and use
Word to achieve one of these goals.
