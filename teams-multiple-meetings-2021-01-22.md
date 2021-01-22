---
title: Teaching with Technology: Managing Multiple Meetings on Microsoft Teams
number: 1123
tags: [Teaching](index-teaching), technical
blurb: Ah, the joys of technology.
version: 0.2
released: 
current: 2021-01-22
---
_Warning!  This musing is currently in draft state.  It is intended
primarily for those with whom I've shared the link._

_If you only care about how to join multiple simultaneous video/audio
meetings on Teams (at least on a Mac), jump ahead to the section entitled
"Instructions"._

Last semester [1], I used Microsoft Teams for my CSC 151 class.
While Teams has many flaws [2], it also seems to be the best available
option for what I want to do.  I particularly appreciate that it
serves as an "all in one" communications approach in class: I can
use it for full-class meetings, for breakout groups, for text chat
with my students, for student-hosted peer-to-peer meetings with screen
sharing, and so on and so forth.

We teach CSC-151 using workshop-style pedagogy, with students working
in pairs on problems while I and the class mentors check in.  Hence,
the ability to have breakout groups is particularly important.  Last
term [3], Teams did not have built-in breakout groups, so I followed 
a colleagues' lead and set up a channel in which students created their
own meetings for the breakout groups.  It worked well.  I had to post
a list of pairs to the channel, but students quickly mastered the task
of setting up a meeting.

Microsoft has now added managed breakout groups [4] to Teams, which
(I hope) will make things even easier.

When a group of faculty and our amazing ITS support person [5] got
together to experiment with managed breakout groups, one of my
colleagues noted that the one issue they've faced with breakout
groups was that it's disruptive when you join a breakout group.
Students see you join and then pause their conversations.  I haven't
had that experience; in general, I find that students don't notice
that I'm in a breakout group until I'm there, but that may be because
my students are focusing on their shared screen.  But I asked myself,
"Is there a way to pretend to be in every meeting so that students
don't know that we're there until we say something?"  I also asked
the question because there's a bit of overhead in joining a breakout
group.  But I put the question on the back burner, as it were, since
I already have a technique that works.

But a few days later, I talked to a colleague who has students share
screens with FastX [6].  They said, "I have a tab open for each team,
that way I can quickly switch between them to see for potential problems."

Switching between tabs is much faster than logging out of one Teams
meeting and joining another.  So I returned to the earlier question:
Are there ways in which I can be in multiple Teams meetings at once,
and quickly jump between them?  What follows is my narrative of
experiments.  If you care only about the solution I developed, feel
free to jump ahead to the section entitled "Instructions".

My first attempt just involved creating a different tab for each
meeting in Chrome.  Unfortunately, that approach failed.  As soon
as I joined in the third tab, the Teams Web App disconnected me in
another tab.

My next attempt involved setting up private windows.  Unfortunately,
you cannot naturally run Teams in a private window on Chrome, because
Chrome disallows third-party cookies in private windows.  So I tried
enabling third-party cookies for the appropriate Microsoft sites [8].
That allowed me to run Teams.  But when I opened the third private
window, the first two disconnected from their meetings.  Bleh.

What next?  I checked how to run multiple copies of the same
application on a Mac [9].  It appears that `open -n Path-To.app`
is supposed to open a new copy of the application.  That approach
works for Microsoft Word and for Safari [10], but it didn't work
for the Microsoft Teams application.  For some reason, the second
copy seems to immediately connect to the first copy.  I had the
same problem with Chrome, Firefox, Edge, and Opera [11,12].  I love
it when software designers think they know better than the OS [14].
But I guess it makes sense: Web browsers regularly write and check
config files; multiple apps sharing the same files can be dangerous.

I considerd using a different browser for each session, but I only
know of eight browsers or so for the Mac.  I also know that not all
of them work well with Teams.

I don't give up easily, so I kept trying.  It turns out that if you
start Chrome from the command line, you can specify the user data
directory.  If you want multiple copies, you just specify different
data directories.  For example, the following lines open three copies
of Chrome on my laptop.

```
/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --user-data-dir=/Users/rebelsky/Chrome/User01 &
/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --user-data-dir=/Users/rebelsky/Chrome/User02 &
/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --user-data-dir=/Users/rebelsky/Chrome/User03 &
```

Isn't that awesome?  You know what's even better?  Once I create and
configure one account, I can copy it to another directory and have
it maintain all of the settings, including the Teams authorization [15].

---

**_Setup Instructions_**

These are instructions the instructions I use for setting up multiple
independent Chrome-based Teams instances on a Mac.  YMMV.

1. In the terminal [16], type the following.  Note that the ampersand at
the end is a required part of the command.

   ```
   /Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --user-data-dir=/Users/$USER/Chrome/User01 &
   ```

   If all goes well, you should see a new Chrome instance open.

2. Log in to Microsoft Teams at <https://teams.microsoft.com>.

3. Navigate to the channel where meetings will happen.  (Or to wherever
you want the browser to start.)

4. Open the preferences for Chrome.  (I use Command-Comma.  You can
   also use Chrome->Preferences.)

5. Click on "On startup" in the left menu.

6. Select "Open a specific page or set of pages" and then "Use current
   pages".  (Alternately, you could use "Continue where you left off".)

7. Wonder why there's no "Save" button.  (That was a joke.)  Then close
   the preferences tab.

8. Right-click or Ctrl-click on the Teams tab.  Then select "Mute
   Site".  This ensures that you won't hear overlapping chatter
   when you have multiple sessions going.

9. Optional: In the "Chrome" menu, uncheck "Warn Before Quitting".  

10. Do any other configuration you consider appropriate.
        
11. Quit Chrome.

12. Type the same command as before to ensure that everything was
    configured correctly.

13. Quit Teams again.

14. In the terminal, type the following.

    ```
    cd ~/Chrome
    cp -r User01 User02
    cp -r User01 User03
    ```

    Repeat as appropriate for as many users as you want.

15. In the terminal, type the following to open all three instances.

    ```
    /Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --user-data-dir=/Users/$USER/Chrome/User01 &
    /Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --user-data-dir=/Users/$USER/Chrome/User02 &
    /Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --user-data-dir=/Users/$USER/Chrome/User03 &
    ```

    If all goes well, you should see three separate sessions (the windows
    may all be in the same location.

16. Try opening a new meeting in each of the windows to make sure they
    don't overlap.  Remember to turn audio (and video) off.

17. Quit everything.

---

**_Back to the musing_**

One things that I find nice about this setup is that it shouldn't
take me long to switch to a different default page.  Just reopen
one instance (e.g., `User01`), change the default page, and then
copy it over to the other instances.

Now that I have everything working, more or less, I'm beginning to
consider how I might do things differently, or perhaps I might have
done things differently.  For example, it turns out you can keep
Teams meetings running for awhile.  So I could have set up the
meetings in advance of class and just asked students to join
particular meetings.  On the other hand, asking them to start their
own meetings gave them ownership of the meetings.

And then there are the things that I won't be able to answer until
the semester starts.  For example, I'm wondering how much time it
will take to connect each instance to the students' individual
meetings and how to keep track of which meeting is which.  Conveniently,
Teams for Web does not put the meeting name of a meeting you are
in anywhere that I can see.  I guess I'll figure out these processes
once the term starts.  I'll also need to figure out the best way
to have students message me when they need help.  We currently use
an `@staff` tag; I'm just wondering how that will work in this
environment.  I may need one spare window to just look at what's
happening in Teams.  I'll also need a new way to work with my
mentors.  Should we each choose a subset of groups to work with,
or should we each rotate through all the groups systematically?
Systematic rotation would be easier if I could see the group numbers
in the different windows.

I look forward to further experiments.

---

**_Postscript_**: On my laptop, each instance of the user directory
requires about half a gig, almost all of which is cache.  I haven't
found a way to avoid that, even starting Chrome with something like
`--disk-cache-size=67108864` (64 MB) doesn't seem to make a difference.

---

**_Postscript_**: If I use "TwT" to abbreviate "Teaching with Technology",
should I pronounce that as "twit"?

---

**_Selected References_**: 

I learned about how to run multiple instances of Google Chrome at
<https://diegocarrasco.com/how-to-rum-multiple-instances-of-google-chrome-on-mac/>.

I learned about Chrome cache limits at 
<https://superuser.com/questions/378991/what-is-chrome-default-cache-size-limit>.

I have intentionally left the names of my faculty and staff colleagues out 
of this musing since I do not have their permission to include those names.

---

[1] Term.

[2] Stay tuned for another musing.

[3] I got it right that time.

[4] I was going to write "instructor-managed breakout groups", but I think
anyone can create breakout groups.  I'll need to experiment a bit more.

[5] I'm not just saying that because I expect that they will read
this piece.  The folks who train and support faculty in Teams and
Blackboard are awesome.  They work hard  to understand our problems,
they care about supporting our work, and they are good at finding
solutions.

[6] FastX is our remote Linux client that I think is layered on top of
VNC.  It provides only desktop sharing [7] and not audio/video.  At least
that's what I think.

[7] Desktop sharing includes not just screen sharing, but also keyboard and
mouse sharing.

[8] I could have enabled third-party cookies for all sites, but that seems
dangerous.  I wonder why so much software expects us to follow bad security
practices.

[9] I'm a Mac/Linux person and do most of my work on my Mac.  Therefore,
my experiments were Mac-based.

[10] It works less well for Safari, presumably because Safari is regularly
writing and reading info about open windows.

[11] I did not try Chrome Canary or Opera GX.  I can't remember whether or
not I tried Brave.  But all of them are based on Chromium, so it seemed
unlikely that I would see different behavior.

[12] Each did open a new window, but it's not the same thing.

[14] Or is it when OS designers don't convey appropriate information to
software designers?

[15] That also makes it important that I protect the directories.
Fortunately, Chrome sets permissions appropriately.

[16] If you're not comfortable with the Terminal, you probably shouldn't
try this.
