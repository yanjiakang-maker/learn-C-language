#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char* Strstr(const char* str1, const char* str2) {
	assert(str1 != NULL && str2 != NULL);

	if (*str2 == '\0') {
		//str2Ϊ���ַ���
		return NULL;
	}
	//������ú��ָ��ķ�ʽ
	//��ΪҪ���ص����Ӵ�����Ԫ�ص�ַ, ����Ҫ�ú�ָ���¼λ��
	char* black = str1;
	while (*black != '\0') {
		char* red = black;
		char* sub = str2;

		//������д����Ҫ������ , ���������
		while (*red != '\0' && *sub != '\0' && *red == *sub) {
			red++;
			sub++;
		}
		//����ѭ��������������������
		//1. red����  \0
		//2. sub����  \0
		//3. *red != *sub

		//��red���� \0 ʱ, �����ҵ����Ӵ�, Ҳ����û�ҵ��Ӵ�
		//����sub���� \0 ʱ ��һ���ҵ����Ӵ� 
		//�������жϺ���
		if (*sub == '\0') {
			return black;
		}
		//ע�������� if ���߼�ǰ��˳��
		//�������ߵ����ʱ��һ���ǲ����������������
		//��������������൱�� *sub != '\0' && *red == '\0'
		if (*red == '\0') {
			return NULL;
		}

		//������ѭ�����ú�ָ��++, ֱ����һ���ַ���*str2һ����ʱ��Ϊֹ
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