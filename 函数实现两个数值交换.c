#include<stdio.h>
#include<stdlib.h>

//����Ҫע�ⲻ��ֱ�Ӵ�ֵ,����ֻ�����βζ�û�н���ʵ��.
//�β���ʵ�ε�һ�ݿ���
//����Ҫ���Ƕ�ʵ�εĲ���

void exchange(int* m, int* n) {
	int tmp = 0;
	tmp = *m;
	*m = *n;
	*n = tmp;
	return 0;
}


int main() {
	int a = 10;
	int b = 20;
	exchange(&a, &b);
	printf("%d\n%d\n", a, b);
	system("pause");
	return 0;
}