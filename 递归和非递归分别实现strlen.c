#include<stdio.h>
#include<stdlib.h>


int Strlen1(char* str) {
	//�ݹ�д��
	if (str[0] == '\0') {
		return 0;
	}
	return 1 + Strlen1(str + 1);
}


int Strlen2(char* str,int len) {
	//�ǵݹ�д��
	int tmp = 1;
	for (int i = 1; i < len; i++) {
		tmp += 1;
	}
	return tmp;
}


int main() {
	char str[] = "abcdef";
	int len = sizeof(str) / sizeof(str[0]) - 1;
	//str��һ���ַ�����,���ַ�����ʼ��
	//sizeof(str) / sizeof(str[0]) ����Ľ�����ַ�����ĳ���,����\0���ֽ���
	///����Ҫ��ʾ�����ַ����ĳ���,,����Ҫ -1
	int num1 = Strlen1(str);
	int num2 = Strlen2(str,len);
	printf("%d\n", num1);
	printf("%d\n", num2);
	system("pause");
	return 0;
}