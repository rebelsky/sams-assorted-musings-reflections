# Makefile
#   Instructions for building documents for the Web site known as
#   Sam's Assorted Musings / Reflections.
#
#   At some point, I'll document what files are expected.
#
#   Many portions of this file are stolen from other Makefiles I've 
#   written in the past.

# +------------------+------------------------------------------------
# | Standard Targets |
# +------------------+

default: html

clean: 
	rm -f *.html *.ps *.pdf 

# +---------+---------------------------------------------------------
# | Globals |
# +---------+

# +-----------------------+-------------------------------------------
# | Converting file types |
# +-----------------------+

%.ps: %.html
	html2ps -D -o $*.ps $<

%.pdf: %.ps
	ps2pdf $<  $*.pdf

%-md.html: %.md
	mdfootnotes $< | Markdown.pl > $@

%.html: %-md.html resources/template.html
	wrap-md-html $^ > $@

# +---------------+---------------------------------------------------
# | Sets of files |
# +---------------+

md := $(shell ls *.md 2>/dev/null)      # Lists all files matching *.md
                                        # sending error messages to /dev/null
md-html := $(md:%.md=%.html)            # Converts .md to .html
md-pdf := $(md:%.md=%.pdf)              # Converts .md to .pdf

html: $(sect-html) $(md-html)           # Builds all valid .html targets
pdf: html $(sect-pdf) $(md-pdf)         # Builds all valid .pdf targets

# +-----------------+------------------------------------------------
# | Generated files |
# +-----------------+

INDICES = index-by-topic-head.md \
	index-on-writing.md \
	index-prospective-students.md \
	index-prospective-faculty.md \
	index-current-students.md \
	index-alumni.md \
	index-important-issues.md \
	index-rants.md \
	index-talks-speeches.md \
	index-thank-you.md \
	index-overcommitment.md \
	index-teaching-online.md \
	index-recommendations.md \
        index-cnix.md \
	index-joc.md \
	index-grinnellians.md \
        index-grinnell.md \
        index-incoming-chair.md \
	index-reviews.md \
        index-autobiographical.md \
	index-misc.md \
        index-multiple-entries.md \
	index-removed.md 

index-by-topic.md: $(INDICES)
	cat $^ | sed -e '2!s/=/-/g' > $@

index-by-number.md: index-by-topic.md
	grep '#' index-by-topic.md  \
	| sort -k2 -t# -n -u \
	| by-number \
	> index-by-number.md
