Repairing my "vintage" MacBook
==============================

*Topics/tags: [Miscellaneous](index-misc), Mac, rambly*

Sometime in the past few weeks, my "[vintage](old-or-vintage-macbook)
MacBook" decided to start acting up.  What do I mean by that?  Well, when
I closed the lid, and then opened it again an hour later, it would not
return to the active state and needed to be restarted.  Once or twice,
it seemed to restart on its own.  As is my wont, I attempted to diagnose
and repair the problem.  This musing represents a log of the things I
tried in attempting to deal with the problem.

I first observed that I had relatively little free space left on the
disk, 10 GB, more or less.  That made me worry; I know that odd things
happen when disk space gets low and that the Mac likes to save what's
in RAM to disk when the lid is closed.  I didn't have much obvious that
I could clean off, so I tried a different approach: I erased the primary
drive and restored from a backup.  That certainly worked to free up space.
After erasing and restoring, I had 36 GB free.  But it made me wonder
what and where the cruft had accumulated [1].

Unfortunately, that did not solve the problem.  After that update, it
started freezing about half the time during the boot process, stopping
partway through that process.  

Resetting the PRAM (reboot with Command-Option-P-R) solved the problem
once in a while, but not always.  And then I had to reset it again to make
any progress.

Starting in [diagnostic mode](https://support.apple.com/en-us/HT201257)
(hold down D while starting; no command key) showed no errors, at least
not with the simple test.  A subsequent start in diagnostic mode with the
full test also showed no errors.

Starting in [verbose mode](https://support.apple.com/en-us/HT201573)
(Command-V) ended up with the computer freezing midway through.  I should
have logged some of the messages, but decided to put that on hold while
I did other things.

Starting in [safe mode](https://support.apple.com/en-us/HT201262) (Shift)
seemed to work, although the screen does not update in a way that I'd
expect.  In particular, it updates slowly.

I did eventually get it to start.  At that point, I checked for Malware.
Malwarebytes did not find any Malware.

What about [resetting the SMC](https://support.apple.com/en-us/HT201295)?
To do that, one holds Shift-Control-Option-Power for ten seconds.  Nope,
that didn't do it either.

The next step?  I booted into [recovery
mode](https://support.apple.com/en-us/HT201314) (Command R) and tried using Disk
Utility.  It revealed no issues.

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

My next attempt: I decided to erase the disk completely and then
re-install the OS.  But it turns out that you can't install
an OS on an external drive on one computer and then boot from
it on another, or at least I couldn't.  So I made [a bootable
installer](https://support.apple.com/en-us/HT201372).  Booting from that
installer required starting the Mac with the option key down.

Did it work?  It seemed to.  But the computer froze as soon as I
started an application.

I won't detail the rest of the week of things I tried.  Nothing was ever
wholly successful.  Sometimes, I'd get all the way to my Desktop, only
to find that applications froze.  Sometimes, I'd have trouble getting even
that far.

---

Eventually, I gave up and brought it to a Mac repair center.
Their comment "Those machines have a video chip that tends to blow
out.  Apple used to have a free repair program, but that's over now.
We'll check it out."  A day later: "Yup, you need a new motherboard.
With labor and tax, it will be $800."

My first question: "Can you really get a motherboard for one of these?
Isn't it 'vintage'?"  Their answer: "You'd better hope not.  If it is,
you probably won't be able to get one.  Let me check again.  Nope,
it's not.  We *can* get a new motherboard."

My next question: "As long as I'm replacing the motherboard, can I get
one with 16GB of RAM rather than 8GB"?  Their answer: "In that case,
it counts as an upgrade, rather than a repair, and so it would be $1500,
rather than $800."  Nope, that's not worth it.

So now I'm left to decide: Do I want to get an official replacement,
do I want to try to find someone else to replace the motherboard,
do I want to get rid of it [2], or do I want to wait until my other
laptop dies [3] to make a decision?  

I'm fortunate that our financial state is such that cost is not the
primary driving factor.  That doesn't mean that it's not a factor.  But
I can afford to pay for the repair without worrying about its effect on
my ability to feed, clothe, or get medical treatment for my family.

Some of those decisions require subsequent decisions.  For example,
if I get rid of it, do I plan to buy a used replacement (about
$1100 for a slightly newer model with 16GB RAM on eBay, plus
another $270 for a two-year warranty) or a new one (about $2249
in the base configuration or $2789 in my preferred configuration
[4], plus another $303 for AppleCare, plus some amount for
all the new cords I'll need)?  Or is it time to give up on Macs
altogether, and set up my own Linux laptop?  I'm not thrilled with Apple's
"[Recycling](https://motherboard.vice.com/en_us/article/yp73jw/apple-recycling-iphones-macbooks)",
so that last option is tempting.

Getting someone else to repair it appears to be a lot of trouble,
and used motherboards are still over $400, at least at first glance.
Buying another used computer worries me.  I know that mine has a
relatively new battery and a screen that is free from blemishes.
I've also kept the case in good condition, except for the wrist rest
where my watch scraped it a bit.  It's harder to tell about battery life
and screens for used ones, especially used ones purchased online [5].

If I wait until my newer laptop dies, will Apple still have a replacement
motherboard for this one?  Even if it's not vintage, it's pretty close.
Apple has already said that if I try to trade it in, they'll just scrap
it, so I think we're getting close to the end of its effective lifetime.
I think I can discard that option.  I should either fix it now or assume
that I won't be able to fix it in the future.

What about switching?  I like Linux.  But switching to a Linux laptop for
my daily use is going to require a decent amount of overhead.  I've spent
enough time configuring my Mac and getting used to a wide variety of
applications that I'm comfortable with the current environment.
Yes, I realize that much of my work happens in Terminal, a Web browser,
DrRacket, or my mail application, and that three of those are essentially
equivalent on a Linux box.  But there are a lot of smaller tasks that
have come to rely on other applications.

What to do?  Decisions, decisions.

---

[1] No, I did not figure it out.  It's yet another task for another day.

[2] Given [my experience over the past year](checking-my-mac-2018-03-21),
that's likely to happen sooner, rather than later.

[3] Well, donate it to the CS department's museum.

[4] 32GB of RAM, 512GB flash drive.  Maxing out the RAM tends to give
me more long-term use.

[5] Since I live in the middle of Iowa, there aren't many places to
purchase used MacBooks face to face.

---

*Version 1.0 of 2018-09-24.*
