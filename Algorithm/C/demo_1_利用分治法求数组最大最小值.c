/*
 * =====================================================================================
 *
 *       Filename:  demo_1.c
 *
 *    Description:  利用分治法求数组的最大最小值
 *
 *        Version:  1.0
 *        Created:  2015年03月31日 16时46分01秒
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

#include <time.h>

int		*init( int array_size ) {
	
	int *array = (int *)malloc(sizeof(int) * array_size);

	srand( (int)time(NULL) );

	printf("初始化数组为: ");
	for ( int i = 0; i < array_size; i ++ ) {
		array[i] = rand() % 100;
		printf("%5d", array[i]);
	}
	printf("\n\n");
	return array;
}

void	get_max_min( int *array, int begin, int end, int *max, int *min ) {

	if ( begin > end - 2 ) { //当begin == end时或仅剩两个元素时
		//数组开头与结尾进行比较, 较大值为最大, 较小值为最小
		*max = array[begin] > array[end] ? array[begin] : array[end];
		*min = array[begin] > array[end] ? array[end] : array[begin];
	}
	else {
		int		mid = (begin + end) / 2;	//取中点位置
		int		temp_max_1, temp_min_1;
		int		temp_max_2, temp_min_2;

		get_max_min( array, begin, mid, &temp_max_1, &temp_min_1 );		//获取左数组的最大最小
		get_max_min( array, mid+1, end, &temp_max_2, &temp_min_2 );		//获取右数组的最大最小

		*max = temp_max_1 > temp_max_2 ? temp_max_1 : temp_max_2;		//比较左右
		*min = temp_min_1 < temp_min_2 ? temp_min_1 : temp_min_2;
	}
}

int main(int argc, char *argv[])
{
	int		*array = init( 10 );
	int		max, min;

	get_max_min( array, 0, 9, &max, &min );

	printf("max = %d\tmin = %d\n", max, min);

	return EXIT_SUCCESS;
}

