libnosdlfullscreen
==================

A quick LD\_PRELOAD hack that forces SDL 1.x apps to not run in fullscreen.

Copyright (C) 2015 Scott Zeid.  Released under the X11 License.  
<http://code.s.zeid.me/libnosdlfullscreen>


Usage
-----

Simply build libnosdlfullscreen (see below) and set the `LD_PRELOAD` environment
variable to the path to the compiled library.

    LD_PRELOAD=path/to/libnosdlfullscreen[32].so <SDL program> [arguments [...]]


Building
--------

1.  Make sure you're on GNU/Linux (yes, the GNU part matters here) and have
    the glibc and SDL 1.2 development packages installed, as well as GNU Make.
    
        fedora$ sudo yum install glibc-devel SDL-devel make

2.  In the repository's root directory, run `make`.


Cross-compiling
---------------

To cross-compile a 32-bit library on a 64-bit machine, run `make 32`.  You
can also run `make 64 32` to make both the 64-bit and 32-bit versions at the
same time.  Make sure you have the 32-bit development packages installed:

    fedora$ sudo yum install glibc-devel.i686 SDL-devel.i686

You can override the compiler and linker with the `CC` and `LD` variables:

    make CC=... LD=... [...]
