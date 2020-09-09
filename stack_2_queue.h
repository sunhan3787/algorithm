
#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

#include "stack.h"
#include "queue.h"


typedef struct STACK_TO_QUEUE{
	unsigned int count;
	stack * pstack_1;
	stack * pstack_2;

}stack2queue;

typedef struct QUEUE_TO_STACK{
	unsigned int count;
	queue * pqueue_1;
	queue * pqueue_2;

}queue2stack;


extern int stack2queue_init(stack2queue ** ppqueue);
extern int queue2stack_init(queue2stack ** ppstack);
extern int stack2queue_push(stack2queue * pqueue, int val);
extern int queue2stack_push(queue2stack * pstack, int val);
extern int stack2queue_pop(stack2queue * pqueue);
extern int queue2stack_pop(queue2stack * pstack);


#endif
