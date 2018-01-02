Building the CSC 151 Site
=========================

*This musing represents some rough instructions for my research assistants
on contributing to the CSC 151 Web site.  It may eventually become the
instructions for students to contribute.*

We use a variety of tools and languages to build the
CSC 151 Web site.  Our primary site building platform is
[Jekyll](http://jekyllrb.com/).  Jekyll relies on a form of
[Markdown](https://daringfireball.net/projects/markdown/) for writing
Web pages and [Liquid](https://github.com/Shopify/liquid/wiki) for doing
more programmatic aspects of development.  Most of the styling is done
with [Bootstrap](http://getbootstrap.com/) and the [Bootswatch Cosmo
Theme](https://bootswatch.com/cosmo/). We also use some additional CSS
and even some raw HTML for part of the development.

This document is intended to give you just enough information to deal
with building and modifying the site.

Directories
-----------

Jekyll has an interesting model for site development.  Directories whose
names begin with an underscore are processed according to various
instructions.  Directories whose names do not begin with an underscore
are copied directly to the site.  Hence, most of the directories we work
with begin with an underscore.  Let's start with those directories.

`_assignments/`
  : Assignments, as the title suggests.

`_bodies/`
  : Bodies of SamR's daily outlines.

`_current/`
  : Pages that "automatically" link to the current reading, lab, or
    whatever.  The wonder of Jekyll lets us place them in the 
    appropriate directory (e.g., `_current/assignment` will end
    up in `assignments/current`).  We put these in a separate directory
    so that the scripts that index a directory don't include them.

`_data/`
  : Data for building the site.  This includes the list of classes, the
    course-specific configuration, and such.  The files in this directory
    are read and used to build the site, but are not copied into the
    site.

`_eboards/`
  : The daily "eboards" that SamR creates for the class.  

`_exams/`
  : The exams for the course.  Since we give take-home exams and the old 
    exams live on the Web, we are not worried that these are public
    (or at least I'm not that worried).

`_handouts/`
  : Various handouts for the course, such as guidelines on academic
    honesty or exam procedures.

`_home/`
  : The home page and other core pages, such as the syllabus and schedule.
    By having everything in a subdirectory, we are able to more easily
    use relative links (e.g., most links are `../dir/filename.html`).

`_indices/`
  : The indices for each section, such as labs, assignments, and readings.
    The wonder of Jekyll lets us place them in the appropriate directory
    (e.g., `_indices/labs` will end up in `labs/index`).  We put these
    in a separate directory so that the scripts that index a directory
    don't include them.

`_includes/`
  : Common parts of pages.  Nothing from this directory is used directly
    in the site, but much is used indirectly.

`_labs/`
  : The daily labs.

`_layouts/`
  : Another set of hidden files.  These are templates for producing
    pages, and part of the normal Jekyll setup.

`_links/`
  : The menus, as pages.  Included because people may turn Javascript
    off, which makes it impossible to get to the menus.

`_outlines/`
  : Sam's daily outlines.

`_overviews/`
  : I'm not sure why these are here.  Should be deleted.

`_plugins/`
  : Formatting information for Racket, I think.  (I got this from Charlie.)

`_problems/`
  : The problems that get incorporated into homework assignments and
    examinations.

`_quizzes/`
  : Placeholders for the quizzes so that they end up in the syllabus.

`_readings/`
  : The Daily readings.

`_reference/`
  : The reference pages.  Probably needs redoing.

`_related/`
  : Should be deleted.

`_sandbox/`
  : A place for experiments.

`_site/`
`_tools/`
`_writeups/`

It appears that there are only three other directories.

`code/`
  : Sample code

`css/`
  : Style sheets

`images/`
  : Images

And then there are a few files

`_config.yml`

`index.html`

`README.md`

Data
----

Includes
--------
