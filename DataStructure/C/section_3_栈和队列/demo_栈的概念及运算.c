/*
 * =====================================================================================
 *
 *       Filename:  demo_栈的概念及运算.c
 *
 *    Description:  栈的顺序存储结构与链式存储结构
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 20时29分04秒
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
#define		FALSE		0
#define		TRUE		1

typedef	int	datatype;
//顺序栈
typedef	struct {
	datatype	data[MAXSIZE];
	int			top;
}SeqStack;
//链栈
typedef struct Stacknode {
	datatype			data;
	struct Stacknode	*next;
}slStacktype;

//入栈操作
int			pushLstack( slStacktype *top, datatype x ) {
	//将元素x压入链栈top中
	slStacktype		*p;
	if ( (p = (slStacktype *) malloc( sizeof(slStacktype) )) == NULL ) {
		return FASLE;
	}
	//申请一个结点
	p->data = x;
	p->next = top->next;
	top->next = p;
	return TRUE;
}

//出栈操作
datatype	popLstack( slStacktype *top ) {
	//从链栈top中删除栈顶元素
	slStacktype		*p;
	datatype		x;

	if ( top->next == NULL ) {
		return NULL;			//空栈
	}
	p = top->next;
	top->next = p->next;
	x = p->next;
	free(p);
	return x;
}


//置空栈:首先建立栈空间,然后初始化栈顶指针
SeqStack	*init_SeqStack() {
	SeqStack *s;

	s = (SeqStack *)malloc( sizeof(SeqStack) );
	s->top = -1;
	return s;
}

//判空栈
int			empty_SeqStack( SeqStack *s ) {
	if ( s->top == -1 ) {
		return -1;
	}
	else {
		return 0;
	}
}

//入栈
int			push_SeqStack( SeqStack *s, datatype x ) {
	if ( s->top == MAXSIZE - 1 ) {
		return 0;		//栈满不能入栈
	}
	else {
		s->top ++;
		s->data[s->top] = x;
		return 1;
	}
}

//出栈
int			pop_SeqStack( SeqStack *s, datatype *x ) {
	if ( empty_SeqStack(s) ) {
		return 0;					//栈空不能出栈
	}
	else {
		*x = s->data[s->top];
		s->top --;
		return 1;				//栈顶元素存入*x, 返回
	}
}

//取栈顶元素
datatype	top_SeqStack( SeqStack *s ) {
	if ( empty_SeqStack(s) ) {
		return 0;				//栈空
	}
	else {
		return s->data[s->top];
	}
}

/**
 * 1. 对于顺序栈,入栈时,首先判栈是否满了,栈满的条件为:s->top=MAXSIZE-1,栈满时,不能入栈;否则出现空间溢出,引起错误,这种现象称为上溢
 * 2. 出栈和读栈顶元素操作,先判栈是否为空,为空时不能操作,否则产生错误.通常栈空时常作为一种控制转移条件
 * 3. 取栈顶元素与出栈的不同之处在于出栈操作改变栈顶指针top的位置(栈顶指针下移一个位置),而取栈顶元素操作只是读出栈顶元素的值,栈顶指针top位置不变
 * */



int main(int argc, char *argv[])
{


	return EXIT_SUCCESS;
}

