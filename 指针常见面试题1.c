#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	// ����������������(32λϵͳΪ��)


// ��һ��

	//int arr[] = { 1, 2, 3, 4 };

	 //printf("%d\n", sizeof(arr)); // 16  ������Ǽ�����������arr���ֽ���
	 //printf("%d\n", sizeof(arr + 0)); // 4 int* arr �Ѿ���ʽת��ָ�� ,  ��Ϊ���鲻�ܼӼ�����, ��ָ�����,���������arr�Ѿ���ʽת����ָ�� , arr + 0 ָ����Ԫ�� һ��int
	 //printf("%d\n", sizeof(*arr));	// 4 arr �Ѿ���ʽת�� int* �ٽ�����, �õ� int
	 //printf("%d\n", sizeof(arr + 1));	// 4 arr �Ѿ���ʽת�� int*  + 1 ָ�� 2 ���Ԫ��
	 //printf("%d\n", sizeof(arr[1]));		// 4 int
	 //printf("%d\n", sizeof(&arr));		// 4 &arr �õ�һ������ָ��, ��һ�� int(*)[4]����, ֻҪ��ָ��, 32λϵͳ�¶��� 4 �ֽ�
	 //printf("%d\n", sizeof(*&arr));		// 16 &arr ������ָ��. �ٴ� * �������ַ��ʼȡ int(*)[4] ���Ͷ�Ӧ���ֽ���
	 //printf("%d\n", sizeof(&arr + 1));	// 4 &arr �õ�һ�� int(*)[4] �� + 1 ���� int(*)[4], ֻҪ��ָ��, ���� 4 ���ֽ�
	 //printf("%d\n", sizeof(&arr[0]));		// 4 arr[0] �õ�int , ��& �õ� int*  ָ��4�ֽ�
	 //printf("%d\n", sizeof(&arr[0] + 1));	// 4 ͬ��



// �ڶ���
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// ����һ���ַ����� , �����ַ���
	// C������ �ַ�����һ��������ַ����� (�ַ������� '\0' Ϊ������־���ַ�����)
	// �ַ�������һ�趨��C���Եĵ�һ��ܱ�
	// ָ����������ʽת����C������Ƶĵڶ���ܱ�
	// ��ʽ���ַ���(%d, %s ......)��C������Ƶĵ�����ܱ�


	// sizeof �����ֽ�(�ֽڵ�Ȼ�����ַ�����'\0') , ����sizeof �� ��������ֵ
	// strlen �����ַ����ĳ��� , ���Ĺ���ԭ���ǴӴ����ָ�뿪ʼֱ���ҵ� '\0' Ϊֹ


	 //printf("%d\n", sizeof(arr));		// 6 arr ����һ����ͨ���ַ�����, ��Ҫ��̫��
	 //printf("%d\n", sizeof(arr + 0));	// 4 arr + 0 �õ�һ�� char*, ֻҪ��ָ�����, ����ռ 4 ���ֽ�
	 //printf("%d\n", sizeof(*arr));		// 1 *arr �õ�һ�� char (a), ����ռһ���ֽ�
	 //printf("%d\n", sizeof(arr[1]));		// 1 arr[1] �õ���һ��char, ����ռһ���ֽ�
	 //printf("%d\n", sizeof(&arr));		// 4 &arr �õ�һ������ָ�� char(*)[6], ֻҪ��ָ��, ���� 4 ���ֽ�
	 //printf("%d\n", sizeof(&arr + 1));	// 4 ͬ��
	 //printf("%d\n", sizeof(&arr[0] + 1));	// 4 &arr[0] �õ� char*, + 1 ���� char*





//������
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// �ַ����鲻�� strlen   ��δ������Ϊ


	// UB ��Ӧ�Ŵ���Ĵ���
	// printf("%d\n", strlen(arr));		// δ������Ϊ(UB)  
	// printf("%d\n", strlen(arr + 0));	// δ������Ϊ(UB)
	// *arr �õ����� char ����, strlen Ҫ��Ĳ����� char* ���͵�. 

	// printf("%d\n", strlen(*arr));	// ����*arr �õ��ַ�'a'=>97, strlen�Ͱ�97�����˵�ַ , ���Ǽ������97��ַ������ǷǷ��ڴ�
	 //������밴��˵, ��Ҫ��������. ���� c �������͵ı������, �� char ��char* �͸���ʽת����
	// printf("%d\n", strlen(arr[1]));		// Ч��ͬ��


//������
	// char arr[] = "abcdef";
	// printf("%d\n", sizeof(arr));		// 7 sizeof �����ڴ�Ĵ�С, �����СҪ���� \0
	// printf("%d\n", sizeof(arr + 0));	// 4 arr + 0 => char*
	// printf("%d\n", sizeof(*arr));		// 1 *arr => char
	// printf("%d\n", sizeof(arr[1]));		// 1 arr[1] => char
	// printf("%d\n", sizeof(&arr));	// 4 &arr => char(*)[7]
	// printf("%d\n", sizeof(&arr + 1));	// 4 &arr + 1 => char(*)[7]
	// printf("%d\n", sizeof(&arr[0] + 1));	// 4 &arr[0] + 1 => char*

	// printf("%d\n", strlen(arr));	// 6 �˴��Ǽ����ַ�������, ���� \0
	// printf("%d\n", strlen(arr + 0)); // arr + 0  ��һ��char* , ָ����Ԫ��
	// printf("%d\n", strlen(*arr));	// UB *arr �õ��ַ�, char �� char* ���Ͳ�ƥ��. ����˵��Ҫ����ʧ�ܵ�
	// printf("%d\n", strlen(arr[1]));	// ͬ��
	// printf("%d\n", strlen(&arr));	// 6   &arr char(*)[7] ����. �� char* ���Ͳ�ƥ��, ����˵��Ҫ����ʧ�ܵ�
									// &arr ���ɺ� arr �õ��ĵ�ֵַ, ����ͬ��ֵ. �����������, �����ɺ�
	// printf("%d\n", strlen(&arr + 1));	// UB &arr + 1 ��������������, �����������Ŀռ�. �Ƿ��ڴ�
	// printf("%d\n", strlen(&arr[0] + 1));	//5   &arr[0] => char* char* + 1 ����һ��Ԫ��, һ��char


//������
	 //char* p = "abcdef";
	 // �����ַ���"abcdef" �ڳ�����, �ǳ����ַ���,  *pָ��"abcdef"����Ԫ�ص�ַ 


	// printf("%d\n", sizeof(p));	// 4 p �� char* 
	// printf("%d\n", sizeof(p + 1));	// 4 p + 1 ���� char*
	// printf("%d\n", sizeof(*p));	// 1 *p char 
	// printf("%d\n", sizeof(p[1]));	// 1 p[1] char  p[1] => *(p + 1)
	// printf("%d\n", sizeof(&p));	// 4 p char* , &p => char**
	// printf("%d\n", sizeof(&p + 1));	// ͬ��
	// printf("%d\n", sizeof(&p[0] + 1));	// 4 &p[0] �� char* �� + 1 ���� char*

	// printf("%d\n", strlen(p));	// 6 p ָ�����һ���ַ���
	// printf("%d\n", strlen(p + 1));	// 5 �� p + 1 ��λ�������� 5 ��Ԫ���ҵ� \0
	// printf("%d\n", strlen(*p));	// UB *p char  strlen Ҫ��Ĳ����� char* . ���Ͳ�ƥ��, ԭ����Ҫ����ʧ��
	// printf("%d\n", strlen(p[1]));	// UB ͬ��
	// printf("%d\n", strlen(&p));	// UB &p �õ� char** �� char* ������ͬ����. ԭ����Ҫ����ʧ��. ��ʱ �� char** ǿת�ɵ� char* ������һ�������ַ���
	// printf("%d\n", strlen(&p + 1));	// UB ͬ��
	// printf("%d\n", strlen(&p[0] + 1));	// 5 &p[0] �õ����� a �ĵ�ַ. + 1 �õ� b �ĵ�ַ. �� b ��ʼ������ 5 ��Ԫ���� \0



// ���һ��  ��ά����
	// ��ν�Ķ�ά���� �����Ͼ���һ�� һά����. �����ÿ��Ԫ������һ��һά����
	// ����Ϊ 3 ��Ԫ�ص�һά����, �����ÿ��Ԫ�����ǳ���Ϊ 4 ��һά����
	//int a[3][4] = {
	//	{1, 2, 3, 4},
	//	{5, 6, 7, 8},
	//	{9, 10, 11, 12},
	//};

	// printf("%d\n", sizeof(a));	// 48   12 ��Ԫ��, ÿ��Ԫ�� 4 ���ֽ�
	// printf("%d\n", sizeof(a[0][0]));	// 4 a[0][0] => int
	// printf("%d\n", sizeof(a[0]));  // 16 a[0] => int[4] ����
	// printf("%d\n", sizeof(a[0] + 1));	// 4 a[0] => int[4] �� + 1 , ����ʽת��ָ�� int*
	// *(a[0]+1) => a[0][1] �ȼ� => 2
	// printf("%d\n", sizeof(   *  ( a[0] + 1 )  )    );	// 4 a[0] => int[4] �� + 1 , ��ʽת�� int*, �� * �õ� int
	// printf("%d\n", sizeof(&a[0] + 1));		//4  a[0] => int[4]    &a[0] => int(*)[4]  �� + 1 ��������ָ��  

	// printf("%d\n", sizeof(*(&a[0] + 1)));	//16  a[0] => int[4]  ��&�õ� int(*)[4] �� + 1�õ��Ļ��� int(*)[4], �ٽ����� int[4]
	// printf("%d\n", sizeof(*a)); // 16 *a => *(a + 0) => a[0] ��� int[4]


	// ������벢����δ������Ϊ
	// ����˵���� "�����±�Խ��δ������Ϊ" ǰ�������� �ڴ����Խ��. ���ǳ�������ʱ����Ϊ
	// ������Ĵ���������֮��, �൱�ڱ�� 
	// printf("%d\n", 16); 
	// ���ǳ�������ʱ�������е��߼�
	// printf("%d\n", sizeof(a[100])); // 16 sizeof ��һ�������(���Ǻ���), �ص���, ��������ֵ


	system("pause");
	return 0;
}