you need x11 devkit

if you dont know what to add to your command line (or too lazy to find out)

``-lm -L/usr/X11R6/lib -lX11``

made for x11r6, should work on everything else.

special command:

at the end of your program call

``void g_x11_finish(struct graphic_r_save *save)``

example to use (if a is the grphcs struct):

``g_x11_finish(&a._dat);``
