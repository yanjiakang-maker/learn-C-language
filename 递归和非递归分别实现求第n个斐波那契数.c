#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int Fibnumber2(int n) {
	//采用递归的方法
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	return Fibnumber2(n - 2) + Fibnumber2(n - 1);
}


int Fibnumber1(int n) {
	//非递归的方法
	int a = 1;
	int b = 1;
	int tmp = 0;
	for (int i = 3; i <= n; i++) {
		tmp = a + b;
		a = b;
		b = tmp;
	}
	return tmp;
}


int main() {
	int n = 0;
	printf("请输入正整数n:");
	scanf("%d", &n);
	int num1 = Fibnumber1(n);
	int num2 = Fibnumber2(n);
	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);
	system("pause");
	return 0;
}