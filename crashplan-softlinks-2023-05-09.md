---
title: CrashPlan and relative soft links
number: 1230
tags: [Rants](index-rants), technology
blurb: The second in a series.
version: 0.1
released: 2023-05-09
current: 2023-05-07
---
_Warning: This rant is on technical issues.  It may not be accessible to all ofmy readers._

As you may have learned in [my prior musing](crashplan-dotfiles-2023-05-08), Grinnell is now using CrashPlan to back up staff and faculty laptops.  Since I've learned that CrashPlan provides incorrect information about how they handle dot files, that voice in the back of my head wants me to consider other aspects.

The next issue that came to mind was symbolic links.  What are symbolic links?  They are a kind of alias.  If file `bar` is a symbolic link to `foo`, each time one looks at `bar`, they see the contents of `foo`.  If `baz` is a symbolic link to directory `qux`, whenever we save files to `baz`, they get saved to `qux`, and vice versa.

There are lots of reasons to use soft links.  I'm not getting into most of them here.  But one reason is particularly relevant: It helps me keep dotfiles private.  We're told that [CrashPlan doesn't back up the targets of aliases](https://support.code42.com/Incydr/Agent/Configuring/How_to_use_soft_and_hard_links_with_the_Code42_agent).  If I put files I don't want backed in a directory, and then soft link to them from my main directory, they should work as expected, but not get backed up.

Here's what [the documentation](https://support.code42.com/Incydr/Agent/Configuring/How_to_use_soft_and_hard_links_with_the_Code42_agent) says,

* The Code42 agent backs up soft links, but not the target of the soft link. If you back up a soft link with the Code42 agent, be aware that only the link is backed up—not the target file.
* Soft links can link to files with relative paths or absolute paths. When you download a soft link, it is downloaded in the same state it was backed up in (relative or absolute). It is possible to download a soft link and its target in such a way that the link does not accurately point to the target.

As I said, I like to check things.  So let's go for it.

First, I set up a test directory (in my case, /Users/rebelskyAliasTest), add some directories, files, and soft links.

```
$ cd
$ mkdir AliasTest
$ cd AliasTest
$ mkdir dir
$ mkdir dir/subdir
$ echo "File One" > dir/file1.txt
$ echo "File Two" > dir/subdir/file2.txt
$ ln -s dir/file1.txt   # Creates a link from file1.txt to dir/file1.txt
$ ln -s dir/subdir/     # Creates a link from subdir to dir/subdir.
$ ln -s subdir/file2.txt# Creates a link file2.txt to dir/subdir/file2.txt 
```

Next, I check to see that things are as expected.

```
$ ls
dir file1.txt file2.txt subdir  # We have the files I expect
$ cat file1.txt                 # Does the link work?
File One
$ cat file2.txt                 # Does the link work?
File Two
$ file *                        # Checking how they are "typed"
dir: dir
file1.txt: ASCII text
file2.txt: ASCII text
subdir: dir
$ ls -l                         # Look at details of the links
total 0
drwxr-xr-x 4 rebelsky staff 128 May 5 14:49 dir
lrwxr-xr-x 1 rebelsky staff 19 May 5 14:49 file1.txt -> dir/file1.txt
lrwxr-xr-x 1 rebelsky staff 16 May 5 14:50 file2.txt -> subdir/file2.txt
lrwxr-xr-x 1 rebelsky staff 17 May 5 14:50 subdir -> dir/subdir/
```

Everything looks good.

So, let's see what CrashPlan does.

First, I get CrashPlan to back up the dir.

Next, I restore to a separate restore dir (in my case, `/Users/Rebelsky/Restore/AliasTest`) and then check to see if the files are as expected.

```
$ cd
$ cd Restore/AliasTest/
$ ls
dir file1.txt file2.txt subdir          # The same files as before
$ cat file1.txt
cat: file1.txt: No such file or dir 
$ cat file2.txt
cat: file2.txt: No such file or dir
```

Things are already looking bad.  `file1.txt` and `file2.txt` don't seem to link correctly.  The "No such file or dir" error is a bit confusing, since we see `file1.txt` and `file2.txt`, but the error is about the file they link to.

Where do those links point?

```
$ file *
dir: dir
file1.txt: broken symbolic link to /Applications/CrashPlan.app/Contents/Library/LaunchServices/CrashPlanService.app/Contents/MacOS/dir/file1.txt
file2.txt: broken symbolic link to /Applications/CrashPlan.app/Contents/Library/LaunchServices/CrashPlanService.app/Contents/MacOS/subdir/file2.txt
subdir: broken symbolic link to /Applications/CrashPlan.app/Contents/Library/LaunchServices/CrashPlanService.app/Contents/MacOS/dir/subdir
$ ls -l
total 0
drwxr-xr-x 4 rebelsky staff 128 May 5 14:52 dir
lrwxr-xr-x 1 rebelsky staff 115 May 5 14:49 file1.txt -> /Applications/CrashPlan.app/Contents/Library/LaunchServices/CrashPlanService.app/Contents/MacOS/dir/file1.txt
lrwxr-xr-x 1 rebelsky staff 112 May 5 14:50 file2.txt -> /Applications/CrashPlan.app/Contents/Library/LaunchServices/CrashPlanService.app/Contents/MacOS/subdir/file2.txt
lrwxr-xr-x 1 rebelsky staff 112 May 5 14:50 subdir -> /Applications/CrashPlan.app/Contents/Library/LaunchServices/CrashPlanService.app/Contents/MacOS/dir/subdir
```

Those are very strange targets.  It appears that CrashPlan does *not* correctly back up symbolic links, at least not relative symbolic links.

Strike two.  At least I'm not relying on CrashPlan for backups.

----

**_Postscript_**: Note that this rant is only about the bad design of CrashPlan.  You'll note that I haven't mentioned ITS at all.  A colleague told me that symbolic links are particularly complicated.  However, I know that Time Machine deals correctly with them, as does `rsync`.
