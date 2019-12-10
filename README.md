# Description
Yet another VTE wrapper. This time made and customized by me.</br>
If anyone is wondering why "valley" is in the name, it's because "valley" is a fairly common handle that I use.

# Features
1. It is fairly minimal.
2. The settings are hard-coded.
3. I'm starting to realize that these might not be features for most people.

Note: You might have to take a look through the source and change what you want. Especially the font.</br>
Don't worry; I made sure to comment things, so it shouldn't be too hard.

Dependencies: vte-2.91 and gtk.

# Installation
#### From source:
1. Clone the repository.
2. Change whatever settings you want in `term.c`.
3. Compile: `make && sudo make install`.
4. Profit: `valleyTERM`.

#### From Portage (Gentoo):
1. Install my [Gentoo overlay](https://github.com/Phate6660/overlay).
2. Install: `emerge valleyterm`.
3. Profit: `valleyterm`.<br>
<br>
Note: Installing from Portage currently uses the default settings.<br>
You need to have the font `Misc Fixed`, else the terminal *will* look like garbage. :)
