#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//
//例如：给定s1 = aabcd和s2 = bcdaa，返回1
//给定s1 = abcd和s2 = acbd，返回0.
//
//aabcd左旋一个字符得到abcda
//aabcd左旋两个字符得到bcdaa
//aabcd右旋一个字符得到daabc


//如果是旋转字符串  返回1  , 不是 则返回0
int Isrotatingstr(char arr[], char str[]) {
    char arr1[1024] = { 0 };
    strcpy(arr1, arr);          //字符串复函数 , 把后面的字符串(arr)  赋值给  前面的字符数组(arr1)
    strcat(arr1, arr);          //字符串连接函数 , 吧arr 连接在arr1的后面  
    int ret = strstr(arr1, str);//判断arr 是不是 arr1 的子串  如果没有返回NULL
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
        printf("是旋转字符串\n");
    }
    else if (ret == 0) {
        printf("不是旋转字符串\n");
    }

    return 0;
}
