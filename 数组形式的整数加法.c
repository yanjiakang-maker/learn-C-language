#include<stdio.h>
#include<stdlib.h>

//���ڷǸ����� X ���ԣ�X ��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣
//���磬��� X = 1231����ô��������ʽΪ[1, 2, 3, 1]��
//�����Ǹ����� X ��������ʽ A���������� X + K ��������ʽ��



void reverse(int* arr, int left, int right) {
    while (left < right) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    //��ȡ�����λ
    int tmp = K;
    int knum = 0;
    while (tmp != 0) {
        knum++;
        tmp /= 10;
    }
    //���ռ� , �������λ�Ľ�λ  ���һλ
    int newAszie = ASize > knum ? ASize + 1 : knum + 1;
    int* newArray = (int*)malloc(newAszie * sizeof(int));

    //ģ��ӷ����� , �ӵ�λ��ʼ
    //��λ�ȷ���ǰ�� , ����һ����ת����
    int i = 0;
    int idx = ASize - 1;
    int step = 0;//�����λ
    while (idx >= 0 || K > 0) {
        //���� while ֻ�ǻ�Ĺ�ϵ , ֻҪ����һ���Ϳ��Խ���ѭ����
        //��ǰλ�ļӷ�
        newArray[i] = step;
        if (idx >= 0)
            newArray[i] += A[idx];
        if (K > 0)
            newArray[i] += K % 10;

        //���½�λ
        if (newArray[i] >= 10) {
            //�������10 ������λ ���Ҹ�stepһ����λ
            newArray[i] -= 10;
            step = 1;
        }
        else {
            //�����������else �粻���ӵĻ�ֻҪ��һ����Ҫ��λ step��һֱΪ1��
            step = 0;
        }
        //������һλ������
        i++;
        idx--;
        K /= 10;
    }
    //�ж����λ�Ƿ���Ҫ��λ
    if (step == 1) {
        newArray[i] = 1;
        i++;
    }
    //��ת����
    reverse(newArray, 0, i - 1);
    *returnSize = i;
    return newArray;
}



int main() {

    system("pause");
    return 0;
}