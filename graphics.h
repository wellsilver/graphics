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
  if (r>255 || g>255 || b>255) {
    // thats not valid!
  }
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
// use bresenhams to draw a line from,to with the color of color ex, graphic_line(&a,g_xy(1,1),g_xy(9,9),g_rgb(255,255,255))
void graphic_line(grphcs *_grphc,vec2 from,vec2 to,pixel color) {
  int dx, dy, p, x, y;
  
  int x0 = from.x;
  int y0 = from.y;
  int x1 = to.x;
  int y1 = to.y;
  
  dx=x1-x0;
  dy=y1-y0;
  x=x0;
  y=y0;
  p=2*dy-dx;
  while(x<x1) {
    if(p>=0) {
      graphic_setp(_grphc,g_xy(x,y),color);
      y=y+1;
      p=p+2*dy-2*dx;
    }
    else {
      graphic_setp(_grphc,g_xy(x,y),color);
      p=p+2*dy;
      }
    x=x+1;
    }
  }

// fill a rectangle at pos, as large as size. ex: graphic_fill(&a,g_xy(5,5),g_xy(2,2),g_rgb(255,255,255))
void graphic_fill(grphcs *_grphc,vec2 pos,vec2 size,pixel color) {
  int loop1,loop2;
  for (loop1=0;loop1<size.y;loop1++) {
    for (loop2=0;loop2<size.x;loop2++) {
      graphic_setp(_grphc, g_xy(pos.x+loop2,pos.y+loop1), color);
    }
  }
}
