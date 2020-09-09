
#include "stack_queue.h"



int stack2queue_init(stack2queue ** ppqueue)
{
	*ppqueue = (stack2queue *)malloc(sizeof(stack2queue));
	if(NULL == *ppqueue){
		return E_NULL;
	}

	(*ppqueue)->count = 0;
	(*ppqueue)->pstack_1 = NULL;
	(*ppqueue)->pstack_2 = NULL;
	
	if(E_NULL == (stack_init(&(*ppqueue)->pstack_1))){
		free(*ppqueue);
		*ppqueue = NULL;
		return E_NULL;
	}

	if(E_NULL == (stack_init(&(*ppqueue)->pstack_2))){
		free(*ppqueue);
		*ppqueue = NULL;
		return E_NULL;
	}

	return E_OK;
}

int queue2stack_init(queue2stack ** ppstack)
{
	*ppstack = (queue2stack *)malloc(sizeof(queue2stack));
	if(NULL == *ppstack){
		return E_NULL;
	}

	(*ppstack)->count = 0;
	(*ppstack)->pqueue_1 = NULL;
	(*ppstack)->pqueue_2 = NULL;
	
	if(E_NULL == (queue_init(&(*ppstack)->pqueue_1))){
		free(*ppstack);
		*ppstack = NULL;
		return E_NULL;
	}

	if(E_NULL == (queue_init(&(*ppstack)->pqueue_2))){
		free(*ppstack);
		*ppstack = NULL;
		return E_NULL;
	}

	return E_OK;
}

int stack2queue_push(stack2queue * pqueue, int val)
{
	if((pqueue == NULL) || (pqueue->pstack_1 == NULL) || (pqueue->pstack_2 == NULL))return -1;

	/*in stack to stack_1*/
	while(!isempty(pqueue->pstack_2)){
		stack_push(pqueue->pstack_1, stack_pop(pqueue->pstack_2));
	}

	stack_push(pqueue->pstack_1, val);

	pqueue->count += 1;
	return E_OK;
}

int stack2queue_pop(stack2queue * pqueue)
{
	int res = 0;

	if((pqueue == NULL) || (pqueue->count == 0))return -1;

	while(!isempty(pqueue->pstack_1)){
		stack_push(pqueue->pstack_2, stack_pop(pqueue->pstack_1));
	}

	res = stack_pop(pqueue->pstack_2);
	pqueue->count -= 1;

	return res;
}

int queue2stack_push(queue2stack * pstack, int val)
{
	return E_OK;
}

int queue2stack_pop(queue2stack * pstack)
{
	int res = 0;

	return res;
}

