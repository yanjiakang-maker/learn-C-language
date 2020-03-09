#include<stdio.h>
#include<stdlib.h>

//int main() {
//	int a = 10, b = 20 ;
//	int c;
//	c = a;
//	a = b;
//	b = c;
//	printf("%d\n%d\n", a, b);
//}


int main() {
	int a = 10, b = 20;
	a = a + b ;
	b = a - b ;
	a = a - b ;
	printf("%d\n%d\n", a, b);
}
