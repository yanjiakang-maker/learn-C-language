#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

int Myatoi(const char* str) {
	//把字符串char 转成 数字int
	if (str == NULL || *str == '\0') {
		return 0;
	}
	int flag = 1; //辅助处理负数的情况
	int ret = 0; //保存结果

	//首先要处理空白字符
	while (isspace(*str)) {
		str++;
	}
	//然后处理 + - 号
	if (*str == '-') {
		flag = -1;
		str++;
	}
	if (*str == '+') {
		str++;
	}
	//处理正常字符
	while (*str != '\0') {
		//判断是不是数字
		if (isdigit(*str)) {
			//字符串转整数的核心操作
			ret = ret * 10 + (*str - '0');
		}
		else {
			return ret;
		}
		str++;
	}
	return flag * ret;
}

int main() {
	char str[] = "100ggg";
	int ret = Myatoi(str);
	//int ret = atoi(str);
	printf("%d\n", ret);
	system("pause");
	return 0;
}