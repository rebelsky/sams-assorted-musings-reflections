Synchronizing stuff
===================

*Topics/tags: [The joy of code](index-joc), [overcommitment](index-overcommitment), Macbooks*

For better or for worse, I have three primary "machines" on which I work
[1].  My ["old" laptop](old-or-vintage) [2], my old, but slightly newer
laptop [4], and MathLAN, a conglomeration of real and virtual Linux
workstations that have a shared filesystem [5].  Like most people who have
multiple computers, I then have the problem of keeping track of where
things reside and of keeping certain things more-or-less in synch.

I store some common things in a Git repository.  For example, I have
a set of small scripts that I like available on an Unix-like operating
system I use.  But there are also things that I would prefer to have a
more limited scope or that only belong on my two MacBooks, such as my
`.bash_profile`.

Unfortunately, my organizational structure generally means that I don't
want the two machines to be exact clones of each other.  There's a lot
of cruft that gathers (e.g., screen shots) that I don't really need on
both machines.  The standard Apple tools also aren't much help; while I
can clone a full machine or account from one to another, Apple generally
assumes that one does that because one is getting rid of one computer
or the other.  I'm keeping both.  The "old" machine generally serves as
one I use when the other isn't working right, but there are times that
I want to use both simultaneously, such as when one gets used for
large-scale uploads or downloads [6].

Because I haven't set up a mechanism for keeping appropriate portions
in synch, I tend to stick with one laptop for way too long.  For example,
I've been using my "old" laptop since the beginning of summer, even though
it's been acting cranky at times.  I know I should switch to the "new" one,
but I worry that there are things that I need.

So it's come time to figure out the best way to synchronize appopriate
parts of the two.  Of course, I will also need to figure out what I mean
by appropriate parts.  That may be a separate musing.

Options: Hard drive (most secure; less useful if I've forgotten it).  Cloud 
(most transportable).  MathLAN (middle level of security, almost as accessible
as the Cloud).  Apple sharing.  But "Cloud" is not uniform.  There's Google.
There's iCloud.  There are Box and DropBox.  I could buy server space on AWS (too complex).

I'd like to be able to access the iCloud folder from terminal and see
it in my home directory.
Note: The iCloud drive folder is 
`~/Library/Mobile Documents/com~apple~CloudDocs/`.  So a soft link is
in order

    ln -s ~/Library/Moble\ Documents/com-apple-CloudDocs ~/iCloudDrive

For the `.bash_profile`, my strategy was: (a) enable iCloudDrive, (b)
move my `.bash_profile` to iCloud/bash_profile.  Create a soft link from
that file to `~/.bash_profile`.

---

[1] Read on to the next sentence to understand why I put "machines" in 
quotation marks.

[2] A mid-2012 MacBook Pro Retina with 8 GB of RAM, a 2.3 GHz Intel Core i7,
and a 256 GB hard drive.  It's currently running macOS Sierra [3].

[3] I tend to be conservative about upgrading operating systems.

[4] An early-2013 MacBook Pro Retina with 16 GB of RAM, a 2.4 GHz Intel
Core i7, and a 256 GB hard drive.  It's also currently running macOS
Sierra.  And it appears that it has a slightly nicer grpahics system
than the other MacBook Pro.

[5] Since MathLAN is a collection of almost-identically-configured
computers, I can treat each machine as the same.  But they are really
separate machines.  So I used "machine" as a compromise  in that early
sentence.

[6] More on those in a future musing.

---

*Version 0.1 of 2018-08-28.*
