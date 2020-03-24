#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

int Myatoi(const char* str) {
	//���ַ���char ת�� ����int
	if (str == NULL || *str == '\0') {
		return 0;
	}
	int flag = 1; //���������������
	int ret = 0; //������

	//����Ҫ����հ��ַ�
	while (isspace(*str)) {
		str++;
	}
	//Ȼ���� + - ��
	if (*str == '-') {
		flag = -1;
		str++;
	}
	if (*str == '+') {
		str++;
	}
	//���������ַ�
	while (*str != '\0') {
		//�ж��ǲ�������
		if (isdigit(*str)) {
			//�ַ���ת�����ĺ��Ĳ���
			ret = ret * 10 + (*str - '0');
		}
		else {
			return ret;
		}
		str++;
	}
	return flag * ret;
}

int main() {
	char str[] = "100ggg";
	int ret = Myatoi(str);
	//int ret = atoi(str);
	printf("%d\n", ret);
	system("pause");
	return 0;
}