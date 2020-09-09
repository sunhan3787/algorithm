
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "include.h"
#include "stack.h"
#include "queue.h"


typedef int  KEY_VALUE;

typedef struct BINARYTREE_NODE{
	KEY_VALUE data;
	struct BINARYTREE_NODE * left;
	struct BINARYTREE_NODE * right;
}tree_node;

typedef tree_node root;

/*binary sort tree*/ 
#if 1

typedef struct BST{
	struct bstree_node * left;
	struct bstree_node * right;
}bst;


typedef struct bstree_node
{
	KEY_VALUE data;
	struct BST * bst;
};

struct bstree {
	struct bstree_node * root;
	struct bstree_node * nil;
};

#else

#define BST_ENTRY(name, type) \
	struct name{              \
		struct type * left;   \
		struct type * right;  \
	}

struct bstree_node{
	KEY_VALUE data;
	BST_ENTRY(, bst_node) * bst;
};

/*数据与业务分离*/
struct bstree {
	struct bstree_node * root;
	struct bstree_node * nil;
};

#endif

extern struct bstree_node * bstree_create_node(KEY_VALUE key);
extern int bstree_insert(struct bstree * T, KEY_VALUE key);
extern int bstree_traversal(struct bstree_node * node);

extern void BinaryTree_FrontTraverse(struct bstree_node * node);
extern void BinaryTree_MiddleTraverse(struct bstree_node * node);
extern void BinaryTree_PostTraverse(struct bstree_node * node);
extern void BinaryTree_LevelTraverse(struct bstree_node * node);

#endif
