
#include "std_lib.h"

#ifdef DATA_IN_CACHE_ENABLE
static int queue_cache[QUEUE_CACHE_SIZE];
static int queue_info_head;
static int queue_info_tail;
static int queue_info_count;
static int enable;

/*queue working in cache  */
void q_init(){
	memset(queue_cache, -1, sizeof(int)*QUEUE_CACHE_SIZE);
	queue_info_head = 0;
	queue_info_tail = 0;
	queue_info_count = 0;
	enable = 1;
}

void q_push(int value){
	if(queue_info_tail >= QUEUE_CACHE_SIZE){
		queue_info_tail = queue_info_tail%QUEUE_CACHE_SIZE;
	}

	queue_cache[queue_info_tail] = value;
	queue_info_tail += 1;
	queue_info_count += 1;
}

int q_pop(){
	if(queue_info_count == QUEUE_EMPTY){
		printf("pop operation queue cache is empty...\n");
		return 0;
	}

	int result = -1;
	result = queue_cache[queue_info_head];
	queue_cache[queue_info_head] = -1;
	queue_info_head += 1;
	queue_info_count -= 1;

	if(queue_info_head >= QUEUE_CACHE_SIZE){
		queue_info_head = 0;
	}

	return result;
}

int q_get_count(){
	return(enable == 1)? queue_info_count : 0;
}


/************************************************************
function description: queue cache main function test interface
input: none;
output: nont;
call the print function;
************************************************************/
int q_cache_main(){
	int i;
	int arr[] = {23,4,35,54,6,45,65,76,81,87,98,9,89,8,90};

	q_init();

	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		q_push(arr[i]);
	}

	i = 1;
	while(queue_info_count > 0){
		printf("phead index:%d; queue count:%d; No.%d queue member:%d\n", queue_info_head, queue_info_count, i, q_pop());
	}

	system("pause");
	return 0;
}

#else

queue_cache_info* q_init(){
	queue_cache_info* queue = (queue_cache_info*)malloc(sizeof(queue_cache_info));
	if(queue == NULL){
		printf("create queue failed...\n");
	}

	memset(queue->data, -1, sizeof(queue->data));
	queue->head = 0;
	queue->tail = 0;
	queue->count = 0;
	queue->size = QUEUE_CACHE_SIZE;
	return queue;
}

void q_push(queue_cache_info* queue, int value){
	if(queue->count >= (int)queue->size){
		printf("queue overflow...\n");
		//return;
	}

	queue->data[queue->tail] = value;
	queue->tail += 1;
	if(queue->tail >= (int)queue->size){
		queue->tail = queue->tail%QUEUE_CACHE_SIZE;
	}
	queue->count += 1;
}

int q_pop(queue_cache_info* queue){
	//cycle queue cache has been overwrited
	if(queue->data[queue->head] == -1){
		queue->count -= 1;
		printf("queue member has been overwrited...\n");
		return -1;
	}

	//queue cache is empty
	if(queue->count <= QUEUE_EMPTY){
		printf("pop operation queue cache is empty...\n");
		return -1;
	}

	int result = -1;
	result = queue->data[queue->head];
	queue->data[queue->head] = -1; //reset the data area;
	queue->head = (queue->head+1)%queue->size;
	queue->count -= 1;

	return result;
}

int q_get_count(queue_cache_info* queue){
	return(queue->count == 0)? 0 : queue->count;
}

int q_reset(queue_cache_info* queue){
	if(queue == NULL)return 1;
	memset(queue->data, -1, sizeof(queue->data));
	queue->head = 0;
	queue->tail = 0;
	queue->count = 0;

	return 0;
}

int q_destroy(queue_cache_info* queue){
	if(queue == NULL)return 1;
	if(queue){
		free(queue);
		queue = NULL;
	}

	return 0;
}

/************************************************************
function description: queue cache main function test interface
input: none;
output: nont;
call the print function;
************************************************************/
int q_cache_main(){
	int i;
	queue_cache_info* queue = NULL;
	int arr[] = {23,4,35,54,6,45,65,76,81,87,98,9,89,8,90};

	queue = q_init();

	for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		q_push(queue, arr[i]);
	}

	i = 0;
	while(queue->count > 0){
		printf("phead index:%d; queue count:%d; No.%d queue member:%d\n", queue->head, queue->count, i++, q_pop(queue));
	}

	q_destroy(queue);


	system("pause");
	return 0;
}
#endif 




