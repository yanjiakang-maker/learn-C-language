#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//ʵ��һ�����������������ַ����е�k���ַ���
//
//���磺
//
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB


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
	printf("��ת��Ϊ: %s\n", str);
}



int main() {
	char arr[] = "ABCD";
	int n = 0;
	printf("������1 - 4 ֮�������: \n");
	scanf("%d", &n);
	softRotate(arr, n);


	system("pause");
	return 0;
}