#include<stdio.h>
#include<stdlib.h>


char reverse_string(char* string,int len) {
	printf("%c", string[len]);
	if (len < 0) {
		return 0; //����Ҫ��һ����ֹ����,��Ȼ���������ѭ��
	}
	return reverse_string(string, len - 1);
}


int main() {
	char arr[] = "abcdefg";
	int len = sizeof(arr) / sizeof(arr[0]) - 1 - 1;
	//�����len������ַ�����arr�ĳ���,Ҳ����˵����\0���ֽ���;
	//����Ҫ��ʾ�ַ����ĳ���Ҫ -1,����������Ҫ����������±�,����Ҫ�� -1
	reverse_string(arr,len);
	putchar('\n');
	system("pause");
	return 0;
}