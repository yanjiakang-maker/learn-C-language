#include<stdio.h>
#include<stdlib.h>


int Strlen1(char* str) {
	//递归写法
	if (str[0] == '\0') {
		return 0;
	}
	return 1 + Strlen1(str + 1);
}


int Strlen2(char* str,int len) {
	//非递归写法
	int tmp = 1;
	for (int i = 1; i < len; i++) {
		tmp += 1;
	}
	return tmp;
}


int main() {
	char str[] = "abcdef";
	int len = sizeof(str) / sizeof(str[0]) - 1;
	//str是一个字符数组,以字符串初始化
	//sizeof(str) / sizeof(str[0]) 算出的结果是字符数组的长度,包含\0的字节数
	///这里要表示的是字符串的长度,,所以要 -1
	int num1 = Strlen1(str);
	int num2 = Strlen2(str,len);
	printf("%d\n", num1);
	printf("%d\n", num2);
	system("pause");
	return 0;
}