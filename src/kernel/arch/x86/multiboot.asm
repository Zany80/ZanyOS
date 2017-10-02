/**
	ZenithOS
	Copyright Noam Preil 2017
	Licensed under the Apache 2.0 license
	
	This file contains the multiboot header for the x86 architecture. The multiboot specification can be found at
	https://www.gnu.org/software/grub/manual/multiboot/multiboot.html
*/

.set MAGIC, 0x1BADB002

.set ALIGN, 1<<0
.set MMAP, 1<<1
.set FLAGS, ALIGN | MMAP
.set CHECKSUM, 0-(FLAGS+MAGIC)

.section .multiboot
//multiboot header has to be 32-bit aligned - see https://www.gnu.org/software/grub/manual/multiboot/multiboot.html#OS-image-format
.align 4

.long MAGIC, FLAGS, CHECKSUM
