Cleaning up my hard drive
=========================

*Topics/tags: [Miscellaneous](index-misc), organization, Mac*

macOS Mojave just came out.  I was toying with the idea of upgrading
to Mojave.  Why?  I'm not entirely sure.  I've been happy with Sierra
and never bothered to upgrade to High Sierra.  But Mojave seems to have
some cool new features, such as Dark Mode [1].  But that's not the
subject of this musing.

In preparing for a potential upgrade, I decided that it would be
a good idea to start cleaning up my internal hard drive [2].  Now,
a complete re-organization of my hard drive is likely to be a long
and arduous task.  I don't do very well at keeping my digital life
organized.  But I can try to get rid of some cruft.  Rocket Yard has [some
tips](https://blog.macsales.com/44433-tech-101-how-to-free-up-mac-storage-space).
One of the more important tips is to use
[OmniDiskSweeper](https://www.omnigroup.com/more) to identify some of
the high-usage spots on the disk [3].  The UI is pretty simple; here's
a screenshot from *after* I'd done some of my cleanup.

<img width="400" src="images/OmniDiskSweeper-2018-09-28" alt='A four-column window.  The first column is labeled with a slash.  The second column is labeled "Users".  The third column is labeled "rebelsky".  And the fourth is labeled "Google Drive".  The first column indicates that Users uses 96.7 GB of data, that Applications use 38.5 GB of data, and so on and so forth.  "Users" is highlighted.  The second column indicates that "rebelsky" uses 96.7 GB of data; "rebelsky" is highlighted.  The third column indicates that Library uses 40.8 GB, that Desktop uses 11.2 GB, that Pictures uses 10.4 GB, that Google Drive uses 5.4 GB, and so on and so forth.  "Google Drive" is highlighted.  The fourth column indicates that Glimmer Camps use 4.5 GB and also provides information about a variety of other things.'>

Here's some of what I discovered as I explored my disk usage.

I still had a VM [4] from the old 151.  I hope to never use a VM in 151
again.  That's 9 GB to free up immediately.  Of course, after erasing
it, I said to myself "Hmmm ... I wonder if I had anything on that particular
machine; I should have checked."  Fortunately, it's stored away on my
Time Machine backup if I ever need it [5]. 

I also have a VM from the old CS 50 when I was using it for an
experimental "online learning" course.  I haven't touched that in three
and a half years.  That can go.  I'm not even sure it's worth coping
out of time machine.

Adobe has been taking up a lot of space, not only in
m;y Applications folder (6.4 GB, most of which is my old
CS 6 suite) but also in `/Library/Application Support`
(another 2 GB).  The latter has cruft from way too many
old versions of Adobe software.  [Even Adobe tells me to clean it
out](https://helpx.adobe.com/x-productkb/global/delete-previously-installed-application-files.html).
So I'm removing all of my Adobe stuff and starting from scratch with my
[obscenely cheap Adobe Creative Cloud license](software-overprivileges).

Looking in the Library, I discovered that I set my cache for Amazon Music
much too large.  I don't need to store all of my recent streams, so
I dropped that to 1GB.  I also seemed to have about 5 GB of Amazon music
presumably from when I was doing [the big download](amazon-music-storage).
But most of that music is on an external drive.  Is it a duplicate?  Yup,
it appears to be a duplicate.  That can go.

What about the applications?  I've already cleared out
the Adobe products and installed Photoshop CC.  That's the
biggest disk hog.  But why is Microsoft Word 2.3 GB?  Microsoft
Office 2011 was under 1.5 GB for all of the applications.  [I found one
answer](https://www.quora.com/Why-is-the-size-of-Office-2016-for-Mac-so-large-compared-to-the-2011-edition):
It stores its own copy of things like Fonts, rather than relying on the
Mac system.

Other ways I can tell that I don't clean through my disk very often.
It appears I got a USB stick in from Sun in 2010 [6] and immediately
copied everything to my Mac, including a version of Alice 3 for Windows.
I'm pretty sure that I didn't touch any of those files since 2010.
That's another 1.8 GB to free up.

Here's a strange thing, at least from my perspective: I seem to have
Anaconda Navigator in my home directory.  As far as I can tell, it's
a helpful container for Python applications.  Why didn't I put it in
applications?  I'm not sure.  In any case, I probably installed it when
I was playing with the design of a data science course.  But I don't
need it right now; I can trash it.

Why is Google Drive taking up over 5 GB when I try to limit the amount
I automatically copy from Google Drive to my laptop?  Ah, I see.  It's
almost all from the summer code camps.  But what in the summer camps?
The 2016 summer camp only required 57.4 MB of disk space; the 2017 camp
requires 4.4 GB.  It appears that we decided to add photos to
the rest of the camp materials.  I can edit the preferences for Backup
and Sync from Google [6] to ignore the photo folders.

I was surprised to discover that a folder called "UDL Workshop 2017" was
occupying a large amount of space.  It turns out that I'd downloaded
ISOs for two different accessible Linux installations while at the workshop.
I don't think I've played with either of them since.  And they've almost
certainly been upgraded since them.  They can go away, too.

I'm amazed at how much is hidden away in the Library folder.  There's
something called Suggestions which occupies 1.9 GB, most in a folder
called "pending".  A Web search reveals very little about that folder,
or even whether it's safe to delete it.  I have 3.0 GB of Caches and
6.4 of Application Support.  Firefox occupies 1.1 GB of the caches, and
CoverScout 3 is using an astounding 1.7 GB of space under application
support.  I don't know how much of that is necessary; I'll clear those
out some other time.

I see from the image above that I have a `.android` folder.  It appears
that's from 2015, when I was using Android Studio.  I'm not sure whether
or not I need to keep the keys that live in that folder, which means that
I'm going to keep them.  But I can certainly clear out the cache.

After all that work, I now have nearly 69 GB free.  Given that I use a
256 GB SSD that is traditionally close to capacity, that's pretty good.
I'll think about upgrading to Mojave another day.

I wonder if I'll ever get everything organized and indexed.

---

[1] It's rare, but once in a while, I'm a sucker for silly UI things.

[2] It's really an SSD.  I'm just accustomed to referring to my internal
drive as a hard drive.

[3] Yes, I know that I could use `du` on the command line.  OmniDiskSweeper
has a friendlier UI and gathers all the data in one spot.

[4] Virtual Machine.

[5] Time Machine does eventually clear out old backups.  Maybe I should
copy it out of that backup, just in case.

[6] Back when Sun still existed.

[7] I did not name the application.  Why can't they call it "Google Drive"?

---

*Version 1.0 of 2018-09-28.*
