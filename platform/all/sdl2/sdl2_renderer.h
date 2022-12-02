// VERY BAREBONES

#ifndef GRAPHIC_DONE
#define GRAPHIC_DONE
#include <stdio.h>
#include <stdlib.h> 
#define SDL_MAIN_HANDLED
#include <SDL2/sdl.h>

static SDL_Renderer *SDL_r_renderer;
static SDL_Window *SDL_r_window;
struct graphic_r_save {
	
};
void graphic_r_init(struct graphic_r_save *save,int size_x,int size_y) {
  SDL_CreateWindowAndRenderer(size_x, size_y, 0,&SDL_r_window, &SDL_r_renderer);
}
void graphic_r_putpixel(struct graphic_r_save *save,int x,int y,int r,int g,int b) {
  SDL_SetRenderDrawColor(SDL_r_renderer, r, g, b, 255);
  SDL_RenderDrawPoint(SDL_r_renderer,x,y);
}
void graphic_r_finishpixels(struct graphic_r_save *save) { 
  SDL_RenderPresent(SDL_r_renderer);
}
#endif
