#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void putprime(int num) {
	if (num <= 1) {
		printf("��������!\n");
		return 0;
	}
	if (num == 2) {
		printf("������!\n");
		return 0;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			printf("��������!\n");
			return 0;
		}
	}
	printf("������!\n");
}



int main() {
	int num = 0;
	printf("����������: ");
	scanf("%d", &num);
	putprime(num);
	system("pause");
	return 0;
}