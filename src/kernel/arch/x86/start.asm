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
	Allocate 64K for the stack - probably not needed, but as long as it's not harmful adding a bit more than strictly necessary should be fine.
*/
.global stack_bottom
stack_bottom:
.skip 65536
.global stack_top
stack_top:

.section .text

.global _start
_start:
	//store multiboot-provided stuff at bottom of stack. This won't be overwritten anytime soon, and is used very quickly.
	movl %eax, stack_bottom
	movl %ebx, stack_bottom+4
	//on x86, stack grows downwards
	movl $stack_top, %esp
	//make sure interrupts are disabled until the IDT is setup
	cli
	//call the C routine
	call main
//Don't do anything... forever.
	cli
halt: hlt
	//In case of a non-maskable interrupt, go back to the halt instruction
	jmp halt
.global panic
panic:
	pushl $_panic_msg
	call _ZN3VGA4putsEPKc@PLT
	addl $4,%esp
	movl 4(%esp),%eax
	pushl $8
	pushl $16
	pushl %eax
	call _ZN3VGA4putiEiii
	jmp halt

.section .rodata
_panic_msg: .string "Kernel panic! Error code: "
