The Joy of Code: Playing with Processing, Example 1
===================================================

This semester, I'm teaching an online course using the Processing
programming language.  Processing is a language that is based on Java
and is somewhat designed "by artists, for artists".  (You might ask
why an artist would design a language based on Java.  Maybe they hate
their peers.)  Anyway, this week the students are exploring pixels and
filters.  I spent about three hours tonight coming up with instructions
and examples for them.

One of the first examples was an animation to illustrate a simple point.
Here's the gist.  For frame `i`, the program turns every `i`th pixel
white.  (Everything else gets set to black.)  That's it.  I had intended
the example to get them thinking about how the two-dimensional grid
of pixels gets mapped to a one-dimensional array.  However, it turns
out to have some interesting effects, at least from my perspective.

Here's the code.

    color black = color(0);
    color white = color(255);
    int frame = 0;
    
    void setup() {
      size(100, 100);
      loadPixels();
      frameRate(5);
    } // setup()
    
    void draw() {
      println(frame);
      frame = (frame % pixels.length) + 1;
      for (int i = 0; i < pixels.length; i++) {
        if (i % frame == 0) {
          pixels[i] = white;
        } else {
          pixels[i] = black;
        }
      } // for
      updatePixels();
    } // draw

I had thought that you could readily see the space between pixels increasing.
And, at times, you can.  But you also get some very interesting
patterns and transitions between patterns.  Download Processing, run
this program, and maybe you'll understand what I mean about it being
somewhat surprising.  You can also try to view the [video](pixels.mp4),
but I haven't had much luck with it.

Here's what I like most about the program.  It took me less than ten
minutes to write.  It creates an interesting animation (or at least
interesting to me).  It's easily adaptable for new things (e.g.,
I'm already thinking about other ways to update the array of pixels,
such as using changing colors, or alternating setting black and white,
wthout setting the other color, or ....)  I could probably spend hours
playing with new versions of the program, relying both on systematic
experimentation and unpredictability (or at least unpredictability to
my limited way of thinking).

While I don't like the Processing is a Java variant (and there are
some excellent critiques of using the Java model), I like that I can
throw together programs quickly, discover new things, and play to my
heart's content.

When code and art come together, it brings me joy.  I spent more than
three hours coming up with examples and instructions for my students,
so I had the opportunity for a lot of joy.  Maybe I'll share some of
the interesting filters I've written in another post (particularly when
I decide on an easy way to include images in posts).

---

Yesterday, I wrote about how I choose what kind of essay to write.  Can
you tell how the use led me to this one?

---

*Version 1.0 released on 2016-10-17.*

*Version 1.0.1 of 2018-01-02.*

