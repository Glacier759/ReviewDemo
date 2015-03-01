/*
 * =====================================================================================
 *
 *       Filename:  demo_队列的概念及运算.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 23时30分55秒
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

#define		MAXSIZE		100
#define		false		0
#define		true		1

//循环队列的类型定义及基本运算
typedef int datatype;
typedef struct {
	datatype	data[MAXSIZE];	//队列的储存区
	int		front, rear;		//队头队尾指针
}SeQueue;						//循环队

//链队列
typedef	struct node {
	datatype	data;
	struct node *next;
}QNode;					//链队列结点的类型
typedef struct {
	QNode	*front, *rear;
}LQueue;

//创建一个带头结点的空队
LQueue	*init_LQueue() {
	LQueue	*q;
	QNode	*p;
	q = (LQueue *)malloc( sizeof(LQueue) );			//申请头尾指针结点
	p = (QNode *)malloc( sizeof(QNode) );			//申请链队头结点
	p->next = NULL;
	q->front = q->rear = p;
	return q;
}

//入队
void	inLQueue( LQueue *q, datatype x ) {
	QNode	*p;
	p = (QNode *)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

//判队空
int		emptyLQueue( LQueue *q ) {
	if (  q->front == q->rear ) {
		return false;
	}
	return true;
}

//出队
int		outLQueue( LQueue *q, datatype *x ) {
	QNode	*p;
	if ( emptyLQueue( q ) ) {
		printf("队空!\n");
		return false;
	}
	else {
		p = q->front;
		q->front->next = p->next;
		*x = p->data;					//队头元素放x中
		free(p);

		if ( q->front->next == NULL ) {			//只有一个元素时,出队后队空,修改队尾指针
			q->rear = q->front;
		}
		return true;
	}
}

//置空队
SeQueue	*init_SeQueue() {
	SeQueue		*q = (SeQueue *)malloc( sizeof(SeQueue) );
	q->front = q->rear = MAXSIZE - 1;
	return q;
}

//入队
int		inSeQueue( SeQueue *q, datatype x ) {
	if ( (q->rear + 1) % MAXSIZE == q->front ) {
		printf("队满!\n");
		return false;			//队满不能入队
	}
	else {
		q->rear = (q->rear + 1) % MAXSIZE;
		q->data[q->rear] = x;
		return true;			//入队完成
	}
}

//出队
int		outSeQueue( SeQueue *q, datatype *x ) {
	if ( q->front == q->rear ) {
		printf("队空!\n");
		return false;
	}
	else {
		q->front = (q->front + 1) % MAXSIZE;
		*x = q->data[q->front];			//读出队头元素
		return true;					//出队完成
	}
}

//判队空
int		emptySeQueue( SeQueue *q ) {
	if ( q->front == q->rear ) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[])
{


	return EXIT_SUCCESS;
}

