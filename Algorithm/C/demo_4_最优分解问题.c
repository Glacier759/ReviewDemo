/*
 * =====================================================================================
 *
 *       Filename:  demo_4_最优分解问题.c
 *
 *    Description:  设n是一个正整数，现在要求将n分解为若干个互不相同的自然数的和，且使这些自然数的乘积最大
 *
 *        Version:  1.0
 *        Created:  2015年06月02日 15时28分28秒
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

void function( int scope ) {

	int sum = 0, size = 0, *array;

	//求从2开始的所有自然数 想加不超过scope 求出数的个数
	for ( int count = 2; count < scope; count ++ ) {
		if ( sum + count > scope ) {
			break;
		}
		size ++;
		sum += count;
	}
	printf("size = %d\n", size);

	//动态开辟空间，将这些数放在其中
	array = (int *)malloc(sizeof(int)*size);
	for ( int count = 2, index = 0; index < size; count ++, index ++ ) {
		array[index] = count;
	}
	printf("sum = %d\n", sum);

	//surplus为剩下的数 scope-sum
	int surplus = scope - sum;
	printf("surplus = %d\n", surplus);

	//如果剩下的数与数组最后一个相等 那么每一位+1 最后一位+2
	if ( surplus == array[size-1] ) {
		for ( int index = 0; index < size; index ++ ) {
			array[index] ++;
		}
		array[size-1]++;
	}
	//如果剩下的数比数组最后一个小，那么从后往前每一位+1 直到总和符号条件为止
	else if ( surplus < array[size-1] ) {
		int sum_2 = sum;
		for ( int index = size-1; index >= 0; index -- ) {
			array[index] ++;
			sum_2 ++;
			if ( sum_2 == scope ) {
				break;
			}
		}
	}

	//求积
	int product = 1;
	for ( int index = 0; index < size; index ++ ) {
		if ( index % 5 == 0 ) {
			printf("\n");
		}
		printf("%-5d", array[index]);
		product *= array[index];
	}
	printf("\nproduce = %d\n", product);
}

int main(int argc, char *argv[])
{

	int num = atoi(argv[1]);
	function( num );

	return EXIT_SUCCESS;
}

