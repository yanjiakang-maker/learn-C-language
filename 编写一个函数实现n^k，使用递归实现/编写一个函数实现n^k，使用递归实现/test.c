#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int power0(int n, int k) {
	//�ǵݹ�д��
	int num = 1;
	for (int i = 1; i <= k; i++) {
		num *= n;
	}
	return num;
}


int power(int n, int k) {
	//�ݹ�д��
	if (k == 0) {
		return 1;
	}
	return n * power(n, k - 1);
}


int main() {
	int k = 0;
	int n = 0;
	printf("������������n��k��ֵ:");
	scanf("%d", &n);
	scanf("%d", &k);
	int num = power(n,k);
	printf("num = %d\n", num);
	system("pause");
	return 0;
}