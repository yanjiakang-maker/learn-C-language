#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//
//���磺����s1 = aabcd��s2 = bcdaa������1
//����s1 = abcd��s2 = acbd������0.
//
//aabcd����һ���ַ��õ�abcda
//aabcd���������ַ��õ�bcdaa
//aabcd����һ���ַ��õ�daabc


//�������ת�ַ���  ����1  , ���� �򷵻�0
int Isrotatingstr(char arr[], char str[]) {
    char arr1[1024] = { 0 };
    strcpy(arr1, arr);          //�ַ��������� , �Ѻ�����ַ���(arr)  ��ֵ��  ǰ����ַ�����(arr1)
    strcat(arr1, arr);          //�ַ������Ӻ��� , ��arr ������arr1�ĺ���  
    int ret = strstr(arr1, str);//�ж�arr �ǲ��� arr1 ���Ӵ�  ���û�з���NULL
    if (ret == NULL) {
        return 0;
    }

    return 1;
}



int main()
{
    char arr[] = "abcdef";
    char str[] = "defabc";
    int ret = Isrotatingstr(arr, str);
    if (ret == 1) {
        printf("����ת�ַ���\n");
    }
    else if (ret == 0) {
        printf("������ת�ַ���\n");
    }

    return 0;
}
