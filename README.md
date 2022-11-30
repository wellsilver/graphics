# graphics
totally is not broken af and hung together by pure luck :)

note: It may segfault clang (but not gcc) if it segfaults clang simply compile it as a dynamicly linked library instead

## docs

### Files

``graphics.h`` the ansi-c graphics library

``platform/grphc_default.h`` an excerpt from graphics.h showing how to make your own renderer for graphics.h

``platform/*`` renderers provided by everyone (to add yours submit pull request) look in the folder of your platform for the renderer you would like and use it :) they may have instructions with them

### quickstart

This little code snippet should showcase all of the functions for graphics.h

```c
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

int main() {
  grphcs a = new_win(10,10);
  
  draw(&a);
}```
