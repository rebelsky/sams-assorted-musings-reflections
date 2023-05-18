---
title: Ah, the joy of Microsoft
number: 1237
tags: [Rants](index-rants), technology
blurb: More technology failures.
version: 1.0
released:  2023-05-17
current: 
---
There are many things I like about Microsoft.  They hire our students.  They support open source.  They are incredible supporters of the SIGCSE community.  They include a Linux subsystem in their operating system.  These are all great things.  I even use Word and Excel with some regularity.

But I have had bad experiences with all sorts of Microsoft software [1]. For example, I still can't believe that Outlook for iOS lacks an easy-to-use undo mechanism.  On Apple Mail for iOS, I need only shake the phone to undo an action.  There's even an undo stack, so I can keep undoing actions.  In contrast, Outlook for iOS gives you about five seconds to click an "undo" button; after that, you're screwed.  At least I can't find anything else, and the folks I've asked for help can't find anything.  Sometimes I wonder whether Windows users are trained to expect less.

My latest bad experience has been with the newish campus directory.  I'm pretty sure that it's not custom software.  Rather, it's a standard Sharepoint directory search.  Enough people use Sharepoint that you'd expect the directory to work well.  But it doesn't.  Here's my experience.

The other day, I searched for "Computer Science" and "Class of 2023" to find all the remaining students in the class of 2023. We had about a dozen mid-year graduates.  We should have 52 remaining majors in the class of 2023.  The first strange thing I noticed was that 53 entries came up.  It's hard to tell since there are only fifteen per page.  But I saw three pages of fifteen and one page of eight.  Nonetheless, the text at the bottom of the pages says "52 entries".

Then I looked a little bit closer.  Some names were repeated between pages.  For example, the last name on page one was the first name on page two, and the last name on page three was the first name on page four.  But I know that we have 52 majors.  What was happening?  Clearly, some names were being left out.  More accurately, the Microsoft directory search duplicated some entries and skipped others.  Isn't that wonderful.

Then I looked closer.  Strangely enough, the contents of page 2 are different depending on whether you reach page 2 from page 1 or page 3.  Similarly, the contents of page 3 differ depending on whether you reach page 3 from page 2 or page 4.  That's just weird.  Really weird.

So, I did the only natural thing.  I put in a ticket.  And the helpful ITS staff both expressed concern and took a closer look at the issue.  After some exploration, they discovered that six names were duplicated and five were missing.  It's nice that they were willing and able to take the time to delve so deeply into the problem.  They also told me that Microsoft search giving different results depending on how you view pages is a known issue.

How can it be a known issue and that Microsoft hasn't fixed it yet?  As I've said, I wonder if Microsoft users are trained to expect less from their software.

In any case, we're using POTSS [2].  ITS has replicated the problem.  So ITS is putting in a ticket with Microsoft.  We'll see what happens.  But something's going massively wrong.  Directory search is a common feature; you'd think Microsoft would have it working correctly by now.

Fingers crossed that they'll have it working soon.

---

[1] Should I call it Microsoftware?

[2] POTSS.
