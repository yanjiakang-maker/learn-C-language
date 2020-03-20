#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char* Strstr(const char* str1, const char* str2) {
	assert(str1 != NULL && str2 != NULL);

	if (*str2 == '\0') {
		//str2为空字符串
		return NULL;
	}
	//下面采用红黑指针的方式
	//因为要返回的是子串的首元素地址, 所以要用黑指针记录位置
	char* black = str1;
	while (*black != '\0') {
		char* red = black;
		char* sub = str2;

		//这里先写符合要求的情况 , 继续向后找
		while (*red != '\0' && *sub != '\0' && *red == *sub) {
			red++;
			sub++;
		}
		//上面循环如果结束了有三种情况
		//1. red遇到  \0
		//2. sub遇到  \0
		//3. *red != *sub

		//当red遇到 \0 时, 可能找到了子串, 也可能没找到子串
		//而当sub遇到 \0 时 则一定找到了子串 
		//所以先判断后者
		if (*sub == '\0') {
			return black;
		}
		//注意这两个 if 有逻辑前后顺序
		//当程序走到这的时候一定是不满足上面的条件的
		//所以这里的条件相当于 *sub != '\0' && *red == '\0'
		if (*red == '\0') {
			return NULL;
		}

		//不满足循环就让黑指针++, 直到第一个字符和*str2一样的时候为止
		black++;
	}
}

int main() {
	char str1[] = "www world world";
	char str2[] = "world";
	char* ret = Strstr(str1, str2);
	printf("%p %p\n", str1, ret);

	system("pause");
	return 0;
}