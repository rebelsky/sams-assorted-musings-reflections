---
title: Planning to crash
number: 1231
tags: [Rants](index-rants), technology
blurb: The third in a series.  Perhaps the last in the series.
version: 1.0
released: 2023-05-10
current: 
---
As I've noted in [my prior musing](crashplan-softlinks-2023-05-09) and [the one before that](crashplan-dotfiles-2023-05-08), ITS at Grinnell has installed CrashPlan on College-owned faculty and staff laptops.  CrashPlan is cloud-based backup software that also permits local backups.

I was a bit excited when I first learned about CrashPlan.  While I regularly make backups using Time Machine [1], it never hurts to have another backup system.  For example, restoring from Time Machine isn't always as straightforward as I'd like.  The last time that ITS wiped my computer, it took me about twenty hours to get it appropriately up and running [2].

Since I was looking forward to CrashPlan, I took a quick look at [their Web site](https://www.crashplan.com/en-us/).  It had many things that I thought I'd appreciate: Cloud and local backup, encryption, and even unlimited storage [3].  So I looked forward to experimenting with it.

ITS told us that they were rolling out CrashPlan slowly.  So I waited.  And I waited some more.  I reached the point where all my departmental colleagues seemed to have CrashPlan installed. But, for some reason, CrashPlan never got installed on my computer.  One of the helpful ITS staff even tried consulting remotely.  They failed to get CrashPlan installed, so they had me visit the Help Desk in person.  They failed, too.  So they decided to wipe my computer [4,5].

CrashPlan wasn't installed when they gave me back a newly-wiped computer.  One person told me, "That's to be expected; we've had some trouble with the CrashPlan rollout and have things on hold."  However, it showed up a few days later.  Unfortunately, since I'd created a second account on my laptop for restoring data, it decided that I was "srebelsky@grinnell.edu" rather than "rebelsky@grinnell.edu".  Have I mentioned that I hate computers?  

After about a week, that got fixed.  And CrashPlan started up my computer.  Whee!  As I suggested in my prior two musings, I discovered that it wasn't backing up my whole computer.  It wasn't even backing up all of my home directory.  In particular, it wasn't backing up my `bin` and `Applications` folders.  And, as we've seen, I had questions about [dot files](crashplan-dotfiles-2023-05-08) and [soft links](crashplan-softlinks-2023-05-09).  But I also wanted to know about those two missing folders, about making local backups [7], and about setting up my own backup set so that I could, for example, back up all of the applications on the MacBook.

Here's the answer, as best I understand it.

> CrashPlan is not intended to make it easy for faculty and staff to back up and restore their laptops.  CrashPlan is only intended to make backups so that the College can access faculty/staff data on laptops, presumably for matters of legal hold or legal challenge.

That's right, CrashPlan provides no utility to users. Instead, it is yet another piece of software in the paranoid ITS`regime's toolkit.

I realize that ITS needs to make our data available in cases of legal hold.  Perhaps I should be glad that they're taking over the process; I lost a day of vacation when the College decided that a legal hold had been placed on my data, and I had to handle making all the backups [8].

But couldn't they make CrashPlan useful to us, too?  These days, it seems like the primary goal of higher-level ITS staff is to manage risk, not to make our professional lives easier or more productive.  Technology is supposed to help, not harm.

Is CrashPlan harmful, even if it's not helpful for everyday activities?  Yes, it is potentially harmful.  Among other things, CrashPlan backs your laptop up no matter how you are connected to the Internet.  So if you're using your phone as a hotspot, or if you have limited bandwidth, CrashPlan is using your resources, not the College's.  As far as I can tell, ITS hasn't warned us about this issue.  And since it has yet to warn us, it hasn't told us how to disable CrashPlan on specific networks.

However, that is something we should all know.  So I'll share what I've learned about how to stop CrashPlan from using my home or phone data network.  I've only tried this on my MacBook; I don't know how it will work on other systems.

---

Welcome to the detour!

1. Open CrashPlan.
2. Open the application settings (using the gear icon).
3. Click on "Network".
4. Near "Wireless network exclusions", click "Change...". A dialog should appear.
5. Click on the plus sign. You should see a new dialog that says something like "Add a restricted network", along with a list of networks. It may take a bit for the list to show up.
6. Click on your home network (or your phone network or whatever network you want to exclude).
7. Click "Save". You should now see your network on the list of excluded networks.
8. Click "Save". You should be back to the general Device Preferences/Network dialog.
9. Click the x in the upper-right-hand corner to close the dialog.

At this point, it should not use your home (phone) network.  At least, I think it shouldn't.  On my computer, it suggests that backups are paused.  However, there's another downside.  In my experience, not only will it not back up on your home network, it also won't let you do much of anything (including change preferences).

---

Okay, we're back from the helpful detour.  Where were we?  That's right; I was claiming that CrashPlan is harmful.  It's harmful because it can use your bandwidth.  It's harmful because you can't control what files it backs up.  Staff and faculty should be able to choose not to have their personal or research files backed up; the College does not own those.  Staff and faculty should be able to choose not to have their ssh keys or encryption keys backed up; the College does not own those either.  CrashPlan is also harmful because it adds yet another layer of complexity to your computer.  At least on my computer, I'm seeing more out-of-memory errors.  I'm also seeing regular check-ins from CrashPlan to our authentication system.

CrashPlan harms us indirectly, too.  CrashPlan requires support, particularly for annoying users like me who ask lots of questions.  Couldn't that support time be used for more helpful things?

Perhaps I should stop asking questions.

---

**_Postscript_**: In case you're wondering, CrashPlan has not responded to the musings I posted on Twitter.

---

**_Postscript_**: Don't worry.  I'm done ranting about CrashPlan for the time being.

---

[1] More precisely, my Mac makes the backups when I plug in my external drives.

[2] Admittedly, some of that time was because I was trying to follow ITS guidelines.

[3] Am I permitted to store the thousands of CDs I own?

[4] As I said, I had to recreate/reconfigure my laptop recently.

[5] Now that I've spent some time reconfiguring my computer, I may understand what went wrong.  I use [Homebrew](https://brew.sh) to manage a bunch of software on my computer.  Homebrew stores that software in `/usr/local`, at least on my x86 MacBook.  Unfortunately, some of the ITS Spyware [6] lives in `/usr/local/jamf`.  So when I restored `/usr/local` with Time Machine, it eliminated Jamf.

[6] ITS likes to install spyware on our computers.  Let's see, there's [Jamf](https://www.jamf.com), [Cortex/Traps](https://www.paloaltonetworks.com/cortex), [BeyondTrust](https://www.beyondtrust.com), and, now, CrashPlan.

[7] As you may recall, one of the benefits of CrashPlan is that it makes both local and remote backups.

[8] Nope, no one ever requested them.  I still think I deserve to be reimbursed for the lost day of vacation.
