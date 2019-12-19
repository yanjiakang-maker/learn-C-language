#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//算法: 想要实现单词逆序, 可以先把他的每一个单词逆序, 最后再把整个字符串逆序即可
//例如:  I am not caixukun
//       I ma ton nukuxiac 
//       caixukun not am I    奈斯!!!

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
	reverseWord(start, arr + i); //把最后一个单词逆序
	reverseWord(arr, arr + i);    // 把整个字符串都逆序
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