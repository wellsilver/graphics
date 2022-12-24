# graphics

## docs

### Files

``graphics.h`` the graphics library

``platform/grphc_console.h`` renderer that prints to console, used in the quickstart below

``platform/*`` renderers provided by everyone (to add yours submit pull request) look in the folder of your platform for the renderer you would like and use it :) they may have instructions with them

### quickstart

This little code snippet should showcase all of the functions for graphics.h

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep()
#include "graphic_console.h" // prints graphics to console (it or similar required), there is a SDL2 renderer in ``./platform``
#include "graphics.h" // the header (obv required)

int main() {
  pixel white = g_rgb(255,255,255); // the color white
  grphcs a = grphc_new(10,10);
  graphic_setp(&a,g_xy(4,4),white); // center of the 10*10 graph
  while (1) {
    graphic_draw(&a);
    sleep(1); // dont overload the terminal!!
  }
}
```

## functions

### basic

``vec2 g_xy(int x,int y)``
quickly makes a vec2 x,y and returns

``pixel g_rgb(int r,int g,int b)``
quickly makes a pixel in rgb format

``grphcs grphc_new(int sizex,int sizey)`` 
makes a new graphic (2D graph) sizex*sizey large

### pixel access

``pixel graphic_getp(grphcs *_grphc,vec2 pos)``
returns the pixel at pos

``void graphic_setp(grphcs *_grphc,vec2 pos,pixel set_to)``
sets the pixel at pos to set_to

### gfx

``void graphic_clear(grphcs *_grphc,pixel color)``
set the entire screen to color

``void graphic_line(grphcs *_grphc,vec2 from,vec2 to,pixel color)``
makes a line from from to to with the color of set_to

``void graphic_fill(grphcs *_grphc,vec2 pos,vec2 size,pixel color)``
fills a square in at pos as large as size with color


