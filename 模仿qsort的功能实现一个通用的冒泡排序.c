#include<stdio.h>
#include<stdlib.h>

int cmp(const void* p1, const void* p2, int size) {
	//这波主要是判断是int类型 还算是char类型
	//这里的意思其实就是前一个元素的值减后一个元素
	if (size == 4) {
		return (*(int*)p1 - *(int*)p2);
	}
	else if (size == 1) {
		return (*(char*)p1 - *(char*)p2);
	}
}

void swap(void* p1, void* p2, int size) {
	//交换每个字节的值 这里就很舒服 每个字节都交换的话当然也可以适用于int

	for (int i = 0; i < size; i++) {

		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void Bubblesort(void* arr, int len, int size, int(*cmp)(void*, void*, int)) {
	//冒泡排序 
	//从小到大排序
	//[0,len - 1 - i]是未排序区间
	//[len - 1 - i, len - 1] 是已排序区间
	//if语句就是自己规定的排序规则, 是从小到大还是从大到小, 两者只需要改变< 或者   >
	
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