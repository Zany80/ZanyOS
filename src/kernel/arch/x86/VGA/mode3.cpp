/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the VGA Mode 3 implementation. 
 */

#include <VGA/mode3.hpp>
#include <stdint.h>

void VGA::putch(int x,int y,unsigned char c,color fg,color bg){
	/*
	 * VGA text mode buffer starts at 0xB8000.
	 * Lines are in memory one after another and are 80 characters in length.
	 */
	if(c=='\n'){
		cursor.x=0;
		cursor.y++;
		if(cursor.y >= 25){
			scrollOnce();
		}
		return;
	}
	volatile uint16_t * pos=(volatile uint16_t*)0xB8000 + (y * 80 + x);
	uint16_t attributes=((uint8_t)bg<<4) | ((uint8_t)fg&0x0F);
	uint16_t value=(attributes<<8) | c;
	*pos=value;
	cursor.x++;
	if(cursor.x == 80){
		cursor.x=0;
		cursor.y++;
		if(cursor.y >= 25){
			scrollOnce();
		}
	}
}

void VGA::puts(const char * string){
	for(;(*string)!=0;string++){
		putch(cursor.x,cursor.y,*string,white,black);
	}
}

void VGA::cls(){
	for(int x=0;x<80;x++){
		for(int y=0;y<25;y++){
			volatile uint16_t * pos=(volatile uint16_t*)0xB8000 + (y*80+x);
			*pos = (black<<4)|(white&0x0F);
		}
	}
	cursor.x=cursor.y=0;
}

void VGA::scrollOnce(){
	/**
	 * For each of the first 24 lines, copy the data from the line below it
	 */
	for(int y=0;y<24;y++){
		for(int x=0;x<80;x++){
			volatile uint16_t * pos=(volatile uint16_t*)0xB8000 + (y*80+x);
			*pos=*(pos+80);
		}
	}
	for(int x=0;x<80;x++){
		volatile uint16_t * pos=(volatile uint16_t*)0xB8000 + (24*80+x);
		*pos=(black<<4)|(white&0x0F);
	}
	cursor.x=0;
	cursor.y--;
}
