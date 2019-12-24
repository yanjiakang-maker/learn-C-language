#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void putmul(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d =%d  ", j, i, j * i);
			if (i == j) {
				printf("\n");
			}
		}
	}
}


int main() {
	int n = 0;
	printf("打印n阶乘法表\n");
	printf("请输入n的值:");
	scanf("%d", &n);
	printf("\n");
	putmul(n);
	system("pause");
	return 0;
}