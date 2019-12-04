#include<stdio.h>
#include<stdlib.h>


char reverse_string(char* string,int len) {
	printf("%c", string[len]);
	if (len < 0) {
		return 0; //这里要加一个终止条件,不然程序会无限循环
	}
	return reverse_string(string, len - 1);
}


int main() {
	char arr[] = "abcdefg";
	int len = sizeof(arr) / sizeof(arr[0]) - 1 - 1;
	//这里的len求的是字符数组arr的长度,也就是说带有\0的字节数;
	//所以要表示字符串的长度要 -1,而这里我们要的是数组的下标,所以要再 -1
	reverse_string(arr,len);
	putchar('\n');
	system("pause");
	return 0;
}