# valleyTERM
Yet another VTE wrapper. This time made and customized by me.</br>
If anyone is wondering why "valley" is in the name, it's because "valley" is a fairly common handle that I use.

Dependencies: vte-2.91 and gtk.

How to use:
1. Either download [term.c](https://github.com/Phate6660/term/blob/master/term.c) or clone the repository.
2. Compile: `gcc -O2 -Wall $(pkg-config --cflags vte-2.91) term.c -o valleyTERM $(pkg-config --libs vte-2.91)`.
3. Profit: `./valleyTERM`.
