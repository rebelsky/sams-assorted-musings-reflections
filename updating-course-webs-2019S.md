Updating my course webs
=======================

*Topics/tags: [Teaching](index-teaching), technical, Web, rambly*

For the past week or so, I've been preparing my course webs
[1] for my spring semester courses.  And, as I wrote [a year
or so ago](updating-course-schedule-complicated), I manage to find ways to
make the process more complicated than it should be.  Like many members
of this department, I use custom software to build my course webs.
In particular, following the lead of one or more of my colleagues,
I use Jekyll for building each site and some Bootstrap for the design.
However, I'm not great at using either, and it appears that I lack either
the time or the mental capacity to get significantly better.

Because my colleagues know the tools better, their sites tend to
evolve more quickly than mine.  Unfortunately, I can't just copy
from their site to mine because we think about course webs somewhat
differently.  One obvious example is the sets of links at the top of
each page.  The colleague I borrow from most recently likes a set of
eight or so links [2].  In contrast, I prefer hierarchical menus [3].
Another is that I tend to integrate my live lecture notes [7] along with
tools that automatically extract information from those notes.

In any case, one stumbling block I thought I was hitting as I prepare
for next semester has to do with the schedule.  My colleague not
only rearranged the visuals for the schedule to make it much more
readable, but also changed the way we're storing data.  In particular,
they have a single file that contains dates and detailed information
on what is covered each day.  You can see some code in Appendix A.

I prefer to separate the semester-focused material, such as the dates
of classes and the due dates of assignments, from the information on the
individual topics I teach.  One advantage of the latter approach is that
it's much easier to rearrange topics [8,10].  In my world, one should
have three files, rather than one: the detailed information on each
topic (see Appendix B), the information on the dates for the semester
(see Appendix C), and the information on assigned work (see Appendix D).

In case it's clear, we both believe in the principle of DRY data [11]: Each
piece of information should reside in a single place, and every page that
needs that information should pull it from that place.  We just differed
on what the places should be.  At least we both moved forward from 
putting the information in the individual files.

I could have ignored my colleague's changes to the appearance of the
schedule.  However, their schedule looks much nicer than mine.  As
importantly, it appears to print in a more convenient form.  That meant
that I had two choices: I could adapt their strategy for structuring
data or I could rewrite their code for generating the syllabus and other
parts of the site.

Can you guess what I decided?

That's right; I'm much too tied to the way I like to arrange data.  So
I sat down and figured out how to rewrite their code.  

It's always a challenge to work with the array of languages associated
with Jekyll.  We use YAML for the data specification, Liquid for much of
the processing, Ruby for a few things, JavaScript for live activities
on the page, and HTML and Markdown for the content.  Most of these
languages make sense to me, but I always wonder why anyone would have
chosen to adopt Liquid as their programming language; it's not bad for
a narrow range of tasks, but there's a lot of extra work involved in
getting more sophisticated things done.  And I really miss the ability
to use regular expressions.

One advantage of spending the time figuring out how they were building
the schedule and how to adapt it to my data model was that it was then
easier to add features to the schedule.  For example, we tend to write
both a short description of each class day and a list of topics we plan
to cover.  My colleague's schedule shows only the short description;
I added the list of topics [12].  I also like to refer to class days by
number, and so added a note about the class number to the schedule.
You can see [the current draft
schedule](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2019S/schedule/)
on the [course site for CSC 151.01
2019S](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2019S/home/).

Perhaps as importantly, I learned enough about the structure of their
code that I was able to build a new variant of the schedule, which I
call the [schedule overview](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2019S/overview/).  This more concise version lists all the topics and
major due dates in more of a grid form, with one row for each week of the
semester.  I find these grids easier to read when I want to quickly 
understand a course.  I expect it will also be useful for students who want
to plan their work for the semester and for other faculty who want to
get a quick sense of what we cover in the course.

Now that the technology and the draft schedules are in place, I can move
forward with the next important step: Updating and finishing all of the
readings and labs.  It should be fun.

---

Postscript: Mustn't forget: I may be putting the 151 labs on a separate site.
In that case, I'll need to rethink some of the menus and such.  Oh well;
that's a task I can put aside until we're slightly closer to the start
of the semester.

---

*Appendix A: The start of a course data file in my colleagues' form*

    "Week 1":

      "2019-01-23":
        topic: Introduction to Algorithms
        abbrev: intro-algorithms
        summary: |
          We begin the class by exploring the definition of computer science and by
          trying to write some basic algorithms.
        subjects: 
          - Introduction - What is CS?
          - Exercise - An everyday algorithm
          - Debriefing on exercise 
          - Common parts of an algorithm
        assigned:
          - page: /assignments/assignment1.html
      "2019-01-25":
        topic: Getting Started with Linux and Scheme
        abbrev: intro-linux
        summary: |
          We begin to consider the content and structure of the course.  We also
          prepare ourselves to use our laboratory environment (that is, the Linux
          workstations and the DrRacket Programming Environment).
        subjects:
          - Getting started with Linux
          - Why use programming languages?
          - Scheme history
          - Scheme basics
          - Using DrRacket
        reading:
          - page: /readings/algorithms.html
          - page: /readings/linux.html
          - page: /readings/drracket.html
          - page: /readings/beginning-scheme.html
    lab:
      - page: /labs/linux.html
      - page: /labs/starting-scheme.html

    "Week 2":

      "2019-01-27":
        message: _Work Due_
        due:
          - page: /assignments/assignment1.html
            time: 10:30pm

---

**Appendix B: The start of a topics file in the form I prefer**

*Note that I have not yet decided where the readings and labs will
reside, so I have their names in place of the links.*

    - topic: An introduction to algorithms
      abbrev: intro-algorithms
      summary: |
        We begin the class by exploring the definition of computer
        science and by trying to write some basic algorithms.
      subjects: 
        - Introduction - What is CS?
        - Exercise - An everyday algorithm
        - Debriefing on exercise 
        - Common parts of an algorithm
    
    - topic: Getting started with Linux, HTML, and CSS
      abbrev: intro-markup
      summary: |
        We begin to consider the content and structure of the course,
        exploring both our laboratory environment (Linux workstations)
        and mechansisms for representing and styling text.
      subjects:
        - Getting started with Linux
        - Generalized markup with XML
        - Web markup with HTML
        - Page styling with CSS
      reading:
        - link: Introduction to FunDHum
        - "An introduction to Linux"
        - "Generalized document markup with XML"
        - "Writing Web Pages"
      lab:
        - "Writing Web Pages"
    
    - topic: Getting started with Racket
      abbrev: intro-racket
      summary: |
        We consider Racket, the programming language we will use
        throughout the course.
      subjects:
        - Why use programming languages?
        - Scheme history
        - Scheme basics
        - Using DrRacket
      reading:
        - "Algorithm building blocks"
        - "An introduction to DrRacket"
        - "An introduction to Racket"
      lab: 
        - "Getting started with Racket"
   
---
 
**Appendix C: The start of a dates file in the form I prefer**

    - week: Week 1
      anchor: week01
      days:
        - { date: 2019-01-20 }
        - { date: 2019-01-21 }
        - { date: 2019-01-22 }
        - { date: 2019-01-23, class: true }
        - { date: 2019-01-24 }
        - { date: 2019-01-25, class: true }
        - { date: 2019-01-26 }
    - week: Week 2
      anchor: week02
      days:
        - { date: 2019-01-27 }
        - { date: 2019-01-28, class: true }
        - { date: 2019-01-29 }
        - { date: 2019-01-30, class: true }
        - { date: 2019-01-31 }
        - { date: 2019-02-01, class: true }
        - { date: 2019-02-02 }

---

**Appendix C: The start of a dates file in the form I prefer**

    - date: 2019-01-23
      assigned:
        - page: /assignments/assignment01.html
        - page: /assignments/assignment02.html
    
    - date: 2019-01-27
      due:
        - page: /assignments/assignment01.html
          time: 10:30pm
    
    - date: 2019-01-29
      due:
        - page: /assignments/assignment02.html
          time: 10:30pm
    
    - date: 2019-01-30
      assigned:
        - page: /assignments/assignment03.html

---

[1] I use the term "course web" to mean "Web site for a course".  But you
probably figured that out already.

[2] Home, Schedule, Readings, Labs, Assignments, Exams, Project, and
Syllabus.

[3] _Primary_, which includes links to the front door [4], the course news,
the course schedule, the course syllabus, my appointment software, and
my statements on a variety of topics.  _Current_, which includes links
to the current assignment, eboard, exam, flashcard assignment, lab,
lab writeup, and reading.  _Resources_ [5], which includes links to
the lists of assignments, eboards, exams, flashcard assignments, labs,
lab writeups, and readings.  _Reference_, which links to some important
reference materials [6].  _Related Courses_, which links to some other
recent offerings of this course.  And _Misc_, which provides links to
other resources.

[4] "Home page", in some people's parlance.  However, "Home page" is
ambiguous; it can be where *I* start my explorations ("origin") or where
you enter the site ("front door").

[5] I used to call this "Sections", but that seemed to imply sections
of the course, as opposed to sections of the Web site.  I don't like
"Resources".  I guess I'll have to come up with a new name.

[6] Someday, it will once again link to full 6P-style documentation for
all the procedures we use.

[7] "Eboards", for those who attend my classes.

[8] Do I rearrange topics more than my colleagues do?  I'm not sure.
Certainly, I rearrange topics multiple times during the weeks leading
up to the start of the semester.  There are also two or three times
each semester in which I find that a topic needs an extra day, so I
need to shift everything afterwards up to the next pause for breath [9].

[9] I got the idea of a "pause for breath" from John Stone and Henry
Walker.  It's a day in the schedule with no planned topic that provides 
some room to allow one to adjust the schedule if something takes
longer.  If there's not a need to adjust the schedule, we find an 
interesting bonus topic to discuss or give students a class period to
work on homework with faculty and mentors available for help.

[10] While I rearrange topics, I do my best not to rearrange the due dates
of major assignments.  I know what havoc such rearrangement can play on
students' plans.

[11] Don't repeat yourself.

[12] I realized how important the list of daily topics was when I 
started putting together [the schedule for CSC 207](csc207-2019S-schedule)
and found myself reading through old class schedules.

---

*Version 1.0 of 2019-01-05*

