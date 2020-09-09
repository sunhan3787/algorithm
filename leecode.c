
#include "leecode.h"

/*
多行注释：选中代码，先按ctrl+k，再按ctrl+c；
取消多行注释：选中代码，先按ctrl+k，再按ctrl+u。
*/

#if 1

/*******************************************************************************
1.去除重复字符, a,ASCLL升序；b,去除后面重复的；c,去除前面重复字符
char * str = "acacdc";  //输出：acd
*******************************************************************************/
char * samllstr(char * str)
{
	return str;
}
#endif

/*******************************************************************************
//2.连续子序列最大值[a,b]区间求和最大，输出max_sum，元素
//res<0 输出0；
*******************************************************************************/
int GetMaxSum_inChildarr(int arr[],int nlength)
{
	int a=arr[0];
	int b=0;
	int Max=0;
	int i;
	for(i=1;i<nlength;i++)
	{
		a+=arr[i];
		b+=arr[i];
    	if(a>Max){
			Max=a;
		}
		if(b>Max){
			Max=b;
		}
		//a>b?b=0:a=0;
		if(a>b){
			b = 0;
		}else{
			a = 0;
		}
	}
	return Max;
}

//输出子序列最大和(包括负值)，并记录子序列[l,r]
int GetMaxSum(int arr[],int nlength)
{
	int CurrentSum=0;
	int Res=0x80000000;
	int i;
	int l=0,r=0;
	if(arr==NULL||nlength<=0)return 0;

	for(i=0;i<nlength ;i++)
	{
		if(CurrentSum<=0){
			CurrentSum=arr[i];
			l=i;
		}
		else{
			CurrentSum+=arr[i];
			r=i;
		}
		if(CurrentSum>Res)
		{
			Res=CurrentSum;
		}
	}
	for(i=l;i<=r;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
	return Res;
}

/*******************************************************************************
//int arr[] = {2,5,12,6,3,2,7,1};
//3.arr[n], arr[i]/arr[j] 或者arr[i]-arr[j]最大的问题；i<j;


优化：事件复杂度O(n)
思路一：从arr[0]->arr[n]找最大；从arr[n]->arr[0]找最小；	缩小[i,j]区间范围的思想
相遇i==j,三种可能，
	a>满足arr[i]<arr[j],i<j,在[max,min]内；
	b>.最小值在当前的[max,j]区间内；需要继续从arr[j]->arr[max]找最小；
	c>最大值在当前的[i,min]区间内；需要继续从arr[i]->arr[min]找最大；
思路二：动态规划思想：动态区间，题意分析arr[i]/arr[j],在[i,j]区间内的结果，[0,n]中的子序列[i,j]


*********************************************************************************/
//时间复杂度为O(3n/2)
int max_arri_arrj_1(int arr[], int len)
{
	int res = 0,cur_res = 0;
	int board[2] = {0};//保存边界[i,j];
//	int len = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	int j = len - 1;
	int min = i,max = j;

	while(i<j){
		if(arr[i] > arr[max]){
			max = i;
		}

		if(arr[j] < arr[min]){
			min = j;
		}
		board[0] = max;
		board[1] = min;
		cur_res = arr[max]/arr[min];

		if(res < cur_res){
			res = cur_res;
		}
		i++;
		j--;
	}

	while(i < min){
		if(arr[i] > arr[max]){
			max = i;
		}

		board[0] = max;
		board[1] = min;

		cur_res = arr[max]/arr[min];

		if(res < cur_res){
			res = cur_res;
		}
		i++;
	}

	while(j > max){
		if(arr[j] < arr[min]){
			min = j;
		}

		board[0] = max;
		board[1] = min;

		cur_res = arr[max]/arr[min];

		if(res < cur_res){
			res = cur_res;
		}
		j--;
	}

	for(i = 0; i < sizeof(board)/sizeof(board[0]); i++){
		printf("board: %d\n",board[i]);
	}

	return res;
}

int max_inij_decmax(int arr[], int len)
{
	int res = 0,cur_res = 0;
	int board[2] = {0};//保存边界[i,j];
//	int len = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	int j = len - 1;
	int min = i,max = j;

	while(i<j){
		if(arr[i] > arr[max]){
			max = i;
		}

		if(arr[j] < arr[min]){
			min = j;
		}
		board[0] = max;
		board[1] = min;
		cur_res = arr[max]-arr[min];

		if(res < cur_res){
			res = cur_res;
		}
		i++;
		j--;
	}

	while(i < min){
		if(arr[i] > arr[max]){
			max = i;
		}

		board[0] = max;
		board[1] = min;

		cur_res = arr[max]-arr[min];

		if(res < cur_res){
			res = cur_res;
		}
		i++;
	}

	while(j > max){
		if(arr[j] < arr[min]){
			min = j;
		}

		board[0] = max;
		board[1] = min;

		cur_res = arr[max]-arr[min];

		if(res < cur_res){
			res = cur_res;
		}
		j--;
	}

	for(i = 0; i < sizeof(board)/sizeof(board[0]); i++){
		printf("board: %d\n",board[i]);
	}

	return res;
}

/*******************************************************************************
//4.将数组内的奇数和偶数分开,偶数放前面，奇数放后面
*******************************************************************************/
void ChopNum(int arr[],int nlength)
{
	int nLow=0;
	int nHigh=nlength-1;
	int i=nLow -1;
	if(arr==NULL||nlength<=0)return ;

	for(;nLow<nlength ;nLow++){
		if(arr[nLow]%2==0){
			if(++i!=nLow ){
				arr[i]=arr[i]^arr[nLow ];
				arr[nLow ]=arr[i]^arr[nLow ];
				arr[i]=arr[i]^arr[nLow ];
			}
		}
	}
	if(++i!=nHigh ){
		arr[i]=arr[i]^arr[nHigh ];
		arr[i]=arr[i]^arr[nHigh ];
		arr[i]=arr[i]^arr[nHigh ];
	}
}


int leecode_MainFunction(void)
{
	int arr[] = {2,5,12,1,6,3,2,7,11};
	int arr2[] = {-2,-5,12,-1,6,-3,-2,7,11};
	int arr3[] = {2,5,12,1,6,3,2,7,11};
	int result = 0;
	int i = 0;

	result = max_arri_arrj_1(arr, sizeof(arr)/sizeof(arr[0]));
	printf("max arr[i]/arr[j] res== %d\n", result);

	result = max_inij_decmax(arr, sizeof(arr)/sizeof(arr[0]));
	printf("max dec res== %d\n", result);

	result = GetMaxSum_inChildarr(arr2, sizeof(arr2)/sizeof(arr2[0]));
	printf("sum1== %d\n", result);
	
	result = GetMaxSum(arr2, sizeof(arr2)/sizeof(arr2[0]));
	printf("sum2== %d\n", result);
	
	ChopNum(arr3, sizeof(arr3)/sizeof(arr3[0]));
	for(i = 0; i < sizeof(arr3)/sizeof(arr3[0]); i++){
		printf("%d  ", arr3[i]);
	}
	printf("\n");
	return 0;
}



