#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

// assert ���� "����" . ( ) ����������Ҫ����, ��������ֱ�ӱ���


int Strcmp(const char* str1, const char* str2) {
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0') {
		//��str1 �� str2 ����Ϊ  \0  ʱ����ѭ��
		//��Ϊ strcmp �ıȽϷ�ʽ�� �ֵ�ʽ  �Ƚ�
		//�� ֻҪ�ҵ�һ����ӦԪ���д�С֮��  ���ɵõ���
		if (*str1 > * str2) {
			return 1;
		}
		else if (*str1 < *str2) {
			return -1;
		}
		else {
			//���������ʱ, ���ܵó���, ��������
			str1++;
			str2++;
		}
	}

	//���ĸ��ַ����ȵ� \0  �ĸ��ַ�����С
	//����ֱ��д�� *str1 == '\0'   ��Ϊ��������ַ������ʱ str1 �� str2 ����'\0'
	//���ֱ��д�� *str1 == '\0'   �ǽ���Զ�޷��ж����
	if (*str1 < *str2) {
		return -1;
	}
	else if (*str1 > * str2) {
		return 1;
	}
	else {
		return 0;
	}
}


int main() {
	char str1[] = "hahahaha";
	char str2[] = "haha";
	int ret = Strcmp(str1, str2);
	if (ret > 0) {
		printf("str1 > str2\n");
	}
	else if (ret < 0) {
		printf("str1 < str2\n");
	}
	else {
		printf("str1 = str2\n");
	}


	system("pause");
	return 0;
}