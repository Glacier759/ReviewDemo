/*
 * =====================================================================================
 *
 *       Filename:  demo_二叉树的基本操作.c
 *
 *    Description:  二叉树的基本操作
 *
 *        Version:  1.0
 *        Created:  2015年03月02日 00时37分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Glacier (RenLixiang), OurHom.759@gmail.com
 *        Company:  Class 1204 of Computer Science and Technology
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define		true	1
#define		false	0

typedef char elemType;
typedef	struct node {
	elemType		data;	//数据域
	struct node		*lChild, *rChild;	//指针域
}BiTree;

typedef struct queueNode {
	elemType			data;
	struct queueNode	*next;
}QueueNode;
typedef	struct {
	QueueNode	*rear, *front;
}Queue;

Queue	*init_Queue() {
	Queue		*queue;
	QueueNode	*node;

	node = (QueueNode *)malloc(sizeof(QueueNode));
	node->next = NULL;

	queue = (Queue *)malloc(sizeof(Queue));
	queue->front = queue->rear = node;

	return queue;
}

int		isEmpty_Queue( Queue *queue ) {
	if ( queue->front == queue->rear ) {
		return true;
	}
	return false;
}

int		push_Queue( Queue *queue, elemType x ) {
	QueueNode	*node;

	node = (QueueNode *)malloc(sizeof(QueueNode));
	node->next = NULL;
	node->data = x;

	node->next = queue->rear->next;
	queue->rear = node;

	return true;
}

QueueNode	*pop_Queue( Queue *queue ) {
	QueueNode	*node;

	node = queue->front;
	queue->front = node->next;

	return node;
}

BiTree	*create_BiTree() {		//先序创建二叉树
	BiTree	*biTree = (BiTree *)malloc(sizeof(BiTree));
	biTree->lChild = biTree->rChild = NULL;

	char ch = getchar();
	if ( ch != '#' ) {
		biTree->data = ch;
		biTree->lChild = create_BiTree();
		biTree->rChild = create_BiTree();
		return biTree;
	}
	return NULL;
}

void	preOrder( BiTree *biTree ) {		//先序遍历二叉树
	if ( biTree ) {
		printf("%5c", biTree->data);
		preOrder( biTree->lChild );
		preOrder( biTree->rChild );
	}
}

void	inOrder( BiTree *biTree ) {			//中序遍历二叉树
	if ( biTree ) {
		inOrder( biTree->lChild );
		printf("%5c", biTree->data);
		inOrder( biTree->rChild );
	}
}

void	postOrder( BiTree *biTree ) {		//后序遍历二叉树
	if ( biTree ) {
		postOrder( biTree->lChild );
		postOrder( biTree->rChild );
		printf("%5c", biTree->data);
	}
}

void	destory_BiTree( BiTree *biTree ) {	//销毁二叉树
	if ( biTree ) {
		destory_BiTree( biTree->lChild );
		destory_BiTree( biTree->rChild );
		free(biTree);
	}
}

void	clean_BiTree( BiTree *biTree ) {	//将bt置为空树
	destory_BiTree( biTree );
}

int		isEmpty_BiTree( BiTree *biTree ) {	//二叉树判空
	if ( biTree ) {
		return false;
	}
	return true;
}

int		getDepth_BiTree( BiTree *biTree ) {		//后序遍历统计树高/深度
	int		leftDepth, rightDepth, maxDepth;
	
	if ( biTree ) {
		leftDepth = getDepth_BiTree( biTree );
		rightDepth = getDepth_BiTree( biTree );
		maxDepth = leftDepth > rightDepth ? leftDepth : rightDepth;
		return maxDepth + 1;
	}

	return 0;
}

BiTree	*parent_BiTree( BiTree *biTree, BiTree *x ) {		//求x的双亲结点
	BiTree	*p;

	if ( biTree ) {
		if ( biTree->lChild == x || biTree->rChild == x ) {
			return biTree;
		}

		p = parent_BiTree( biTree->lChild, x );
		if ( !p ) {
			p = parent_BiTree( biTree->rChild, x );
		}
		return p;
	}
	return NULL;
}

BiTree	*leftChild_BiTree( BiTree *biTree, BiTree *x ) {	//求x的左子树
	return x->lChild;
}

BiTree	*rightChild_BiTree( BiTree *biTree, BiTree *x ) {	//求x的右子树
	return x->rChild;
}

/***********************************************************88*/
void	layerOrder( BiTree *biTree ) {
	Queue	*queue = init_Queue();
	BiTree	*temp;
	
	push_Queue( queue, biTree->data );
	while( !isEmpty_Queue(queue) ) {

		printf("%5c", value);
		push_Queue()
	}
}
/***********************************************************88*/

int main(int argc, char *argv[])
{
	printf("先序创建二叉树\n");
	BiTree *biTree = create_BiTree();
	printf("\n先序遍历二叉树: ");
	preOrder( biTree );
	printf("\n中序遍历二叉树: ");
	inOrder( biTree );
	printf("\n后序遍历二叉树: ");
	postOrder( biTree );


	return EXIT_SUCCESS;
}

