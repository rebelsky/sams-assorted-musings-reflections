Fiddling with Linux applications on macOS
=========================================

*Topics/tags: [Rants](index-rants), technical, macOS, Linux, rambly*

I've been using Unix workstations since about 1985.  If I recall
correctly, my first Unix systems were a Pyramid [1] running some custom
version of Unix and some form of VAX running BSD Unix, both under the
auspices of the CS Department at The University of Chicago [2].

I've been using Macs for about as long.  Michelle and my first
Mac was a 512Ke [3].

So when Apple decided to rewrite the Macintosh operating system to use
a \*nix [4] core, I was overjoyed.  I expected to get the consistent Macintosh
UI [5] along with a terminal that I could use when I wanted the more
efficient command line.  And, in general, that's proven true.

But there are times that I want to use popular Linux programs that don't
necessarily come native on my Mac.  Sometimes that works well; sometimes
it doesn't.  This is a story about one of the times things went less well.

---

One of my favorite \*nix applications is [ImageMagick](http://imagemagick.org/).
I use it mostly for small tasks on the command line, such as resizing images
or converting from one file format to another.  

The other day, I needed to resize an image.  I thought I had ImageMagick
installed on my Mac, but it seemed that I did not.  So I went to look for
an installer.  The [first place I found](http://cactuslab.com/imagemagick/)
suggested that their installers did not work for El Capitan or Sierra.
Since I still run Sierra [6], I was out of luck.  Of course, upgrading
would not help; that site only supports up to 10.10 (whatever that was).

So I employed the other recommended strategy, installing with
[MacPorts](https://www.macports.org/).  Conceptually, MacPorts is great.
It provides a simple, command-line tool for installing and updating
a wide variety of \*nix software.  And, conceptually, the process is
easy.  I should just be able to type

    sudo port install ImageMagick

and everything is supposed to go fine.  But MacPorts doesn't like the
fact that I've only installed part of Xcode [7].  That's not supposed
to be an obstacle, but it sometimes is.  Since I'm running an older
version of macOS, it's also a bit of a pain to find and download the
correct version of Xcode [8].  I crossed my fingers that it was not
necessary.

Installing ImageMagick also requires the installation of a bunch of
other software.  I didn't keep track of it all.  I'll note that 
`atlas` took perhaps the most time to install.  Unfortunately, not
all of it installed successfully.  Since I know a little bit about
building software, I don't generally quit when that happens.  I spent
a bit uninstalling and then reinstalling the dependencies and doing
a Web search on error messages.  Eventually, it looked like I had
succeeding in installing all of the necessary parts.  I went to convert
the file that started the whole process and, amazingly enough, it worked.

Then I went to run [Scribble](https://docs.racket-lang.org/scribble/),
the markup language I'm using for the textbook [9].  And, well, I got
ugly error messages.  I was able to read them and determine that it
was something to do with LaTeX.  I hadn't changed LaTeX, so I was
confused.  After some time puzzling, I realized that the version of
LaTeX I was using had changed.  I had been using the version that comes
with [MacTeX](http://www.tug.org/mactex/).  For some reason, another
version got installed under the MacPorts file hierarchy.  And that
version wasn't working.  I *think* resetting my path corrected the
problem.

But playing with these issues made me realize that (a) my installation
of MacTex is two years out of date and (b) the latest version of 
ImageMagick is version 7.0.9, while MacPorts only supports 6.9.9.
On to more upgrades.

MacTeX is pretty straightforward.  I just need to download a new installer
(3.4 GB) and run it (another 6 GB).  It takes about three minutes on my
Mac [10].  At some point in the near future, I should probably uninstall
the old version.  And I should keep my eye out for the next version.
Somewhere in the middle, I should consider whether I want to use TeX
Live to update the asssociated files.  

It turns out that there's [a download of ImageMagick 7 for macOS].  How
did I miss that?  Let's see.  I downloaded the tarball, unpacked it,
moved it to my /Applications folder, and updated my `.bash_profile` file.
That's much simpler than using MacPorts.

I'm not sure that I want two versions of ImageMagick installed [11].  I know
that I don't want three versions of the TeX universe installed [12].  And
MacPorts is taking about 8 GB on this system, compared to 3.2 GB on my
other system, which also has the old ImageMagick installed [14].  I bet it's
the TeX stuff.  But there's probably other cruft, too.  I'm tempted to
nuke the whole thing.  And then there's the question of whether to
replicate everything on the other Mac.

Maybe it's time to make a list of what I like installed and to keep it
up to date [15].

One way I'll figure out what I need or want is to clear everything out
and start again.  That's also a good way to get rid of cruft.  First,
I'll make a list, just in case.

    $ port list installed > macports-installed.tex

Now I'll clean out the MacPorts stuff.  Here's the [first command
that they suggest](https://guide.macports.org/chunked/installing.macports.uninstalling.html).

    $ sudo port -fp uninstall installed

It's kind of scary is that I get error messages from that process,
such as "Warning: All compilers are either blacklisted or unavailable;
defaulting to first fallback option".  I'm also puzzled that there's still
about 1 GB in use in `/opt/local` after that command.  Ah!  It's all in
`/opt/local/var/macports`.  Okay, I'm going to follow the suggestion to
nuke `/opt/local` too.

    $ sudo rm -rf /opt/local

As long as I'm doing that, I should also get rid of the applications in
`/Applications/MacPorts` [16].  Now, let's reinstall MacPorts and
ImageMagick.  I wonder how long it takes to install ImageMagick and all
of its dependencies from scratch?  Let's see.

    $ time sudo port install ImageMagick

Much faster this time; only eight minutes.  And it didn't install atlas.
I wonder what was going on last time.  In addition, at present, I only
have 1 GB in `/opt/local`.  I'm a bit worried about what's gone, but
not enough to think more about it at the moment.

Isn't system administration fun?

---

[1] The Pyramid's tendency to crash under high loads led me to make it
a policy to start homework assignments the day after they were do; that
way, I was the only one working on the system, and it was less likley to
crash and destroy my work.  More details on my experiences with the Pyramid,
including its poorly-designed Pascal compiler and my exposure to Gosling
Emacs, may follow in subsequent musings.  If you want me to write more, let
me know.

[2] At some point, I became one of the grad student sysadmins  for the
department's Unix systems.  I forget what server we were running then.

[3] I don't remember what happened to it.  The MacPlus we purchased next
lives in the CS Museum outside of my lab, still with the old "Gargoyle"
sign on it that I claimed after the UofC CS department discarded it.

[4] I tend to use "\*nix" to refer to Unix, Linux, BSD, and the other
various variants of Unix out there.

[5] I still have the classic _Macintosh User Interface Guidelines_ somewhere
in my lab.

[6] I'm not alone in my reluctance to upgrade.  My department chair also
runs Sierra.

[7] I don't use Xcode, so I install only the command-line tools.

[8] Xcode 10 is the latest version.  Xcode 8.3 or so is the last one
that works under Sierra.

[9] I also have an outstanding musing on choosing Scribble.  I may also
have an outstanding rant on my experiences with Scribble.

[10] It said it would take ten minutes, but it was much faster.

[11] Actually, until I have spent some time with the new ImageMagic, I'm
probably best off making sure I still have the old one installed.

[12] I have MacTeX 2016, MacTeX 2018, and the strange TeX installation
in my MacPorts filesystem.

[14] *That's* why I thought I had ImageMagick installed.

[15] I went to create a new repository for
that list on GitHub.  GitHub suggested I call it
[**reimagined-memory**](https://github.com/rebelsky/reimagined-memory).
How's that for serendipity?

[16] In doing so, I realized that I still have MacPython 2.5 in my
Applications directory.  It takes from 2010, and I haven't used it
in years.

[17] No, I will not list all of the output from `port`.  However, you
may be interested in the list of dependencies that need to be 
installed:
`autoconf`
`automake`
`bzip2`
`db48`
`djvulibre`
`expat`
`fftw-3`
`fontconfig`
`freetype`
`gdbm`
`gettext`
`ghostscript`
`giflib`
`ilmbase`
`jasper`
`jbig2dec`
`jbigkit`
`jpeg`
`lcms2`
`libedit`
`libffi`
`libiconv`
`libidn`
`libpaper`
`libpng`
`libraw`
`libtool`
`libxml2`
`ncurses`
`openexr`
`openjpeg`
`openssl`
`ossp-uuid`
`perl5`
`perl5.26`
`pkgconfig`
`python27`
`python2_select`
`python_select`
`readline`
`sqlite3`
`tiff`
`urw-fonts`
`webp`
`xorg-libX11`
`xorg-libXau`
`xorg-libXdmcp`
`xorg-libXext`
`xorg-libXt`
`xorg-libice`
`xorg-libpthread-stubs`
`xorg-libsm`
`xorg-libxcb`
`xorg-xcb-proto`
`xorg-xorgproto`
`xz`
`zlib`
. I'm not quite sure how to react.

---

*Version 0.9 of 2018-10-24.*
