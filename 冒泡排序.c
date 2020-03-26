#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int* arr, int len) {
	//√∞≈›≈≈–Ú∑®
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[10] = { 55, 99, 88, 77, 44, 55, 33, 22, 11 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, len);
	system("pause");
	return 0;
}