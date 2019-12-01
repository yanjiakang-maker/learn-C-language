#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sushu(int m){
	int i;
	for (i = 2; i <= sqrt(m); i++)
	{
		if (m % i == 0)
			printf("%d\n", m);
		break;
	}
}

int  main() {
	int n;
	for (n = 100; n <= 200; n++)
		sushu(n);
}