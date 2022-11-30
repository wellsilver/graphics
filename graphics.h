#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pixel {
  char r;
  char g;
  char b;
} pixel;

pixel rgb(int r,int g,int b) {
  pixel i;
  i.r=r;
  i.g=g;
  i.b=b;
  return i;
}
typedef struct vec2 {
  int x;
  int y;
} vec2;

typedef struct grphcs {
  void (*draw)(struct grphcs*); // for custom
  vec2 size;
  pixel **pixels; // pixels[x][y]
} grphcs;

vec2 xy(int x,int y) {
  vec2 i;
  i.x=x;
  i.y=y;
  return i;
}

#ifndef GRAPHICS_USE_MY_RENDERER
// note: have function as draw()
void map_draw(grphcs *fav) {
  
}
#endif

#ifdef GRAPHICS_USE_MY_RENDERER
grphcs new_win(unsigned int x,unsigned int y,void (*map_draw)(grphcs*)) {
#else
grphcs new_win(unsigned int x,unsigned int y) {
#endif
  grphcs a;
  // if GRAPHICS_USE_MY_RENDERER is not defined then the function is map_draw
  // if it is defined however, then the function is map_draw arguement
  a.draw=map_draw;
  a.size.x = x;
  a.size.y = y;
  a.pixels = (pixel **) malloc(sizeof(pixel *)*y);
  int loop;
  for (loop=0;loop<x;loop++) {
    a.pixels[loop] = (pixel *) malloc(sizeof(pixel)*x);
  }
}

void line(grphcs *_map,vec2 point1,vec2 point2,pixel color) {
  grphcs map = *_map;
  int loop;
  vec2 dist; // distance between the two points for each axis
  dist.x = abs(point1.x-point2.x);
  dist.y = abs(point1.y-point2.y);
  int when_to_step=0; // when to set up or down if y is different
  int has_stepped=0;
  if (dist.y!=0) {
    // calc when_to_step
    when_to_step=dist.y/dist.x;
  }
  vec2 current;
  current.x=point1.x;
  current.y=point1.y;
  for (loop=0;loop<dist.x;loop++) {
    printf("-%i,%i-",current.x,current.y);
    map.pixels[current.x][current.y] = color;
    // calculate next current
    if (has_stepped==when_to_step) {
      if (current.y>point2.y) current.y++;
      if (current.y<point2.y) current.y--;
    }
    if (current.x>point2.x) current.x++;
    if (current.x<point2.x) current.x--;
    has_stepped++;
  }
}

void rect(grphcs *map,vec2 point1,vec2 point2) {
  
}

void fill(grphcs *map,vec2 point1,vec2 point2) {
  
}
