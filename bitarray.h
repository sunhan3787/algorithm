#ifndef BIT_ARRAY_LIB_H
#define BIT_ARRAY_LIB_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define STD_ON                                 1
#define ERROR_BIT                              (-1)
#define ERROR_NULL                             (-2)

#define BIT_SATAE_1                            1
#define BIT_SATAE_0                            0

typedef struct ARRAY_BIT
{
	unsigned char * bit_arr;
	unsigned long max_bit; //sum of bits
	unsigned long len;//number of bitarray bytes
	
}bitarray;

extern bitarray * bitarray_create(unsigned long bits);
extern int bitarray_destroy(bitarray * arr);
extern int bitarray_print(bitarray * arr);
extern int bitarray_setbit(bitarray * arr, unsigned long bit);
extern int bitarray_clearbit(bitarray * arr, unsigned long bit);
extern int bitarray_getbitstate(bitarray * arr, unsigned long bit);
extern unsigned long bitarray_getmaxbit(bitarray * arr);

#endif


