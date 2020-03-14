#include<stdio.h>
#include<stdlib.h>


int Strlen(const char* str) {
	if (str == NULL) {
		return NULL;
	}
	int size = 0;
	while (*str != '\0') {
		size++;
		str++;
	}
	return size;
}

int main() {
	char str[] = "abcdef";
	int len = Strlen(str);
	printf("%d\n", len);

	system("pause");
	return 0;
}