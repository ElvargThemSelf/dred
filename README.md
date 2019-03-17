![dred](http://dred.io/img/banner2_wide.png)

dred is a fast, ultra-lightweight graphical text editor. It currently weighs in at less
than 1MB.

Supported platforms include Windows, Linux and Mac. Linux and Mac depend on GTK+ 3.


Compiling
=========
Just compile source/dred/dred_main.c using your favourite compiler.

Compiling this on Unix based platforms requires the development version of the
GTK+ 3.0 library and all associated libraries (glib, gdk, atk, cairo, ...).

To compile dred on Unix based platforms use the following command:

    cc source/dred/dred_main.c -o dred `pkg-config --cflags --libs gtk+-3.0` -lm -ldl


Features
========

* Dark and light theme
* Favourite files
* Command bar
* Simple installation process with minimal dependencies

![screenshot](http://dred.io/img/screenshot-1.jpg)


License
=======

    Copyright (C) 2019 David Reid
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
