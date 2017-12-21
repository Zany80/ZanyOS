/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file contains the architecture agnostic string header.
 */

#pragma once

#ifdef __cplusplus
extern "C"
#endif
char* itoa(int num, char* str, int base,int minsize);

void reverse(char str[], int length);

#ifdef __cplusplus
extern "C"
#endif
int strcmp(const char * str1, const char * str2);
