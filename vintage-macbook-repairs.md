Repairing my "vintage" MacBook
==============================

Some time in the past week, my "[vintage](old-or-vintage-macbook) MacBook"
dedided to start acting up.  What do I mean by that?  Well, when I closed
the lid, and then opened it again an hour later, it wouldn't restart.
And, once or twice, it seemed to restart on its own.  So I attempted to
diagnose and repair the problem.  This musing represents a log of the
things I tried in attempting to deal with the problem.

I observed that I had relatively little free space left on the disk,
10 GB, more or less.  That made me worry; I know that odd things happen
when disk space gets low and that the Mac likes to save memory to disk
when the lid is closed.  I didn't have much obvious that I could clean off,
so I tried a different approach: I erased the main drive and restored
from a backup.  That certainly worked in terms of freeing up space.
I now have about 36 GB free.  But it makes me wonder what and where
the cruft had accumulated.

Unfortunately, that did not solve the problem.  After that update, it
started freezing about half the time during the boot process, stopping
partway through that process.  (Essentially halfway.)

Resetting the PRAM (reboot with Command-Option-P-R) solves the problem
once in a while, but not always.  And then I have to reset it again to make
any progress.

Starting in [diagnostic mode](https://support.apple.com/en-us/HT201257)
(hold down D while starting; no command key) shows no errors, at least
not with the simple test.  (I'm leaving the more complex test for later.)

Starting in verbose mode (Command-V) freezes.  I should log some of those.

Starting in safe mode (Shift) works, although the screen has some
interesting update issues (that is, update is slow).

Malwarebytes does not find any Malware.

What about [resetting the SMC](https://support.apple.com/en-us/HT201295)?
Let's see Shift-Control-Option-Power for ten seconds.  Nope, that
doesn't do it either.

Let's try the more sophisticated diagnostic test.  (That is, Apple Hardware
Test with "Perform extended testing" check.)  It identifies no errors.

Boot into recover mode and try Disk Utility.  No issues.

I thought I'd try installing a new OS.  I'm still running Sierra, so I 
could upgrade
to High Sierra, right?  Let's see ... how do I erase and install
without booting?  THat's right, I start in [Recovery Mode](https://support.apple.com/en-us/HT204904), Command-R.  I've downloaded High Sierra and it should
be straightforward.

I was wrong.  It appears that if you boot into recovery mode, it can
only download the OS that was last on there.  I *think* it even had
to download it from the Interweb.  (I left it running while I went
off to do other things.)

installed sierra.  looked good  but no.  froze at screensaver  And
wouldn't successfully reboot.

Next attempt: Completely erase and then re-install OS.  But that
requires that I can boot it at all.

Suspect video card.
