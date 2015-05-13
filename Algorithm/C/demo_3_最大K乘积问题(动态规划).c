/*
 * =====================================================================================
 *
 *       Filename:  demo_3_最大K乘积问题(动态规划).c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月12日 17时50分04秒
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

int I(int *array, int s, int t) {
	int num = 0;
	for ( int i = s; i < t; i ++ ) {
		num = num * 10 + array[s];
	}
	return num;
}

int R( int *array, int i, int j ) {
	
}

int main(int argc, char *argv[])
{

	int array[4] = {1,2,3,4};
	int max_dp = R(array, 4, 3);
	printf("max_dp = %d\n", max_dp);
	return EXIT_SUCCESS;
}

