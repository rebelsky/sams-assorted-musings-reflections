Clearing cruft
==============

*Topics/tags: [Meta-musings](index-meta), GitHub, organization, rambly*

In some ways, my musings are like any software project.  That is, the
"musing project" consists of a variety of files and programs that I
modify, test, and "compile" [1].  I regularly add new files.  I sometimes
delete files.  Since the musings are a project, I use the same tools to
manage the musings that I use for most of my software projects.  There's
a [Makefile](cnix-make-intro)  to keep track of the various instructions.
I use Git to keep track of changes to the files [3,4].  And, even though
Microsoft now owns it, I store my files on GitHub.

The musings are also like a standard software project in that they tend
to accumulate cruft [8].  And I'm not good about either remembering
to commit all my files or about cleaning out the cruft.  So, whenever
I look at the status of the project, there are generally a dozen or so
files that I've updated but haven't committed and a few dozen files that
I've never added to the repository.  Here's what things looked like
recently.

    $ git status
    On branch master
    Your branch is up-to-date with 'origin/master'.
    Changes not staged for commit:
      (use "git add <file>..." to update what will be committed)
      (use "git checkout -- <file>..." to discard changes in working directory)
    
            modified:   Makefile
            modified:   eoce-history.md
            modified:   inbox-zero-revisited-06.md
            modified:   jekyll-scribble-or.md
            modified:   markdown-pandoc.md
            modified:   portable-cellos.md
            modified:   resources/template.html
            modified:   sketches/accumulation.md
    
    Untracked files:
      (use "git add <file>..." to include in what will be committed)
    
            about-grinnell.md
            arts-and-computing.md
            assessment-revisited.md
            ban.md
            bar
            code-style.rkt
            css/grinnell.css
            css/musings.css
            deleted/
            examples/cnix-permissions/strange/
            fonts-with-html2ps.md
            grinnell-eoce.md
            images/NewLetterhead.png
            images/OmniDiskSweeper-2018-09-28.png
            images/sam-office-huge.png
            inbox-zero-cleanup.txt
            joc-synchronizing-stuff.md
            make-item-new
            memory-musing-202-large.png
            nonsequitors-anonymous.md
            obermann-bookshelves.md
            pandoc.css
            parsing-the-brand-2018-05-09.md
            resources/pandoc.css
            revising-mediascheme-csc151.md
            sample.md
            sample3.md
            sandbox.PDF
            sandbox.md
            sandbox/
            sokal-revisited-continued.md
            table.md
            tmp/

What are all those files?  Well, many of them are sketches for future
musings.  Those generally end in `.md`.  A few are related to experiments.
Certainly, anything labeled "sandbox" or "sample" falls in that category,
but so do some of the css files.  Some of the things marked as "modified"
represent changes to the system that I forgot that I made.

In any case, last night I decided that it was time to deal with the
cruft so that, in the future, I could more easily tell what I'd been
doing recently.  Because I believe in sensible commit messages, I did
look at each file [9] individually.

Some things were easy.  I cleared out the sample and sandbox files.  I
updated the `.gitignore` so that it ignored what I call "development
directories" (`deleted`, `sandbox`, and `tmp`).  And, while it took time
to look at each sketch and to give it a commit message, doing so was
relatively straightforward.

I was a bit surprised to discover that I'd forgotten to commit some
relatively major beyind-the-scenes changes to the site.  I'd added
another program to the Markdown to HTML chain, and the Makefile reflected
that.  I'd updated one of the programs that I use on that chain and
changed the template file to reflect the update [10].  Why hadn't I committed
those changes when I made them?  I probably should have.  But there was
enough cruft around that I forgot.  That's why it's good to clear your cruft
regularly.

I also deleted a bunch of files.  Did I mention that already?

Twenty-five commits later, and the cruft is gone.

    $ git status
    On branch master
    Your branch is up-to-date with 'origin/master'.
    Untracked files:
      (use "git add <file>..." to include in what will be committed)
    
            musings-clearing-cruft.md
    
    nothing added to commit but untracked files present (use "git add" to track)

Let's hope I can keep it that way.

---

---

[1] I write in Markdown.  You read the musings in HTML [2].  There are a few
steps involved in getting from Markdown to HTML or to PDF.

[2] Or, in some cases, PDF.

[3] I'll write more about Git on some day.

[4] My use of Git for the musings is comparatively primitive.  For example,
I don't really see a need for branches [5].

[5] That's not quite true.  If I ever decide to start using Jekyll [6] to
manage the site, I'll probably set up a branch for that new version.
However, as time passes, it seems less and less likely that I'll start
using Jekyll, particularly because each time I encounter Liquid [7],
I regret using Jekyll.

[6] Jekyll is a toolkit to make it easy to build static Web sites using
Markdown.  Many Grinnell CS faculty use it for their course Web sites.

[7] Liquid is a badly designed scripting language that you use with
Jekyll.  Using Liquid makes me wish I could use PHP.  And I don't like PHP.

[8] [Wikipedia](https://en.wikipedia.org/wiki/Cruft) tells us that

> Cruft is a jargon word for anything that is left over, redundant and getting in the way. It is used particularly for defective, superseded, useless, superfluous, or dysfunctional elements in computer software. 

I prefer that to [the definition from the Jargon
file](http://catb.org/jargon/html/C/cruft.html).

[9] Or, in some cases, changes to the file.

[10] Maybe it was the other way around.  I'd realized that I wanted to
change some aspect of the template and then updated the program to match.
I can't remember.  That's why I should do commits when I make the changes.

---

*Version 0.9 of 2018-10-06.*

