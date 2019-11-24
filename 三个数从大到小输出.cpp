#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main( ) { 
	int i, arr[3],a;
	printf("请输入三个整数：");
	for (i = 0; i < 3; i++)
		scanf("%d", &arr[i]);
	if (arr[0] < arr[1]) {
		a = arr[0];
		arr[0] = arr[1];
		arr[1] = a;
	}
	if (arr[0] < arr[2]) {
		a = arr[0];
		arr[0] = arr[2];
		arr[2] = a;
	}
	if (arr[1] < arr[2]) {
		a = arr[1];
		arr[1] = arr[2];
		arr[2] = a;
	}
	printf("排序后为：");
	for (i = 0; i < 3; i++)
		printf("%3d", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}