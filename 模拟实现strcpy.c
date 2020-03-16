#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* Strcpy1(char* dest, const char* src) {
	//ָ��ʵ��
	if (dest == NULL || src == NULL) {
		return NULL;
	}

	//��¼��ʱdest ָ��λ�� , ��󷵻�
	//��Ϊ�����иı���destָ��
	char* p = dest;

	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	//һ���������˼� \0 
	*dest = '\0';
	return p;
}


char* Strcpy2(char* dest, const char* src) {
	//��ָ��ʵ��
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	int cur = 0;
	for (; src[cur] != '\0'; cur++) {
		dest[cur] = src[cur];
	}
	dest[cur] = '\0';
	return dest;
}


int main() {
	char str1[] = "saber";
	char str2[100];
	char* p1 = Strcpy1(str2, str1);
	char* p2 = Strcpy2(str2, str1);
	printf("%s\n", p1);
	printf("%s\n", p2);
	system("pause");
	return 0;
}