#include<stdio.h>
#include<stdlib.h>

//ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)


int removeElement(int* nums, int numsSize, int val) {
    int start = 0;
    int ret = 0;
    while (start < numsSize) {
        if (nums[start] != val) {
            nums[ret] = nums[start];
            start++;
            ret++;
        }
        else {
            start++;
        }
    }
    return ret;
}


int main() {
    int nums[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int size = sizeof(nums) / sizeof(nums[0]);
   int ret = removeElement(nums, size, 2);
   printf("%d\n", ret);

	system("pause");
	return 0;
}