Repairing my "vintage" MacBook
==============================

Some time in the past two weeks, my "[vintage](old-or-vintage-macbook)
MacBook" decided to start acting up.  What do I mean by that?  Well,
when I closed the lid, and then opened it again an hour later, it
wouldn't restart.  And, once or twice, it seemed to restart on its own.
So I attempted to diagnose and repair the problem.  This musing represents
a log of the things I tried in attempting to deal with the problem.

I observed that I had relatively little free space left on the disk,
10 GB, more or less.  That made me worry; I know that odd things happen
when disk space gets low and that the Mac likes to save what's in RAM to
disk when the lid is closed.  I didn't have much obvious that I could
clean off, so I tried a different approach: I erased the main drive
and restored from a backup.  That certainly worked in terms of freeing
up space.  After that, I had 36 GB free.  But it made me wonder what
and where the cruft had accumulated.

Unfortunately, that did not solve the problem.  After that update, it
started freezing about half the time during the boot process, stopping
partway through that process.  

Resetting the PRAM (reboot with Command-Option-P-R) solved the problem
once in a while, but not always.  And then I had to reset it again to make
any progress.

Starting in [diagnostic mode](https://support.apple.com/en-us/HT201257)
(hold down D while starting; no command key) showed no errors, at least
not with the simple test.  A letter start in diagnostic mode with the 
full test also showed no errors.

Starting in verbose mode (Command-V) freezes.  I should have logged
some of the message, but decided to put that on hold while I did other
things.

Starting in safe mode (Shift) seemed to work, although the screen has some
interesting update issues (that is, update is slow).

Malwarebytes does not find any Malware.

What about [resetting the SMC](https://support.apple.com/en-us/HT201295)?
To do that, one holds Shift-Control-Option-Power for ten seconds.  Nope,
that didn't do it either.

I booted into recovery mode and tried using Disk Utility.  It revealed
no issues.

I thought I'd try installing a new OS.  I'm still running Sierra, so I
could upgrade to High Sierra, right?  My first task was to figure out
how I install a new OS without booting.  I thought I should start in
[Recovery Mode](https://support.apple.com/en-us/HT204904) (Command-R).
I'd downloaded High Sierra and thought it would be straightforward.
I was wrong.  It appears that if you boot into recovery mode, it can
only download the OS that was last on there.  I *think* it even had
to download it from the Interweb.  (I left it running while I went
off to do other things.)

Finally, Sierra installed.  I thought things looked good.  But no; it
froze on the screensaver.  And then it would not reboot.

My next attempt: I decided to completely erase the disk and then re-install 
the OS.  But it turns out that you can't install an OS on an external disk
on one computer and then boot from it on another, or at least I couldn't.
So I made [a bootable installer](https://support.apple.com/en-us/HT201372).
Booting from that required starting with the option key down.

Did it work?  It seemed to.  But the computer froze as soon as a I
started an application.

I won't detail the rest of the week of things I tried.  Eventually, I gave
up and brought it to a Mac repair center.  Their comment "Those machines
have a video chip that tends to blow out.  Apple used to have a free
repair program, but that's over now.  We'll check it out."  A day later:
"Yup, you need a new motherboard.  With labor and tax, it will be $800."

My first question: "Can you really get a motherboard for one these?
Isn't it 'vintage'?"  Their answer: "You better hope not.  Let's see
... Yes, we can get a new motherboad.  If it were vintage, you probably
wouldn't be able to get one."

My next question: "As long as I'm replacing the motherboard, can I get
one with 16GB of RAM rather than 8GB"?  Their answer: "In that case,
it doesn't count as a trade-in, so it would be $1500, rather than $800."

So now I'm left to decide: Do I want to get an official replacement,
do I want to try to find someone else to replace the motherboard,
do I want to get rid of it [1], or do I want to wait until my other
laptop dies [2] to make a decision?  If I get rid of it, do I plan to
buy a used replacement (about $1100 for a new model with 16GB RAM on
eBay, plus another $270 for a two-year warranty) or a new one (about
$2249 in the base configuration or $2789 in my preferred configuration
[3], plus another $303 for AppleCare, plus some amount for all the
new cords I'll need)?  Or is it time to give up on Macs altogether,
and build my own Linux laptop?  I'm not thrilled with Apple's
"[Recycling](https://motherboard.vice.com/en_us/article/yp73jw/apple-recycling-iphones-macbooks)".

Buying used worries me.  I know that mine has a relatively new battery and
a screen that is free from blemishes.  I've kept the case in good condition,
except for the wrist rest where my watch scraped it a bit.

If I wait until my newer laptop dies, will Apple still have a replacement
motherboard for this one?  Even if it's not vintage, it's pretty close.
Apple has already said that if I try to trade it in, they'll just scrap
it, so I think we're getting close

Decisions, decisions.

---

[1] Given [my experience over the past year](checking-my-mac-2018-03-21), that's
likley to happen sooner, rather than later.

[2] Well, donate it to the CS department's museum.

[3] 32GB of RAM, 512GB flash drive.  Maxing out the RAM tends to give
me more long-term use.

---

*Version 0.9 of 2018-09-20.*
