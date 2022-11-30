#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pixel {
  short int r;
  short int g;
  short int b;
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
#ifndef GRPHC_DONE 
// if no graphics header (for opengl or sdl2) then make a function that prints it to console instead
#include <stdio.h>
#include <stdlib.h>
struct grphc_default_save {
  
};
void grphc_default_init(struct grphc_default_save *data) {
  int rslt;
#ifdef _WIN32
  rslt=system("cls");
#else
  rslt=system("clear");
#endif
#ifndef GRPHC_DEFAULT_NO_HINT
  printf("Using default rendering config, renders in command line, to hide this #DEFINE GRPHC_DEFAULT_NO_HINT\n");
#endif
}
void grphc_default_draw(struct grphc_default_save *data,int sizex,int sizey,int r[sizex][sizey],int g[sizex][sizey],int b[sizex][sizey]) {
  int rslt;
#ifdef _WIN32
  rslt=system("cls");
#else
  rslt=system("clear");
#endif
#ifndef GRPHC_DEFAULT_NO_HINT
  printf("Using default rendering config, renders in command line, to hide this #DEFINE GRPHC_DEFAULT_NO_HINT\n");
#endif
  int loop1,loop2;
  int pos;
  for (loop1=0;loop1<sizex;loop1++) {
    printf("\n");
    for (loop2=0;loop2<sizey;loop2++) {
      // convert to grayscale and print
      pos = r[loop1][loop2] + g[loop1][loop2] + b[loop1][loop2];
      if (pos > 374) {
        printf("+");
      }
      else {
        printf("-");
      }
    }
  }
}
#define GRPHC_DONE 
// define the function that is used to init
#define GRPHC_INIT grphc_default_init
// define the function that is used to put a pixel on the screen
#define GRPHC_DRAW grphc_default_draw
// define the struct with the data that grphc_win needs
#define GRPHC_DATA grphc_default_save
#endif

typedef struct grphcs {
  struct GRPHC_DATA win_data;
  void (*draw)(struct grphc_default_save *data,int sizex,int sizey,int r[sizex][sizey],int g[sizex][sizey],int b[sizex][sizey]);
  vec2 size;
  pixel **pixels; // pixels[x][y]
} grphcs;

vec2 xy(int x,int y) {
  vec2 i;
  i.x=x;
  i.y=y;
  return i;
}

grphcs new_win(unsigned int x,unsigned int y) {
  grphcs a;
  GRPHC_INIT(&a.win_data); // #define GRPHC_INIT
  a.draw = GRPHC_DRAW; // #define GRPHC_DRAW
  a.size.x = x;
  a.size.y = y;
  a.pixels = (pixel **) malloc(sizeof(struct pixel *)*y);
  int loop;
  for (loop=0;loop<x;loop++) {
    a.pixels[loop] = (pixel *) malloc(sizeof(struct pixel)*x);
  }
  return a;
}

pixel getpix(grphcs *map,vec2 place) {
  return map->pixels[place.x][place.y];
}

void setpix(grphcs *map,vec2 place,pixel color) {
  map->pixels[place.x][place.y] = color;
}

void draw(grphcs *map) {
  int r[map->size.x][map->size.y], g[map->size.x][map->size.y], b[map->size.x][map->size.y];
  int loop,loop2;
  for (loop=0;loop<map->size.x;loop++) {
    for (loop2=0;loop2<map->size.y;loop2++) {
      r[loop][loop2] = map->pixels[loop][loop2].r;
      g[loop][loop2] = map->pixels[loop][loop2].g;
      b[loop][loop2] = map->pixels[loop][loop2].b;
    }
  }
  struct GRPHC_DATA a = map->win_data;
  map->draw(&a,map->size.x,map->size.y,r,g,b);
}
