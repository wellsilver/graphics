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
