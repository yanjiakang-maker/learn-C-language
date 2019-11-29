#include<stdio.h>
#include<stdlib.h>

int main() {
	int i, num = 0;
	for (i = 1; i <= 100; i++) {
		if ( i % 10 == 9)
			num++;
		if (i / 10 == 9)
			num++;	
	}
	printf("9一共出现了%d次\n", num);
}