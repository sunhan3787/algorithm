
#ifndef QUEUE_H
#define QUEUE_H


#include"include.h"

typedef struct NODE queue_node;

typedef struct QUEUE{
	queue_node * phead;
	queue_node * pend;
	unsigned int count;
}queue;

extern int queue_init(queue ** ppqueue);
extern int queue_push(queue * pqueue, int val);
extern int queue_pop(queue * pqueue);
extern int queue_reset(queue * pqueue);
extern int queue_destory(queue ** ppqueue);
extern int queue_getcount(queue * pqueue);
extern int  queue_isempty(queue * pqueue);


#endif
