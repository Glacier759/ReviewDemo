/*
 * =====================================================================================
 *
 *       Filename:  demo_3_最大K乘积问题.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月12日 14时25分09秒
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
#include <math.h>

//转化为整型值
int array_to_integer( int *integer_array, int begin, int end ) {
	int integer = 0;
	for ( int i = begin; i < end; i ++ ) {
	//	printf("a[%d] = %d ", i, integer_array[i]);
		integer = integer * 10 + integer_array[i];
	}
//	printf("\n%d - %d\tarray_to_integer = %d\n", begin, end, integer);
	return integer;
}

int maxdp_realize( int *integer_array, int length, int split_count ) {

	if ( split_count == 1 ) {
		return array_to_integer( integer_array, 0, length );	//当分割为1个段时表示就是本身
	}
	else if ( split_count == length ) {			//当分割为length段时表示直接返回每一位的乘积
		int max = 1;
		for ( int i = 0; i < length; i ++ ) {
			max *= integer_array[i];
		}
		return max;
	}
	else {	//否则
		int max = 0;
		//假设从最后一个数划开， 然后再乘上前面的k-1个不同划分的积，找出最大值
		//然后从倒数第二个数划分开，然后再乘上前面k-2个不同划分的积，依此类推
		for ( int i = length-1; i >= split_count; i -- ) {	//
			int temp = maxdp_realize( integer_array, i, split_count-1 ) * array_to_integer( integer_array, i, length );
			printf("%d * %d = %d\n", maxdp_realize(integer_array, i, split_count-1), array_to_integer(integer_array, i, length), temp);
			//取得其中的最大值
			if ( temp > max ) {
				max = temp;
			}
		}
		printf("max = %d\n", max);
		return max;
	}

}

//将输入整型数每一位切割为一个整形数组
int maxdp( int integer, int length, int split_count ) {
	if ( split_count > length || split_count <= 0 ) {
		printf("Exception.\n");
		exit(1);
	}
	int *integer_array = (int *)malloc(sizeof(int)*length);
	for ( int i = 1; i <= length; i ++ ) {
		integer_array[i-1] = (int)(integer / pow(10, length-i)) % 10;
	}
	return maxdp_realize(integer_array, length, split_count);
}


int main(int argc, char *argv[])
{
	if ( argc != 7 ) {
		printf("Exception.\n");
		exit(1);
	}

	int integer, length, k;

	//接受main函数参数并处理
	for ( int i = 1; i < argc; i += 2 ) {
		if ( strcmp(argv[i], "-i") == 0 ) {
			integer = atoi(argv[i+1]);
		}
		else if ( strcmp(argv[i], "-l") == 0 ) {
			length = atoi(argv[i+1]);
		}
		else if ( strcmp(argv[i], "-k") == 0 ) {
			k = atoi(argv[i+1]);
		}
	}
	printf("integer = %d, length = %d, K = %d\n", integer, length, k);

	//调用求最大K乘积函数
	int max_dp = maxdp(integer, length, k);
	printf("max_dp = %d\n", max_dp);

	return EXIT_SUCCESS;
}

