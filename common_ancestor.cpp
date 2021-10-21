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
//	struct NODE*pFather;
}TreeNode;

TreeNode * CreateTree(int arr[],int nlength)
{
	if(arr==NULL ||nlength<=0)return NULL;
	int i;
	TreeNode *pNode=NULL;
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

void GetPath(TreeNode*pTree,TreeNode*pNode,list<TreeNode *>&path)
{
	if(pTree==NULL)return;
	TreeNode *pTemp=NULL;
	Stack*pstack=NULL;
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
			if(pNode->nValue ==pTemp->nValue )
			{
				path.push_back (pTemp);
				while(!IsEmpty (pstack)){
					pTemp=PopStack (pstack);
					path.push_back (pTemp );
				}
				return;
			}
		}
		else{
		
			pTree=pstack->pTop ->pTreeNode ->pRight ;
		}
	}
}

TreeNode *GetCommonNode(list<TreeNode *>&lst1,list<TreeNode *>lst2)
{
	//���������󽻵�
	TreeNode *pNode=NULL;
	//��������󹫹��ڵ�
	list<TreeNode *>::reverse_iterator revite1=lst1.rbegin ();
	list<TreeNode *>::reverse_iterator revite2=lst2.rbegin ();
	while(revite1!=lst1.rend()&&revite2!=lst2.rend()){
		if(*revite1==*revite2){
			pNode=*revite1;
		}
		revite1++;
		revite2++;
	}
	return pNode;
}

TreeNode *LastCommonNode(TreeNode *pTree,TreeNode*pNode1,TreeNode *pNode2)
{
	if(pTree==NULL||pNode1==NULL||pNode2==NULL)return NULL;
	TreeNode *pCommonNode=NULL;
	//1.��������ڵ��·��
	list<TreeNode *>path1;
	GetPath (pTree,pNode1,path1);
	list<TreeNode *>path2;
	GetPath (pTree,pNode2,path2);
	//2.�󹫹�����
	pCommonNode=GetCommonNode (path1,path2);
	//return pCommonNode ;
	//��ӡ·��
	list<TreeNode *>::iterator ite1=path1.begin ();
	printf("path1 print: ");
	while(ite1!=path1.end()){
		printf("%d,",(*ite1)->nValue );	
		ite1++;
	}
	printf("\n");
	printf("path1 print: ");
	list<TreeNode *>::iterator ite2=path2.begin ();
	while(ite2!=path2.end()){
		printf("%d,",(*ite2)->nValue );
		ite2++;
	}
	printf("\n");
	return pCommonNode ;
}

int main()
{
	int arr[]={4,2,8,3,7,6,10,12,1,23,9,5,15,53,11};
	TreeNode*pTree=NULL;
	TreeNode*pTemp=NULL;
	TreeNode*pNode1=NULL;
	pNode1=(TreeNode *)malloc(sizeof(TreeNode ));
	pNode1->nValue =53;
	pNode1->pLeft =NULL;
	pNode1->pRight =NULL;
	TreeNode*pNode2=NULL;
	pNode2=(TreeNode *)malloc(sizeof(TreeNode ));
	pNode2->nValue =23;
	pNode2->pLeft =NULL;
	pNode2->pRight =NULL;
	pTree=CreateTree (arr,sizeof(arr)/sizeof(arr[0]));

	pTemp=LastCommonNode (pTree,pNode1,pNode2);
	if(pTemp==NULL){
		printf("�޹������Ƚڵ�\n");
	}
	printf("%d\n",pTemp->nValue );
	return 0;
}
