#include <stdlib.h>
typedef struct pixel {
  short int r;
  short int g;
  short int b;
} pixel;
typedef struct vec2 {
  int x;
  int y;
} vec2;
typedef struct grphcs {
  vec2 size;
  pixel **pixels;
#ifdef GRAPHIC_DONE
  struct graphic_r_save _dat;
#endif
} grphcs;

// utils
vec2 g_xy(int x,int y) {
  vec2 i;
  i.x=x;
  i.y=y;
  return i;
}

pixel g_rgb(int r,int g,int b) {
  pixel i;
  i.r=r;
  i.g=g;
  i.b=b;
  return i;
}

grphcs grphc_new(unsigned int x,unsigned int y) {
  grphcs i;
#ifdef GRAPHIC_DONE
  graphic_r_init(&i._dat,x,y);
#endif
  i.size.x=x;
  i.size.y=y;
  i.pixels = (struct pixel **) malloc(sizeof(struct pixel *)*y);
  int loop;
  for (loop=0;loop<y;loop++) {
    i.pixels[loop] = (struct pixel *) malloc(sizeof(struct pixel)*x);
  }
  char clear = 0;
  int loop2;
  for (loop=0;loop<x;loop++) { // malloc doesnt initialize, we need to do it manually
    for (loop2=0;loop2<y;loop2++) {
      i.pixels[loop][loop2].r=clear;
      i.pixels[loop][loop2].g=clear;
      i.pixels[loop][loop2].b=clear;
    }
  }
  return i;
}

pixel graphic_getp(grphcs *_grphc,vec2 pos) {
  return _grphc->pixels[pos.y][pos.x];
}

void graphic_setp(grphcs *_grphc,vec2 pos,pixel set_to) {
  _grphc->pixels[pos.y][pos.x] = set_to;
}

void graphic_draw(grphcs *_grphc) {
#ifdef GRAPHIC_DONE
  int loop,loop2;
  pixel cr;
  for (loop=0;loop<_grphc->size.x;loop++) {
    for (loop2=0;loop2<_grphc->size.x;loop2++) {
      cr = graphic_getp(_grphc,g_xy(loop,loop2));
      graphic_r_putpixel(&_grphc->_dat,loop,loop2,cr.r,cr.g,cr.b);
    }
  }
  graphic_r_finishpixels(&_grphc->_dat);
#endif
}
