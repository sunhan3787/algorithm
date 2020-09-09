
#ifndef STACK_H
#define STACK_H

#include "include.h"

#ifdef STACK_2_QUEUE
typedef struct STACK_NODE{
	int val;
	struct STACK_NODE * pnext;
}stack_node;

typedef struct STACK{
	stack_node * ptop;
	unsigned int count; 
}stack;

#else
typedef struct NODE stack_node;

typedef struct STACK{
	stack_node * ptop;
	unsigned int count; 

}stack;

#endif

extern int stack_init(stack ** ppstack);
extern int stack_push(stack * pstack, int val);
extern int stack_pop(stack * pstack);
extern int stack_reset(stack * pstack);
extern int destory(stack ** ppstack);
extern stack_node* gettop(stack * pstack);
extern int getcount(stack * pstack);
extern int  isempty(stack * pstack);

#endif
