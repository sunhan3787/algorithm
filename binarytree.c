
#include "binarytree.h"

/*binarytree traverse front middle back*/

#define STACK_ON
#define QUEUE_ON




#ifdef STACK_ON



#endif

#ifdef QUEUE_ON


#endif

#if 1 /*binary sort tree*/ 

struct bstree_node * bstree_create_node(KEY_VALUE key)
{
	struct bstree_node * node = NULL;
	bst * pbst = NULL;

	node = (struct bstree_node*)malloc(sizeof(struct bstree_node));
	if(node == NULL) return NULL;

	pbst = (bst*)malloc(sizeof(bst));
	if(pbst == NULL)return NULL;

	pbst->left = NULL;
	pbst->right = NULL;
	
	node->data = key;
	node->bst = pbst;

	return node;
}


int bstree_insert(struct bstree * T, KEY_VALUE key)
{
	struct bstree_node *node = NULL;
	struct bstree_node * tmp = NULL;

	if(NULL == T)return -1;

	if(T->root == NULL){
		T->root = bstree_create_node(key);
		return 0;
	}

	node = T->root;
	tmp = T->root;

	while(node != NULL){
		tmp = node;
		if(key < node->data){
			node = node->bst->left;
			
		}else if(key > node->data){
			node = node->bst->right;
		}else{
			printf("node been, exit...\n");
			return -2;
		}
	}

	if(key <tmp->data){
		tmp->bst->left = bstree_create_node(key);
	}else{
		tmp->bst->right = bstree_create_node(key);
	}
	
	return 0;
}

int bstree_traversal(struct bstree_node * node)
{
	if(node == NULL)return 0;
	bstree_traversal(node->bst->left);
	printf("%d\n",node->data);
	
	bstree_traversal(node->bst->right);
		
	return 0;
}

#else

struct bstree_node * bstree_create_node(KEY_VALUE key)
{
	struct bstree_node * node = NULL;
	node = (struct bstree_node*)malloc(sizeof(struct bstree_node));
	if(node == NULL) return NULL;

	node->data = key;
	node->bst.left = node->bst.right = NULL;

	return node;
}


int bstree_insert(struct bstree * T, KEY_VALUE key)
{
	if(NULL == T)return -1;

	if(T->root == NULL){
		T->root = bstree_create_node(key);
		return 0;
	}

	struct bstree_node *node = T->root;
	struct bstree_node * tmp = T->root;

	while(node != NULL){
		tmp = node;
		if(key < node->data){
			node = node->bst.left;
			
		}else if(key > node->data){
			node = node->bst.right;
		}else{
			printf("node been, exit...\n");
			return -2;
		}
	}

	if(key <tmp->data){
		tmp->bst.data = bstree_create_node(key);
	}else{
		tmp->bst.right = bstree_create_node(key);
	}
	
	return 0;
}

int bstree_traversal(struct bstree_node * node)
{
	if(node == NULL)return 0;
	bstree_traversal(node->bst.left);
	printf("%d\n",node->data);
	
	bstree_traversal(node->bst.right);
		

}

#endif

void BinaryTree_FrontTraverse(struct bstree_node * node)
{

}

void BinaryTree_MiddleTraverse(struct bstree_node * node)
{

}

void BinaryTree_PostTraverse(struct bstree_node * node)
{

}

void BinaryTree_LevelTraverse(struct bstree_node * node)
{

}







