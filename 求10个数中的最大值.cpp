#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main( ) {
	int arr[10], i, max ;
	printf("请输入十个整数： ");
	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	max = arr[0];
	for (i = 1; i < 10; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	printf("max = %d\n", max);
	system("pause");
	return 0;
}