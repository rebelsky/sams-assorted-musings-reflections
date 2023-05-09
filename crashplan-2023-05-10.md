---
title: Planning to crash
number: 1231
tags: [Rants](index-rants), technology
blurb: The third in a series.  Perhaps the last in a series.
version: 0.2
released: 2023-05-10
current: 2023-05-08
---
As I've noted in [my prior musing](crashplan-softlinks-2023-05-09) and [the one before that](crashplan-dotfiles-2023-05-08), ITS at Grinnell has installed CrashPlan on College-owned faculty and staff laptops.  CrashPlan is cloud-based backup software that also permits local backups.

I was a bit excited when I first learned about CrashPlan.  While I regularly make backups using Time Machine [1], it never hurts to have another backup system.  For example, restoring from Time Machine isn't always as straightforward as I'd like.

How do you stop CrashPlan from using your expensive home or phone data network?

1. Open CrashPlan.
2. Open the Settings (using the gear icon).
3. Click on Network
4. Near "Wireless network exclusions", click "Change...". A dialog should appear.
5. Click on the plus sign. You should see a new dialog that says something like "Add a restricted network" along with a list of networks. It may take a bit for the list to show up.
6. Click on your home network (or your phone network or whatever).
7. Click "Save". You should now see your network on the list of excluded networks.
8. Click "Save". You should be back to the general Device Preferences/Network dialog.
9. Click the x in the upper-right hand corner.

At this point, it should not use your home (phone) network. In my experience, not only will it not back up on your home network, it also won't let you do much of anything (including change preferences).

---

[1] More precisely, my Mac makes the backups when I plug in my external drives.
