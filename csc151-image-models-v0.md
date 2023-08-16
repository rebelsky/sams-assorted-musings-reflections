---
title: Preliminary notes on revised image models for CSC-151
number: 1253
tags: [CSC-151](index-151), rambly, semi-technical
blurb: Just starting to think through the issues.
version: 1.0
released: 2023-08-15
current: 
---
As you may have seen in [an earlier musing](csc151-2023fa-learning-objectives), this fall, I'm building a revised version of the old "mediascheme" version of CSC-151 [1].  In particular, I'm returning to a course model in which students focus on image making and manipulation.  If I recall correctly, four primary issues made that version of the course successful.

* Students reported that it's easier to see when something goes wrong when you're trying to make an image than it is when you're, say, computing a value.
* We could use multiple models of image making, which allowed students to compare and contrast models and to consider which might be most appropriate for a particular task.
* Once we'd chosen suitable models and an appropriate ordering, students seemed to understand pure code [2] better.
* It was fun for both students and faculty.  We often saw students thinking about what else to do with an assignment.

Why did it go away?  In part, we wanted to look at other themes, themes potentially of interest to different groups of students.  In part, we acknowledged that the infrastructure that we'd built was fritzy [3,4].  In part, we wanted to have versions of the course that might be more accessible to those with limited vision.

So why return to the model?  In part, it's that it's my favorite of the models we've developed.  In part, it's that image making has been creeping back into the course; for example, students often end up doing some kind of data visualization in the other versions of the course.

Do I worry about accessibility issues?  A bit.  But that's one of the reasons we have multiple themes.  Since the other fall sections will emphasize sound and music, students with vision issues might choose those sections, while students with hearing issues might choose my section.  We also rarely get students with significant vision or hearing issues [6,7].

As I said, we had multiple models of image making.  So one of my responsibilities in preparing for the new course is building image-making libraries to support all those models.  A year or so ago, when I decided to make the change, I assumed I'd be working with DrRacket.  Now that we seem to have adopted Scamper as our Scheme implementation, I'm likely to be working with Scamper.  Ideally, it won't matter which implementation I use, at least from the API design side.

As is occasionally the case, I'm using this musing to think through ideas.  In this case, those ideas are the issues and the design relating to our image making model.  You should expect incomplete thoughts, side trips, retreats from bad directions, and more.  Believe it or not, but my complete thought process is even more convoluted; I've tried to think through many of these issues, both consciously and subconsciously [8].  Nonetheless, writing down those abstract thoughts helps me consider them in new ways.  And that's one of the reasons I enjoy writing [9].

---

Back in the day, we had five models of image making: Color grids, drawings as values (aka "shapes"), images as functions, GIMP tools, and Turtle graphics.  At least, those are all that I recall.

*Color grids* are the simplest model and exist primarily to get students thinking about RGB colors and the manipulation of RGB colors.  Once you build a few colors, you can put them into a grid.  This model does not permit very sophisticated images.  But, as I said, it introduces students to the color model.  It also primes students to understand pure functions.  You don't expect "a darker version of red" [10] to change the color red.  You don't expect "a darker version of our base color" [11] to change our base color.  So why would you expect "a scaled version of this drawing of a house" to change the drawing of a house?  More precisely, you should read `(drawing-scale house 2)` as "a copy of house, scaled by a factor of two", rather than as "enlarge house by a factor of 2".  The former is a new drawing; the latter is a mutated drawing.

*Drawings as values* (aka "shapes", aka "advanced colorforms" [12]) treat images as collections of basic shapes (e.g., the unit circle and the unit square) that can then be recolored, stretched, shifted, and combined in various ways.  This model reinforces the idea of pure functions and also gives an easy-to-understand (and debug) approach to image making.  Note that if we can "shift" shapes, we're using an explicit coordinate plane.  We used the traditional graphics model, with (0,0) at the upper-left-hand corner.  We'll explore a variant of this mode---one without a coordinate plane---in a bit.

*Images as functions* treat images as functions from coordinates to colors.  You can use this model to create fascinating color blends.  But you can also use this model to create the basic shapes mentioned above.  For example, the function to create a 10x10 blue square centered in a 20x20 red square asks if the x and y coordinates are both between 10 and 20; if so, it uses the color blue.  Otherwise, it uses the color red.  If I recall correctly, we would write that as

```
(image-compute 20 20
               (lambda (x y)
                 (if (and (<= 10 x 19) (<= 10 y 19))
                     "blue"
                     "red")))
```

This model is, by far, my favorite.  In part, it's because we could do some amazing things with it.  In part, it's because it permits a wide variety of relatively small "thinking" problems.  In part, it's that it reinforces the value of math, particularly as you try to do shapes like triangles and circles.  I'm not sure that all students liked that last bit.

The model also provides a natural model of image transformation: Many image transformations can be represented as a color transformation applied to each pixel in the grid.

The model had one "useful bug".  We treated all colors as integers.  Hence, you could generate very unexpected but enjoyable effects by, say, multiplying all of the colors in an image by 3.  I don't expect to replicate that effect in our new model.  But we can still find other transformations to do.

Since we're using coordinates, this model also relies on a coordinate grid.

*GIMP tools* [14] used the GNU Image Manipulation Program to build images.  This model allowed us to switch from functional thinking to a more stateful model.  It's also a model that corresponds to how they often think about writing series of instructions.  "Select the ellipse tool.  Then drag from (10,10) to (50,30).  Select the brush tool.  Set the brush to the radius 3 paintbrush.  Outline the selection."  Students had a lot of fun with this model, particularly given GIMP's wide variety of brushes.  The green pepper was surprisingly popular.

As the "drag from (10,10) to (50,30)" suggests, this model also uses a coordinate system.

Unfortunately, the connection to GIMP is what caused things to crash.  And I don't think we'll attempt to replicate the GIMP features in the new course.  Oh well; you can't have everything.

*Turtle Graphics* is an image-making model from Seymour Papert's LOGO.  In the first versions of LOGO, released in the early 1960s, students programmed robots that looked a little like turtles.  You could attach a pen to the turtle, and they'd make interesting drawings on the floor.  Soon thereafter, Papert's team created virtual turtles.  Turtle graphics have been a thing ever since.  As you might expect, turtle graphics are a very imperative model, one in which you tell the turtle to lift and drop the pen, move forward, turn, and such.  Once you add control structures, you can create amazingly complex images.

In teaching the course, I drew upon James Clayson's [_Visual Modeling with Logo_](https://www.academia.edu/5203649/Visual_modeling_with_Logo_a_structured_approach_to_seeing) [15] for clever examples.  It's a fantastic book on the kinds of things you can do with basic turtle graphics.  And since it comes from the Logo community, it also has a clear constructionist perspective [16].

---

There's also another image model: The [Racket 2htdp [17] image model](https://docs.racket-lang.org/teachpack/2htdpimage.html).  In many ways, it's an improvement upon our drawings-as-values model.  In particular, it permits more basic shapes and more ways to combine shapes.  On the other hand, it doesn't appear to provide the same kinds of access/manipulation we had, such as recoloring objects or mapping a function onto a compound image.  I also like that the Racket drawing model presents shapes as data.  That is, when you create a shape, it shows up as the shape rather than a textual representation thereof.

There's one critical difference between the Racket drawing model and our drawings-as-shapes model.  Our model was coordinate-based, and we rendered images on a canvas, so if you tried to render a drawing outside of the bounds of the canvas, the drawing wasn't visible.  Racket drawings don't have a coordinate space, at least not until you put them in a scene.  Is one strategy better than the other?  I don't think so.  There are times when coordinates are more convenient (we saw that when students were trying to do some kinds of precise drawing with the Racket 2htdp model), but there are other times in which they get in the way (e.g., when we're making lists of drawings).

The designers of Scamper have included something like the Racket 2htdp image model, so I'll have a good starting point.

---

At a conference some years back, the legendary Brian Harvey [18] stopped by to talk to me as I was talking about the old MediaScheme course.  Brian asked me why the different models didn't cohere better.  For example, why couldn't I place a functional image next to a drawings-as-values image?  As I rethink the course, it may be time to consider that question.  It's not that I haven't been thinking about the question; it's just that I haven't reached a conclusion.

The biggest problem I see in making the models cohere has to do with moving between coordinate-based models (drawings-as-values, functional images, turtles, scenes, GIMP Tools) and the non-coordinate-based models (colors and color grids, Racket 2hdtp images).  

Hmmm ... since Racket seems to move between the two, perhaps I can, too.  I'll need to explore their model further.  And I'll have to get used to different terminology.  The things I call "drawings", they call "images".  The things I call "images" or "canvases", they call "scenes".

On a separate note, a coherent model should permit me to eliminate color grids.  After all, if colors are images, color grids are just colors arranged using horizontal and vertical composition.  The open question I have is how to size the composition.  Or maybe colors shouldn't be images; perhaps we can still require students to put them in little shapes.  That should be easier if they do simple shapes first.

---

Hmmm ... I was anticipating that I would get further than this.  But that's about all I'm up to thinking about right now.  Perhaps I'll discuss a set of functions and their meanings in a subsequent musing.  Perhaps more than one musing.  It doesn't matter yet, because the new Scamper is still not ready.

Stay tuned!

---

**_Postscript_**: What does it say about me that I wrote a long musing about images and still didn't manage to include any?

---

[1] CSC-151, _Functional Problem Solving_, is the introductory course in Grinnell's Computer Science curriculum.  It serves prospective majors as well as students who want to gain some skills in computational thinking.  We often "theme" the course, giving students a problem-solving domain to ground their work.

[2] A pure function does not change its argument.  If you write `(enlarge img)`, `img` stays the same size; you just get back a larger copy.  Similarly, if you write `(louder sound)`, `sound` stays the same volume; `louder` returns a louder version.  One of the debates I had with the originator of media computing was whether these kinds of procedures should be pure or mutate their parameters.  I think he's finally come around to my perspective.

[3] Students and faculty both appreciated getting rid of the regular crashes.

[4] No, not Fritzi Ritz.  Random trivia: My mother's nickname was "Fritzi Ritz".  Fritzi Ritz was also a cartoon character.  She's Nancy's aunt, but she had her own strip before Nancy [5].

[5] Fritzi Ritz had the strip, not my mother.

[6] Nonetheless, we should plan for such students in advance so that we don't scramble to support them at the last moment and, therefore, give them an inferior learning experience.

[7] We did have one student with significant vision impairment take the data science version of the course.  That worked acceptably well.

[8] I've even dreamed about them.

[9] Or at least musing.

[10] `(color-darker "red")`, as we'd write it in Scheme.

[11] `(color-darker base-color)`, as we'd write it in Scheme.

[12] Sadly, few of my students seem to know what Colorforms are.  That's okay

[14] Please excuse the somewhat offensive name.  I didn't name it.  I'm surprised that they still have not changed the name.

[15] For some reason, the print copy often sells for $100 or more.  But you can download the PDF for free.  I've accumulated a few too many print copies that I found for much less than $100.  (The PDF wasn't available when I bought them.)

[16] In its shortest formulation, Papert's Constructionism is a variant of Piaget's Constructivism.  In its simplest formulation, onstructionism suggests that we build knowledge (and the schemata on which we hang new knowledge) by building things.  Let's see ... what does [Wikipedia](https://en.wikipedia.org/wiki/Constructionism_(learning_theory)) say?

> Constructionist learning is the creation by learners of mental models to understand the world around them. Constructionism advocates student-centered, discovery learning where students use what they already know, to acquire more knowledge. Students learn through participation in project-based learning where they make connections between different ideas and areas of knowledge facilitated by the teacher through coaching rather than using lectures or step-by-step guidance. Further, constructionism holds that learning can happen most effectively when people are active in making tangible objects in the real world. In this sense, constructionism is connected with experiential learning and builds on Jean Piaget's epistemological theory of constructivism.

That seems to be a reasonable summary, at least according to what I know.

[17] 2htdp is the library for the second edition of _How to Design Programs_, one of the better introductory CS texts.

[18] Brian is responsible for an excellent set of Logo-based textbooks.  He is also one of the core folks on the [Snap!](https://snap.berkeley.edu) [19] team.

[19] A.k.a. Build Your Own Blocks.
