/**
	ZenithOS
	Copyright Noam Preil 2017
	Licensed under the Apache 2.0 license
	
	This file contains the multiboot2 header for the x86 architecture. The multiboot specification can be found at
	https://www.gnu.org/software/grub/manual/multiboot2/multiboot.html
*/

.set MAGIC, 0xE85250D6
.set ARCHITECTURE, 0

.section .multiboot2
