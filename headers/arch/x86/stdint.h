/**
 * ZenithOS
 * Copyright Noam Preil 2017
 * Licensed under the Apache 2.0 license
 * 
 * This file creates standard names for integer types.
 */

#ifndef _ZENITHOS_ARCH_X86_STDINT_H_
#define _ZENITHOS_ARCH_X86_STDINT_H_

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef long int32_t;
typedef unsigned long uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;

#ifndef __cplusplus
typedef uint8_t bool;
#define false 0
#define true 1
#endif

#endif
