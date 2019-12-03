#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int factor1(int n) {
	//递归写法
	if (n == 1) {
		return 1;
	}
	return n * factor1(n - 1);
}


int factor2(int n) {
	//非递归写法
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		tmp *= i;
	}
	return tmp;
}


int main() {
	int n = 0;
	printf("请输入正整数n的值:");
	scanf("%d", &n);
	int num1 = factor1(n);
	int num2 = factor2(n);
	printf("%d\n", num1);
	printf("%d\n", num2);
	system("pause");
	return 0;
}