---
title: Redesigning the CSC-151 image model
number: 1268
tags: [CSC-151](index-151)
blurb: I may have done this before.
version: 1.0
released: 2024-01-09
current: 
---
I have slightly less than two weeks left in winter break. One of my highest priorities for winter break, beyond spending time with family and finishing grading, was rewriting [1] the image functions we use in 151. I last wrote about this issue [in August](csc151-image-models-v0), but lacked the time to finish the design or implement it. With a semester of teaching a new image-based 151 behind me, it's time to get to work. I've already spent a day or two on the work, which helped me better understand how I'd wrap the Racket `2hdtp/image` functions and got me to reflect more on what I wanted to do. This musing might help me move forward on ideas. I don't plan to discuss implementation this time through.

Why am I rewriting these procedures? There are a few reasons. 

First, I'd like to be able to extract more information from images. Is this a circle? A rectangle? A compound image? If it's one of the basic shapes, what color is it? Is it outlined or filled? If it's one of the compound images, what are the subimages?

Second, I'd like to make "bitmaps" a more explicit type of image. The 2htdp images provide mechanisms for moving between images and lists of pixels. I'd rather students be able to think of bitmaps as width-by-height grids of pixels. I added such functions last semester, but they were kludgey [2,3].

Third, I had hoped to support something like a `map` over images. I already have a `map` over the pixels. But for compound images, it would be nice to write a procedure that affects the individual shapes.

Finally, I've discovered over the past few days that I'm not very comfortable with 2htdp's design of the basic shapes. Consider, for example, the `circle` procedure, which builds a circle [4].

```
(circle radius mode color) → image?
  radius : (and/c real? (not/c negative?))
  mode : mode?
  color : image-color?
(circle radius outline-mode pen-or-color) → image?
  radius : (and/c real? (not/c negative?))
  outline-mode : (or/c 'outline "outline")
  pen-or-color : (or/c pen? image-color?)
```

What's a mode? It can be `'outline` or `"outline"`, which represents an outlined shape [5]. It can be `'solid` or `"solid"`, which represents a solid shape. It can be an integer between 0 and 255, inclusive, which represents the opacity [6].

Then there's that last parameter. In some cases, it must be a color. In some cases, it can also be a pen [7]. Will students find that confusing? It's somewhat strange. But what I find even more confusing is that colors can also have an alpha channel [8]. It appears there are two ways we can set the alpha channel; we can use the mode and we can use the alpha channel in the color. What happens if we use both? [9]

I appreciate the model of "put everything into one function". Nonetheless, I'd prefer to separate it into two procedures, `(solid-circle diameter color)` and `(outlined-circle diameter pen)`. What happened to the option of providing the opacity in the mode? To avoid ambiguity, the opacity can only be found in the color. What happened to providing the color for outlines? 'Eh, pens will suffice.

That's enough background. Our library should permit students to ask questions about images and decompose images. It should support "bitmaps" as a type of image. It should include `image-structure-map` or something similar; that comes almost automatically with appropriate decomposition procedures. I will reflect carefully on the basic shapes as I redesign them.

On to the overall design. I firmly believe in type hierarchies, so we'll have one for images.

Broad design
------------

An **image** (`image?`) is, well, an image or picture, a design or representation. Isn't that wonderfully vague? Images support a few basic operations: `(image-width img)`, `(image-height img)`, `(image-subimages img)`, `(image-structure img)`, `(image-get-pixel img col row)`, `(image-set-pixel! img col row color)`, `(image-save img file)`. Okay, it's not just a few. The `image-structure` procedure allows a programmer to get an imperfect overview of how the image is built. We can treat all images as bitmaps, even if they are not created as bitmaps. Speaking of bitmaps, I suppose we should also provide `(image-pixel-map fun img)`, that creates a new image by applying `fun` to each pixel in the image [10]. 

I gave students `bitmap->vector` and `vector->bitmap` procedures on an assignment last semester, writing them in terms of `image-get-pixel` and `image-set-pixel!`. I think I'll do that again this semester, rather than including them directly.

It may also be useful to write something like `image-description` for images, which would make it easier for people with vision issues to understand the things we've built. Or perhaps it suffices to have `image-structure`. Alternately, we could have an optional parameter to some procedures that permits the programmer to specify a description. Or there could be an `(image-describe img description)` procedure. 

Would it be useful to have `image-type`, that gives the type of an image (e.g., `'ellipse`, `text`)? Or does the structure suffice?

We don't build images directly. Rather, we work with one of the three primary kinds of images: basic images, compound images, and bitmaps.

A **basic image** (`image-basic?`) can be a shape (circle, square, rectangle, ellipse, polygon, etc.), a line (straight or curved), or some text. Basic images add `(image-color img)`. They might also have `(recolor img color)` that creates an equivalent image ina  new color. Is that it? I may need to think more on this issue. As one might expect, basic images have no subimages.

Some basic images (maybe just shapes) can be **solid** or **outlined**.

A **compound image** (`image-compound?`) is almost any image that is created by combining or transforming other images. For example, we might place images beside each other or above one another. We might overlay images. We might rotate, scale, flip, or crop images. I'm not sure that compound images add any new procedures; they are just a way to think about images. Should I separate combinations from transformations? The former will generally take two or more images as parameters; the latter will take only one.

A **bitmap** `(image-bitmap?)` is an image that we think about primarily as a grid of colors. It might be created by `(file->image filename)`. It may be created by `(image-compute fn width height)`. `(image-set-pixel img col row color)` also creates a bitmap. I'll have to consider whether there are others.

Is that it? Wow. I expected more. I suppose I will need to reflect more as I write the individual kinds of images.

The hierarchy
-------------

Here's an attempt to gather all of the types of images we'll create.

### The basic hiearchy

As I mentioned above, there are three primary types of images (at least I think there will be three primary types of images).

* Image
    * Basic image
    * Compound image
    * Bitmap

I haven't identified natural subtypes for Bitmaps, but basic and compound images need more consideration.

### Basic images

There are four kinds of basic images.

* Image
    * Basic image
        * Shape
        * Straight line
        * Curved line
        * Text
    * Compound image
    * Bitmap

Decomposing shapes will be a bit harder.

* Image
    * Basic image
        * Shape
            * Polygon
                * Regular polygon
                * Irregular polygon
                    * Rectangle
                        * Square
                    * Triangle
            * Ellipse
                * Circle

Hmmm ... I'm already hitting some problems with a strict heirarchy. For example,squares and equilateral triangles are both regular polygons and rectangles (which are _not_ regular polygons). Each of the shapes can also be solid or filled. A heirarchy is not the right model. Yay multiple inheritance [11]!

Then there are those "pulled polygons" that `2htdp/image` supports, but that I haven't used much. It would be nice to include them. But where do they fit in the model? And do I really want both `outlined-pulled-regular-polygon` and `solid-pulled-regular-polygon`? Is it appropriate to even call those polygons?

I may have to figure those issues out as I implement the various procedures.

I'm not sure that I need subclasses/subtypes for straight lines, curved lines, or text. Yay! Text will need some optional parameters, but I should be able to handle that.

### Compound objects

Did I decide to have two kinds of compound objects? I think so. Combinations of objects and transformed images.

* Image
    * Basic image
    * Compound image
        * Combination
            * Beside
            * Above
            * Overlay
            * Place
        * Tranformation
            * Rotated
            * Scaled
                * Horizontally scaled
                * Vertically scaled
            * Flipped
            * Cropped
    * Bitmap

The `2htdp/image` library also provides a `frame` transformation and an `underlay` combination. I'm not sure whether these are strictly necessary. Are `overlay` and `place` similar? Yes. One difference is that `place` also seems to crop.

Once again, I'll determine whether these others are necessary as I strive to implement or use them, or as students ask for them.

Detour: Colors
--------------

It's hard to think about images without considering colors [12]. The designers of `2htdp/image` used the term `color` for RGBA colors. Since there are a variety of kinds of colors (RGB(A) colors, color names, HSV colors, the `color%` objects that come with `racket/draw`, the `color` structs from `2htdp/image`, perhaps even indexed colors), I'm not comfortable with that terminology. I wonder how hard it will be to change everything to use different terminology. I wonder how much that will slow things down.

I guess that's my task for today. More on the details of the image library are coming soon!

---

[1] Or perhaps "wrapping".

[2] Is "kludgey" really a word, or just a SamR invention, like "recurse"? Yup, it's a real word. Google tells me that [Oxford Languages](https://languages.oup.com/google-dictionary-en/) says it means "awkwardly or inelegantly made or done". That's an appropriate description of last semester's bitmap model.

[3] I wrote "a bit kludgey". Grammarly told me to remove "a bit". I wonder how it knows so much about my programming.
[4] Taken from [the documentation for `2hdtp/image`](https://docs.racket-lang.org/teachpack/2htdpimage.html#%28def._%28%28lib._2htdp%2Fimage..rkt%29._circle%29%29).

[5] It's nice to have the option to use a symbol or a string.

[6] Also known as the alpha channel.

[7] We'll reflect on pens at a later time.

[8] That is, an opacity.

[9] Experimentation suggests that it multiplies the two alpha channels and divides by 255.

[10] And yes, I should permit more than one image, provided they are all the same size.

[11] Perhaps interfaces. Perhaps mixins.

[12] Perhaps it's only hard for sighted people to think about images vs.
