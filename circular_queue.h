#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"std_include.h"

/**************************************************
description:
this file is lib data structure define:
such as:{queue,stack,binarytree,AVL, BST, RBT, map}

use for: leecode algorithm traning
author: will
date  : 2021/8/14
copy right: will
***************************************************/

typedef struct Q_NODE{
	struct Q_NODE* next;
	struct Q_NODE* pre;
	int value;
}queue_node;

typedef struct Q_STRUCT{
	queue_node* head;
	queue_node* tail;
	int count;
}queue;

/****************************************************
1.queue create create by array 
****************************************************/
#define QUEUE_CACHE_SIZE         128
#define QUEUE_EMPTY              0
//#define DATA_IN_CACHE_ENABLE     0
/*data in heap*/
typedef struct QUEUE_CACHE_INFO{
	int head;
	int tail;
	int count;
	size_t size;
	//int data[QUEUE_CACHE_SIZE];
	int data[QUEUE_CACHE_SIZE];
}queue_cache_info;

#ifdef DATA_IN_CACHE_ENABLE
/*queue cache interface define*/
void q_init();
void q_push(int value);
int q_pop();
int q_get_count();
int q_find();//get index value in queue;
int q_cache_main();//test interface;
int q_reset();

#else
queue_cache_info* q_init();
void q_push(queue_cache_info* queue, int value);
int q_pop(queue_cache_info* queue);
int q_get_count(queue_cache_info* queue);
int q_find(queue_cache_info* queue, int value);//search hashtable, get index value in queue;
int q_reset(queue_cache_info* queue);
int q_destroy(queue_cache_info* queue);
int q_cache_main();//test interface;

#endif

/****************************************************
2.queue use struct point
****************************************************/
void queue_init(queue ** q);
void queue_push(queue* q, int value);
int queue_pop(queue* q);
bool is_queue_empty(queue* q);

/****************************************************
3.LUR queue
3.1.find value is in queue cache data, 
3.2.if in pop it and push it again
3.3.if not, add new one, and out the one that not used to recently,

****************************************************/
void lur_init();

#endif
