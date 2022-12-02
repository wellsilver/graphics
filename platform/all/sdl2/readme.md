This is very barebones, graphics.h is missing alot of things right now and not alot of effort was put into this

## Downloading

Download (SDL2 development libraries)[https://github.com/efornara/sdl2/releases]

## usage

2 global variables for your use

``static SDL_Renderer *SDL_r_renderer;``
``static SDL_Window *SDL_r_window;``

## example

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep()
#include "sdl2_renderer.h" // 
#include "graphics.h" // the header (obv required)

int main() {
  pixel white = g_rgb(255,255,255); // the color white
  grphcs a = grphc_new(100,100);
  graphic_setp(&a,g_xy(49,49),white); // center of the 100*100 graph
  while (1) {
    graphic_draw(&a);
  }
}
```

## issues

window too small?

increase window size ``grphc_new(500,500)`` instead of ``grphc_new(100,100)``
