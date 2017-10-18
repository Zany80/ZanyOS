/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the header for GDT manipulation.
 */

typedef struct{
	uint16_t lower_limit;
	uint16_t lower_base;
	uint8_t mid_base;
	uint8_t access;
	uint8_t upper_limit_flags;
	uint8_t upper_base;
} gdt_entry;

////gdt_entry encode_gdt(
