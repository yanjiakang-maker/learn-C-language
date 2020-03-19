#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* Strcat1(char* dest, const char* src) {
	//ָ��ʵ��
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	//��¼ָ�뿪ʼʱλ��, ��󷵻�
	char* result = dest;
	//��һ������ָ��ָ���һ���ַ����� \0
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
	//��ָ��ʵ��
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	int cur = 0;
	//���ҵ� dest �� \0 λ��
	while (dest[cur] != '\0') {
		cur++;
	}
	//����Ͱ� src ���Ƹ� dest ����
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