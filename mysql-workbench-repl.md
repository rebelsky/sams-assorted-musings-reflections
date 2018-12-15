I want my REPL!
===============

*Topics/tags: [Rants](index-rants), SIGCSE, technical*

I'm a moderately old-school computer scientist.  Among other things,
that means that when I work on programming-related tasks, I generally
prefer to deal with the command line rather than a fancy graphical
user interface.  It's not that I mind GUIs; for many tasks, I may even
prefer them.  But I'm generally more efficient as a programmer when I
can type on the keyboard than when I have to click around.

This week, I'm dealing with the SIGCSE Student Volunteer database and
associated Web service.  Long-term readers may recall that this is
software that was written by undergraduates that I inherited.  I may
not have mentioned that it also runs on a server to which I lack sudo
privileges [1].  That's probably a good thing, but it makes some issues
difficult.

In any case, I have two primary modes of working with the database.
Sometimes, I work with the database in what I'd call *interactive
mode*: I type a command, look at the results, reflect on their meaning,
and then type the next command.  Most programmers refer to this mode
of interaction as the "read-eval-print loop" or just REPL.  It's a
mode of working with systems that we emphasize in 151.  I also work with
the database in *batch mode*: I've put a series of instructions in a file,
and I just want the system to execute them in sequence.  That's easy to
do from the command line with a command like the following.

    $ mysql SIGCSE -u USERNAME -p < instructions.sql

I also use a batch command when I want to make a backup copy of the
database in both human-readable and machine-executable form.  Here's
an example.

    $ /usr/bin/mysqldump -p -u sigcsedb --databases SIGCSE > SIGCSE-2018-12-14.sql

My colleagues who work with the database prefer to use MySQL Workbench,
which presents a GUI for navigating MySQL databases.  I think most people
use MySQL Workbench because it display results well.  Some other
aspects of the workbench are quite nice.  For example, you can edit
batch scripts and them from within the workbench; you can also select
a few lines of a script and execute only those lines.

I had trouble setting up MySQL Workbench when I tried a year ago,
and I'm most comfortable working with MySQL from the command line,
so I decided to stick with my old habits.  It worked fine last year.

This year, there have been changes to the server.  I've found that
the `mysql` and `mysqldump` commands work some of the time, but not
all of the time.  When they don't work, I get lovely error messages like

    mysqldump: Got error: 2002: Can't connect to local MySQL server through socket '/var/run/mysql/mysql.sock' (2) when trying to connect

All the suggestions I can find online suggest that I need sudo privs
in order to make sure that the daemon is running correctly.  The more
puzzling issue is that they work some of the time, but not all of the
time.

However, even when the command-line tools fail, it appears that a remote
MySQL Workbench ssh connection continues to work fine.  This year, I
tried again to get it to work, and this time it did.  So now I'm trying
to work in GUI.  And you know what?  I'm much less efficient.  It takes
approximately twice as much time to click in the right place, type a command,
click on the line again [2], and then click on the appropriate execute
button than it takes to type the command and just hit return, which I
could do in a REPL.  So I went online to figure out how to run a REPL
in MySQL Workbench.  It turns that there isn't one.  In effect, the
response is "If you want a REPL, use mysql from the command line."  But
I can't.  And setting up an ssh tunnel didn't work.  So I'm stuck with
MySQL Workbench.

As you might expect, it turns out I'd rather do most things on the command
line, even if it's "easier" in MySQL Workbench.  For example, to change a
value in a table in the workbench, you need only click on the appropriate
cell, type in the new value, and hit an "Apply" button.  But something
in my brain wants to type `UPDATE table SET col='newval' WHERE id="1234';`
And, in the case of longer scripts, I'd rather edit them in, say vi,
than in the more primitive visual editor.


Mostly, though, I want my REPL.

---

Postscript: In case it's not clear, I'm not blaming the designers of MySQL
Workbench for the lack of a REPL.  I'm just expressing my frustration
at not having one available.

---

Obligatory confusing Dad joke: I don't care all that much about my
empty vee.

---

[1] For non-technical users: That means that I can do many things, but
not mess with system software.

[2] I'm much too used to hitting return at the end of a command.

---

*Version 1.0 of 2018-12-14.*
