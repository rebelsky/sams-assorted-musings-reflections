Java code style
===============

*Topics/tags: [The joy of code](index-joc), Java, technical*

As I've noted in [an earlier musing](cnix-formatting-c), when I teach most
programming languages, I encourage students to follow a consistent style.
As I suggest to my students, consistent formatting makes code more readable.
One would hope that most formatting guidelines are designed for clarity,
but it's not always clear that that's always the case [1].

I tend to prefer GNU C style for the C-like languages I use.  The design
choices often have a sensible rationale [2]; it's also a style I've
both read and used a lot.  In the past, when I've taught Java, I've
encouraged my students to use a similar style for their Java programs.
But I've come to realize that almost no Java programmers use GNU C style.
Among other things, Java programmers don't seem to like open braces on a
line by themselves, and Java programmers don't follow the GNU convention
of separating a procedure from its modifiers.

What do I mean by the latter?  I'm always tempted to write something
like the following.

    public static void
    main (String[] args)
      throws Exception
    {
      ...
    }

But most Java programmers would write something more like this.

    public static void main(String[] args) throws Exception {
        ...
    }

I worry that the procedure name gets lost in all of the modifiers.

In any case, I was looking around for a decent Java style guide to
adopt for the coming semester when I stumbled upon the
[Google Java Style Guide](https://google.github.io/styleguide/javaguide.html).
It seems quite extensive.  It meets some of my other preferences, such
as avoiding tabs and using a two-space indent.  And it even has
[settings for Eclipse](https://github.com/google/styleguide/blob/gh-pages/eclipse-java-google-style.xml).

While the Google style guide seems comprehensive, I find it interesting to
see what it does not include.  It does not say that all the modifiers for
a procedure declaration belong on the same name as the declaration, but
it seems that they do.  It is silent on `extends` and `implements`,
although I'm pretty sure that Google expects them on the same line as
the class name.  So, although I'd much prefer

    public class Foo
      extends Bar
      implements Baz
    {
    }

it's clear that I'll be stuck writing

    public class Foo extends Bar implements Baz {
      ...
    }

Bleh.  

While it's not a style I like, I do tell my students that there are
many benefits to following a standard style.  It looks like I'll
be rewriting my Java code to follow these new style conventions.

---

[1] More likely, there are competing design goals.  For example, GNU
C style makes matching braces easy, but at the cost of extra vertical
space.

[2] For example, in a procedure declaration, we put the procedure name 
at the start of a line so that it's easy to find the declaration.

[3] Not so surprisingly, Google has [a decent Markdown style guide](https://github.com/google/styleguide/blob/gh-pages/docguide/style.md), too.

---

*Version 0.9 of 2019-01-06.*
