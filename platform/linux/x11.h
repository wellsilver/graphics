#ifndef GRAPHIC_DONE
#define GRAPHIC_DONE
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

// not needed, used by graphic_console not by graphics.h
struct graphic_r_save {
  int sizex,sizey;
  Display *dpy;
  Window win;
  XEvent e;
  GC gc;
};

// called when map_new is called
void graphic_r_init(struct graphic_r_save *save,int size_x,int size_y) {
  save->dpy = XOpenDisplay(NULL);
  int s = DefaultScreen(save->dpy);
  save->win = XCreateSimpleWindow(save->dpy, RootWindow(save->dpy, s), 0, 0, size_x, size_y, 1,BlackPixel(save->dpy, s), WhitePixel(save->dpy, s));
  XSelectInput(save->dpy, save->win, ExposureMask | KeyPressMask);
  XMapWindow(save->dpy, save->win);
  Atom WM_DELETE_WINDOW = XInternAtom(save->dpy, "WM_DELETE_WINDOW", 1);
  XSetWMProtocols(save->dpy, save->win, &WM_DELETE_WINDOW, 1);
  save->gc = XCreateGC(save->dpy, save->win, 0,0);
}
// called for each pixel
void graphic_r_putpixel(struct graphic_r_save *save,int x,int y,int r,int g,int b) {
  XSetForeground(save->dpy, save->gc, (b + (g<<8) + (r<<16)));
  XDrawPoint(save->dpy, save->win, save->gc, x, y);
}
// called when all pixels placed, to finalize placing.
void graphic_r_finishpixels(struct graphic_r_save *save) { 
  
}

void g_x11_finish(struct graphic_r_save *save) {
  XDestroyWindow(save->dpy, save->win);
  XCloseDisplay(save->dpy);
}
#endif
