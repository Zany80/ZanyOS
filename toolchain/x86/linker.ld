/**
	ZenithOS
	Copyright Noam Preil 2017
	Licensed under the Apache 2.0 license
	
	This file contains the linker script for the kernel for x86.
*/

ENTRY(_start)

SECTIONS{
	/* Apparently, putting kernels at the 1M point is standard for bootloaders */
	. = 1M;
	/*
		Note that the .multiboot section will not be defined in the output. It's contents will go into .text instead.
		The only reason .multiboot has it's own input section is to ensure it is placed at the beginning. */
	.text ALIGN(4K) : {
		/* Put the multiboot header at the beginning of the kernel image */
		*(.multiboot)
		/* Put the .text section (the main code) immediately afterwards */
		*(.text)
	}
	/* Read only stuff */
	.rodata ALIGN(4K) : { *(.rodata) }
	/* Writable stuff */
	.data ALIGN(4K) : { *(.data) }
	/* Uninitialized writable stuff */
	.bss ALIGN(4K) : { *(COMMON) *(.bss) }
}
