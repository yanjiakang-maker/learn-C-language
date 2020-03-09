#include<stdio.h>
#include<stdlib.h>

int main() {
	int i,a,b,c;
	printf("0-999之间的水仙花数:\n");
	for (i = 100; i <= 999; i++) {
		a = i % 10;
		b = i % 100 / 10;
		c = i / 100;
		if (i == a * a * a + b * b * b  + c * c *c)
			printf("%d\n", i);
	}
	system("pause");
	return 0;
}