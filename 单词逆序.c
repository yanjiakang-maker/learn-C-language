#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//�㷨: ��Ҫʵ�ֵ�������, �����Ȱ�����ÿһ����������, ����ٰ������ַ������򼴿�
//����:  I am not caixukun
//       I ma ton nukuxiac 
//       caixukun not am I    ��˹!!!

void reverseWord(char* start, char* end) {
	int len = end - start;
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		char tmp = start[i];
		start[i] = start[j];
		start[j] = tmp;
	}
}

void Reverse(char* arr) {
	char* start = arr;
	char* end;
	int i = 0;
	for (i = 0; arr[i]; i++) {
		if (arr[i] == ' ') {
			end = arr + i;
			reverseWord(start, end);
			start = end + 1;
		}
	}
	reverseWord(start, arr + i); //�����һ����������
	reverseWord(arr, arr + i);    // �������ַ���������
	puts(arr);
}

int main() {
	//char arr[] = "I am not caixukun.";
	char arr[1024] = { 0 };
	gets(arr);
	Reverse(arr);
	system("pause");
	return 0;
}