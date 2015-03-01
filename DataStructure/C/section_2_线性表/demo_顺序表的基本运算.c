/*
 * =====================================================================================
 *
 *       Filename:  demo_顺序表的基本运算.c
 *
 *    Description:  顺序表的基本运算
 *
 *        Version:  1.0
 *        Created:  2015年02月27日 19时08分54秒
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

#define		MAXSIZE		100		//线性表可能达到的最大长度

#define		FALSE		0
#define		TRUE		1

typedef int ElemType;
typedef struct {
	ElemType	elem[MAXSIZE];
	int			length;			//线性表长度
}SeqList;

/**
 * 顺序表的初始化
 * */
void	init_seqList( SeqList *L ) {
	L->length = 0;
}

/**
 * 顺序表的插入
 * 1. 将An～Ai按从后向前的顺序向下移动，为新元素让出位置
 * 2. 将x置入空出的第i个位置
 * 3. 修改表长
 */
int insert_SeqList( SeqList *L, int i, ElemType x ) {
	//在顺序表的第i个位置插入元素x
	int j;
	if ( L->length == MAXSIZE - 1 ) {
		printf("表满");
		return FALSE;						//表空间已慢，不能插入
	}
	if ( i < 1 || i > L->length + 1 ) {		//检查插入位置的正确性
		printf("位置错");
		return FALSE;
	}

	for ( j = L->length; j >= i; j -- ) {
		L->elem[j+1] = L->elem[j];
	}

	L->elem[i] = x;
	L->length ++;
	return TRUE;						//插入成功，返回
}

/**
 * 顺序表的删除
 * 1. 将Ai+1～An依此向上移动
 * 2. 将length值减1
 * */
int delete_SeqList( SeqList *L, int i ) {
	//删除表中第i个元素，若表空或不存在指定元素，则返回FALSE
	int j;
	if ( i < 1 || i > L->length ) {				//检查空表及删除位置的合法性
		printf("不存在第i个元素");
		return FALSE;
	}
	for ( j = i; j < L->length - 1; j ++ ) {
		L->elem[j] = L->elem[j+i];			//向上移动
	}
	L->length --;
	return TRUE;							//删除成功，返回
}

/**
 * 顺序表中按值查找
 * 从第一个元素A1起依此和x比较，直到找到一个与x相等的数据元素，返回它在顺序表中的序号
 * */
int location_SeqList( SeqList *L, ElemType x ) {
	int i = 1;
	
	while( i < L->length && L->elem[i] != x ) {
		i ++;	
	}
	if ( i > L->length ) {					//查找失败
		return FALSE;
	}
	else {
		return i;							//返回x的存储位置
	}
}

/**
 * 两个顺序表的合并
 * 依此扫描A和B的元素，比较当前元素的值，将较小值的元素赋给C，如此知道一个线性表扫描完毕
 * 然后将为处理完的顺序表中的余下部分元素连在C的后面即可
 * */
void merge_SeqList( SeqList *L1, SeqList *L2, SeqList *L3 ) {
	int i, j, k;
	i = j = k = 1;

	while( i <= L1->length && j <= L2->length ) {
		if ( L1->elem[i] <= L2->elem[j] ) {
			L3->elem[k++] = L1->elem[i++];
		}
		else {
			L3->elem[k++] = L2->elem[j++];
		}
	}
	while( i <= L1->length ) {
		L3->elem[k++] = L1->elem[i++];
	}
	while( j <= L2->length ) {
		L3->elem[k++] = L2->elem[j++];
	}

	L3->length = L1->length + L2->length;
}


int main(int argc, char *argv[])
{
	SeqList		*L;


	return EXIT_SUCCESS;
}

