#include<stdio.h>
#include<stdlib.h>


void output(int n) {
	for (int i = 1; i <= n; i++) {
		printf("*");
	}
	printf("\n");
}

int main() {
	int i;
	for (i = 1; i <= 13; i += 2)
		output(i);
	for (; i >= 1; i -= 2)
		output(i);
	system("pause");
	return 0;
}