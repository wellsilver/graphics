# graphics

## docs

### Files

``graphics.h`` the ansi-c graphics library

``platform/grphc_console.h`` renderer that prints to console, used in the quickstart below

``platform/*`` renderers provided by everyone (to add yours submit pull request) look in the folder of your platform for the renderer you would like and use it :) they may have instructions with them

``libs/*`` libraries for graphics.h

### quickstart

This little code snippet should showcase all of the functions for graphics.h

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep()
#include "graphic_console.h" // prints graphics to console (it or similar required)
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
