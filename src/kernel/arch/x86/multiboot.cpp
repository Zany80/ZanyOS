/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the multiboot information parser.
 */

#include <kernel.h>
#include <multiboot.h>
#include <VGA/mode3.hpp>
using VGA::putch;
using VGA::puti;

inline void puts (bool b,const char * c){
	if(b)VGA::puts (c);
}

void parse_multiboot(multiboot_header* header,bool print){
	if(header->flags & 1){
		puts(print,"Lower memory available: ");
		puti(header->mem_lower,10,8);
		puts(print," Kb\n");
		puts(print,"Upper memory available: ");
		puti(header->mem_upper,10,8);
		puts(print," Kb\n");
	}
	if(header->flags & (1<<1)){
		puts(print,"BIOS drive number: ");
		puti(header->boot_device.drive,16,2);
		putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
		if(header->boot_device.part1!=0xFF){
			puts(print,"BIOS part1: ");
			puti(header->boot_device.part1,16,2);
			putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
			if(header->boot_device.part2!=0xFF){
				puts(print,"BIOS part2: ");
				puti(header->boot_device.part2,16,2);
				putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
				if(header->boot_device.part3!=0xFF){
					puts(print,"BIOS part3: ");
					puti(header->boot_device.part3,16,2);
					putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
				}
			}
		}
	}
	if(header->flags & (1<<2)){
		if(!(header->cmdline))
			panic(2);
		puts(print,"Command line: ");
		puts(print,(char*)header->cmdline);
		puts(print,"\n");
	}
	if(header->flags & (1<<3)){
		if(header->mods_count>0){
			puti(header->mods_count,10,1);
			puts(print," boot modules loaded\n");
			multiboot_module * m=(multiboot_module*)header->mods_addr;
			for(uint32_t i=0;i<header->mods_count;i++,m++){
				puts(print,"Module ");puti(i,10,2);puts(print,": \n");
				puts(print,"\tString: \'");puts(print,(char*)m->string);puts(print,"\"\n");
				puts(print,"\tStart address: ");puti(m->start,16,8);puts(print,"\n");
				puts(print,"\tEnd address: ");puti(m->end,16,8);puts(print,"\n");
				puts(print,"\tValue: \n");puts(print,(char*)m->start);puts(print,"\n");
			}
		}
		else
			puts(print,"No boot modules loaded\n");
	}
	if(header->flags & (1<<4)){
		puts(print,"a.out symbol table valid\n");
	}
	if(header->flags & (1<<5)){
		puts(print,"ELF symbol table valid\n");
	}
	if(header->flags & (1<<6)){
		multiboot_mmap * m=(multiboot_mmap*)header->mmap_addr;
		uint32_t traversed=0;
		for(uint32_t i=0;traversed<header->mmap_length;i++,traversed+=m->size+sizeof(m->size),m++){
			puts(print,"mmap ");puti(i,10,2);puts(print,":\n");
			puts(print,"\tAddress: ");
			puti((uint32_t)(m->base_addr>>32),16,8);
			puti(((uint32_t)m->base_addr&0xF0000000)>>28,-16,1);
			puti(((uint32_t)m->base_addr&0x0FFFFFFF),-16,7);
			puts(print,"\n");
		}
	}
	if(header->flags & (1<<7)){
		
	}
	if(header->flags & (1<<9)){
		puts(print,"Bootloader: ");
		puts(print,(char*)header->boot_loader_name);
		putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
	}
}
