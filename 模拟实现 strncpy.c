#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* Strncpy(char* dest, const char* src, size_t num) {
	assert(dest != NULL && src != NULL);
	char* ret = dest;  //记录地址 , 以供最后返回
	for (size_t i = 0; i < num; i++) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return ret;
}


int main() {
	char str1[1024];
	char str2[100] = "xiaozhan bi huhuhuhuhuhu !!";
	char* ret = Strncpy(str1, str2, 10);
	printf("%s\n", ret);
	system("pause");
	return 0;
}