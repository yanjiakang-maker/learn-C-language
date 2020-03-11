#include<stdio.h>
#include<stdlib.h>

int cmp(const void* p1, const void* p2, int size) {
	//�Ⲩ��Ҫ���ж���int���� ������char����
	//�������˼��ʵ����ǰһ��Ԫ�ص�ֵ����һ��Ԫ��
	if (size == 4) {
		return (*(int*)p1 - *(int*)p2);
	}
	else if (size == 1) {
		return (*(char*)p1 - *(char*)p2);
	}
}

void swap(void* p1, void* p2, int size) {
	//����ÿ���ֽڵ�ֵ ����ͺ���� ÿ���ֽڶ������Ļ���ȻҲ����������int

	for (int i = 0; i < size; i++) {

		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void Bubblesort(void* arr, int len, int size, int(*cmp)(void*, void*, int)) {
	//ð������ 
	//��С��������
	//[0,len - 1 - i]��δ��������
	//[len - 1 - i, len - 1] ������������
	//if�������Լ��涨���������, �Ǵ�С�����ǴӴ�С, ����ֻ��Ҫ�ı�< ����   >
	
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (cmp((char*)arr + j * size, (char*)arr + (j + 1) * size, size) > 0) {

				swap((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
			}
		}
	}

}


int main() {
	int arr[] = { 0 , 5 , 8 , 9 , 7 , 2 , 6 , 3 };
	//int arr[] = { 'b', 'f', 'r', 'y','p' };
	int len = sizeof(arr) / sizeof(arr[0]);

	Bubblesort(arr, len, sizeof(arr[0]), cmp);

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
		//printf("%c ", arr[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}