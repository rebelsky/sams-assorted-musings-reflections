Bootstrapping my musings
========================

_Some of you may have noted that the musings now look somewhat different.
In this musing, I attempt to explain why._

As you've surfed the Web, you may have noted that there are some standard
styles of Web sites.  I've written about that issue before, but I can't
remember where.  In any case, there's a kind of site that I think of as a
"Bootstrap" site.  Bootstrap is a collection of element types and site
styles (CSS) that make it easier to build a nice-looking and adaptable
Web site.  Lots of startups use Bootstrap.  On one hand, it beats the
garbage that many so-called "designers" come up with.  On the other,
it shows almost no originality.

Nonetheless, as I noted a few months ago, I've bitten the bullet and
[moved my class Web sites to Bootstrap](giving-in-to-bootstrap).  In
that case, my primary reason was because it was clear that Bootstrap
and Jekyll were a better way to build the shared CSC 151 resources.

In the time since, I've found some other advantages to using
Bootstrap, many of which I knew.  It's (relatively) easy to switch
the overall appearance, since there are a variety of [Bootstrap
themes](https://bootswatch.com/) easily available.  My colleagues
had also developed some simple tools for keeping a theme, but 
modifying the color palette.

But appearance (or at least theming) is not the main reason I like
Bootstrap.  The primary advantage I've seen is that if one uses 
Bootstrap correctly, sites are more accessible.  Since I consider it
part of my responsibility to make my sites accessible, I appreciate
things that help me in that job.

I also like how Bootstrap allows sites to adjust to different screen
sizes, particularly to mobile devices.  

In any case, these reasons led me to start thinking about how to move
the musings to a Bootstrap theme.  I had originally planned to use
both Jekyll and Bootstrap because I like Jekyll's ability to set and
use variables and to use control structures like conditionals and 
loops.  But I realized that it would be too much of a pain to make
that conversion.  So I'm just using Bootstrap.

Unfortunately, like every programming project, converting the musings
to Bootstrap turned out to take more effort than I expected.  First, I
discovered that I wasn't getting the hamburger menu to work on my mobile.
It took about two hours to figure out why [1].  Then I realized that the
highlighting was wrong in the hamburger menu.  I could have ignored that
issue, but, well, I care about such things.  Then I decided to switch
from the Cosmo theme to the Readable theme, although with a different
navigation bar.  That ended up breaking more of the CSS than I expected
[2].

I started to work on the navigation bar, but I think that's going to be
a task for another day.  

I've thought about rearranging the files.  But I think it's important
the URLs remain consistent.  At some point, I may rearrange a bit [4], but
the old URLs will point to the new locations

I hope that you find the new site easier to read and easier to use.  I'd
appreciate any comments or suggestions you have for grouping or organizing
materials.  

---

[1] It turns out that I needed some JavaScript in the footer.

[2] Perhaps I should just stick with the default Readable theme.
I'll probably figure out how to switch back to that some time soon [3].

[3] I did try, but the menubar did not collapse like I like it to.

[4] E.g., to create a subdirectory for each category.

---

*Version 1.0 released 2017-07-09.*

*Version 1.0.1 of 2018-02-25.*

