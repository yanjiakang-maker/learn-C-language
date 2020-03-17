#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

// assert 叫做 "断言" . ( ) 的条件必须要成立, 否则程序就直接崩溃


int Strcmp(const char* str1, const char* str2) {
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0') {
		//当str1 和 str2 都不为  \0  时进行循环
		//因为 strcmp 的比较方式是 字典式  比较
		//即 只要找到一个对应元素有大小之分  即可得到答案
		if (*str1 > * str2) {
			return 1;
		}
		else if (*str1 < *str2) {
			return -1;
		}
		else {
			//当两者相等时, 不能得出答案, 向后继续找
			str1++;
			str2++;
		}
	}

	//看哪个字符串先到 \0  哪个字符串就小
	//不能直接写成 *str1 == '\0'   因为如果两个字符串相等时 str1 和 str2 都是'\0'
	//如果直接写成 *str1 == '\0'   那降永远无法判断相等
	if (*str1 < *str2) {
		return -1;
	}
	else if (*str1 > * str2) {
		return 1;
	}
	else {
		return 0;
	}
}


int main() {
	char str1[] = "hahahaha";
	char str2[] = "haha";
	int ret = Strcmp(str1, str2);
	if (ret > 0) {
		printf("str1 > str2\n");
	}
	else if (ret < 0) {
		printf("str1 < str2\n");
	}
	else {
		printf("str1 = str2\n");
	}


	system("pause");
	return 0;
}