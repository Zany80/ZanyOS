/**
	ZenithOS
	Copyright Noam Preil 2017
	Licensed under the Apache 2.0 license
	
	This file contains the initialization routine for the x86 architecture.
*/

//Set up the stack
.section .bss
//Stack has to be word-aligned according to the System-V ABI. GCC will assume it's aligned correctly, so bad things™ will happen if it isn't.
.align 16
/*
	Allocate 64K for the stack - probably not needed, but a) better safe than sorry and b) ZenithOS is going to run an emulator. That's it.
	Also, every modern computer has at *least* 1GB RAM, and there's no *chance* that Zenith will *ever* use that much.
*/
.skip 65536
stack_top:

.section .text

.global _start
_start:
	//on x86, stack grows downwards
	movl $stack_top, %esp
	//call the C routine
	call main
	cli
halt: hlt
	//In case of a non-maskable interrupt, go back to the halt instruction
	jmp halt

