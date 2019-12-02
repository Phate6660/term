# term
Yet another VTE wrapper. This time made and customized by me.

Dependencies: vte-2.91 and gtk.

How to use:
1. Either download [term.c](https://github.com/Phate6660/term/blob/master/term.c) or clone the repository.
2. Compile: `gcc -O2 -Wall $(pkg-config --cflags vte-2.91) term.c -o term $(pkg-config --libs vte-2.91)`.
3. Profit: `./term`.
