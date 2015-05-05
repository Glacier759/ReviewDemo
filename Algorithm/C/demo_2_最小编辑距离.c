/*
 * =====================================================================================
 *
 *       Filename:  demo_2_最小编辑距离.c
 *
 *    Description:  将字符串A转换为字符串B所用的最少字符操作数称为字符串A到B的最小编辑距离
 *
 *        Version:  1.0
 *        Created:  2015年05月05日 14时35分58秒
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
#include <fcntl.h>

#define		LINE_SIZE	1024

int		distance(char *base_str, int base_str_length, char *to_str, int to_str_length) {
	//如果两个字符串长度都为0，则返回0
	if ( base_str_length == 0 && to_str_length == 0 ) {
		return 0;
	}
	//如果原字符串长度为0，目标字符串长度大于0，则返回目标字符串的长度
	else if ( base_str_length == 0 && to_str_length > 0 ) {
		return to_str_length;
	}
	//如果原字符串长度大于0，目标字符串为0，则返回原字符串长度
	else if ( base_str_length > 0 && to_str_length == 0 ) {
		return base_str_length;
	}
	//否则，如原字符串与目标字符串长度均不为0
	else if ( base_str_length >= 1 && to_str_length >= 1 ) {
		//计算得到原字串的缺1位子串到目标字串的最小编辑距离+1
		int distance_1 = distance( base_str, base_str_length - 1, to_str, to_str_length ) + 1;
		//计算得到原字串到目标字串的缺1位子串的最小编辑距离+1
		int distance_2 = distance( base_str, base_str_length, to_str, to_str_length - 1 ) + 1;
		//计算两个字串缺1位子串的最小编辑距离+l；l表示两个字符串的末尾字符是否相等，相等则返回0，不等则返回1
		int distance_3 = distance( base_str, base_str_length - 1, to_str, to_str_length - 1 )
			+ ( *(base_str + base_str_length - 1) == *(to_str + to_str_length - 1) ? 0 : 1 );
		//取得三个距离中的最小值返回
		int distance = (distance_1 > distance_2 ? distance_2 : distance_1) ;
		return (distance > distance_3 ? distance_3 : distance);
	}
}

int main(int argc, char *argv[])
{

	if ( argc < 2 ) {
		puts("Missing Parameter.");
		exit(1);
	}
	
	char *filename = argv[1];
	char *base_str = (char *)malloc(LINE_SIZE);
	char *to_str = (char *)malloc(LINE_SIZE);

	FILE *fp = fopen(filename, "r");

	memset(base_str, '\0', LINE_SIZE);
	fgets(base_str, LINE_SIZE, fp);

	memset(to_str, '\0', LINE_SIZE);
	fgets(to_str, LINE_SIZE, fp);

	int base_str_length = strlen(base_str);
	int to_str_length = strlen(to_str);

	int distance_value = distance(base_str, base_str_length, to_str, to_str_length);
	printf("distance = %d\n", distance_value);
/*	
	fclose(fp);
	fp = fopen("output.txt", "w");
	fprintf(fp, "%d\n", distance_value);
*/
	free(base_str);
	free(to_str);
	fclose(fp);

	return EXIT_SUCCESS;
}

