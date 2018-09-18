Amazon music storage
====================

*Topics/tags: [Rants](index-rants), music, the cloud*

People who know me know that I accumulate things.  Since my early days
of College [1], I've collected popular music.  I used to collect vinyl.
When CDs came out, I started accumulating CDs.  And, when digital music
came out, well, I kept accumulating CDs, but started ripping them [2].
One of my first big personal projects was a huge database of my albums.
I could tell you where I bought any album and how much I'd paid,
which albums any particular song appeared on, and other trivia both
useless and useful.  Unfortunately, I wrote the damn thing in HyperCard,
and so it is now long gone [3].

In any case, I have a lot of music in both physical and electronic form.
Hence, when Amazon started offering a cloud storage service of 250,000
songs for $29.99/year, I jumped at it.  250,000 songs is somewhere between
10,000 and 25,000 albums.  I'm not even sure that I have that many.
In any case, I figured that it would be a way for me to get everything
together and in order.

But, well, ripping CDs takes time.  Tagging them appropriately and
adding covers adds more time.  So I never quite got around to uploading
everything I ripped, let alone everything I had.  It feeels like every
time I dig out an old external drive, I find a folder labeled "Upload"
that contains a few discs I'd ripped at some point that I had intended
to upload.  Sometimes I did, sometimes I didn't.

Early this year, Amazon announced that they were discontinuing Amazon
music.  Folks who timed their accounts correctly could continue to
upload until the end of this year.  Other folks might have a less
generous deadline.  Mine was September 10 [4].  I had four goals for that 
date: Arrange the music I seem to have put on too many external drives,
tag and add images to the music that needed it, upload everything, and
download what was already on Amazon music [5].

But, well, the summer was way too busy.  So while I made some progress,
I didn't make enough.  The week of September 3 I spent downloading what
I already had on Amazon, just in case.  Of course, I encountered some
problems with the downloader, which meant that I had to restart a lot.
What problems?  It seems to give up if it encounters a song with no
length.  It also doesn't like to download more than 1800 songs at a
time before freezing up.  So I'd start it going, do some other work,
and glance over from time to time to see if it was making progress.
Of course, it doesn't tell you when it's stopped, so I wrote a small
program that counted how many songs were downloaded and printed it out
every minute; when that number stopped changing, I knew that it was time
to quit and start again [6].

How many songs had I attempted to upload in the years that I had Amazon
music?  Slightly under 60,000.  Clearly, I had not spend as much time
uploading as I planned.

But what about the last-minute rush to get more songs onto Amazon
Music Storage?  I didn't get to uploading until the weekend; September
8, or so.  I kept telling myself "First you should get the music in
order."  But once I hit the 8th, I gave up and just uploaded what I
could find.  Unfortunately, the Amazon uploader is even worse than the
Amazon downloader.  It would tell me things like "2,000 songs uploaded,
300 songs matched, 200 songs could not be uploaded because of a format
error, 100 songs could not be uploaded for an unknown error, 50 songs
could not be uploaded because of a server error."  Would it tell me
what songs could not be uploaded?  No; that would make too much sense.
So, whenever a batch upload would fail, I'd have to redo the same
batch upload and wait for Amazon to realize that most of the songs had
been uploaded already.  A batch of 2000 or so songs would usually take
three or four tries before Amazon finally accepted everything.  Hence,
even though I had a bunch that I expected to be able to upload, I could
only upload some of them.  I guess I'll not achieve my goal of having
an organized music collection, at least not on Amazon.

That may be for the best.  I've been looking at what I got from Amazon
and, well, Amazon does not do a particularly good of either naming
the downloads or, in the cases it adds an album cover, of choosing
the right cover.  Take, for example, Ani DiFranco's _Living in Clip_.
I'm not sure why I looked at it; I seem to recall that I'd chosen it
because it's a multi-disc album.  

Problem the first: Some of the songs are named things like "01-02-
Wherever.mp3", the first part of which represents "Disc 01, Song 02".
But others are named things like "-03- Gravel.mp3", which don't include
the disc number.  Why not?  They're on the same album.  They had better
names when I uploaded them.  So why didn't Amazon use either the names I
had named them or a consistent naming scheme?  It *looks* like the names
of songs that Amazon matched don't include the disc number and the ones
that actually uploaded do.

Equally surprising is that Amazon has chosen at least three different
covers for the album.  Most of the songs that it auto-matched have the
correct cover.  Most of the ones that I uploaded have ended up with the
cover of _Monkey Business_ by the Black Eyed Peas.  Since I have no albums
by the Black Eyed Peas, I have no idea how that happened.  And one song,
"Letter to a John", has the cover of DiFranco's _Out of Range_.  Did the
auto-match fail and give me the wrong song, or at least the wrong version
of the song?  While it's not a song I know well, a little detective work
suggests that although I uploaded the one from _Living in Clip_, the one
Amazon decided to store does, in fact, come from _Out of Range_.  No, they
are not the same version of the song.

What else?  Oh, for compilations, instead of setting up a separate
"Various Artists" folder, Amazon puts each song on the compilation into a
folder associated with the artist.  For example, the songs on _Badlands:
A Tribute to Bruce Springsteen's Nebraska_ appear in 13 different folders.
Getting the compilations back together will be an adventure [7].

Badly designed software for uploading music.  Badly designed software for
downloading music.  Bad file names for songs.  Incorrect song matches.
Maybe it's good that Amazon discontinued the service.  Perhaps I should
not have counted on it in the first place.

---

[1] Officially "The College at The University of Chicago".  I'm pretty sure
that some people pronounce it so that you can hear the capital T's.

[2] That's not quite true. I did join eMusic in the early "all you can
download" days.  Somewhere I have a bunch of CDs with those wonderful
128K mp3's.  If I recall correctly, eMusic had a bunch of Miles Davis as
well as a lot of Rykodisc titles.  And it was a good source for artists
not on major labels.

[3] There's a chance that I have an 800K floppy somewhere with the 
database on it.  But it's unlikely that a floppy that old still works.
At some point, I could try with one of the Macs in the CS museum.

[4] My notes said September 11.  But upload privs seemed to stop at 12:01
a.m. on September 11, rather than midnight.  That strikes me as ending
on September 10.  Yet another thing to dislike about Amazon.

[5] Amazon claims that it will continue to store everything.  It's still
safer to have a local copy.

[6] No, I did not look over every minute.  I just glanced over every fifteen
minutes or so.  I suppose if I were smarter, I would have written a program
that made a noise when the downloads stopped.  I didn't think of it at
the time.

[7] Something in the back of my brain tells me that iTunes will help.
I'll have to see.

---

*Version 1.0 of 2018-09-16.*
