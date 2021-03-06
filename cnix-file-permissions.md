File permissions
================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

Unix systems were designed with the assumption that lots of people would
be working on the same system.  And, when multiple people work on the same
system, people may want to look at each other's files.  Good system designers
therefore include appropriate mechanisms for ensuring privacy.

In introducing Unix permissions, my graduate advisor used to say
"The Unix filesystem is like a file cabinet."  How would you interpret
that statement?  Well, this is what he meant: "By default, things are
unlocked unless you explicitly lock them."  That may seem strange, until
you realize that he kept file cabinets of papers that were unlocked so
that his graduate students could rummage [1] through them to find things
of interest [2].

In any case, you should assume that files are accessible unless you
explicitly make them inaccessible.  That's no longer true on most
Linux systems, but it's still better to be safe than sorry.  

So, what permissions does Linux let you set?  There are three basic categories
of permissions for each file and three sets of people for whom we set
permissions.  Let's look at them in reverse order.

The three sets of people are *user*, *group*, and *other*.  As you
might expect, the *user* is *you*, the person who owns the files.
The *group* is the set of people in your workgroup.  On some systems,
everyone is in one workgroup.  On others, you can be in multiple groups
[3].  We'll return to groups later.  And, as you might expect, *other*
represents everyone else.

The three categories are *read*, *write*, and *execute*.  For files,
they represent what you might think.  If a file has *read* permission,
you can look at its contents.  If a file has *write* permission, you 
can edit or change it.  If a file has *execute* permission, it's intended
to be a program (including shell scripts).

You can see the permissions associated with a file or directory by including 
the `-l` flag when you use `ls`.

    $ ls -lF
    total 28
    drwx-wx-wx 2 rebelsky mathfac 4096 Mar  2 21:07 dropbox/
    -rw-r--r-- 1 rebelsky mathfac   13 Mar  2 21:05 file1.txt
    drwx------ 2 rebelsky mathfac 4096 Mar  2 21:06 private/
    -rwxr-xr-x 1 rebelsky mathfac   26 Mar  2 21:05 program*
    drwxr-xr-x 2 rebelsky mathfac 4096 Mar  2 21:06 public/
    d--x--x--x 2 rebelsky mathfac 4096 Mar  2 21:09 semipublic/
    -rw-rw---- 1 rebelsky glimmer    7 Mar  2 21:07 shared.txt

You can see that the permissions are grouped into triplets, with
`r` representing "read", `w` representing "write", and `x`
representing "execute".  A dash means that the permission is not
active.  You can also see that directories have a `d` in the first
column.

Now, let's consider what the permissions might mean.  There are three
files: `file1.txt`, `program`, and `shared.txt`.  Because there
are `r`'s in all three entries, `file1.txt` can be read by everyone.
However, since there's only a `w` in the user section, I'm the only
one who can edit it.  In contrast, `shared.txt` cannot be read by
people not in the `glimmer` group, but can be both read and
written by anyone in that group.  Finally, `program` can be run
by everyone, but only changed by me.  (Note that it rarely makes sense
to have a file executable but not readable, since it's hard to
execute something you can't read.)

How do we change permissions?  With the `chmod` command [4,5].  When
calling `chmod`, you give the permissions you want and the files whose
mode you want to change [6].  Permissions can be specified numerically
or mnemonically [7].  For the mnemonic approach, specify three things:

* The people whose permission you want to change: `u`ser, `g`roup, `o`ther, or `a`ll.
* The change you want to make: `+` (add permission), `-` (remove permission),
  or `=` (set permissions).
* The permissions you want to change: `r`ead, `w`rite, or e`x`ecute.

Let's consider a few examples.  I generally won't bother to explain them.

    $ ls -lF file1.txt 
    -rw-r--r-- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt

    $ chmod g+w file1.txt
    $ ls -lF file1.txt 
    -rw-rw-r-- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt

    $ chmod a-rw file1.txt
    $ ls -lF file1.txt 
    ---------- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt
    $ more file1.txt 
    file1.txt: Permission denied

    $ chmod o+r file1.txt 
    $ ls -lF file1.txt 
    -------r-- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt
    $ more file1.txt 
    file1.txt: Permission denied

    $ chmod ug+rw file1.txt 
    $ ls -lF file1.txt 
    -rw-rw-r-- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt
    $ more file1.txt 
    Hello
    world.

    $ chmod g=x file1.txt
    $ ls -lF file1.txt 
    -rw---xr-- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt*

    $ chmod a=r file1.txt
    $ chmod u+w file1.txt
    $ ls -lF file1.txt 
    -rw-r--r-- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt

Note that if the *user* doesn't have read permission, they can't
read their own file, even if others can.  Note also that if anyone
can execute a file, `ls` marks it with a `*` to indicate that it
is executable.

You may recall that we noted that you need to be able to read a program
in order to execute it.  Let's check that claim.

    $ ls -lF program
    -rwxr-xr-x 1 rebelsky mathfac 26 Mar  2 21:05 program*
    $ ./program
    Hello

    $ chmod u-r program
    $ ls -lF program
    --wxr-xr-x 1 rebelsky mathfac 26 Mar  2 21:05 program*
    $ ./program
    /bin/bash: ./program: Permission denied

Okay, that's all well and good [8].  But if novices use mnemonics, what
do expert users use?  File permissions can be thought of as a sequence
of three octal values, with the user in the leftmost column, the group
in the middle column, and other in the rightmost column.  Read permission
has value 4.  Write permission has value 2.  Execute permission has
value 1.  You add the permissions up and use that number.

    $ chmod 700 program
    $ ls -lF program
    -rwx------ 1 rebelsky mathfac 26 Mar  2 21:05 program*

    $ chmod 555 program
    $ ls -lF program
    -r-xr-xr-x 1 rebelsky mathfac 26 Mar  2 21:05 program*

    $ chmod 755 program
    $ ls -lF program
    -rwxr-xr-x 1 rebelsky mathfac 26 Mar  2 21:05 program*

    $ chmod 000 file1.txt
    $ ls -lF file1.txt
    ---------- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt

    $ chmod 460 file1.txt
    $ ls -lF file1.txt
    -r--rw---- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt

    $ chmod 644 file1.txt
    $ ls -lF file1.txt
    -rw-r--r-- 1 rebelsky mathfac 13 Mar  2 21:05 file1.txt

Most Unix users make `755` their default mode for executables
and `644` their default mode for other files.

What about directories?  Do the `r`, `w`, and `x` have similar meanings
for directories?  Somewhat.  Read permission means that you can see what's
in the directory.  Write permission means that you can create files in
that directory.  Execute permission means that you can access files
in that directory.  Interestingly, if you have execute access to
a directory, but not read access, you can see only the files whose
name you know.

    $ ls -ldF public
    drwxr-xr-x 2 rebelsky mathfac 4096 Mar  2 21:40 public/
    $ ls public
    file1.txt  file2.txt
    $ ls -lF public
    total 4
    -rw-r--r-- 1 rebelsky mathfac 16 Mar  2 21:40 file1.txt
    -rw-r--r-- 1 rebelsky mathfac  0 Mar  2 21:40 file2.txt

    $ ls -ldF private
    drwx------ 2 rebelsky mathfac 4096 Mar  2 21:40 private/
    $ ls -lF private
    total 4
    -rw-r--r-- 1 rebelsky mathfac 16 Mar  2 21:40 file1.txt
    -rw-r--r-- 1 rebelsky mathfac  0 Mar  2 21:40 file2.txt
    $ ls -ldF private
    d--------- 2 rebelsky mathfac 4096 Mar  2 21:40 private/
    $ ls -lF private
    ls: cannot open directory private: Permission denied

    $ ls -ldF semipublic
    d--x--x--x 2 rebelsky mathfac 4096 Mar  2 21:09 semipublic/
    $ ls -lF semipublic
    ls: cannot open directory semipublic: Permission denied
    $ ls -lF semipublic/file1.txt
    -rw-r--r-- 1 rebelsky mathfac 16 Mar  2 21:09 semipublic/file1.txt
    $ cat semipublic/file1.txt
    This is file 1.
    $ ls -lF semipublic/file*.txt
    ls: cannot access semipublic/file*.txt: No such file or directory
    $ cat semipublic/file3.txt
    cat: semipublic/file3.txt: No such file or directory

    $ ls -ldF strange
    dr-------- 2 rebelsky mathfac 4096 Mar  2 21:49 strange/
    $ ls -lF strange
    ls: cannot access strange/file1.txt: Permission denied
    ls: cannot access strange/file2.txt: Permission denied
    total 0
    ?????????? ? ? ? ?            ? file1.txt
    ?????????? ? ? ? ?            ? file2.txt
    $ cat strange/file1.txt 
    cat: strange/file1.txt: Permission denied

    $ ls -ldF dropbox
    d-wx-wx-wx 2 rebelsky mathfac 4096 Mar  2 21:42 dropbox/
    $ ls -lF dropbox
    ls: cannot open directory dropbox: Permission denied
    $ ls -lF dropbox/newfile
    ls: cannot access dropbox/newfile: No such file or directory
    $ cat > dropbox/newfile
    Meow
    ^D
    $ ls -lF dropbox/newfile
    -rw-r--r-- 1 rebelsky mathfac 5 Mar  2 21:54 dropbox/newfile
    $ ls -lF dropbox
    ls: cannot open directory dropbox: Permission denied
    $ cat > dropbox/newfile
    -bash: dropbox/newfile: cannot overwrite existing file

Although we've explored a few strange directory permissions, you'll
generally focus on whether or not you want people to be able to read
files in the directory (both `r` and `x`) and whether or not you want
them to be able to create files in the directory (both `w` and `x`).

Are there other things you will eventually need to know about file
permissions?  Certainly.  Should what we've covered suffice for now?  
Most certainly.

---

[1] Is "rummage" the right word?  Maybe "riffle"?  Maybe "look"?

[2] Yes, this was before the days of a large Interweb; we often relied 
on actual paper for the papers we read.

[3] On MathLAN, I'm in a bunch of groups.

    $ groups
    mathfac users wireshark sudo pg_omar pg_us pg_bob hyper csc362 blazers games networks glimmer cvs card statsgames csc325

It appears that groups live more or less forver.  `blazers` is the
trailblazers group that included the legendary [Rachel Rose '01](rachel-rose)
and probably got formed in 1998 or so.  The `pg_*` groups are project
groups from some time period.  The `mathfac` group is all faculty.

[4] `chmod` is often pronounced "see aitch mod" or "chuh mod".  

[5] It is so named because it *ch*anges file *mod*es.

[6] Yes, you can change permissions for more than one file at a time.

[7] No, not daemonically.

[8] Or perhaps not.

---

*Version 1.0 of 2017-03-02.*
