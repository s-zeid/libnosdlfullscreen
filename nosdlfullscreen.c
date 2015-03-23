/* libnosdlfullscreen
 * A quick LD_PRELOAD hack that forces SDL 1.x apps to not run in fullscreen.
 * 
 * Copyright (C) 2015 Scott Zeid.
 * http://code.s.zeid.me/libnosdlfullscreen
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * Except as contained in this notice, the name(s) of the above copyright holders
 * shall not be used in advertising or otherwise to promote the sale, use or
 * other dealings in this Software without prior written authorization.
 * 
 */

#define _GNU_SOURCE

#include <dlfcn.h>

#include <SDL/SDL.h>

static SDL_Surface* (*next_SDL_SetVideoMode)(int width, int height, int bpp, Uint32 flags)
 = NULL;

SDL_Surface* SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags) {
 flags = flags & ~SDL_FULLSCREEN;
 return next_SDL_SetVideoMode(width, height, bpp, flags);
}

void _init(void) {
 next_SDL_SetVideoMode = dlsym(RTLD_NEXT, "SDL_SetVideoMode");
}
