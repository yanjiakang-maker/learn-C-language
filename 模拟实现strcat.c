#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* Strcat1(char* dest, const char* src) {
	//指针实现
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	//记录指针开始时位置, 最后返回
	char* result = dest;
	//这一步是让指针指向第一个字符串的 \0
	while (*dest != '\0') {
		dest++;
	}
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return result;

}

char* Strcat2(char* dest, const char* src) {
	//非指针实现
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	int cur = 0;
	//先找到 dest 的 \0 位置
	while (dest[cur] != '\0') {
		cur++;
	}
	//下面就把 src 复制给 dest 即可
	int i = 0;
	while (src[i] != '\0') {
		dest[cur + i] = src[i];
		i++;
	}
	dest[cur + i] = '\0';
	return dest;
}

int main() {
	char str1[100] = "I can ";
	char str2[100] = "sing jump";
	char str3[100] = "rap and ";
	char str4[100] = "basketball !!";

	char* p1 = Strcat1(str1, str2);
	char* p2 = Strcat2(str3, str4);
	printf("%s\n", p1);
	printf("%s\n", p2);
	system("pause");
	return 0;
}