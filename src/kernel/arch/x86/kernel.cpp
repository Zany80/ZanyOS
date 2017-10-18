/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the main kernel function.
 */

#include <VGA/mode3.hpp>
using VGA::cls;
using VGA::puts;
using VGA::puti;
using VGA::putch;
#include <multiboot.h>

#include <config.h>
#include <kernel.h>

void main(){
	cls();
	puts("Git revision: ");
	puts(STRINGIFY(GIT_REVISION));
	putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
	puts("Zenith80 starting up...\n");
	multiboot_header * header;
	multiboot_validate();
	asm("nop" : "=b"(header));
	puts("Multiboot header at ");
	puti((int)header,16,8);
	puts(", parsing...\n");
	parse_multiboot(header,true);
}
