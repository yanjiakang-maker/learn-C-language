#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
};


int main() {

// ����1
	//int a[5] = { 1, 2, 3, 4, 5 };
	//// ptr ��ָ��Ӧ���� 5 �����һ��Ԫ��. 
	//// &a �õ����� int(*)[5]
	//int* ptr = (int*)(&a + 1);
	//// 2 5
	//printf("%d,%d", *(a + 1), *(ptr - 1));  // ptr �Ѿ������汻ǿת�� int* ��

// ����2
	//struct Test* p = (struct Test*)0x100000;
	//// 100020  
	//printf("%p\n", p + 0x1);
	//// �����ǿ������ת��, ���� p �ͱ����һ�� unsigned long, ��ȥ + 1 , ��ֻ�ǵ��������� + 1
	//printf("%p\n", (unsigned long)p + 0x1);
	//printf("%p\n", (unsigned int*)p + 0x1);

// ����3
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int *)(&a + 1);
//	int *ptr2 = (int *)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);

// ����4
	// //����Ϊ 3 ��Ԫ�ص�һά����, ÿ��Ԫ�س���Ϊ 2  => 1
	// //����Ϊ 2 ��Ԫ�ص�һά����, ÿ��Ԫ�س���Ϊ 3  => 2
	////int a[3][2] = { {0, 1}, {2, 3}, {4, 5} };
	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//int *p;
	//// a[0] ȡ����һ������Ϊ 2 ��Ԫ�ص�һά����
	//// p �ǵ�ǰ����������Ԫ�ص�ַ
	//p = a[0];
	//printf("%d", p[0]);

// ����5
//	int a[5][5];	// ��ά����
//	int(*p)[4];		// ����ָ��
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);


// ����6
	//int aa[2][5] = { 
	//	{1, 2, 3, 4, 5},
	//	{6, 7, 8, 9, 10 } 
	//};
	//// &aa Ӧ����һ������ָ�� int(*)[2][5], �� + 1 Ӧ��Ҫ������������
	//int *ptr1 = (int *)(&aa + 1);
	//// aa �Ƕ�ά������ �� + 1, ��ʽת�� int(*)[5]
	//// int *ptr2 = (int *)(*(aa + 1));
	//int *ptr2 = (int *)(aa[1]);
	//// 10   5
	//printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));


// ���� 7
	// //ָ������
	//char *a[] = { "work","at","alibaba" };
	//char**pa = a;
	//pa++;
	//printf("%s\n", *pa);


// ���� 8
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	// cpp[-2] => *(cpp-2) �������û���޸� cpp ������. ������� ++ �����޸� cpp 
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);

	system("pause");
	return 0;
}