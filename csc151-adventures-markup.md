Adventures in markup
====================

*Topics/tags: [The joy of code](index-joc), [CSC 151](index-csc151), markup languages, Jekyll, technical, rambly*

**Choosing a markup language**

A key issue I've been struggling with as I prepare the new CSC
151 is what markup language to use for the readings and labs.
When Janet Davis and I first created the image-focused CSC 151,
we used [DocBook](https://docbook.org/) as our markup language.
A few years ago, Charlie Curtsinger encouraged us to switch to
[Markdown](https://en.wikipedia.org/wiki/Markdown) [1] as part of the
more general use of [Jekyll](https://jekyllrb.com/) for the course sites.
Markdown has the advantage that it's simple and easy to write.  It has
the disadvantage that it's relatively shallow in it's capabilities.

There are host of other possibilities.
[LaTeX](https://www.latex-project.org/) is powerful; it's
also a markup language [2] that most CS faculty know well.
[Scribble](https://docs.racket-lang.org/scribble/) is the standard
language for Racket documentation and can produce both Web pages and
nicely formatted text.  It's also extensible with Racket code.

I initially settled on Scribble.  It seemed sensible to follow the
standards of the broader Racket community.  Scribble had also been
on my list of languages to learn, particularly because at least some
digital humanities Racket work uses Scribble.  Perhaps most importantly,
Scribble provides a nice interface for showing what happens in the
interactions pane.  For example, if I enter

    @examples[
    (+ 3 5)
    (define inc
      (lambda (x)
        (+ 1 x)))
    (inc 4)
    inc
    (circle 15 'outline "blue")
    (circle 10 'solid "red")
    ]

I'll see a result that looks something like the following, except with
syntax highlighting on [3].

<pre>
> (+ 3 5)                    
8                            
> (define inc                
    (lambda (x)              
      (+ 1 x)))              
> (inc 4)                    
5                            
> inc                        
#&lt;procedure:inc&gt;
> (circle 15 'outline "blue")
<img src='images/shapes1-01.png' alt='A hollow blue circle of radius 15'/>
> (circle 10 'solid "red")   
<img src='images/shapes1-02.png' alt='A solid red disc of radius 10'/>
</pre>

That feature helped convince me to use Scribble for my work.

**Revisiting my choice**

A few months later, and I've found myself questioning that decision.
As I reflect, I've found a variety of reasons that I don't want to
use Scribble.  Most importantly, I find myself writing more slowly
when I use Scribble.  I'm not sure about all the reasons, but it's
clear that I'm much too accustomed to writing in Markdown and using
Scribble inserts some extra mental baggage.  

I've also encountered an issue that a colleague refers to as "I don't
want to debug syntax when I'm writing."  Too often, I've missed a brace,
parenthesis, or bracket and get a vague error message.  That happens no
matter what markup language I use, but I find Scribble harder to debug.

Scribble is also a niche language, so help is limited.  It's also not
supported by [Pandoc](https://pandoc.org/), which means that I have more
effort in translating formats.  Because it's a niche language and I don't
completely understand it, it's hard to achieve all of the things I want.
For example, while I appreciate the ability to include image-making
commands in my Scribble code, I haven't been able to find a natural way
to get alt text into the resulting images.

It's also the case that most of the CSC 151 materials get edited and
updated by multiple people.  It will be much harder for my colleagues
to work with Scribble than, say, Markdown.  Our site is also
configured to do some convienient tasks with Markdown files, such
as automatically extracting the title.

So I've realized that I should probably go back to Markdown.  I don't
regret choosing Scribble; I learned a variety of things using it.  I may
even use it for the "textbook" version of the CSC 151 materials.  However,
for the time being, it strikes me that Markdown will be better for this
semester, particularly given how far behind I am on my writing [4].

**Incorporating features**

As I reflected on the switch from Scribble back to Markdown, I realized 
that I would miss the capability quickly generate examples quickly.  I'd
written something to something similar a decade or so ago, but I haven't
used it for at least five years, and I'm not sure that it works anymore.
As importantly, it doesn't handle Racket images.  "That's okay," I said
to myself, "I'm a programmer.  I can write something new that uses
Scribble as a helper."

At first, I was a bit worried about the complexity of parsing the HTML
that Scribble generates.  It's not something that's all that hard once
you understand the structure of a document.  But that meant looking at
the document structure and reminding myself how to deal with HTML
parsing.

Then I realized that Scribble can also generate Markdown as output.
At that point, I thought the process would be straightforward.
I could write a program that reads Racket code from standard input or
a file, wraps it with the appropriate Scribble code, runs Scribble on
it with the Markdown output feature, and put the generated Markdown in
the appropriate place.

But Scribble doesn't generate images when you use Markdown.  Here's
what I ended up with when I ran my program on the example above.

    ```racket
    > (+ 3 5)                    
    8                            
    > (define inc                
        (lambda (x)              
          (+ 1 x)))              
    > (inc 4)                    
    5                            
    > inc                        
    #<procedure:inc>             
    > (circle 15 'outline "blue")
    #(struct:object:image% ...)  
    > (circle 10 'solid "red")   
    #(struct:object:image% ...)  
    ```

That's not quite what I wanted.  But I'm a creative programmer.  I realized
that when Scribble generates HTML, it also creates images in order with a 
standard naming scheme: The first image is `pict.png`; the next is
`pict_2.png`; the next is `pict_3.png`; and so on and so forth.  That
meant that I could postprocess the Markdown code, replacing those image
placeholders with appropriate code.  And, to prevent name overlap, I
could also rename the images.  Here's some sample output from the updated
program.

    > (circle 15 'outline "blue")
    ![IMAGE1](./shapes1-01.png)
    > (circle 10 'solid "red")   
    ![IMAGE2](./shapes1-02.png)

For those who don't read kramdown-style Markdown, the way you describe
an image is `![alt text](url)`.

I was feeling pretty satisfied with myself.  I realized that, at present,
I would need to update the alt text for each image manually.  But at least
I had access to the alt text and the images.  If I really wanted to automate
things, I could add command-line flags to my script to add alt text [6].

**An obstacle and a solution**

Unfortunately, that output did not suffice.  You see, kramdown won't
process image markup (or any markup) in preformatted sections.  That
is, the basic output from the code block above looks something like
the following.

    <p><code>
    &gt; (circle 15 'outline "blue")
    ![IMAGE1](./shapes1-01.png)
    &gt; (circle 10 'solid "red")   
    ![IMAGE2](./shapes1-02.png)
    </code></p>

What I want is something more like this.

<pre>
&lt;pre&gt;
&amp;gt; (circle 15 'outline "blue")
&lt;img src="./shapes1-01.png" alt="IMAGE1"/&gt;
&amp;gt; (circle 10 'solid "red")   
&lt;img src="./shapes1-02.png" alt="IMAGE2"/&gt;
&lt;/pre&gt;
</pre>

I suppose I could just generate that directly.  But the Jekyll site
adds syntax highlighting with [Rouge](http://rouge.jneen.net/), and
I'd prefer to preserve that highlighting.  What does the Jekyll
output look like?  Let's see.

    <div class="language-racket highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="nv">&gt;</span> <span class="p">(</span><span class="nf">circle</span> <span class="mi">15</span> <span class="ss">'outline</span> <span class="s">"blue"</span><span class="p">)</span>
    <span class="nv">!</span><span class="p">[</span><span class="nf">IMAGE1</span><span class="p">](</span><span class="o">.</span><span class="nv">/shapes1-01</span><span class="o">.</span><span class="nv">png</span><span class="p">)</span>
    <span class="nv">&gt;</span> <span class="p">(</span><span class="nf">circle</span> <span class="mi">10</span> <span class="ss">'solid</span> <span class="s">"red"</span><span class="p">)</span>
    <span class="nv">!</span><span class="p">[</span><span class="nf">IMAGE2</span><span class="p">](</span><span class="o">.</span><span class="nv">/shapes1-02</span><span class="o">.</span><span class="nv">png</span><span class="p">)</span>
    </code></pre></div></div>

Lovely, isn't it?  I started to compose a letter to a colleague who is
better at this stuff than I am.  However, after some reflection, I realized
that the best strategy was probably to post-process
the page.  Amazingly, there was [a helpful post on Stack
Overflow](https://stackoverflow.com/questions/26615640/postprocessing-html-in-jekyll).
Of course, that meant learning how to write a Jekyll plugin.  It
turns out that writing the plugin was easier than I expected.

**Wrapping up**

That's about it.  I now seem to have the tools I need to generate Racket
examples, including Racket examples that build images.  Perhaps I'll
report back in a few days on how well it works in practice.

What languages did I use to do this work?  Let's see.  I used Perl for
my script to build, run, and parse the Scribble code.  The Jekyll plugin
is in Ruby.  There's a very small piece of Liquid in the Ruby plugin.
I needed to know a little bit of HTML and Markdown.  Do we count regular
expressions as a language?  I wrote some ugly ones.  Ah, the joy of code.

---

**Appendix A: My Jekyll plugin**

Here is the Jekyll plugin in wrote [7].

    # Process images of the form ![alt text](url) in preformatted Scheme code.
    # Set preimg to true in a page's yaml prologue to enable.

    module Jekyll
      module ProcessImageInPreFilter
        def process_image_in_pre(input)
          preimg = process_liquid "{{ page.preimg }}"
          if preimg == 'true' then
            result = input.gsub(/^<span class="nv">!.*$/) {|s| piipf(s)}
            result
          else
            input
          end
        end
    
        def piipf(str)
          # Drop the HTML tags
          newstr = str.gsub(/<[^>]*>/, "")
          if newstr =~ /^!\[([^\]]*)\]\(([^)]*)\)/ then
            result = "<img src='#{$2}' alt='#{$1}'/>"
            result
          else
            str
          end
        end
      end
    end

There's probably a better way to get the yaml flag from the environment,
but my more sensible attempts failed.  This one has the unfortunate
consequence of always returning a string, which is why I have the
strange `preimg == 'true'`.

On a separate note, I thought about using the `markdownify` command in
computing the result, as follows.

            result = markdownify newstr
            result.sub!("<p>","")
            result.sub!("</p>","")

Strangely enough, even though that produces similar output, my Web browser
renders it differently, with space after the image.  I can't figure
out why.  Have I mentioned how much I hate computers?

---

**Appendix B: My script**

My Perl script for building the Markdown is a bit too long for this
musing.  You can find it online at <https://raw.githubusercontent.com/rebelsky/samr-utils/master/rackex>.

---

[1] More precisely, [kramdown](https://kramdown.gettalong.org/), a dialect
of Markdown.

[2] LaTeX may be Turing complete.  So perhaps I should refer to it as
a programming language.

[3] I've also added alt tags for the images.  More about that later.

[4] If I'm behind on my writing, why am I taking the time to muse?
One reason is that I wanted to think through the various issues in a
bit more depth.  Another is that I enjoy musing [5].

[5] I also often enjoy writing the daily readings and labs for CSC 151.

[6] Come to think of it, that's a good time-wasting activity.  I'll do
that soon.

[7] Yes, I should probably work on my Ruby style.

---

*Version 1.0 of 2019-01-09.*
