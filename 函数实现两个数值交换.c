#include<stdio.h>
#include<stdlib.h>

//这里要注意不能直接传值,否则只交换形参而没有交换实参.
//形参是实参的一份拷贝
//我们要的是对实参的操作

void exchange(int* m, int* n) {
	int tmp = 0;
	tmp = *m;
	*m = *n;
	*n = tmp;
	return 0;
}


int main() {
	int a = 10;
	int b = 20;
	exchange(&a, &b);
	printf("%d\n%d\n", a, b);
	system("pause");
	return 0;
}