#include<stdio.h>
#include<stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
	int tmp = 0;
	int start = 1;
	int ret = 0;
	// �������˼·һ�£���ͬ����ֻ����һ����������ǰ��
	while (start < numsSize) {
		nums[ret] = nums[tmp];
		ret++;
		//�������ָ��ָ���Ԫ�ز��ظ�����ָ��ͬʱ����ƶ�
		if (nums[tmp] != nums[start]) {
			tmp++;
			start++;
		}
		else {
			//����ظ����ҵ���һ�����ظ���Ԫ��
			while (nums[tmp] == nums[start]) {
				start++;
			}
			//����ָ��
			tmp = start;
			start++;
		}
	}

	if (tmp < numsSize) {
		nums[ret] = nums[tmp];
		ret++;
	}

	return ret;
}

int main() {
    int num[] = { 0, 0, 1, 1 ,1 ,2, 2 ,3, 3, 4 };
    int size = sizeof(num) / sizeof(num[0]);
    int ret = removeDuplicates(num, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

	system("pause");
	return 0;
}