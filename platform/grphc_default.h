#ifndef GRAPHIC_DONE
#define GRAPHIC_DONE
#include <stdio.h>
#include <stdlib.h> 
// not needed, used by graphic_console not by graphics.h
struct graphic_r_save {
  int sizex;
  int sizey;
  int a_dist;
  char *a;
};
// called when map_new is called
void graphic_r_init(struct graphic_r_save *save,int size_x,int size_y) {
  save->sizex = size_x;
  save->sizey = size_y;
  save->a_dist=0;
  save->a = (char *) malloc(sizeof(char)*(size_x*size_y));
}
// called for each pixel
void graphic_r_putpixel(struct graphic_r_save *save,int x,int y,int r,int g,int b) {
  if (y+x==0) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
  }
  if (r+g+b>384) {
    putchar('+');
  }
  else {
    putchar('-');
  }
  if (y+1==save->sizey) { // every time y changes print a new line
    putchar('\n');
  }
}
// called when all pixels placed, to finalize placing.
void graphic_r_finishpixels(struct graphic_r_save *save) { 
  // nothing to do, just leave it blank
}
#endif
