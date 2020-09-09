
#include"queue.h"

int queue_init(queue ** ppqueue)
{
	*ppqueue = (queue*)malloc(sizeof(queue));

	if(NULL == *ppqueue){
		return E_NULL;
	}

	(*ppqueue)->count  = 0;
	(*ppqueue)->pend = NULL;
	(*ppqueue)->phead = NULL;

	return E_OK;
}

int queue_push(queue * pqueue, int val)
{
	queue_node * ptemp  = NULL;
	if(NULL == pqueue)return E_ERROR;

	ptemp = (queue_node *)malloc(sizeof(queue_node));
	ptemp->pnext = NULL;
	ptemp->value = val;

	/*push back in queue*/
	if((NULL == pqueue->phead) || (pqueue->count == 0)){
		pqueue->phead = ptemp;
	}else{
		pqueue->pend->pnext = ptemp;
	}

	pqueue->pend = ptemp;
	pqueue->count += 1;

	return E_OK;
}

int queue_pop(queue * pqueue)
{
	int res = 0;
	queue_node * pdel = NULL;

	if((NULL == pqueue) || (pqueue->count == 0)){
		return -1;
	}

	/*pop head from queue*/
	pdel = pqueue->phead;
	res = pqueue->phead->value;

	pqueue->phead = pqueue->phead->pnext;
	pqueue->count -= 1;

	free(pdel);
	pdel = NULL;

	return res;
}

int queue_reset(queue * pqueue)
{
	if(NULL == pqueue){
		return E_ERROR;
	
	}else{
	
		while(pqueue->count){
			queue_pop(pqueue);		
		}

		return E_OK;
	}
}

int queue_destory(queue ** ppqueue)
{
	int err = 0;
	if(*ppqueue){
		err = queue_reset(*ppqueue);
		if(E_OK == err){
			free(*ppqueue);
			*ppqueue = NULL;
			return E_OK;
		}else{
			printf("reset err...\n");
			return E_ERROR;
		}
	}else{
		return E_ERROR;
	}
}

int queue_getcount(queue * pqueue)
{
	if(pqueue == NULL){
		return -1;
	}else{
		if(pqueue->count){
			return pqueue->count;
		}else{
			return 0;
		}
	}
}

int  queue_isempty(queue * pqueue)
{
	if(pqueue == NULL){

		exit(-1);
	}else{
		return pqueue->count == 0 ? 1:0;
	}
}






