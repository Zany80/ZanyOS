/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the VGA Mode 3 interface for the x86 architecture. VGA mode 3 is a text mode.
 * 
 * More info can be found at http://wiki.osdev.org/Text_UI and https://en.wikipedia.org/wiki/VGA-compatible_text_mode
 */

#ifndef _ZENITHOS_ARCH_X86_VGA_MODE3_H_
#define _ZENITHOS_ARCH_X86_VGA_MODE3_H_

#include <arch/x86/stdint.h>

enum color{
	black=0,blue,green,cyan,red,magenta,brown,light_gray,
	dark_gray,light_blue,light_green,light_cyan,light_red,light_magenta,yellow,white
};

typedef enum color color;

void putch(int x,int y,unsigned char c,color fg,color bg);
void puts(const char * string);
void cls();
void scrollOnce();

struct{
	uint8_t x;
	uint8_t y;
}cursor;

#endif
