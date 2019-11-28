//¼ÆËã1/1-1/2+1/3-1/4+1/5¡­¡­+1/99-1/100µÄÖµ¡£
#include<stdio.h>
#include<stdlib.h>

int main() {
	double sum = 0.0;
	int i , n ;
	for (i = 1; i <= 100; i++) {
		if (i % 2 == 0)
			n = -1;
		else n = 1;
		sum += n * 1.0 / i;
	}
	printf("sum = %f", sum);
}
