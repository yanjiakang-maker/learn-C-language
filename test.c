#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int interface() {
	printf("����������0��1:\n");
	printf("0���������Ϸ        ");
	printf("1����ʼ��Ϸ\n");
	printf("==================");
	printf("\n");
	printf("����������:");
	int n;
	scanf("%d", &n);
	if (n == 1)
		return 1;
	else return 0;
}

void game( int x) {
	int num;
	while (1) {
		printf("������һ��1 - 100֮�������:");
		scanf("%d", &num);
		printf("\n");
		if (num > x) {
			printf("����!");
			printf("\n");
		}
		if (num < x) {
			printf("����!");
			printf("\n");
		}
		if (num == x) {
			printf("�¶���!");
			printf("\n");
			break;
		}
	}
}

int main() {
	srand(time(0));
	int num = rand() % 100 + 1;
	int a = interface();
	if (a == 1) {
		game(num);
	}
	else
	{
		printf("�˳���Ϸ!\n");
	}
	system("pause");
	return 0;
}