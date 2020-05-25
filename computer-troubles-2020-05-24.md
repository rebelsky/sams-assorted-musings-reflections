---
title: Computer troubles
number: 1075
tags: [Rants](index-rants), rambly
blurb: Why are these things never easy?
version: 1.0
released: 2020-05-24 
current: 
---
*Warning: Most readers will likely find this musing pointless and
rambly.  Of course, that disclaimer may hold for all my musings.*

I had at least two other musings planned for today.  But neither got
finished.  To be honest, one didn't even really get started.  Why?
You should be able to tell from the title of this musing.  That's
right, I had computer troubles.

I'll admit that I can't quite recall when the problems started.  At
some point, my new old Macbook [1] seemed to have difficulty freeing
disk space.  Sometimes reboots would help.  Sometimes more space would 
just miraculously appear.  That is, I would empty the trash and reboot
and only a little more space would appear.  But if I waited an hour
or so, suddenly another 10 GB or so would be available.  It was a bit
of a pain, but the space eventually showed up.

And then, sometime last week, it stopped reappearing.  That Macbook
has a comparatively small disk, only 256 GB [2], and I usually have it
close to full.  But Macs don't work well when you have less than, say,
20 GB available and mine kept dropping below that level.  Disk Utility
reported some issues with broken partial Time-Machine backups stored
on the local disk, even immediately after a backup.

Oh, yeah, I forgot to mention.  Before things really started to go
sour (so last Wednesday or so), some other strange things started
to happen [3].  First, Excel wouldn't open.  I had no idea why other
than that it's a Microsoft product.  I don't necessarily blame 
Microsoft.  It could be that an Apple programmer decided that 
macOS should randomly refuse to start Microsoft products.  So I did
the only sensible thing, I re-downloaded Office for Mac and then
reinstalled it.  But it sat there saying "one minute to go" for an
hour or more.  I killed the process.  Or did I do a force shutdown?
I can't remember.  But whatever I did, it probably wasn't the best
idea.

It seemed like a good idea at the time.  When I moved Word and Excel
to the trash and then ran the installer again, it worked fine.  And
then I discovered the likely reason Excel wouldn't start.  While I
was testing out Microsoft Teams [4], I created another account on
Microsoft and that laptop was signed into that account.  But my
Microsoft products are registered to my personal rebelsky@grinnell.edu
account [5].  Sounds good, right?

But I couldn't fully delete the copies of Word and Excel in the trash,
even though new ones were now installed on my hard drive.  Almost
everything would go away, leaving one un-deletable, but with the
Mac reporting that it used no disk space.  Have I mentioned that I
hate computers?

At that point, it became clear that something else was going on.  Space
did not free up.  I ended up with about 4 GB left on the disk.  I deleted
another 12 GB or more.  Did the Mac notice?  Nope.  I tried Disk Utility.
It reported something wrong with my backups.  Oh, that's right.  I
mentioned that already.

Somewhere in that,, I figured out how to delete the local partial
backups (`diskutil apfs deletelocalsnapshots` or something like
that).  That didn't really help.  At some point, it seemed like
I couldn't even make Time Machine backups.  Or was that earlier?
It's a blur by now.

Okay, at that point I decided I needed to erase the disk and restore
it.  The most natural thing to do seemed to make a fresh copy of my
local drive and then copy back.  But Disk Utility didn't want to make a
copy.  That is, it tried, and then it gave up.  I then tried using the
TechTool Pro copy mechanism.  That also failed.  So I decided to boot
into Recovery mode and just use "restore from backup".  Can you guess
what happened?

That's right.  It failed, too.

On to more severe approaches involving external boot disks.  But I
didn't have a newish external boot disk.  I tried making one with
TechTool Pro.  That failed.  I tried downloading a new copy of the
macOS Catalina installer.  How, given that I only had 4 GB remaining?
Well, I do have a new Macbook.  But downloading a Catalina installer
on a Macbook 's harder than I expected, particularly since I
had to use the Mac app store.  Unfortunately, I turned away for a while 
and my Mac eventually decided that because already had the latest
version of Catalina, it could delete the installer.

What next?  Too many things.  I don't even want to try to enumerate them
all.  At some point, I had a lightweight Catalina installer working,
but it refused to install Catalina on my old Macbook because the
internal drive was not formatted as MacOS Extended (Journaled).
But it also wouldn't reformat it from apfs.  And it shouldn't.  When
I tried a partition on another drive, it reported that the partition
was MacOS Extended (Journaled) and needed to be apfs.

Eventually, I managed to download the full Catalina installer, create
an external boot disk, boot the new old Macbook from that boot disk,
erase the noM's disk (keeping it apfs), worry about why a newly-erased
disk seemed to have over 100 GB in use, erase it again, discover it
doesn't help, ignore the worry, run the installer, cross my fingers, 
create a new account, see if it starts and, if so, how much space
is available, discover that it's a lot, use Migration Assistant to
get all my applications, files, and settings back, discover that I
need to set new passwords for my family members' accounts, wait for
the files to restore, discover that I now have 70 GB left [6],
celebrate, and quit for the night.  Will I have to re-authorize
all my apps?  Probably.  But that's a task for another day.

That last paragraph represented most of Sunday.  Everything else?
Parts of Thursday, Friday, and Saturday, I think.  I did other
things while attempting all of these tasks.  After the four days,
in addition to a working Macbook (or so I hope), I also have a
Catalina startup disk and a downloaded Catalina installer (all 8
GB).  And, um, maybe I learned something.

Could I have written my other musings instead of this one?  Probably
not.  I wrote this one while watching a movie with my family [7].
One required deep concentration.  The other required me to listen
to some music.  Neither permitted much multitasking.  This one did
[9].  Of course, I did have to go back and check how much space was
available on the Macbook, but that only took a few minutes.  (It
wanted me to verify other things when I went back to it, so it wasn't
as quick a check as I expected.)

---

[1] The 2013 version with the broken "e" key.  Youngest now has my
old old Macbook, which has a working "e" key, but less memory.

[2] Have I mentioned how enthusiastic Michelle and I were when we
bought our first 100 MB drive back in 1988 or so?  If I recall
correctly, it cost more than $500.

[3] Those do not include me typing "strings" instead of "strange
things", although that happened just now.

[4] No, not teams of people at Microsoft.  The product that helps
support teams, or at least tries do.

[5] As opposed to my professional rebelsky@grinnell.edu.  Microsoft
products regularly ask me which account I intend o use.

[6] Not all of that is from the erase and reinstall process.  I also
skipped over the Macports stuff, since I'm using Homebrew now.

[7] Alice Wu's _The Half of It_ and not just because it name checks 
Grinnell [8].  Also not because she helped Vivek with his latest 
Speechless show.  But both things helped.

[8] Why does it name check Grinnell?  Probably something to do with the
connection that allowed Vivek to convince her to come on his show.  I
don't know the connection.

[9] It took about twice as much time to write because I was multitasking.
And it's likely less good than it would have been if I'd focused on
it.  Perhaps, then, I would have thought more about ordering or looked
at language.  As I've said all too often, "they can't all be gems".
