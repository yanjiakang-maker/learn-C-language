#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//实现一个函数，可以左旋字符串中的k个字符。
//
//例如：
//
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB


void softRotate(char arr[], int n) {
	char p[1024] = { 0 };
	strcpy(p, arr);
	strcat(p, arr);    // p = "ABCDABCD"
	char str[10] = { 0 };
	int i = 0;
	for (; i < 4; i++) {
		str[i] = p[i + n];
	}
	str[i] = '\0';
	printf("旋转后为: %s\n", str);
}



int main() {
	char arr[] = "ABCD";
	int n = 0;
	printf("请输入1 - 4 之间的数字: \n");
	scanf("%d", &n);
	softRotate(arr, n);


	system("pause");
	return 0;
}