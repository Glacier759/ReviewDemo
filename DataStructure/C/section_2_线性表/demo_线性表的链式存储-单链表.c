/*
 * =====================================================================================
 *
 *       Filename:  demo_线性表的链式存储-单链表.c
 *
 *    Description:  线性表的链式存储
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 10时29分26秒
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

typedef int ElemType;
typedef struct node {
	ElemType		data;
	struct node		*next;
}LNode, *LinkList;

#define		TRUE	1
#define		FALSE	0

//单链表的基本运算
/**
 * 头插法建立单链表
 * */
LinkList create_LinkList_a() {
	LinkList H = (LinkList)malloc(sizeof(LNode));	//生成头结点
	H->next = NULL;			//空表
	LNode *s;
	int x;					//设数据元素的类型为int

	scanf("%d", &x);
	while( x != -1 ) {
		s = (LNode *) malloc( sizeof(LNode) );
		s->data = x;
		s->next = H->next;
		H->next = s;
		scanf("%d", &x);
	}
	return H;
	
}

/**
 * 尾插法建立单链表
 * */
LinkList create_LinkList_b() {
	LinkList H = (LinkList)malloc( sizeof(LNode) );		//生成头结点
	H->next = NULL;			//空表
	LNode *s, *r = H;
	int x;					//设数据元素的类型为int

	scanf("%d", &x);
	while( x != -1 ) {
		s = (LNode *)malloc( sizeof(LNode) );
		s->data = x;
		s->next = r->next;	//感觉可以直接写为s->next = NULL;
		r->next = s;
		r = s;				//r指向新的尾结点
		scanf("%d", &x);
	}
	return H;
}

/**
 * 求单链表的表长
 * */
int length_LinkList( LinkList H ) {
	LNode *p = H;
	int j = 0;

	while( p->next != NULL ) {
		p = p->next;
		j ++;
	}
	return j;
}

/**
 * 单链表中按序号查找
 * */
LNode* get_LinkList( LinkList H, int k ) {
	LNode *p = H;
	int j = 0;

	while( p->next != NULL && j < k ) {
		p = p->next;
		j ++;
	}
	if ( j == k )
	  return p;
	else
	  return NULL;
}

/**
 * 单链表中按值x查找
 * */
LNode* locate_LinkList( LinkList H, ElemType x ) {
	LNode *p = H->next;

	while ( p != NULL && p->data != x ) {
		p = p->next;
	}
	return p;
}

/**
 * 单链表的插入
 * 1. 查找第i-1个结点,若存在继续2,否则结束
 * 2. 创建新的结点
 * 3. 将新节点插入,结束
 * */
int insert_LinkList( LinkList H, int i, ElemType x ) {
	//在单链表H的第i个位置上插入值为x的元素
	LNode *p, *s;
	p = get_LinkList( H, i-1 );				//查找第i-1个结点

	if ( p == NULL ) {						//第i-1个不存在,不能插入
		printf("插入位置i错");
		return FALSE;
	}

	s = (LNode *)malloc( sizeof(LNode) );		//申请新结点
	s->data = x;
	s->next = p->next;
	p->next = s;
	return TRUE;
}

/**
 * 单链表的删除
 * */
int del_LinkList( LinkList H, int i ) {
	LinkList p, q;
	p = get_LinkList( H, i-1 );				//查找第i-1个结点

	if ( p == NULL ) {
		printf("第i-1个结点不存在");
		return FALSE;
	}
	else if ( p->next == NULL ) {
		printf("第i个结点不存在");
		return FALSE;
	}
	
	q = p->next;							//指向第i个结点
	p->next = q->next;						//从链表中删除
	free(q);								//释放*q
	return TRUE;
}

/**
 * 单链表的倒置
 * */
void reverse_LinkList( LinkList H ) {
	LNode *p, *q;

	p = H->next;			//p指向第一个数据结点
	H->next = NULL;			//将原链表置为空表

	while( p ) {
		q = p;
		p = p->next;
		q->next = H->next;	//将当前结点插到头结点的后面
		H->next = q;
	}
}

/**
 * 单链表中删除重复结点
 * */
void pur_LinkList( LinkList H ) {
	LNode *p, *q, *r;

	p = H->next;										//p指向第一个结点
	if ( p != NULL ) {
		while( p->next ) {
			q = p;
			while( q->next ) {							//从*p的后继开始找重复结点
				if ( q->next->data == p->data ) {
					r = q->next;						//找到重复结点,用r指向,删除*r
					q->next = r->next;
					free(r);
				}
				else {
					q = q->next;
				}
			}//while(q->next)
			p = p->next;	//p指向下一个结点,继续
		}//while(p->next)
	}
}

/**
 * 两个集合的差集
 * */
void difference_LinkList( LinkList L1, LinkList L2 ) {	//此算法求两个集合的差集
	LNode *pre, *p, *q, *r;
	pre = L1;
	p = L1->next;				//p指向表中的某一结点,pre始终指向p的前驱
	while( p != NULL ) {
		q = L2->next;			//扫描L2中的结点,寻找与L1中*p结点相同的结点
		while( q != NULL && q->data != p->data ) {
			q = q->next;
		}
		if ( q != NULL ) {
			r = p;
			pre->next = p->next;
			p = p->next;
			free(r);
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}

int main(int argc, char *argv[])
{


	return EXIT_SUCCESS;
}

