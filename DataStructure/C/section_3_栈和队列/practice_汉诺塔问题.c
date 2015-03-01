/*
 * =====================================================================================
 *
 *       Filename:  practice_汉诺塔问题.c
 *
 *    Description:	使用栈来解决汉诺塔问题
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 21时54分08秒
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

#define		false	0
#define		true	1

typedef	char elemType;
typedef struct Stack {
	elemType		data;
	struct Stack	*next;
}LinkStack;

LinkStack	*init_LinkStack() {
	LinkStack	*linkStack = (LinkStack *)malloc( sizeof(LinkStack) );
	linkStack->next = NULL;
	return linkStack;
}

int			isEmpty_LinkStack( LinkStack *linkStack ) {
	if ( linkStack->next == NULL ) {
		return true;
	}
	return false;
}

void		push_LinkStack( LinkStack *linkStack, elemType x ) {
	LinkStack	*new_node = (LinkStack *)malloc( sizeof(LinkStack) );
	new_node->data = x;
	new_node->next = linkStack->next;
	linkStack->next = new_node;
}

elemType		pop_LinkStack( LinkStack *linkStack ) {
	LinkStack	*temp_node;
	elemType	value;

	if ( isEmpty_LinkStack(linkStack) ) {
		printf("栈空!\n");
		return false;
	}
	temp_node = linkStack->next;
	value = temp_node->data;
	linkStack->next = temp_node->next;
	free( temp_node );
	return value;
}

elemType		getTop_LinkStack( LinkStack *linkStack ) {
	if ( isEmpty_LinkStack(linkStack) ) {
		printf("栈空!\n");
		return false;
	}
	return linkStack->next->data;
}

void		move( char A, char B, int number ) {
	printf("%d\t%c -> %c\n", number, A, B);
}

void		tower_of_hanoi( char X, char Y, char Z, int count, int level ) {
	//将塔座x上按直径由小到大且至上而下编号为1至n的n个圆盘按规则搬到塔座z上,y作辅助塔座
	if ( level == 1 ) {
		move(X, Z, 1);	//将编号为1的圆盘从x搬到z
		count ++;
	}
	else {
		tower_of_hanoi( X, Z, Y, count, level - 1 );	//将编号为level-1的塔从X搬到Y,通过Z中转
		move( X, Z, level );
		count ++;
		tower_of_hanoi( Y, X, Z, count, level - 1 );
	}
}

int main(int argc, char *argv[])
{
	tower_of_hanoi( 'X', 'Y', 'Z', 0, 2 );

	return EXIT_SUCCESS;
}

