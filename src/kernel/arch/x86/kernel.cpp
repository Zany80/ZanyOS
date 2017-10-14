/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the main kernel function.
 */

#include <VGA/mode3.hpp>
using VGA::puts;
using VGA::cls;

#include <config.h>

void main(){
	cls();
	puts("Zenith80 starting up...\n");
	puts("Git revision: ");
	puts(STRINGIFY(GIT_REVISION));
	VGA::putch(VGA::cursor.x,VGA::cursor.y,'\n',VGA::white,VGA::black);
}
