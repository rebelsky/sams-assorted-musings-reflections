Scraping course schedule data
=============================

*Topics/tags: [The joy of code](index-joc), Grinnell, schedule*

The other day, Youngest Son asked whether I knew that you could use
Google Sheets to scrape Web data.  Michelle looked at us with a bit of
confusion, so we explained what it means to scrape Web data and why you
might want to do so [1].

Today, as I was [reflecting on the course
timetable](unintended-consequences-course-schedule) and wondering how
popular each timeslot is, I realized that I could use Google sheets to
gather and extract the data.  In this musing, I do my best to document
my steps and to report on what I've discovered.

First, let's get the data into the spreadsheet.  It turns out that that's
relatively simple, using the `IMPORTHTML` command.  Here's what I put
in cell A1 of my spreadsheet.

    =IMPORTHTML("https://itwebapps.grinnell.edu/DotNet/CourseOffering/", "table", 1)

And, voila!, the data appear.  Unfortunately, I only seem
to be able to get data for the current semester as itwebapps
doesn't have a clear API [2].  Wait a second.  I'm a computer
scientist; I should be able to figure things out.  Ah hah!
I can add a query string and it seems to work.  For example
<https://itwebapps.grinnell.edu/DotNet/CourseOffering/?Term=2019/SP>
gives me the spring 2019 listings [3].  So I can scrape data from both
this semester and next semester.

Next, I'd like to be able to analyze the data.  I suppose it would make
sense for me to put them in an SQL database and write appropriate queries.
But I'm lazy.  So I'm just going to save them in a tab-separated-value
file and use Linux command-line tools.

What does one line look like?  Here's an example.

    81788       Open    CSC-161-01      Imperative Prblm Solvng w/lab   MWF     8:30 AM - 9:50 AM -     Walker, Henry M 10/28   4

We seem to have the course code (column 0 [4]), a tab, an
open/closed/blanced status (column 1), a tab, the course number (column
2), a tab, the course title (column 3), a tab, the days it meets (column
4), a tab, the meeting times (column 5), a tab, the instructor (column 6),
a tab, available/capacity (column 7), a tab, and the number of credits
(column 8).

Some of those entries are a bit strange because the course meets at multiple times in the week.  Here's an example which meets Monday and Wendesday from 1:00-3:50 p.m. and Friday from 1:00-1:50 p.m.  It also has one more field..

82505   Closed  BIO-150-01      Intro to Biolgcl Inqry W/Lab    MW F    1:00 PM - 3:50 PM 1:00 PM - 1:50 PM     Brown, Jonathan M       0/24    4       Yes

I'm going to ignore those complexities for now.  

My first step is to extract the courses that meet on Monday, Wednesday,
or Friday.  I'm going to use `egrep`, which means that I'll generate
a fairly ugly regular expression.

    $ egrep '^([^\t]*\t){4}[MWF]' 2018F.txt

Nope.  That didn't work.  While it includes the lines I want, it also
includes entries whose weekday column doesn't start with M, W, or F.
I'm not sure why.  It may have something to do with the interpretation
of tabs.  Have I ever mentioned how much I hate computers?  I wonder
what happens if I replace all the tabs with tildes.

    $ cat 2018F.txt | tr '\t' '~' | egrep '^([^~]*~){4}[MWF]'

Yup.  That does seem to work.  That is, I seem to get only the courses
whose weekday column starts with M, W, or F.  

Since I've written some ugly code, I should probably explain it.

* `tr '\t' '~'` translates tabs to tildes.
* `egrep` is "extended `grep`", a utility for searching files.
* The first caret (`^`) represents "the start of the line"
* The `[^~]` represents "anything but a tilde".  Square brackets
  represent a set.  A caret after the left square bracket indicates
  that it's an anti-set; anything except the next characters.
* The asterisk (`*`) represents "zero or more copies".
* The parentheses group, just as they do in most languages [5].
  So `([^~]*~)` means "a bunch of characters, not including a tilde,
  and then a tilde".  Given the structure of our file, it matches
  one column.
* The `{4}` means "four times".  Since we put it after something that
  matches one column, we now match the first four columns.
* And the `[MWF]` is, once again, set notation.  In this case, it means
  "`M`, `W`, or `F`".

And yes, there are people out there who found the original clear enough
that it did not need this explanation.  

You know what?  I really only want courses that meet at least two days
per week.  So I'm going to change my command a bit, and save the result
to a file.  

    $ cat 2018F.txt | tr '\t' '~' | egrep '^([^~]*~){4}(MTW|MW|WF)' > 2018F-mwf.txt

I can probably create one for the Tuesday/Thursday courses, too.

    $ cat 2018F.txt | tr '\t' '~' | egrep '^([^~]*~){4}(TTH)' > 2018F-tth.txt

Now I should think a bit about the content of these files.  Did I miss
anything by using "TTH" instead of "T TH"?

    $ cat 2018F.txt | tr '\t' '~' | egrep '^([^~]*~){4}(T TH)'
    83072~Open~ALS-100-05~Korean I~T TH~8:00 PM - 9:00 PM 4:30 PM - 5:30 PM~Frances, Claire~2/8~2~

One course, and it's at a nontraditional time.  I can ignore that one in
my analysis.

What about courses that meet MWF but also have an extra meeting time
(e.g., for lab)?

    $ egrep '^([^~]*~){4}([A-Z]* )' 2018F-mwf.txt 
    81446~Open~ARB-221-01~Intermediate Arabic I~MWF TH~1:00 PM - 1:50 PM 2:00 PM - 2:50 PM~Hussein, Mona Hamed~16/20~4~
    82505~Closed~BIO-150-01~Intro to Biolgcl Inqry W/Lab~MW F~1:00 PM - 3:50 PM 1:00 PM - 1:50 PM~Brown, Jonathan M~0/24~4~Yes
    82479~Closed~BIO-251-01~Molcls, Cells, & Orgnsm w/lab~MWF T~3:00 PM - 3:50 PM 1:00 PM - 3:50 PM~Sandquist, Joshua C.~2/24~4~
    ...

Oh.  There are a bunch.  Let's see how many.

    $ egrep '^([^~]*~){4}([A-Z]* )' 2018F-mwf.txt  | wc -l
    27

That's too many to process by hand.  I know!  I can eliminate the second
time slot so that I don't h ave to worry about it in future queries.  Let's
see.

    $ egrep '^([^~]*~){4}([A-Z]* )' 2018F-mwf.txt | sed -E 's/M [0-9]+:[0-9]+ .M - [0-9]+:[0-9]+ .M/M/'
    81446~Open~ARB-221-01~Intermediate Arabic I~MWF TH~1:00 PM - 1:50 PM~Hussein, Mona Hamed~16/20~4~
    82505~Closed~BIO-150-01~Intro to Biolgcl Inqry W/Lab~MW F~1:00 PM - 3:50 PM~Brown, Jonathan M~0/24~4~Yes
    82479~Closed~BIO-251-01~Molcls, Cells, & Orgnsm w/lab~MWF T~3:00 PM - 3:50 PM~Sandquist, Joshua C.~2/24~4~
    ...

That does the trick.  The "lab times", such as they are, don't get
included.  But that's a pretty horrendous sed command.  Can I clean it up?

    $ egrep '^([^~]*~){4}([A-Z]* )' 2018F-mwf.txt | sed -E 's/M [0-9]+:[^~]*~/M~/'
    81446~Open~ARB-221-01~Intermediate Arabic I~MWF TH~1:00 PM - 1:50 PM~Hussein, Mona Hamed~16/20~4~
    82505~Closed~BIO-150-01~Intro to Biolgcl Inqry W/Lab~MW F~1:00 PM - 3:50 PM~Brown, Jonathan M~0/24~4~Yes
    82479~Closed~BIO-251-01~Molcls, Cells, & Orgnsm w/lab~MWF T~3:00 PM - 3:50 PM~Sandquist, Joshua C.~2/24~4~

That's a bit better.  Of course, I should probably use that sed command as I
generate the two files.

    $ cat 2018F.txt | tr '\t' '~' | egrep '^([^~]*~){4}(MTW|MW|WF)' | sed -E 's/M [0-9]+:[^~]*~/M~/' > 2018F-mwf.txt
    $ cat 2018F.txt | tr '\t' '~' | egrep '^([^~]*~){4}(TTH)' | sed -E 's/M [0-9]+:[^~]*~/M~/' > 2018F-tth.txt

Oh, yeah.  I should ignored the Canceled classes.  And I really should
include the TWTH courses in the TH list (at least if I care about those
that use up those time slots).  Time to clean up my commands a bit.

    $ grep -v "\tCanceled\t" 2018F.txt | tr '\t' '~' | sed -E 's/M [0-9]+:[^~]*~/M~/' > 2018F.tmp
    $ egrep '^([^~]*~){4}(MTW|MW|WF)' 2018F.tmp > 2018F-mwf.txt 
    $ egrep '^([^~]*~){4}(TTH|MTWTH)' 2018F.tmp > 2018F-tth.txt 

At this point, I'm beginning to wonder if I should use a different
tool [6].  But I've gotten this far, so I'm going to continue.

Let me take stock.  I have created two files, `2018F-mwf.txt` and
`2018F-tth.txt`.  The first contains all the courses that meet at least
two of Monday, Wednesday, and Friday.  The second contains all the courses
that meet only on Tuesday and Thursday.  I don't think we have any
courses that meet Tuesday, Wednesday, and Thursday, except for those
that meet all five days [7].  I think I'm ready to gather data.

    $ grep "8:00 AM - 8:50 AM" 2018F-mwf.txt | wc -l
    22
    $ grep "8:00 AM - 9:50 AM" 2018F-mwf.txt | wc -l
    7

Yup, things look good.  It's time for a table [8].

    Slot        Times (MWF)       Number
     1           8:00- 8:50 AM      19
     2           9:00- 9:50 AM      40
     3          10:00-10:50 AM      26
     4          11:00-11:50 AM      34
     5           1:00- 1:50 PM      34
     6           2:00- 2:50 PM       5
     7           3:00- 3:50 PM      20
     8           8:30- 9:50 AM      13
     9          10:00-11:20 AM      12
    10           1:00- 2:20 PM      18
    11           2:30- 3:50 PM      11
    12           8:00- 9:50 AM       7
    13          10:00-11:50 AM      11
    14           2:00- 3:50 PM      12
    15           8:00-10:50 AM      2
    16           9:00-11:50 AM      1
    17           1:00- 3:50 PM      7

Now, we can combine the data.  If I were smarter, I'd write a program.
    
    Times (MWF)         Slots           Count
      8:00- 8:50 AM     1,8,12,15       19+13+7+2 =    41
      9:00- 9:50 AM     2,8,12,16       40+13+7+1 =    61
     10:00-10:50 AM     3,9,13,15,16    26+12+11+2+1 = 52
     11:00-11:50 AM     4,9,13,16       34+12+11+1 =   58
      1:00- 1:50 PM     5,10,17         34+18+7 =      59
      2:00- 2:50 PM     6,10,11,14,17   5+18+11+12+7 = 53
      3:00- 3:50 PM     7,11,14,17      20+11+12+7 =   50

I won't claim that the count is exact.  For example, we do sometimes have 
classes that meet one day per week for, say, 8:00-10:50 or 9:00-11:50.
However, I don't think there are all that many.

What about the equivalent slots on Tuesday and Thursday?  Let's see.

    Slot        Times (TTh)       Number
     1           8:00- 8:50 AM       1
     2           9:00- 9:50 AM       2
     3          10:00-10:50 AM      13
     5           1:00- 1:50 PM       7
     6           2:00- 2:50 PM       2
     7           3:00- 3:50 PM       1
    18           8:00- 9:20 AM       4
    19           9:30-10:50 AM      14
    20           1:00- 2:20 PM      15
    21           2:30- 3:50 PM      10
    22           8:00- 9:50 AM      38
    23           9:00-10:50 AM       3
    24           2:00- 3:50 PM      14
    25           8:00-10:50 AM       2
    26           1:00- 3:50 PM       7

Just in case you're wondering, the large number of classes in the
8:00-9:50 slot represent offerings of Tutorial.  

Now, let's see what this means for each hour of the day.

    Times (TTh)         Slots             Count
      8:00- 8:50 AM     1,18,22,25        1+4+38+2 =     45
      9:00- 9:50 AM     2,18,19,22,23,25  2+4+14+38+3 =  61
     10:00-10:50 AM     3,19,23,25        13+14+3+2 =    32
      1:00- 1:50 PM     5,20,26           7+15+7 =       29
      2:00- 2:50 PM     6,20,21,24,26     2+15+10+14+7 = 48
      3:00- 3:50 PM     7,21,24,26        7+10+14+7 =    38

My imperfect read is that our pressure points are MWF [9] 9:00, 11:00, and
1:00 and TuTh at 9:00.  Can a bit of arm twisting solve these issues?
It *looks* like moving a few 9:00 a.m. MWF and 11:00 MWF class to
10:00 a.m. should solve some problems.  We also have a reasonable
amount of room on TuTh afternoons.  How many two-day-per-week classes
meet in the MWF time slot?  Sixty meet just MW.  Two meet MF.  Five
meet WF.  We could shift a few of those to TuTh afternoons and address
some of our problems.

Unfortunately, I've just realized that my counting doesn't deal with
cross listed courses.  Maybe I'm better off just asking the Registrar's
office for the data.  Still, I've gotten a rough picture of the pressure
points for this fall.

---

Postscript: This exercise may seem secondary to my primary digital
humanities project.  However, many parts relate directly to that project.
I should teach my students how to scrape data.  Google spreadsheets
may be more convenient than the scripts I have them write.  I'll probably
have them learn both.  And the Scheme library for scraping data needs
to be on my "to write soon" list.  Then I'll rewrite this musing using
those tools.

---

[1] Youngest Son's college choice spreadsheet has reached a few hundred
columns of data.  He's clearly at the point that he wants those cells
filled in automatically.

[2] That is, if I change the semester the URL does not change.

[3] Interestingly, that approach also gives me access to summer listings.

[4] As a computer scientist, I tend to start numbering at zero.

[5] Scheme is a notable exception.

[6] See the postscript for some more reflection.

[7] I used `grep "TWTH" 2018F.txt | grep -v "MTWTH"` to check.

[8] The slot numbers come from the current timetable.

[9] "MWF" represents "MWF" and "MW" and "WF" and "MF" and "MTWF" and
"MTWTHF" and variants thereof.

---

*Version 0.9 of 2018-10-16.*
