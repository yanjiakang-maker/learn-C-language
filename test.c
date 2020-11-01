#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int interface() {
	printf("请输入数字0或1:\n");
	printf("0代表结束游戏        ");
	printf("1代表开始游戏\n");
	printf("==================");
	printf("\n");
	printf("请输入数字:");
	int n;
	scanf("%d", &n);
	if (n == 1)
		return 1;
	else return 0;
}

void game( int x) {
	int num;
	while (1) {
		printf("请输入一个1 - 100之间的整数:");
		scanf("%d", &num);
		printf("\n");
		if (num > x) {
			printf("高了!");
			printf("\n");
		}
		if (num < x) {
			printf("低了!");
			printf("\n");
		}
		if (num == x) {
			printf("猜对了!");
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
		printf("退出游戏!\n");
	}
	system("pause");
	return 0;
}