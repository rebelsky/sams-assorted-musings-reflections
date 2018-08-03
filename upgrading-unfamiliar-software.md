Upgrading unfamiliar software
=============================

*Topics/tags: [The joy of code](index-joc) [1], technical, rambly*

**Introduction**

Once in a while, I take on a task that involves using and therefore
maintaining someone else's custom-written software.  The SIGCSE Volunteer
System, which I've written about in the past, is one such case.  But
there are others.

At present, I'm dealing with software that I use about once a year.
It's written in PHP, a language whose name I insist generally stands
for "Pretty Horrible Programs".  When I inherited the program, it was
already issuing error messages that some of the procedures it used
were deprecated.

I went to use it this year.  I first had to deal with a number of
obstacles related to recent "upgrades" to our system.  That meant working
on group ownership issues, convincing our SysAdmin to re-install MySQL
and reload an important database, and a few other things.

Once all that was done, I tried to run the program.  Guess what?
The formerly deprecated procedures are now deleted.  PHP 7 no longer
supports `mysql_pconnect` and some related procedures [2].  And so it's
time for me to figure out how to update a system that I didn't write
using a language that I encounter primarily when I'm dealing with someone
else's software.

**Preparation**

My first step was to set up a Git repository.  I've been making changes
to the software over the past few years.  I've always felt uncomfortable
that I wasn't documenting those changes in a version control system.
This change seems significant enough that I'd really like to document
the changes I'm making.

Of course, setting up the Git repository led me to make additional
changes, even before I started attacking the code.  For example, I
decided to choose a consistent naming scheme for the files.  Some had
used camelCase.  Others were snake_style.  I settled on the third major
style, which is to separate words with dashes [3,4].  I wasn't up to
thinking about the style for the underlying code.

There was a lot of cruft sitting in the directory in which the software
lived.  Hence, to figure out what files I needed, I rewrote the instructions.
That had been on my long-term "to do" list, and it seemed like an appropriate
start.  I'm actually glad that I did so.  When I hit the last part of the
instructions, I realized that last year or the year before I had written
some utilities of my own and, in doing so, had moved to one of the new PHP 
models for working with MySQL databases.  Have I chosen the best one?
Probably not.  But it's not deprecated.

Before committing anything, I decided to make sure that the MySQL account
and password weren't in any files I was using.  That meant rewriting the
non-working database commands to read those values from elsewhere.  I was
tempted to use environment variables, which is one standard approach to
storing that information.  In the end, I decided to use text files that
aren't in the repo.  That may not seem like a significant difference,
but it does ensure that all of the *code* is in the repo.

**Planning for updates**

Once I had everything in the repository, it was time to sit down [5]
and get to the real work of updating the software.  My main goal was
to use a new approach to databases.  But I can't leave things well enough
alone, so I had other changes to make, too.  One simple change is to add
a bit of documentation to the top of each file.  I like being able to see
the author of a file at the top.

A not-as-simple change, but one that's also not likely to be as hard is
to change the interaction paradigm.  The people who wrote the software
fall in the "interactive" camp.  The program prompts you for a variety
of inputs.  I fall in the "command line" camp.  I'd rather just specify
as many inputs as possible on the command line.

In the past, I've found that change relatively easy to make.  Many of
the scripts require just one or two inputs.  But some of these files have
been more challenging.  It's clear that the mindsets of folks who like the
command line and those who like textual prompts are somewhat different.
But I'll probably be using this system for another decade or so, so I
might as well spend the effort now.

**Updating the first script**

The first program I needed to use had calls to `mysql_pconnect`,
`mysql_select_db`, `mysql_query`, `mysql_num_rows`, `mysql_result`,
and `mysql_error`.  I've already replaced the calls to `mysql_pconnect` and
`mysql_select_db` with a call to the appropriate `mysqli` constructor.
`mysql_query` becomes a call to the `query` method of that object.

I have mixed feelings on what to do with something like
`mysql_num_rows($result)`.  I could maintain the procedural
syntax and use `mysqli_num_rows($result)`.  However, I feel a bit
more comfortable switching to an object-oriented syntax and using
`$result->num_rows`.  But there may be more at play.  I see from the
[documentation](http://php.net/manual/en/mysqli-result.num-rows.php) that
"For unbuffered result sets, mysqli_num_rows() will not return the correct
number of rows until all the rows in the result have been retrieved."

Dealing with `mysql_result` will be a bit more challenging.  In the code
I'm working with, it's typically used in the form `mysql_result($result,
$i, $field)` to select a particular field from the ith row of the result.
The new model doesn't provide for that.  There are ways to simulate it
[6].  However, it appears that in many cases it's only being used for
iteration.  In those cases, I should follow the newer iteration model.
My notes say that it looks something like the following.

    $result->data_seek(0);
    while ($row = $result->fetch_assoc())
      {
        ...
      }

Further on, there's a bit of code that does a query that potentially
returns multiple lines and grabs the last of them, calling it the
"latest row".  But the query does not sort the rows in any order.
I think that means that we have no guarantee about which row will be last.
One of the problems of working with student-written code is that I can
never tell whether I'm missing a subtle issue or whether they missed
a subtle issue.  Dare I change the program "logic" and just grab an
arbitrary row?  My reading of the program suggests that I can.

As always, I can't resist making other changes.  Repeated code?  DRY
it out.  Awkward formatting?  Fix it.  Missing comment?  Add it.

After three or so hours, I finally got the first script working.  But
I'll admit that the `git commit` felt unclean.  I'm used to making
each type of change separately.  I wonder whether I can do better on
the next script.

**Updating the remaining scripts**

For the second script, I was able to divide my updates into (a) add
documentation; (b) update the UI [7], (c) switch to the new database
model, and (d) clean up a few pieces of cruft that offended my 
sensibilities.  That git log feels a lot nicer.

Along the way, I discovered something interesting.  The database has an
id field that is stored as characters.  But the ids have always been numbers.
My experiments have all involved ids that include letters.  That breaks
a lot of the code.  Fortunately, the fix is easy: I just have to remember
to put the id in quotation marks in the SQL queries [8].

The next two scripts were ones that I had written.  One already used the
new database model [9].  The other did not [10].  Those changes were quick.

How many scripts is that?  Four or so.  There's another one that I already
know works.  I think there are three or four more that still need updates.
Why did I decide to take on this task?  Wouldn't I have been better off
finding a machine with an old version of PHP? [11]  

Okay, on to the next script.  Once again, I'm trying to do separate commits
for each of the four main activities (add comments, update UI, fix database,
clean up code).  I've now done the activities enough that it's going a
bit faster.  But the database stuff is always the slowest.  Fortunately,
this one was mostly looping through input.

**Done (for the time being)**

I'm not done, but I've verified that I can make the important changes.
I also seem to have covered most of the different issues involved.  Everything
else *should* be straightforward.  A few more hours and I'll have all
of the scripts updated.  I just need to keep myself from deciding to clean
up more of the code.

Now I'm ready for the regular annual updates.  I may make fewer than normal
this year.  We shall see.

---

Postscript: I chose the title for this musing when I started it.  Now that
I'm finished, I'm tempted to call it something like "Another day and a half
of my life down the drain."

---

Postscript: The to-do list for this software seems to grow every year.  At
some point, I should write automated tests.  Or maybe I can just pass
the whole shebang on to some other person and they can worry about them.

---

Postscript: One I posted this musing, I realized that the title could be
misinterpreted; "upgrading software" usually just means installing the
next version.  Perhaps I should have called it "upgrading legacy code".
Or maybe "updating legacy code".  But I like the "unfamiliar".  Is
"unfamiliar" implied by "legacy".  I'm not sure.  In any case, I've spent
enough time on the code that I don't have the energy to think through
those issues.  I'm leaving the title as it is.

---

[1] That tag is almost certainly sarcastic.

[2] I'm pretty sure that it's a sensible decision; it looks like the
old model involved a single global database connection.  The new model
requires that you keep track of a database connection object.  That makes
much more sense.

[3] Can you tell that I regularly work in a Lisp variant?

[4] The InterWeb tells me that this style is sometimes called "Kebab case".

[5] Okay, I was sitting down already.

[6] For example, see the comment from tuexdobob in [the documentation
for `mysqli-result`](http://php.net/manual/en/class.mysqli-result.php).

[7] Well, there was one bug in the UI that I didn't catch until the next
step.  It's hard to tell whether or not the UI works until the underlying
code works.

[8] More precisely, I need to make sure that the code generates SQL queries
that include the quotation marks.

[9] Yay!  I was looking ahead.

[10] Boo!  I was not universal in how I looked ahead.  But I'm pretty sure
that the script with the old database model is older.

[11] Maybe for this year.  But then I'd be stuck with the same problem
next year.

---

*Version 1.0 of 2018-08-02.*
