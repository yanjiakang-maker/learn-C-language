#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b,m,i;
	printf("����������������");
	scanf("%d%d", &a, &b);
		if (a > b)
			m = b;
		else m = a;
	for (i = m; i > 1; i--) { 
	    if(a % i == 0 && b % i == 0) {
			printf("���Լ���ǣ�%d\n", i);
			break;
		}
	}
	if(i == 1)
	printf("���Լ���ǣ�1\n");
	return 0;
}