/*
 * =====================================================================================
 *
 *       Filename:  practice_线性表逆置.c
 *
 *    Description:  树勇顺序表和单链表两种方式进行逆置
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 18时04分00秒
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

typedef	int elemType;

typedef struct arrayList {
	elemType	elem[MAXSIZE];
	int			length;
}ArrayList;

typedef	struct linkList {
	elemType			data;
	struct linkList		*next;
}LinkList;

LinkList	*init_LinkList() {
	LinkList	*linkList = (LinkList *)malloc( sizeof(LinkList) );
	linkList->next = NULL;
	return linkList;
}

int			add_LinkList( LinkList *linkList, elemType data ) {
	LinkList	*new_node = (LinkList *)malloc( sizeof(LinkList) );
	LinkList	*temp = linkList;

	if ( new_node == NULL ) {
		printf("内存满了 开辟失败!\n");
		return false;
	}

	new_node->data = data;
	while(temp->next) {
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next = new_node;
	
	return true;
}

int			add_LinkList_index( LinkList *linkList, elemType data, int index ) {
	LinkList	*new_node = (LinkList *)malloc( sizeof(LinkList) );
	LinkList	*temp = linkList->next;
	int			i;

	if ( new_node == NULL ) {
		printf("内存满了 开辟失败!\n");
		return false;
	}
	for ( i = 0; temp != NULL && i < index - 1; temp = temp->next, i ++ );
	if ( temp == NULL && i < index - 1 ) {
		printf("Exception!\n");
		return false;
	}
	new_node->data = data;
	new_node->next = temp->next;
	temp->next = new_node;

	return true;
}

void		print_LinkList( LinkList *linkList ) {
	printf("\nprint:");
	int		i = 0;
	for ( LinkList *temp = linkList->next; temp != NULL; temp = temp->next, i ++ ) {
		if ( i % 5 == 0 ) {
			printf("\n");
		}
		printf("%5d", temp->data);
	}
	printf("\n");
}

void		reverse_LinkList( LinkList *linkList ) {
	LinkList	*p, *q;

	p = linkList->next;
	linkList->next = NULL;

	while( p ) {
		q = p;
		p = p->next;
		q->next = linkList->next;
		linkList->next = q;
	}
}

/**
 * 请设计算法求线性表中第一个值为x的元素的前驱和后继的存储位置,要求采用顺序表和单链表两种方法来表示.
 * */
void		prior_next_LinkList( LinkList *linkList, elemType data ) {
	LinkList	*prior;
	int			index = 0;

	for ( prior = linkList; prior->next->data != data; prior = prior->next, index ++ );
	printf("prior: value = %d, index = %d\nnext:  value = %d, index = %d\n", 
				prior->data, index, prior->next->next->data, index+2);
}

ArrayList	*init_ArrayList() {
	ArrayList	*arrayList = (ArrayList *)malloc( sizeof(ArrayList) );
	arrayList->length = 0;
	return arrayList;
}

int			add_ArrayList( ArrayList *arrayList, elemType data ) {
	if ( arrayList->length >= MAXSIZE ) {
		printf("表满!\n");
		return false;
	}
	arrayList->elem[arrayList->length++] = data;
	return true;
}

int		add_ArrayList_index( ArrayList *arrayList, elemType data, int index ) {
	if ( index > arrayList->length || arrayList->length >= MAXSIZE - 1 ) {
		printf("Exception!\n");
		return false;
	}
	for ( int i = arrayList->length - 1; i >= index; i --  ) {
		arrayList->elem[i+1] = arrayList->elem[i];
	}
	arrayList->elem[index] = data;
	arrayList->length ++;
	return true;
}

void	reverse_ArrayList( ArrayList *arrayList ) {
	elemType	temp;
	for ( int i = 0; i < (arrayList->length)/2; i ++ ) {
		temp = arrayList->elem[i];
		arrayList->elem[i] = arrayList->elem[arrayList->length - i - 1];
		arrayList->elem[arrayList->length - i - 1] = temp;
	}
}

void	print_ArrayList( ArrayList *arrayList ) {
	printf("\nprint: ");
	for ( int i = 0; i < arrayList->length; i ++ ) {
		if ( i % 5 == 0 ) {
			printf("\n");
		}
		printf("%5d", arrayList->elem[i]);
	}
	printf("\n");
}

/**
 * 已知长度为n的线性表A采用顺序存储结构,请写算法,找出该线性表中值最小的数据元素
 * */
void		minele_ArrayList( ArrayList *arrayList ) {
	int		index = 0, value = arrayList->elem[0];

	for ( int i = 1; i < arrayList->length; i ++ ) {
		if ( arrayList->elem[i] < value ) {
			value = arrayList->elem[i];
			index = i;
		}
	}

	printf("minele value = %d, index = %d\n", value, index);
}

/**
 * 已知线性表A的长度为n,并且采用顺序存储结构.编写算法,删除线性表中所有值为x的元素
 * */
void		remove_all_ArrayList( ArrayList *arrayList, elemType data ) {
	for ( int i = 0; i < arrayList->length; i ++ ) {
		if ( arrayList->elem[i] == data ) {
			for ( int j = i; j < arrayList->length; j ++ ) {
				arrayList->elem[j] = arrayList->elem[j+1];
			}
			arrayList->length--;
			i--;
		}
	}
	printf("size = %d\n", arrayList->length);
}

/**
 * 请设计算法求线性表中第一个值为x的元素的前驱和后继的存储位置,要求采用顺序表和单链表两种方法来表示.
 * */
void		prior_next_ArrayList( ArrayList *arrayList, elemType data ) {
	for ( int i = 0; i < arrayList->length; i ++ ) {
		if ( arrayList->elem[i] == data ) {
			printf("prior: value = %d, index = %d\nnext:  value = %d, index = %d\n", 
						arrayList->elem[i-1], i-1, arrayList->elem[i+1], i+1);
			break;
		}
	}
}


int main(int argc, char *argv[])
{
	ArrayList	*arrayList = init_ArrayList();
	for ( int i = 0; i < 10; i ++ ) {
		add_ArrayList( arrayList, i*2 );
	}
	print_ArrayList(arrayList);
	for ( int i = 0; i < 3; i ++ ) {
		add_ArrayList_index( arrayList, i*3, i*3 );
	}
	print_ArrayList(arrayList);

	reverse_ArrayList(arrayList);
	print_ArrayList(arrayList);

	prior_next_ArrayList( arrayList, 6 );

	minele_ArrayList( arrayList );
	
	remove_all_ArrayList( arrayList, 6 );
	print_ArrayList( arrayList );

	printf("\n-----------------------现在是单链表------------------------\n");

	LinkList	*linkList = init_LinkList();
	for ( int i = 0; i < 10; i ++ ) {
		add_LinkList( linkList, i*2 );
	}
	print_LinkList(linkList);
	for ( int i = 0; i < 3; i ++ ) {
		add_LinkList_index( linkList, i*3, i*3 );
	}
	print_LinkList( linkList );
	
	reverse_LinkList( linkList );
	print_LinkList( linkList );

	prior_next_LinkList( linkList, 6 );

	return EXIT_SUCCESS;
}

