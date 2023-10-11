#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<sys/time.h>


#define DATASET_SIZE  100000

int devide_merge_data[DATASET_SIZE] = {0};
int bubble_data[DATASET_SIZE] = {0};
int quick_sort_data[DATASET_SIZE] = {0};
int ret_int = 65535000;
//int ret_int = 32767;


//归并排序
void devide_merge_sort(int* data, int start, int end);
void merge_sort(int* data, int left, int right);

//快速排序
void quick_sort(int* data, int start, int end);
int qsort_exchange(int* data, int start, int end);

//冒泡排序
void bubble_sort(int* data, int length);

//打印数据集
void print_dataset(int* data, int length);

int is_result_err(int* data_1, int* data_2, int length);

int main(){
	int i = 0;
	int ret = 0;
	int length = sizeof(devide_merge_data)/sizeof(int);

	//time_t timer_start = 0, timer_stop = 0;
	struct timeval tv;
	unsigned long sec_start, sec_stop,ms_start, ms_stop, us_start, us_stop;
	
	printf("Test Entry, Data set size is %d  \n", length);
	//printf("RET INT == %d \n", ret_int);

	srand((unsigned long) time(0));

	//1.获取随机数据集
	for(i = 0; i < sizeof(devide_merge_data)/sizeof(int); i++){
		//ret = rand() % ret_int;
		ret = rand();

		devide_merge_data[i] = ret;
		bubble_data[i] = ret;
		quick_sort_data[i] = ret;
	}
	printf("dataset collection is finished...\n");

	//2.归并排序，打印时间戳，计算消耗的时间
	printf("Devide merge sort begining...\n");
	
	//timer_start = time(NULL);
	gettimeofday(&tv, NULL);
	sec_start = tv.tv_sec;
	ms_start = tv.tv_usec/1000;
	us_start = tv.tv_usec % 1000;
	printf("devide merge sort started at %ld s %ld ms %ld us\n", sec_start, ms_start, us_start);

	devide_merge_sort(devide_merge_data, 0, length - 1);

	//timer_stop = time(NULL);
	gettimeofday(&tv, NULL);
	sec_stop = tv.tv_sec;
	ms_stop = tv.tv_usec/1000;
	us_stop = tv.tv_usec % 1000;
	printf("devide merge sort finished at %ld s %ld ms %ld us\n", sec_stop, ms_stop, us_stop);

	//print_dataset(devide_merge_data, length);
	printf("devide merge sort cost time: %ld s %ld ms %ld us \n", sec_stop - sec_start, ms_stop - ms_start, us_stop - us_start);
	
	//3.quick sort
	printf("Quick sort begining...\n");
	
	gettimeofday(&tv, NULL);
	sec_start = tv.tv_sec;
	ms_start = tv.tv_usec/1000;
	us_start = tv.tv_usec % 1000;
	printf("bubble sort started at %ld s %ld ms %ld us\n", sec_start, ms_start, us_start);

	quick_sort(quick_sort_data, 0, length - 1);

	gettimeofday(&tv, NULL);
	sec_stop = tv.tv_sec;
	ms_stop = tv.tv_usec/1000;
	us_stop = tv.tv_usec % 1000;	
	printf("bubble sort finished at %ld s %ld ms %ld us\n", sec_stop, ms_stop, us_stop);
	
	printf("bubble sort cost time: %ld s %ld ms %ld us\n", sec_stop - sec_start, ms_stop - ms_start, us_stop - us_start);

	if(0 != is_result_err(devide_merge_data, quick_sort_data, length)){
		printf("Quick sort result ERROR...\n");
	}else{
		printf("the result is no ERROR...\n");
	}

	//4.冒泡排序，打印时间戳，计算算法运行的时间
	printf("Bubble sort begining...\n");
	
	//timer_start = time(NULL);
	gettimeofday(&tv, NULL);
	sec_start = tv.tv_sec;
	ms_start = tv.tv_usec/1000;
	us_start = tv.tv_usec % 1000;
	printf("bubble sort started at %ld s %ld ms %ld us\n", sec_start, ms_start, us_start);

	bubble_sort(bubble_data, length);

	//timer_stop = time(NULL);
	gettimeofday(&tv, NULL);
	sec_stop = tv.tv_sec;
	ms_stop = tv.tv_usec/1000;
	us_stop = tv.tv_usec % 1000;	
	printf("bubble sort finished at %ld s %ld ms %ld us\n", sec_stop, ms_stop, us_stop);
	
	//print_dataset(bubble_data, length);
	printf("bubble sort cost time: %ld s %ld ms %ld us\n", sec_stop - sec_start, ms_stop - ms_start, us_stop - us_start);

	if(0 != is_result_err(devide_merge_data, bubble_data, length)){
		printf("Bubble sort result ERROR...\n");
	}else{
		printf("the result is no ERROR...\n");
	}

	return 0;
}

void merge_sort(int* data, int left, int right){
	
	int start1 = left;
    int end1 = left + (right - left)/2;
    int start2 = end1 + 1;
    int end2 = right;
    int * temp = NULL;
    int index = 0;
    
	temp = (int *)malloc(sizeof(int) * (right - left + 1));
    
	if(NULL != temp){
        while(start1 <= end1 && start2 <= end2){
            if(data[start1] < data[start2]){
                temp[index++] = data[start1++];
            }else{
                temp[index++] = data[start2++];
            }
        }

        while(start1 <= end1){
            temp[index++] = data[start1++];
        }

        while(start2 <= end2){
            temp[index++] = data[start2++];
        }

        for(index = 0; index < (right - left +1); index++){
            data[index + left] = temp[index];
        }
    }

//test code
#if 0
	//index = 0;
	//printf("");
	print_dataset(temp, right - left + 1);
#endif

    free(temp);
    temp = NULL;
}

void devide_merge_sort(int* data, int start, int end){
    if(NULL == data || start >= end)return;

    int mid = 0;
    mid = start + (end - start)/2;

    devide_merge_sort(data, start, mid);
    devide_merge_sort(data, mid + 1, end);

    merge_sort(data, start, end);
}

void quick_sort(int* data, int start, int end){
	if(NULL == data || end <= start)return;

	int standard_n = 0;

	standard_n = qsort_exchange(data, start, end);

	quick_sort(data, start, standard_n - 1);
	quick_sort(data, standard_n + 1, end);
}

int qsort_exchange(int* data, int start, int end){
	int small_i = 0;
	int temp_n = 0;
	
	small_i = start - 1;
	
	for( ; start < end; start++){
		if(data[start] < data[end]){
			if(++small_i != start){
				temp_n = data[small_i];
				data[small_i] = data[start];
				data[start] = temp_n;
			}
		}
	}

	if(++small_i != end){
		temp_n = data[small_i];
		data[small_i] = data[end];
		data[end] = temp_n;
	}
	
	return small_i;
}

void bubble_sort(int* data, int length){
	if(NULL == data || length <= 0)return;

	int i = 0, j = 0;
	int temp = 0, flag = 0;
	
#if 1
	//大的元素不断向后放，进行大元素升序冒泡, 速度慢
	for( i = 0; i < length; i++){

		flag = 0;
		for(j = 0; j < length - 1 - i; j++){
			
			if(data[j] > data[j + 1]){
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				flag = j + 1;
			}
		}

		if(flag == 0)break;
		i = length - 2 - flag;
	}

#else
	//找小的元素替换data[i],会产生很多不必要的交换
	for( i = 0; i < length; i++){
		for(j = i + 1; j < length; j++){
				
			if(data[i] > data[j]){
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		
		}
	}
#endif

}

void print_dataset(int* data, int length){
	if(NULL == data || length <= 0)return;
	
	printf("Print Dataset Entry: \n");

	int i = 0;

	for(i = 0; i < length; i++){
		printf("%d, ", data[i]);
	}

	printf("print dataset finished...\n");
}

int is_result_err(int* data_1, int* data_2, int length){
	if(NULL == data_1 || NULL == data_2 || length <= 0)return 1;

	int i = 0;
	for( i = 0; i < length; i++){
		if(data_1[i] != data_2[i]){
			printf("bubble sort result is not consistent to devide merge sort...\n");
			return 1;
		}
	}
	
	printf("align all the result consistent...\n");
	return 0;
}



