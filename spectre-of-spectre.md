The spectre of Spectre
======================

This week, two major security flaws were identified in most modern
processors: [Meltdown and Spectre](https://meltdownattack.com/).
As a computer science educator, I find most security flaws interesting
as they reveal issues our students should be thinking about and I should
be teaching about.  The most common flaws have to do with programmers
not thinking carefully enough about their memory model and, for example,
failing to make sure that a memory reference is valid [1].  And many flaws
have to deal with one particular program or component of the environment.

These two sounded different than most flaws because they hit
the computer at a different level.  At first, my interest
was mostly academic because (a) it was clear that most major
operating systems had already installed a patch for Meltdown and
(b) because the first article I read on it, from [_The New York
Times_](https://www.nytimes.com/2018/01/04/technology/meltdown-spectre-questions.html), suggested that

> Phones and PCs are more difficult targets. Before they can exploit the
chip flaws, hackers must find a way of getting their software onto your
device. They could fool you into downloading an app from a smartphone
app store. Or they could trick you into visiting a website that moves
code onto your machine.

However, as I started to read more on other sites, I realized that what
the _Times_ calls "moves code onto your machine" can just mean "includes
a JavaScript program that takes advantage of the flaw".  In fact, the
researchers who found the flaw had already written a short JavaScript
program that dumps the memory of the browser.  That's a serious problem.
So I've patched my primary computers as best I can.  The folks at
Mozilla, makers of Firefox, have found one approach that disables
Spectre; the implications of that patch are not completely clear.

Anyway, as I said earlier, I like to learn more about security flaws
for what they might help me teach my students (and because it's interesting).
These newest flaws take advantage of modern processor designs, designs
that I did not know a lot about.  So I started to read the [research paper
on Spectre](https://spectreattack.com/spectre.pdf).  I found it remarkably
clear, even for someone like me who does not study architecture.
That's also where I discovered that they already had a browser-based
proof of concept.  The approach is interesting.  I'm going to attempt
a bit of a summary here.  You can skip over the summary and read some
other comments later in this musing.

---

*Technical summary*

Let's start with something that may be a bit surprising to my
non-technical readers: The processor on a computer is *much* faster
than the memory on a computer.  That is, the computer can do a bunch [4]
of computations (additions, subtractions, multiplications, divisions)
before you can read a value from your "fast" solid-state drive.  Processor
designers have developed a number of techniques to handle this issue.
The traditional technique is to put a bit of really fast (but really expensive)
memory in the processor and copy the most recently used data there.  This
memory is called the "cache" [5].  When programs need a value from memory,
the processor first checks whether or not it is in the cache and, if it is,
can quickly grab it.  If not, the processor needs to load the data from
the disk into the cache.

What should the processor do while it's waiting?  One option is to do
some work on other programs that are not currently waiting for data to
load.  But switching from program to program can be expensive.  And so
it seems that processors made the decision to use a technique that is
called "*speculative computation*": they save the state of the processor
and continue with the computation until the load finishes.  If the data
loaded suggests that they should have done that computation, they are
fine.  If not, they restore the state of the system.  Here's a really
contrived example.

    if (a > values[x])
      {
        discriminant = b*b - 4*a*c;
        tmp = sqrt (discriminant);
        divisor = 2*a;
        root1 = (-b + tmp) / divisor;
        root2 = (-b - tmp) / divisor;
      }

While we're waiting to find out the value of `values[x]`, we can probably
do the four multiplications, one call to `sqrt`, two divisions, and a
few additions and subtractions necessary to compute the roots [6].  When the
memory finally loads, if we made the right prediction, then we're done with
the computation.  If not, well, things aren't really any slower (except
for the cost of restoring the state of the system, which is supposed to
be fast and is certainly fast compared to a memory load).  I admit that
I find it strange that we see gains from what seems to be just a little 
extra work while waiting for memory (after all, don't we tend to use the
memory we've just requested after the test?), it seems like empirical 
evidence suggests that this approach makes a big difference.

Of course, this approach does require that the processor can restore
the state of the system if it speculated incorrectly.  But what does it
mean to restore the state of the system?  Saving and resetting the cache
is expensive, so the cache is not considered part of the state.  Rather,
I believe it is a just a few values [7] that get saved or restored.
Changing the cache should not change the overall behavior of a program,
but it may change the speed of the program because some data that were
in the cache will now take longer to access and some data that were not
in the cache and are now in the cache will now take less time to access.

It turns out that the "Is data in the cache?" question is a key 
component of the Spectre approach.  While there isn't a "check whether
a memory location is in the cache" command, or at least I don't think
there is.  But it's easy to figure out if you want to: You start a
timer, you load the memory location, and you stop the timer.  If the
time to load the memory location was quick, you know that the memory
was in the cache.  If the time to load the memory location was not quick,
you know that it was not in the cache. 

Knowing whether or not a particular memory location is in the cache tells
you nothing about the contents of that memory location.  And that's where
we get to the interesting part of the Spectre approach.  The authors
provide the following sample code.

    if (x < array1_size)
      y = array2[array1[x] * 256];

This type of compound instruction makes conceptual sense.  You don't
want to access `array1[x]` unless `x` is less than the size.  And so
this is a compound instruction you would find in many programs, often
behind the scenes.

The note that for the approach to work, `array1_size` should not be in
the cache (and, presumably, `x` and `array1[x]` should be in the cache,
if at all possible).  With some work, they are able to set the value
of `x` to something outside of the range and to choose the value that
`array1[x]` refers to [8].

Why does this help?  Suppose I care whether memory location `m` contains
the value 42.  I set `array1[x]` to `m` [9].  I let this code execute.
By the time the processor realizes that `x` is greater than or equal to
`array1_size`, it has also loaded `array2[array1[x] * 256]` (which equals
`array2[m*256]`) into the cache.  To see whether memory location `m`
contained 42, I check whether or not `array2[42*256]` is in the cache.

We can generalize this technique to find the exact value and
not just whether `m` contains 42.  It's slow, but it's doable.  And
processors are fast.

So, here's the thing: JavaScript code runs in the same memory space as
your browser.  JavaScript code gets compiled.  When JavaScript code gets
compiled, the new code likely has checks about array indices.  Even if
it doesn't, you can force some.  Hence, a bit of JavaScript code can use
this technique to probe any area of browser memory, even if the browser
has tried to "sandbox" the code.  But writing the code understands some
understanding of various aspects of the browser, and different browsers
will therefore require different code.  And there's more to it than
what I've covered; you also need to clear some things out of the cache
in advance and otherwise configure the system "just right".  But it's
doable.

I'll admit that I haven't taken the time to look at the particular
JavaScript exploit they provide [10].  I was interested more in the
high-level concept than the details of the implementation.

The solution that the folks at Mozilla seem to have used is to add some
noise to time measurements, which makes the "is it in the cache" check
no longer useful.  I believe they've done some other things, too.

---

Okay, we're back from the technical detour.  What's left to write about?
The more I read about Spectre and Meltdown, the more I find myself interested
in the social aspects.  These flaws were discovered about six months ago;
good cooperation kept them secret for six months.  That's impressive, but
I also think that's typical of the relationship between security researchers
and the major OS makers.  It's kind of neat, once you think about it.

However, cooperation did not work perfectly.  The two flaws were not supposed
to be announced until January 9 and some other factors led to an early
announcement.  In particular, [an engineer at AMD revealed details about
Meltdown in a Linux Kernel Patch](https://lkml.org/lkml/2017/12/27/2).
There has been an earlier patch whose primary note was that x86 CPUs
are insecure.

    /* Assume for now that ALL x86 CPUs are insecure */
    setup_force_cpu_bug(X86_BUG_CPU_INSECURE);

This engineer seemed to be offended by that claim that all x86 CPUs are
insecure since AMDs do not seem to have the meltdown flaw.  And so he
wrote the following in a public forum.

> AMD processors are not subject to the types of attacks that the kernel
page table isolation feature protects against.  The AMD microarchitecture
does not allow memory references, including speculative references, that
access higher privileged data when running in a lesser privileged mode
when that access would result in a page fault.

Since this musing is mostly on Spectre, I have not described the details
of Meltdown. However, the Meltdown flaw has to deal with speculative
references to higher privileged data.  And so his posting helped
others discover the Meltdown flaw before it was supposed to be public.
Is that the only reason that Meltdown and Spectre got announced a week
or so early?  I assume not, but I also assume that it contributed to
the earlier-than-expected notification.

---

What should you do?  The obvious answer is "patch your system".
I think my Mac updated itself a few days ago.  But, just to be sure,
I downloaded and applied [the appropriate security update for macOs
Sierra](https://support.apple.com/kb/DL1940?locale=en_US).  Our Linux
machines at work are being patched over the weekend, so I'm waiting for
those patches before I do any additional serious work on those systems.  
Oh, my iPhone is up to date and running iOS 11.2.1.

What do you do if you have an older operating system that Apple or
Microsoft or whoever has decided not to patch?  I'm not sure.  Apple
has patches for High Sierra (10.13), Sierra (10.12), and El Capitan
(10.11).  If you have an earlier Mac that can be updated to El Capitan,
I'd recommend updating.  If not, I'd suggest that you be cautious about
the software you install and that you use a browser extension like
NoScript.  I don't use Microsoft Windows if I can avoid it, so I have 
no idea what's happening in that realm.

But, you know what?  Don't rely on me for advice on these issues.  There
should be better (and more up to date) information on the Interweb.  Look
there and look at sources you trust.

Good luck!

---

[1] There is a reason that I tend to reject programs from upper-level
students that have obvious memory flaws [2].

[2] An "obvious" memory flaw is one that I can find with a tool like
`valgrind` [3] or through manual inspection of the code for a few minutes.

[3] Or, were I more up to date, AddressSanitizer.

[4] "Bunch" is intentionally vague.  I have no idea what the ratio of
read time to multiplication time is; I just know that it gets larger every
year.

[5] To be accurate, most modern processors have multiple levels of cache
of different speeds.  That difference is not relevant to this discussion.

[6] It may be that we can do even more than those operations.  But they
suffice for the example.

[7] Primarily the registers, including things like the program counter,
if I understand correctly.

[8] C programmers can probably figure out some straightforward techniques.

[9] More precisely, I set some other variable that I know to be at
the same location as `array1[x]`.

[10] <https://spectreattack.com/spectre.pdf>, listings 2 and 3.

[11] From <https://www.theguardian.com/technology/2018/jan/04/meltdown-spectre-worst-cpu-bugs-ever-found-affect-computers-intel-processors-security-flaw>.

> Google said it informed the affected companies about the Spectre flaw on 1 June 2017 and later reported the Meltdown flaw before 28 July 2017. Both Intel and Google said they were planning to release details of the flaws on 9 January, when they said more fixes would be available, but that their hand had been forced after early reports led to Intel stock falling by 3.4% on Wednesday.

---

*Version 1.0 released 2018-01-06.*

*Version 1.0.1 of 2018-02-25.*
