#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void* Memcpy(void* dest, void* src, size_t num) {
	assert(dest != NULL && src != NULL);
	for (size_t i = 0; i < num; i++) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src +1;
	}
}

int main() {
	char str1[1024] = { 0 };
	char str2[] = "xzf sigema";
	Memcpy(str1, str2, 6);
	printf("%s\n", str1);
	system("pause");
	return 0;
}