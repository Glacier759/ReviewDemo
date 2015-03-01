/*
 * =====================================================================================
 *
 *       Filename:  demo_约瑟夫环问题.c
 *
 *    Description:  约瑟夫环问题
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 12时38分24秒
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

#define		MAX		100

typedef	struct NodeType {
	int					id;
	int					password;
	struct NodeType		*next;
}NodeType;

void createList( NodeType **, int );
NodeType *getNode( int, int );
void printList( NodeType * );
int isEmptyList( NodeType * );
void josephusOperate( NodeType **, int );


void	createList( NodeType **ppHead, int n ) {		//创建有n各节点的循环链表ppHead
	int		i = 0;
	int		password = 0;
	NodeType *pNew = NULL;
	NodeType *pCur = NULL;

	for ( i = 1; i <= n; i ++ ) {
		printf("输入第%d个人的密码: ", i);
		scanf("%d", &password);
		pNew = getNode( i, password );
		if ( *ppHead == NULL ) {
			*ppHead = pCur = pNew;
			pCur->next = *ppHead;
		}
		else {
			pNew->next = pCur->next;
			pCur->next = pNew;
			pCur = pNew;
		}
	}
	printf("完成单向循环链表的创建!\n");
}


NodeType	*getNode( int id, int password ) {			//向结点中传送编号和密码
	NodeType	*pNew = NULL;							//建立指针
	pNew = (NodeType *)malloc( sizeof(NodeType) );		//为当前结点开辟新空间

	if ( !pNew ) {
		printf("Error, the Memory is not enough!\n");
		exit(-1);
	}
	pNew->id = id;
	pNew->password = password;
	pNew->next = NULL;									//pNew的next指向空,置空表尾
	return pNew;
}

void	printList( NodeType *pHead ) {		//依此输出至第n个人,且输出密码,完成原始链表的打印
	NodeType *pCur = pHead;

	if ( !isEmptyList(pHead) ) {			//调用EmptyList()函数来判断if语句是否执行,若pHead不为空则执行
		printf("--ID-- --PASSWORD--\n");
		do {
			printf("%3d %7d\n", pCur->id, pCur->password);
			pCur = pCur->next;				//让指针变量pCur改为指向后继结点
		} while( pCur != pHead );
	}
}

int		isEmptyList( NodeType *pHead ) {
	if ( !pHead ) {
		//若pHead为空,提示"空",返回值1.
		printf("The list is empty!\n");
		return 1;
	}
	return 0;	//否则返回0
}

void	josephusOperate(  NodeType **ppHead, int password ) {
	int		counter = 0;
	int		flag =  1;
	NodeType	*pPrv = NULL;
	NodeType	*pCur = NULL;
	NodeType	*pDel = NULL;

	pPrv = pCur = *ppHead;
	while( pPrv->next != *ppHead ) {	//将pPrv初始为指向尾结点,为删除做好准备
		pPrv = pPrv->next;
	}
	while( flag ) {
		for ( counter = 1; counter < password; counter ++ ) {
			pPrv = pCur;
			pCur = pCur->next;
		}
		if ( pPrv == pCur ) {
			flag = 0;
		}
		pDel = pCur;				//删除pCur指向的结点,即有人出列
		pPrv->next = pCur->next;		//使得pPrv指向结点与下一个结点相连,让pCur从链表中脱节
		pCur = pCur->next;				//让指针pCur改为指向后继结点,后移一个结点
		password = pDel->password;		//记录出列的人手中的密码
		printf("第%d个任出列(密码:%d)\n", pDel->id, pDel->password);
		free(pDel);						//释放删除pDel指向的结点
	}
	*ppHead = NULL;
}

int main(int argc, char *argv[])
{
	int		n = 0;
	int		m = 0;
	NodeType	*pHead = NULL;

	do {
		if ( n > MAX ) {
			//人数n超过最大人数循环,接着做下一次循环,重新输入人数n,直至条件满足为止
			printf("人数太多,请重新输入!\n");
		}
		printf("请输入人数n(最多%d个): ", MAX);
		scanf("%d", &n);
	}while( n > MAX );

	printf("请输入初始密码m: ");
	scanf("%d", &m);
	createList(&pHead, n);											//创建单向循环链表
	printf("-------------------打印循环链表-------------------\n");
	printList(pHead);												//打印循环链表
	printf("-------------------打印出队情况-------------------\n");
	josephusOperate(&pHead, m);										//运行"约瑟夫环"问题

	return EXIT_SUCCESS;
}

