#include<stdio.h>
#include<stdlib.h>

int main() {
	int i, j, a;
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= i; j++)
		{
			a = i * j;
			printf(" %d * %d = %d  ",j,i,a);
			if (i == j)
				printf("\n");
		}
}