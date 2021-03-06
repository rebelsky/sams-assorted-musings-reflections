Surface problems
================

I've been a Mac user for about as long as there have been Macs.  While I
never owned a 128K [1], Michelle and I bought a 512Ke or a Plus together
[2].  I've also been a Unix user for about the same amount of time,
since one of the systems I used as an undergraduate was a Unix system
[3].  In the early days of the Macintosh, I found them superior for
many reasons, not least because there was an assumption that programs
would have a uniform user interface - you knew you'd have a File menu,
an Edit menu, a Help menu, and so on and so forth.  Printer drivers have
to follow a particular contract.  In contrast, it often felt like you
were learning a new UI for every DOS and Windows program.  I liked Unix
because I subscribe to many aspects of the Unix philosophy and because
I'm a programmer.

I was ecstatic when Apple decided to rework their operating system to
use a Unix core.  That meant I could use the convenient and consistent [5]
user interface for everyday work and drop down to the shell when I wanted
to automate tasks or be more efficient.

Since I had systems that worked fine, I generally did not worry about
Microsoft Windows.  I did my best to help Michelle when she had problems
with her machines [6], but it was a struggle because I'm not familiar with
the whole Windows ecosystem of registries and the ilk [7].

So, when I saw a refurbished Surface tablet, including keyboard, for $100
[8], I bit.  It seemed like an opportunity to learn a bit more about
Windows while playing with a tablet.  While an iPad is probably more to
my liking, the $100 was pretty cheap and worth a try.  It took a bit to
get used to the very different UI, but I've figured it out.  And the
display is really nice.

But the past two days have made me want to defenestrate the damn thing.
What happened?  I decided to install a new piece of software. I went
to the Microsoft store and clicked "Install".  After a few minutes,
I got an error message that my network connection was not fast enough.
That seemed strange, so I checked out network speed on both my Mac and
the Surface.  Both seemed to show reasonable download speeds.  So I did a
Web search.  There was a recommendation to run Windows Update.  I tried.
After thirty minutes of waiting for it to decide if it needed updates,
I gave up [9].  I refreshed the damn thing, which I think is supposed to
drop everything.  I then went back to run Windows Update.  It again took
awhile to check for updates, but at least it found some (60-some-odd)
[10].  I installed those updates.  I checked again.  It took awhile to
check, but found more updates (20-some-odd).  I installed those updates.
I installed a few more optional updates that appeared.  And I checked
again.  I waited overnight for it to finish checking.  It never finished.

So I again did a Web search for what to do when Windows Update doesn't
work.  I discovered the Windows Update Troubleshooter.  I ran that.  I
got the following message.

> **_Troubleshooting has completed_**

> The troubleshooter made some changes to your system.  Try attempting the
task you were trying to do before.

> **Problems Found**

> * Potential Windows Update Database error detected 0x80070490 - Fixed

> * Windows Update components must be repaired - Fixed

I rebooted the computer.  I tried installing software.  Same problem.
I tried running the Troubleshooter again.  It gave the same message.
I tried running the Troubleshooter again.  It gave the same message.
Clearly, the Troubleshooter's aim is off, so I did another Web search.

There was some advice that I try a clean boot, so I followed the
[instructions from Microsoft support](https://support.microsoft.com/en-us/help/929135/how-to-perform-a-clean-boot-in-windows).  First, I should turn off
the non-Microsoft services.  Nope, there are none.  Next, I should turn
off all startup items.  Nope, there are none.  In any case, the clean
boot did not make a difference.

What next?  It sounds like it's time to enter the command line.  Let's
see ... the advice is to type

> `DISM.exe /Online /Cleanup-image /Scanhealth`

Unfortunately, that freezes at 20%.  Another quick Web search reveals that
lots of other people have the same problem.  What to do?  What to do?

At this point, here are the plans I came up with.

* Refresh the thing again.
* Run the Troubleshooter.  There should not be any problems, since I've
  just refreshed the damn thing [11].
* Install the first set of updates [14].
* Run the Troubleshooter.  Hope that there are not any problems [15].
* Install the next set of updates.
* Run the Troubleshooter.  Hope that there are not any problems [16].
* Install the next set of updates and hope that it doesn't sit there
  trying to figure out what to do [17].
   
I'd almost understand the need to do all of this on a machine that had
lots of additional software installed [18].  But it makes no sense on a
machine that has essentially nothing extra.

Please explain to me again why people use Windows?

---

[1] Yes, that's right.  The first Mac had 128 _kilobytes_ of memory.
It had no hard drive, and only one floppy drive that held 400K disks.

[2] I really don't remember which we bought.  All I remember is that we 
had different opinions about it.

[3] The campus also had a Vax running Tops-20, which was my primary
computer system, and a giant IBM mainframe clone running whatever
IBM mainframes ran at the time [4].

[4] All I remember is that I had to learn JCL to use the thing.

[5] Less so these days.

[6] Michelle also prefers Macs.  

[7] Yes, "ilk" is a word and not a typo.  It means "of the same sort".

[8] 2 gigabytes of RAM, about 24 gigabytes of flash storage, around 6.5x10",
includes the Office suite.

[9] No, that's not 30 minutes of updating.  That's 30 minutes of "Checking
for Updates".

[10] When my Mac has that many updates to install, Apple has generally
provided one compound package that includes them all.  It seems much
more convenient.

[11] I was wrong.  There were problems even on a refreshed machines with
no updates installed.  But at least it let me install software [12].

[12] More precisely, it let me install software before I installed the
updates.

[14] This time, it didn't give me a count.

[15] Of course there were.  There were problems before I ran the updates.

[16] You know the answer.

[17] It seemed to take forever.  But I left the tablet alone for a few
days, and it seems to finally found an update to install.

[18] That's not really true.  Installed software should not interfere with
the update process.  Installed software should not make it impossible
to install other software, except when (a) it is something like a
virus protection product that is intended to prevent the installation
of certain kinds of software or (b) the software to be installed relies
on a newer [19] version of some already installed software.

[19] or older.

---

*Version 1.0 of 2017-07-05.*
