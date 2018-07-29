Badly designed software
=======================

*Topics/tags: [Rants](index-rants), Linux*

I've been using Unix and Linux workstations for long enough that I
do most of my work from the command line, rather than through some
graphical user interface that makes me much slower.  But most users,
or at least most of my students, seem to find graphical user interfaces
more convenient.

Yesterday, we found a significant disadvantage of using the graphical
File Manager under xfce on Debian Linux [1,2].  A student had a directory,
which we will call `public_html/story` and they had an alias to that
directory, which we will call `Desktop/story` [3].  When browsing in the
File Manager, both look like folders.  There's a small mark on the alias,
but it's easy to ignore.

In any case, the students were working with the folder that appeared
to be on their desktop.  Then they were told that things needed to be
in their `public_html` folder.  So they dragged them over.  They got a
dialog with a question like "Replace files with the same name?" and answered
"Yes".  

Can you guess what happened?

That's right.  Instead of copying the files, it deleted them.  After about
thirty minutes of looking, I'm left to conclude that it's an irreversible
deletion.  The files didn't end up in the trash.  They were just gone.

*That's atrocious behavior!*  Graphical File Managers are there primarily
for novice users; more experienced users use the terminal.  Hence, they
should not delete files without a clear indication that they are doing so.
And, ideally, they should put the files aside in "the trash" rather than
actually deleting them.  This software did neither.

What happens if we do the same thing in the terminal?  Let's see.

    $ ls ~/public_html/story
    important.html
    $ ls ~/public_html/story/
    important.html
    $ file ~/Desktop/story/
    /home/rebelsky/Desktop/story/: directory
    $ file ~/public_html/story/
    /home/rebelsky/public_html/story/: directory
    $ mv ~/Desktop/story/important.html ~/public_html/story
    mv: '/home/rebelsky/Desktop/story/important.html' and '/home/rebelsky/public_html/story/important.html' are the same file

Yeah, the terminal is smart enough to detect what's happening.  Shouldn't
the File Manager be equally smart?

What happens with the Mac File Manager (aka, the Finder)?  It appears to
do nothing.  No messages about replacing files.  Just keeps things as they
should be.

As much as I love Linux, there are some ways that it's still clearly not
ready for prime time.

---

[1] I'm not positive we have the latest version of Debian, but we
have a relatively recent one.  I don't pay a lot of attention to how
we determine Linux versions, but our login screen reports that we have
"SMP Debian 4.9.65-3+deb9u2 (2018-01-04) x86_64"

[2] I provide those details so that it's clear that the issue may not
be with all versions of Linux or even Debian Linux.

[3] In reality, the directory was something like `April&August's Story`.
However, I cringe at file names with apostrophes and ampersands.  I
verified that those weren't the at play.

---

*Version 1.0 of 2018-07-28.*
