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

#include <string.h>

void main(){
	////cls();
	////puts("Git revision: ");
	////puts(STRINGIFY(GIT_REVISION));
	////putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
	////puts("Zenith80 starting up...\n");
	multiboot_header * header;
	// multiboot_validate() puts the address of the header in %ebx.
	multiboot_validate();
	// no assembly is needed - just copies the address from %ebx to header
	asm("" : "=b"(header));
	////puts("Multiboot header at ");
	////puti((int)header,16,8);
	////puts(", gathering information...\n");
	
	// Gather information about the multiboot header w/o printing anything
	// Just does some basic validation that the header is sane
	parse_multiboot(header,false);
	if (header->flags & (1<<12)) {
		// Framebuffer information is present. Set up video drivers.
		
	}
	else {
		// No framebuffer info available.
		if (strcmp((const char*)header->boot_loader_name,"qemu") == 0) {
			//If this is qemu, then we're fine, and currently VGA mode 3 is
			//active.
			
		}
		else {
			panic(2);
		}
	}
}
