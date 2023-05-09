---
title: CrashPlan and dotfiles
number: 1229
tags: [Rants](index-rants), technology
blurb: The first in a series
version: 1.0
released: 2023-05-08
current: 
---
_Warning!  This rant is technical in nature.  Not everyone will understand the details._

Recently, ITS installed [CrashPlan](https://www.crashplan.com/en-us/) on all of the faculty and staff laptops [1].  For those who've never heard of it, CrashPlan is cloud-based backup software [2].

For better or for worse, I'm one of those people who likes to play with the software that gets installed on my computer.  Although I back up my laptop regularly using Time Machine [3], there are times when having a different kind of backup might prove helpful.

One of the first things I noticed was that CrashPlan did not seem to list my dot files [4] and dot directories [5].  For those of you who don't use Unix-based systems, or don't delve deeply into them, dot files are hidden (or semi-hidden) files [6] that are typically used for configuration information.  In the macOS Finder, you can see them by hitting Shift-Command-Period.  In terminal applications, you can see them by adding the `-a` flag to the `ls` command, as in `ls -a`.

Here's what you see in my Finder window.  I've scrolled down to reach the files after the dotfiles in an alphabetical listing.

<img src="images/sample-finder-listing.png" width=600 alt="A Finder window.  We see a `.vim` folder, a `.viminfo` file, a `.vimrc`, a bunch more files starting with a period, `advisees.html`, an `Advising` folder, an `Applications` folder, and  more."/>

In contrast, here's what you see at the start of my CrashPlan listing.

<img src="images/sample-crashplan-listing.png" width=600 alt="A CrashPlan window.  We see it starting with `_BACKUPS-ARE-IN-HOME-SLASH-SSH`, then `advisees.html`, then an `Advising` folder, then an `Art` folder, then a `bin` folder, then a `Books` folder, and more.  Advising, Art, and Books have checkmarks next to them; the others do not."/>

You'll likely find yourself asking two things: _Where are the dot files?_ and _Why are some things checked and not others?_  At least I found myself asking those questions.  Or questions like them: _Where are the dot files?_, _Can I uncheck files?_, _Why aren't `Applications` and `bin` checked?_, and _Can I check those last two?_

Let's start with my last three questions.  Yes, I can uncheck files.  That's why we're not backing up my advisee list.  No, I can't check `Applications` or `bin`; they won't get backed up.  As to why ... ITS doesn't think that it's important to back those up.  More on that issue in a future musing.

What about the dot files?  What CrashPlan does with dotfiles is an important question, at least for me.  I have important settings in my dotfiles.  I also have some things in dot files, such as my ssh keys, that I'd prefer that ITS not copy. 

So, I followed a typical set of steps for finding an answer.  First, I did a Web search.  That was not successful.  Next, I submitted a ticket.  The first person to respond only knew CrashPlan on Windows, so they passed the question on to our remote CrashPlan Mac specialist.  They asked CrashPlan.  The folks at CrashPlan said (approximately), "The files are not being backed up; they would show a check box next to the files in Crashplan if they were being backed up."

That's good to know.  I worked out how to back up my dot files separately.  And it's comforting to know that ITS won't have easy access to all of them.

---

But something in the back of my head wanted to be sure [7].  So I ran an experiment [8].

First, I created a new directory.

```
$ cd
$ mkdir DotTest
$ cd DotTest
```

Then I created some files (both dot files and regular files).

```
$ echo "Foo" > .foo
$ echo "Bar" > .bar
$ echo "Baz" > baz
$ mkdir .quux
$ echo "Qux" > .quux/qux
```

After that, I told CrashPlan to back up the new directory.  After it did so, I verified that it had backed up the folder.  Of course, all CrashPlan showed in that folder was the `baz` file.

<img src="images/crashplan-dottest.png" width=600 alt="A screenshot from CrashPlan for `/Users/rebelskyDotTest`.  It shows only a file named `baz`, with a checkmark."/>

Next, I restored the `DotTest` directory to a new location (a folder named `Restore`).  Lo and behold, it contained the dot files and the dot directories.

<img src="images/finder-dottest.png" width=600 alt="A screenshot from the Finder for the folder `Restore`.  It contains the folder `DotTest`.  That folder contains a folder called `.quux` and files called `baz`, `.bar`, and `.foo`.  The `.quux` folder contains a file called `qux`.  Any file with a dot in front of it shows in a lighter grey color."/>

So, in spite of what Code42 says about CrashPlan, it *does* back up dot files; it just doesn't give you control over excluding them from backups or restoring them individually.  That's absolutely horrible UI design [9].

Why do we buy such poorly designed software? [11]

---

**_Postscript_**: Just in case it's not clear, my concern is with CrashPlan and not with ITS staff.  It's certainly not with the awesome person who has spent way too much time trying to help me figure out CrashPlan.

---

**_Postscript_**: I wonder if I can handle some of these issues with Preferences -> Backup Sets -> File Exclusions.  I suppose that's an experiment for another day.

---

[1] My broader thoughts on CrashPlan---as well as my adventures getting it installed on my laptop---are the subjects of a future musing.

[2] CrashPlan also supports local backups, but that's a topic for another day (or another musing).

[3] More precisely, I plug my laptop into my time machine drive every few days, and it backs up automatically.

[4] Sometimes written as "dotfiles".

[5] Does "dot files" include "dot directories"?

[6] Or directories.

[7] I have a muse that makes me write.  I have a muse or muse-like creature that makes me want to look at data.  I may also have a muse-like creature that makes me test or try to break technology.

[8] I originally wrote, "I ran a test".  However, I try to teach my students to limit their use of the word "test" to mean "code that tests a feature of the system and automatically reports success or failure".  Since I'm looking at the results, and I haven't automated the various steps, I'd call this an "experiment".

[9] Grammarly wants me to be less negative and use "That isn't very good UI design."  However, I am correct in saying that it's horrible.  I'll stick with that description [10].

[10] Amusingly, when I wrote "That isn't very good UI design" in the preceding endnote, Grammarly wanted to change "very good" to "perfect".  I'll agree that failing to list files is an imperfect design.

[11] Does anyone buy software anymore?  Perhaps I should write, "Why do we license such badly designed software?"
