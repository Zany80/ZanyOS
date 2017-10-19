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
using VGA::puts;

void parse_multiboot(multiboot_header* header,bool print){
	//suppress warning
	if(header->flags & 1){
		if(print){
			puts("Lower memory available: ");
			puti(header->mem_lower,10,8);
			puts(" Kb\n");
			puts("Upper memory available: ");
			puti(header->mem_upper,10,8);
			puts(" Kb\n");
		}
	}
	if(header->flags & (1<<1)){
		if(print){
			puts("BIOS drive number: ");
			puti(header->boot_device.drive,16,2);
			putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
			if(header->boot_device.part1!=0xFF){
				puts("BIOS part1: ");
				puti(header->boot_device.part1,16,2);
				putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
				if(header->boot_device.part2!=0xFF){
					puts("BIOS part2: ");
					puti(header->boot_device.part2,16,2);
					putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
					if(header->boot_device.part3!=0xFF){
						puts("BIOS part3: ");
						puti(header->boot_device.part3,16,2);
						putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
					}
				}
			}
		}
	}
	if(header->flags & (1<<2)){
		if(!(header->cmdline))
			panic(2);
		if(print){
			puts("Command line: ");
			puts((char*)header->cmdline);
			puts("\n");
		}
	}
	if(header->flags & (1<<3)){
		if(header->mods_count>0){
			if(print){
				puti(header->mods_count,10,1);
				puts(" boot modules loaded\n");
				multiboot_module * m=(multiboot_module*)header->mods_addr;
				for(uint32_t i=0;i<header->mods_count;i++,m++){
					puts("Module ");puti(i,10,2);puts(": \n");
					puts("\tString: \'");puts((char*)m->string);puts("\"\n");
					puts("\tStart address: ");puti(m->start,16,8);puts("\n");
					puts("\tEnd address: ");puti(m->end,16,8);puts("\n");
					puts("\tValue: \n");puts((char*)m->start);puts("\n");
				}
			}
			else
				puts("No boot modules loaded\n");
			}
	}
	if(header->flags & (1<<4)){
		if(print)
			puts("a.out symbol table valid\n");
	}
	if(header->flags & (1<<5)){
		if(print)
			puts("ELF symbol table valid\n");
	}
	if(header->flags & (1<<6)){
		multiboot_mmap * m=(multiboot_mmap*)header->mmap_addr;
		uint32_t traversed=0;
		for(uint32_t i=0;traversed<header->mmap_length;i++,traversed+=m->size+sizeof(m->size),m++){
			if(print){
				puts("mmap");puti(i,10,2);puts(":\n");
				puts("\tAddress: ");
				puti((uint32_t)(m->base_addr>>32),16,8);
				puti(((uint32_t)m->base_addr&0xF0000000)>>28,-16,1);
				puti(((uint32_t)m->base_addr&0x0FFFFFFF),-16,7);
				puts("\n");
			}
		}
	}
	if(header->flags & (1<<7)){
		if(print){
			puts("drives_length: ");
			puti(header->drives_length,10,4);
			puts("\n");
		}
	}
	if(header->flags & (1<<8)){
		if(print)
			puts("Config table valid");
	}
	if(header->flags & (1<<9)){
		if(print){
			puts("Bootloader: ");
			puts((char*)header->boot_loader_name);
			putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
		}
	}
	if(header->flags & (1<<10)){
		multiboot_apm_table* a=(multiboot_apm_table*)header->apm_table;
		if(print){
			puts("APM table version number: ");
			puti(a->version,16,4);
			puts("n");
		}
	}
	if(header->flags & (1<<11)){
		if(print)
			puts("VBE valid.\n");
	}
	if(header->flags & (1<<12)){
		if(print){
			puts("Framebuffer address: ");
			puti((header->framebuffer_table.addr&0xF000000000000000)>>60,16,1);
			puti((header->framebuffer_table.addr&0x0FFFFFFF00000000)>>32,-16,7);
			puti((header->framebuffer_table.addr&0x00000000F0000000)>>28,-16,1);
			puti(header->framebuffer_table.addr&0x000000000FFFFFFF,-16,7);
			puts("\n");
		}
	}
}
