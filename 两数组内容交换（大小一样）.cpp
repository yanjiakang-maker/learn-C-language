#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//int main() {
//	int arr[] = { 1,2,3,4,5 };
//	int brr[] = { 5,4,3,2,1 };
//	int i , j = sizeof(arr) / sizeof(arr[0]) - 1;
//	for (i = 0; i <= j; i++) {
//		int m = arr[i];
//		arr[i] = brr[i];
//		brr[i] = m;
//	}
//	for (i = 0; i <= j; i++) {
//		printf("%3d", arr[i]);
//	}
//	printf("\n");
//	for (i = 0; i <= j; i++) {
//		printf("%3d", brr[i]);
//	}
//	system("pause");
//	return 0;
//}


int main() {
	int arr[5], brr[5];
	printf("请输入两个包含五个元素的数组:\n");
	printf("arr[5]:");
		for (int i = 0; i < 5; i++)
			scanf("%d", &arr[i]);
	printf("\n");
	printf("brr[5]:");
		for (int i = 0; i < 5; i++)
			scanf("%d", &brr[i]);
	for (int i = 0; i < 5; i++) {
		int m = arr[i];
		arr[i] = brr[i];
		brr[i] = m;
	}
	printf("=================\n");
	printf("交换后的结果为:\n");
	printf("arr[5]:");
	for (int i = 0; i < 5; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	printf("brr[5]:");
	for (int i = 0; i < 5; i++) {
		printf("%d\t", brr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}