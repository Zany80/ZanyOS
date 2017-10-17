/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the VGA Mode 3 interface for the x86 architecture. VGA mode 3 is a text mode.
 * 
 * More info can be found at http://wiki.osdev.org/Text_UI and https://en.wikipedia.org/wiki/VGA-compatible_text_mode
 */

#ifndef _ZENITHOS_ARCH_X86_MULTIBOOT_H_
#define _ZENITHOS_ARCH_X86_MULTIBOOT_H_

#include <stdint.h>

typedef struct{
	uint32_t tabsize;
	uint32_t strsize;
	uint32_t addr;
	uint32_t reserved;
} multiboot_aout_table;

typedef struct{
	uint32_t num;
	uint32_t size;
	uint32_t addr;
	uint32_t shndx;
} multiboot_elf_table;

typedef struct{
	uint32_t flags;
	uint32_t mem_lower;
	uint32_t mem_upper;
	struct{
		uint8_t part3;
		uint8_t part2;
		uint8_t part1;
		uint8_t drive;
	} boot_device;
	uint32_t cmdline;
	uint32_t mods_count;
	uint32_t mods_addr;
	union{
		multiboot_aout_table aout;
		multiboot_elf_table elf;
	} syms;
	uint32_t mmap_length;
	uint32_t mmap_addr;
	uint32_t drives_length;
	uint32_t drives_addr;
	uint32_t config_table;
	uint32_t boot_loader_name;
	uint32_t apm_table;
	struct{
		uint32_t control_info;
		uint32_t mode_info;
		uint16_t mode;
		uint16_t interface_seg;
		uint16_t interface_off;
		uint16_t interface_len;
	} vbe_table;
	struct{
		uint64_t addr;
		uint32_t pitch;
		uint32_t width;
		uint32_t height;
		uint8_t bpp;
		uint8_t type;
	} framebuffer_table;
} multiboot_header;

typedef struct{
	uint32_t start;
	uint32_t end;
	uint32_t string;
	uint32_t zero;
} multiboot_module;

typedef struct{
	uint32_t size;
	uint64_t base_addr;
	uint64_t len;
	uint32_t type;
} multiboot_mmap;

extern "C" void multiboot_validate();
extern "C" void parse_multiboot(multiboot_header* header);

#endif
