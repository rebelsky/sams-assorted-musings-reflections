`git flame`
===========

*Topics/tags: [Miscellaneous](index-misc), technical, git, short*

**Short version**

`git flame`

> To be used when you discover that someone pushed non-working code to
the main branch.  Incinerates that person, thereby limiting the amount
of future damage they can do to this project or any project. [1]

**Long version**

I regularly use Git, a tool for collaborating on software projects 
that involve shared files.  Git makes it easy [2] to see a history
of your project, to create temporary development versions, to combine
independent changes to the project, and more.  Old fogies like me
prefer to use Git from the command line.  I use commands like
`git add` to add a file to the project, `git commit` to incorporate
and comment on my changes, `git push` to send my changes to the main
repository, and `git pull` to bring my colleagues' changes into my
copy of the project.

Okay, it's a bit more complicated than that.  You can have multiple
versions of the project.  Each version is called a "branch".  The main
branch is supposed to have the latest stable version.  Those who use
Git make it practice to regularly pull from the main branch so that
their copy is up to date.  Hence, when I teach my students how to
use Git, one of the first maxims is

> Never commit non-working code to the main branch!

There are other important maxims [3].  But that comes first.  What
should you do if you see that someone has committed non-working code?
Often, the first thing you do is try to back up to before they
added the code.  The difficulty of doing so depends not only on your
knowledge of Git but how many changes have been made.  And there's
a convenient `git blame` to add a note about the problem.

But I've always wanted a more extreme command.  After all, it's
incredibly frustrating to go from a working project that you can test
to a non-working project that you're then stuck mucking with it for
some unspecified amount of time.  It's particularly frustrating when
you were counting on time to test or fix your own code.  And so I find
myself wishing for a **`git flame`** command.  I don't really want to
incinerate someone, but it would be nice to have a command that I could
use to express my frustration [4].

---

Postscript: I've played with a variety of names for that command.
I originally called this musing `git sack` [5].  But that didn't feel
strong enough; someone who damages projects shouldn't be working on *any*
project [6].  Commands like `git nuke` and `git incinerate` seem like
they refer to the project, rather than to the committer.  I also came
up with some more extreme names for that command, few of which are fit
for a public musing.  

If you have a better safe-for-work variation, I'd love to hear it.

---

Postscript: Don't worry.  I never really get that angry.  It's just
nice to envision a silly way to let off steam [7].

---

[1] No, not really.

[2] Well, relatively easy.

[3] For example, "_Don't put the AWS keys in a public repo!_"  That one
derives from a war story I'll tell at the next SIGCSE.

[4] Or that I could give to my students to express their frustration
with their group mates.

[5] "sack" means "to dismiss (someone) from a job".

[6] Can you tell how angry I get dealing with someone else's mistakes?

[7] No pun intended.

---

*Version 1.0 of 2018-12-11.*
