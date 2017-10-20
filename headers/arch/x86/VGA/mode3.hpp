/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the VGA Mode 3 interface for the x86 architecture. VGA mode 3 is a text mode.
 * 
 * More info can be found at http://wiki.osdev.org/Text_UI and https://en.wikipedia.org/wiki/VGA-compatible_text_mode
 */

#pragma once

#include <stdint.h>

namespace VGA{

	enum color{
		black=0,blue,green,cyan,red,magenta,brown,light_gray,
		dark_gray,light_blue,light_green,light_cyan,light_red,light_magenta,yellow,white
	};

	typedef enum color color;
	
	void puti(int i,int base,int n);
	void putch(uint8_t x,uint8_t y,char c,color fg,color bg);
	void puts(const char * string);
	void cls();
	void scrollOnce();
	uint8_t getX();
	uint8_t getY();

}
