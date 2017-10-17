/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the architecture agnostic string implementation.
 * 
 * More info can be found at http://wiki.osdev.org/Text_UI and https://en.wikipedia.org/wiki/VGA-compatible_text_mode
 */

#include <string.h>
#include <stdint.h>

void swap(char * a,char *b){
	char t=*a;
	*a=*b;
	*b=t;
}

/* A utility function to reverse a string  */
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap((str+start), (str+end));
        start++;
        end--;
    }
}

// Implementation of itoa()
char* itoa(int num, char* str, int base,int minsize)
{
    int i = 0;
    bool isNegative = false;
    bool hex=base==16;
    
    if(base<0)
		base=0-base;
 
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
    
    while(i<minsize){
		str[i++]='0';
	}    
    
    if(hex){
		str[i++]='x';
		str[i++]='0';
	}
    
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
 
    return str;
}
