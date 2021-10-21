#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;

typedef struct NODE
{
	int nValue;
	struct NODE*pLeft;
	struct NODE* pRight;
}TreeNode, *Tree;
typedef struct NODE1
{
	TreeNode*pTreeNode;
	struct NODE1 *pNext;
}StackNode;
typedef struct NODE2
{
	int nCount;
	StackNode *pTop;
}Stack;

void InitStack(Stack**ppstack)
{
	(*ppstack)=(Stack*)malloc(sizeof(Stack));
	(*ppstack)->nCount =0;
	(*ppstack )->pTop =NULL;
}

void PushStack(Stack*pstack,TreeNode *pNode)
{
	if(pstack==NULL||pNode==NULL)return;
	StackNode*pstackNode=(StackNode*)malloc(sizeof(StackNode ));
	pstackNode ->pTreeNode  =pNode;
	pstackNode ->pNext =pstack->pTop ;
	pstack->pTop =pstackNode;
	pstack->nCount ++;
}

TreeNode * PopStack(Stack*pstack)
{
	StackNode*pDel=NULL;
	TreeNode *pNode=NULL;

	if(pstack==NULL)return NULL;

	pDel=pstack->pTop ;
	pNode=pDel->pTreeNode ;
	pstack->pTop =pstack ->pTop ->pNext ;
	free(pDel);
	pDel=NULL;
	pstack->nCount --;
	return pNode ;
}

int IsEmpty(Stack*pstack)
{
	if(pstack==NULL)exit(1);
	return pstack->nCount ==0?1:0;
}

TreeNode * CreateTree(int arr[],int nlength)
{
	printf("create tree running...\n");
	int i;
	TreeNode *pNode=NULL;

	if(arr==NULL ||nlength<=0)return NULL;
	pNode=(TreeNode *)malloc(sizeof(TreeNode )*nlength );
	memset(pNode,0,sizeof(TreeNode )*nlength); 
	for(i=0;i<nlength;i++){
		pNode[i].nValue =arr[i];
		pNode[i].pLeft =NULL;
		pNode[i].pRight =NULL;
	}
	for(i=0;i<nlength;i++)
	{
		if(2*i+1<nlength){
			pNode[i].pLeft =&pNode[2*i+1];
		}
		if(2*i+2<nlength)
		{
			pNode[i].pRight =&pNode[2*i+2];
		}
	}
	return pNode;
}
void PreTraverse(TreeNode *pTree)
{
	if(pTree==NULL)return;
	printf("%d ",pTree->nValue );
	PreTraverse (pTree->pLeft );
	PreTraverse (pTree->pRight );
}

void Pre(TreeNode *pTree)
{
	printf("Pre Traverse tree running...\n");
	stack<TreeNode *>ps;

	if(pTree==NULL)return;
	while(1){
		while(pTree){
			ps.push (pTree);
			printf("%d ",pTree->nValue );
			pTree=pTree->pLeft ;
		}
		if(ps.size ()>=0){
			if(ps.size ()==0)break;
			pTree=ps.top ();
			ps.pop();
		}
		pTree=pTree->pRight ;
	}
}

void PostTraverse(TreeNode *pTree)//后序遍历的完整路径
{
	printf("Post Traverse tree running...\n");
	TreeNode *pTemp=NULL;
	Stack*pstack=NULL;

	if(pTree==NULL)return;

	InitStack (&pstack);
	while(1){
		while(pTree){
			PushStack (pstack,pTree);
			pTree=pTree->pLeft ;
		}
		if(pstack->pTop ==NULL)break;
		if(pstack->pTop ->pTreeNode ->pRight ==NULL||pstack ->pTop ->pTreeNode ->pRight ==pTemp)
		{
			pTemp=PopStack (pstack);
			printf("%d ",pTemp->nValue );
		}
		else{
		
			pTree=pstack->pTop ->pTreeNode ->pRight ;
		}
	}
}


void LevelTraverse(TreeNode *pTree)
{
	printf("Level Traverse tree running...\n");
	int bj=1;
	static int i=0;

	if(pTree==NULL)return;
	queue<TreeNode*> pq;
	pq.push (pTree);

	while(!pq.empty ()){
		pTree=pq.front ();
		pq.pop();
		if(pTree->nValue > 0)printf("%d ",pTree->nValue );
		++i;
		if(i%bj==0){
			printf("\n");
			bj*=2;
			i=0;
		}
		if(pTree->pLeft !=NULL)
		{
			pq.push (pTree->pLeft );
		}
		if(pTree->pRight !=NULL)
		{
			pq.push (pTree->pRight );
		}
	}
}

//树的深度
int Depth(TreeNode *pTree)
{
	if(pTree==NULL)return 0;
	int nLeft=Depth(pTree->pLeft );
	int nRight=Depth (pTree->pRight );
	return nLeft>nRight?nLeft+1:nRight+1;
}

void ChangeChild(TreeNode *pTree)
{
	if(pTree==NULL)return;
	queue<TreeNode *>pq;
	TreeNode *pTemp=NULL;
	pq.push (pTree);
	while(!pq.empty ()){
		pTree=pq.front ();
		pq.pop();
		if(pTree->pLeft !=NULL && pTree->nValue > 0)
		{
			pq.push(pTree->pLeft );
		}
		if(pTree->pRight !=NULL && pTree->nValue > 0){
			pq.push (pTree->pRight );
		}
		pTemp=pTree->pLeft ;
		pTree->pLeft =pTree ->pRight ;
		pTree->pRight =pTemp ;
	}

}

//count tree node
int CountTreeNode(TreeNode *ptree)
{
	int nleft = 0, nright = 0;
	if(ptree == NULL){
		return 0;
	}else{
		nleft = CountTreeNode(ptree->pLeft);
		nright = CountTreeNode(ptree->pRight);
		return (nleft + nright +1);
	}
}

static int res = 0;
//count tree leaf
void CountLeafTraverse(TreeNode *ptree)
{
	if(ptree == NULL) return;

	if((ptree->pLeft == NULL) && (ptree->pRight == NULL)){
		res++;
	}

	CountLeafTraverse(ptree->pLeft);
	CountLeafTraverse(ptree->pRight);
}

int CountLeaf_Rec(TreeNode *ptree)
{
	int n = 0;

	if(ptree == NULL) return 0;

	if((ptree->pLeft == NULL) && (ptree->pRight == NULL)){
		n++;
	}

	n = CountLeaf_Rec(ptree->pLeft) + CountLeaf_Rec(ptree->pRight);

	return n;
}

//分治思想
int CountLeaf(TreeNode *ptree)
{
	int count = 0;

	if(ptree == NULL){ 
		count = 0;
	}
	else if((ptree->pLeft == NULL) && (ptree->pRight == NULL)){
		count = 1;
	}
	else{
		count = CountLeaf(ptree->pLeft) + CountLeaf(ptree->pRight);
	}

	return count;
}

void copy_binarytree(Tree t, Tree &tt){
	if(t == NULL)return;
	TreeNode* ptemp = (TreeNode*)malloc(sizeof(TreeNode));
	ptemp->nValue = t->nValue;
	ptemp->pLeft = NULL;
	ptemp->pRight = NULL;
	tt = ptemp;

	copy_binarytree(t->pLeft, tt->pLeft);
	copy_binarytree(t->pRight, tt->pRight);
}

bool is_sametree(Tree t1, Tree t2){
	bool same_left = false;

	if(((t1 == NULL) && (t2 != NULL)) || 
		((t1 != NULL) && (t2 == NULL))){
		return false;
	}

	if((t1 == NULL) && (t2 == NULL))return true;
	
	if(t1->nValue != t2->nValue)return false;

	same_left = is_sametree(t1->pLeft, t2->pLeft);
	if(same_left == false){
		return false;
	}
	return is_sametree(t1->pRight, t2->pRight);
}

int main()
{
	int arr[]={4,2,8,3,7,6,10,12,1,23,9,5,15,53};
	int is_samearr[]={4,2,8,3,7,6,12,1,23,9,5,15,53};
	TreeNode* pTree=NULL;
	TreeNode* pTemp=NULL;
	TreeNode* ptt=NULL;
	TreeNode* pSameTree = NULL;
	bool IsSame = false;

	pTree=CreateTree (arr,sizeof(arr)/sizeof(arr[0]));
	pSameTree=CreateTree (is_samearr,sizeof(is_samearr)/sizeof(is_samearr[0]));
	
	IsSame = is_sametree(pTree, pSameTree);
	if(IsSame == false){
		printf("the trees are different...\n");
	}else{
		printf("the trees are same...\n");
	}

	LevelTraverse(pTree );
	printf("\n");
	LevelTraverse(pSameTree );
	printf("\n");

	PostTraverse (pTree);
	printf("\n");
	//LevelTraverse(pTree );
	printf("\n");

	int nDepth=0;
	nDepth =Depth (pTree);
	printf("树高：%d",nDepth);
	printf("\n");
	printf("镜像\n");

	ChangeChild (pTree);
	LevelTraverse (pTree);
	printf("\n");

	int nCount = 0;
	nCount = CountTreeNode(pTree);
	printf("树节点总数：%d\n",nCount);

	nCount = CountLeaf(pTree);
	printf("CountLeaf树叶子节点总数：%d\n",nCount);

	CountLeafTraverse(pTree);
	printf("树叶子节点总数：%d\n",res);
	printf("\n");

	copy_binarytree(pTree, ptt);
	LevelTraverse (pTree);
	printf("\n");
	LevelTraverse (ptt);
	printf("\n");

	return 0;
}
