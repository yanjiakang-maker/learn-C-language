#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int Youngtableau(int arr[3][3], int tofind) {
	int i = 2;
	int j = 0;
	while (i >= 0 && j < 3) {
		if (tofind < arr[i][j]) {
			i--;
		}
		if (tofind > arr[i][j]) {
			j++;
		}
		if (i < 0 || j >= 3) {
			return 0;
		}
		if (arr[i][j] == tofind) {
			return 1;
		}
	}
	return 0;
}


int main() {
	int arr[3][3] = { {1, 2, 3},
					  {3, 4, 5},
					  {4, 5, 6} };
	int tofind = 0;
	printf("��������Ҫ�ҵ�����:");
	scanf("%d", &tofind);
	int ret = Youngtableau(arr, tofind);
	if (ret == 1) {
		printf("�����ִ���\n");
	}
	if (ret == 0) {
		printf("�����ֲ�����\n");
	}

	system("pause");
	return 0;
}