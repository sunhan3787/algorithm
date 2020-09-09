
#include"stack.h"


int stack_init(stack ** ppstack)
{
	*ppstack = (stack *)malloc(sizeof(stack));

	if(NULL == *ppstack){
		return E_NULL;
	}else{	

		(*ppstack)->count = 0;
		(*ppstack)->ptop = NULL;

		return E_OK;
	}
}

int stack_push(stack * pstack, int val)
{
	stack_node * ptemp  = NULL;
	if(NULL == pstack)return E_ERROR;

	ptemp = (stack_node *)malloc(sizeof(stack_node));
	ptemp->pnext = pstack->ptop;
	ptemp->value = val;

	/*push in stack*/
	pstack->ptop = ptemp;
	pstack->count += 1;

	return E_OK;
}

int stack_pop(stack * pstack)
{
	int result = 0;
	stack_node * pdel = NULL;

	if((NULL == pstack) || (pstack->count == 0))return -1;

	pdel = pstack->ptop;
	result = pstack->ptop->value;

	pstack->ptop = pstack->ptop->pnext;
	pstack->count -= 1;
	
	free(pdel);
	pdel = NULL;

	return result;
}

int stack_reset(stack * pstack)
{
	if(NULL == pstack){
		return E_ERROR;
	
	}else{
	
		while(pstack->count){
			stack_pop(pstack);		
		}

		return E_OK;
	}
}

int destory(stack ** ppstack)
{
	int err = 0;
	if(*ppstack){
		err = stack_reset(*ppstack);
		if(E_OK == err){
			free(*ppstack);
			*ppstack = NULL;
			return E_OK;
		}else{
			return E_ERROR;
		}
	}else{
		return E_ERROR;
	}
}

stack_node* gettop(stack * pstack)
{
	if(NULL == pstack){

		exit(1);
	}else{
		return pstack->ptop;
	}

}

int getcount(stack * pstack)
{

	if(pstack == NULL){
		return -1;
	}else{
		if(pstack->count){
			return pstack->count;
		}else{
			return 0;
		}
	}
}

int  isempty(stack * pstack)
{
	if(pstack == NULL){

		exit(-1);
	}else{
		return pstack->count == 0 ? 1:0;
	}
}













