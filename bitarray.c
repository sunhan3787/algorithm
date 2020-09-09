#include "bitArraylib.h"

const unsigned char A_BYTE = CHAR_BIT;
const unsigned char MASK_1 = 1;
const unsigned char MASK_0 = 0;

bitarray * bitarray_create(unsigned long bits)
{
	bitarray * ptemp = NULL;
	unsigned long length = 0;

	/*1.number of bit be allowed or not*/
	if((0 == bits) || (0 != (bits % A_BYTE))){
		printf("Error Code 100: \n number of bit be allowed or not\n");
		return NULL;

	}

	ptemp = (bitarray*)malloc(sizeof(bitarray));
	if(NULL == ptemp){
		printf("malloc failed...\n");
		return NULL;
	}

	length = bits / A_BYTE;

	ptemp->bit_arr = (unsigned char *)calloc(length, sizeof(unsigned char));

	if(NULL == ptemp->bit_arr){
		printf("create bit array failed...\n");
		free(ptemp);
		ptemp = NULL;
		return NULL;
	}

	ptemp->len = length;
	ptemp->max_bit = bits;
	return ptemp;
}

int bitarray_destroy(bitarray * arr)
{
	if(arr != NULL){
		free(arr);
		arr = NULL;
		return 1;

	}else{
		return ERROR_NULL;
	}
}

int bitarray_print(bitarray * arr)
{
	unsigned long i  = 0;
	int bit_stae = 0;

	for(i = 0; i < arr->max_bit; i++){

		if((i != 0) && (0 == (i % A_BYTE))){
			printf(" \n");
		}

		bit_stae = bitarray_getbitstate(arr, i);
		printf("%d ", bit_stae);

	}

	return 1;
}


int bitarray_setbit(bitarray * arr, unsigned long bit)
{
	unsigned long index = 0;
	unsigned char pos = 0;

	if(NULL == arr){
		return ERROR_NULL;
	}

	if((bit < 0) || (bit >= arr->max_bit)){
		return ERROR_BIT;

	}

	index = bit / A_BYTE;
	pos = bit % A_BYTE;

	arr->bit_arr[index] |= (MASK_1 << pos);
	return 0;
}

int bitarray_clearbit(bitarray * arr, unsigned long bit)
{

	unsigned long index = 0;
	unsigned char pos = 0;

	if(NULL == arr){
		return ERROR_NULL;
	}

	if((bit < 0) || (bit >= arr->max_bit)){
		return ERROR_BIT;

	}

	index = bit / A_BYTE;
	pos = bit % A_BYTE;

	arr->bit_arr[index] &= ~(MASK_1 << pos);

	return 0;
}

int bitarray_getbitstate(bitarray * arr, unsigned long bit)
{
	unsigned long index = 0;
	unsigned char pos = 0;
	unsigned char bit_state = 0;

	if(NULL == arr){
		return ERROR_NULL;
	}

	if((bit < 0) || (bit >= arr->max_bit)){
		return ERROR_BIT;

	}

	index = bit / A_BYTE;
	pos = bit % A_BYTE;

	bit_state = arr->bit_arr[index] & (MASK_1 << pos);

	if(bit_state){
		return BIT_SATAE_1;
	}else{
		return BIT_SATAE_0;
	}
}

unsigned long bitarray_getmaxbit(bitarray * arr)
{
	if(arr == NULL){
		return 0;
	}else{
		return arr->max_bit;
	}
}




