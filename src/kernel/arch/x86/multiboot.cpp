#include <kernel.h>
#include <multiboot.h>
#include <VGA/mode3.hpp>
using VGA::putch;
using VGA::puts;
using VGA::puti;

void parse_multiboot(multiboot_header* header){
	if(header->flags & 1){
		puts("Lower memory available: ");
		puti(header->mem_lower,10,8);
		puts(" Kb\n");
		puts("Upper memory available: ");
		puti(header->mem_upper,10,8);
		puts(" Kb\n");
	}
	if(header->flags & (1<<1)){
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
	if(header->flags & (1<<2)){
		if(!(header->cmdline))
			panic(2);
		puts("Command line: ");
		puts((char*)header->cmdline);
		puts("\n");
	}
	if(header->flags & (1<<3)){
		if(header->mods_count>0){
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
	if(header->flags & (1<<4)){
		puts("a.out symbol table valid\n");
	}
	if(header->flags & (1<<5)){
		puts("ELF symbol table valid\n");
	}
	if(header->flags & (1<<6)){
		puts("mmap valid\n");
		multiboot_mmap * m=(multiboot_mmap*)header->mmap_addr;
		uint32_t traversed=0;
		for(uint32_t i=0;traversed<header->mmap_length;i++,traversed+=m->size+sizeof(m->size),m++){
			puts("mmap ");puti(i,10,2);puts(":\n");
			puts("\tAddress: ");
			puti((uint32_t)(m->base_addr>>32),16,8);
			puti(((uint32_t)m->base_addr&0xF0000000)>>28,-16,1);
			puti(((uint32_t)m->base_addr&0x0FFFFFFF),-16,7);
			puts("\n");
		}
	}
	if(header->flags & (1<<9)){
		puts("Bootloader: ");
		puts((char*)header->boot_loader_name);
		putch(VGA::getX(),VGA::getY(),'\n',VGA::white,VGA::black);
	}
}
