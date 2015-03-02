/*
 * =====================================================================================
 *
 *       Filename:  practice_课后题联系.c
 *
 *    Description:  课后题练习
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 23时59分56秒
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
#include <string.h>

#define		true		1
#define		false		0

typedef	char elemType;
typedef	struct linkStack {
	elemType			data;
	struct linkStack	*next;
}LinkStack;

typedef	struct queueNode {
	elemType			data;
	struct queueNode	*next;
}QueueNode;
typedef	struct linkQueue {
	QueueNode	*rear, *front;
}LinkQueue;

LinkStack	*init_LinkStack() {
	LinkStack	*linkStack = (LinkStack *)malloc(sizeof(LinkStack));
	linkStack->next = NULL;
	return linkStack;
}

int			isEmpty_LinkStack( LinkStack *linkStack ) {
	if ( linkStack->next == NULL ) {
		return true;
	}
	return false;
}

int			push_LinkStack( LinkStack *linkStack, elemType data ) {
	LinkStack	*new_node = (LinkStack *)malloc(sizeof(LinkStack));
	new_node->data = data;
	new_node->next = linkStack->next;
	linkStack->next = new_node;
	return true;
}

elemType	pop_LinkStack( LinkStack *linkStack ) {
	LinkStack	*temp;
	elemType	value;
	if ( isEmpty_LinkStack(linkStack) ) {
		return NULL;
	}
	temp = linkStack->next;
	value = temp->data;
	linkStack->next = temp->next;
	free(temp);
	return value;
}

elemType	getTop_LinkStack( LinkStack *linkStack ) {
	if ( isEmpty_LinkStack(linkStack) ) {
		return NULL;
	}
	return linkStack->next->data;
}

int			judgeString ( char *string, int length ) {
	LinkStack	*linkStack = init_LinkStack();
	int		index = 0;
	for ( ; index < length/2; index ++ ) {
		char ch = *(string+index);
		push_LinkStack( linkStack, ch );
	}
	if ( length % 2 == 1 ) {
		index ++;
	}
	while( !isEmpty_LinkStack(linkStack) ) {
		char ch = pop_LinkStack(linkStack);
		if ( ch != *(string + index++) ) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	char	string[100];
	printf("input string: ");
	scanf("%s", string);
	if ( judgeString( string, strlen(string) ) ) {
		printf("[%s] 是回文\n", string);
	}
	else {
		printf("[%s] 不是回文\n", string);
	}

	return EXIT_SUCCESS;
}

