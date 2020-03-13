#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	// 常见笔试题面试题(32位系统为例)


// 第一组

	//int arr[] = { 1, 2, 3, 4 };

	 //printf("%d\n", sizeof(arr)); // 16  这里就是计算整个数组arr的字节数
	 //printf("%d\n", sizeof(arr + 0)); // 4 int* arr 已经隐式转成指针 ,  因为数组不能加减整数, 而指针可以,所以这里的arr已经隐式转化成指针 , arr + 0 指向首元素 一个int
	 //printf("%d\n", sizeof(*arr));	// 4 arr 已经隐式转成 int* 再解引用, 得到 int
	 //printf("%d\n", sizeof(arr + 1));	// 4 arr 已经隐式转成 int*  + 1 指向 2 这个元素
	 //printf("%d\n", sizeof(arr[1]));		// 4 int
	 //printf("%d\n", sizeof(&arr));		// 4 &arr 得到一个数组指针, 是一个 int(*)[4]类型, 只要是指针, 32位系统下都是 4 字节
	 //printf("%d\n", sizeof(*&arr));		// 16 &arr 是数组指针. 再次 * 从这个地址开始取 int(*)[4] 类型对应的字节数
	 //printf("%d\n", sizeof(&arr + 1));	// 4 &arr 得到一个 int(*)[4] 再 + 1 还是 int(*)[4], 只要是指针, 就是 4 个字节
	 //printf("%d\n", sizeof(&arr[0]));		// 4 arr[0] 得到int , 再& 得到 int*  指针4字节
	 //printf("%d\n", sizeof(&arr[0] + 1));	// 4 同上



// 第二组
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// 这是一个字符数组 , 不是字符串
	// C语言中 字符串是一种特殊的字符数组 (字符串是以 '\0' 为结束标志的字符数组)
	// 字符串的这一设定是C语言的第一大败笔
	// 指针和数组的隐式转化是C语言设计的第二大败笔
	// 格式化字符串(%d, %s ......)是C语言设计的第三大败笔


	// sizeof 是求字节(字节当然包括字符串的'\0') , 并且sizeof 是 编译期求值
	// strlen 是求字符串的长度 , 他的工作原理是从传入的指针开始直到找到 '\0' 为止


	 //printf("%d\n", sizeof(arr));		// 6 arr 就是一个普通是字符数组, 不要想太多
	 //printf("%d\n", sizeof(arr + 0));	// 4 arr + 0 得到一个 char*, 只要是指针变量, 就是占 4 个字节
	 //printf("%d\n", sizeof(*arr));		// 1 *arr 得到一个 char (a), 就是占一个字节
	 //printf("%d\n", sizeof(arr[1]));		// 1 arr[1] 得到的一个char, 就是占一个字节
	 //printf("%d\n", sizeof(&arr));		// 4 &arr 得到一个数组指针 char(*)[6], 只要是指针, 就是 4 个字节
	 //printf("%d\n", sizeof(&arr + 1));	// 4 同上
	 //printf("%d\n", sizeof(&arr[0] + 1));	// 4 &arr[0] 得到 char*, + 1 还是 char*





//第三组
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// 字符数组不能 strlen   是未定义行为


	// UB 对应着错误的代码
	// printf("%d\n", strlen(arr));		// 未定义行为(UB)  
	// printf("%d\n", strlen(arr + 0));	// 未定义行为(UB)
	// *arr 得到的是 char 类型, strlen 要求的参数是 char* 类型的. 

	// printf("%d\n", strlen(*arr));	// 这里*arr 得到字符'a'=>97, strlen就吧97当成了地址 , 但是计算机上97地址大概率是非法内存
	 //这个代码按理说, 是要编译出错的. 但是 c 是弱类型的编程语言, 把 char 和char* 就给隐式转换了
	// printf("%d\n", strlen(arr[1]));		// 效果同上


//第四组
	// char arr[] = "abcdef";
	// printf("%d\n", sizeof(arr));		// 7 sizeof 是求内存的大小, 这个大小要包含 \0
	// printf("%d\n", sizeof(arr + 0));	// 4 arr + 0 => char*
	// printf("%d\n", sizeof(*arr));		// 1 *arr => char
	// printf("%d\n", sizeof(arr[1]));		// 1 arr[1] => char
	// printf("%d\n", sizeof(&arr));	// 4 &arr => char(*)[7]
	// printf("%d\n", sizeof(&arr + 1));	// 4 &arr + 1 => char(*)[7]
	// printf("%d\n", sizeof(&arr[0] + 1));	// 4 &arr[0] + 1 => char*

	// printf("%d\n", strlen(arr));	// 6 此处是计算字符串长度, 不算 \0
	// printf("%d\n", strlen(arr + 0)); // arr + 0  是一个char* , 指向首元素
	// printf("%d\n", strlen(*arr));	// UB *arr 得到字符, char 和 char* 类型不匹配. 按理说是要编译失败的
	// printf("%d\n", strlen(arr[1]));	// 同上
	// printf("%d\n", strlen(&arr));	// 6   &arr char(*)[7] 类型. 和 char* 类型不匹配, 按理说是要编译失败的
									// &arr 碰巧和 arr 得到的地址值, 是相同的值. 这个结果能算对, 纯属巧合
	// printf("%d\n", strlen(&arr + 1));	// UB &arr + 1 跳过了整个数组, 访问数组后面的空间. 非法内存
	// printf("%d\n", strlen(&arr[0] + 1));	//5   &arr[0] => char* char* + 1 跳过一个元素, 一个char


//第五组
	 //char* p = "abcdef";
	 // 这里字符串"abcdef" 在常量区, 是常量字符串,  *p指向"abcdef"的首元素地址 


	// printf("%d\n", sizeof(p));	// 4 p 是 char* 
	// printf("%d\n", sizeof(p + 1));	// 4 p + 1 还是 char*
	// printf("%d\n", sizeof(*p));	// 1 *p char 
	// printf("%d\n", sizeof(p[1]));	// 1 p[1] char  p[1] => *(p + 1)
	// printf("%d\n", sizeof(&p));	// 4 p char* , &p => char**
	// printf("%d\n", sizeof(&p + 1));	// 同上
	// printf("%d\n", sizeof(&p[0] + 1));	// 4 &p[0] 是 char* 再 + 1 还是 char*

	// printf("%d\n", strlen(p));	// 6 p 指向的是一个字符串
	// printf("%d\n", strlen(p + 1));	// 5 从 p + 1 的位置往后找 5 个元素找到 \0
	// printf("%d\n", strlen(*p));	// UB *p char  strlen 要求的参数是 char* . 类型不匹配, 原则上要编译失败
	// printf("%d\n", strlen(p[1]));	// UB 同上
	// printf("%d\n", strlen(&p));	// UB &p 得到 char** 和 char* 不是相同类型. 原则上要编译失败. 此时 把 char** 强转成的 char* 并不是一个真正字符串
	// printf("%d\n", strlen(&p + 1));	// UB 同上
	// printf("%d\n", strlen(&p[0] + 1));	// 5 &p[0] 得到的是 a 的地址. + 1 得到 b 的地址. 从 b 开始往后找 5 个元素是 \0



// 最后一组  二维数组
	// 所谓的二维数组 本质上就是一个 一维数组. 里面的每个元素又是一个一维数组
	// 长度为 3 个元素的一维数组, 里面的每个元素又是长度为 4 的一维数组
	//int a[3][4] = {
	//	{1, 2, 3, 4},
	//	{5, 6, 7, 8},
	//	{9, 10, 11, 12},
	//};

	// printf("%d\n", sizeof(a));	// 48   12 个元素, 每个元素 4 个字节
	// printf("%d\n", sizeof(a[0][0]));	// 4 a[0][0] => int
	// printf("%d\n", sizeof(a[0]));  // 16 a[0] => int[4] 类型
	// printf("%d\n", sizeof(a[0] + 1));	// 4 a[0] => int[4] 再 + 1 , 就隐式转成指针 int*
	// *(a[0]+1) => a[0][1] 等价 => 2
	// printf("%d\n", sizeof(   *  ( a[0] + 1 )  )    );	// 4 a[0] => int[4] 再 + 1 , 隐式转成 int*, 再 * 得到 int
	// printf("%d\n", sizeof(&a[0] + 1));		//4  a[0] => int[4]    &a[0] => int(*)[4]  再 + 1 还是数组指针  

	// printf("%d\n", sizeof(*(&a[0] + 1)));	//16  a[0] => int[4]  再&得到 int(*)[4] 再 + 1得到的还是 int(*)[4], 再解引用 int[4]
	// printf("%d\n", sizeof(*a)); // 16 *a => *(a + 0) => a[0] 结果 int[4]


	// 这个代码并不是未定义行为
	// 曾经说过的 "数组下标越界未定义行为" 前提条件是 内存访问越界. 这是程序运行时的行为
	// 当下面的代码编译结束之后, 相当于变成 
	// printf("%d\n", 16); 
	// 这是程序运行时真正进行的逻辑
	// printf("%d\n", sizeof(a[100])); // 16 sizeof 是一个运算符(不是函数), 特点是, 编译期求值


	system("pause");
	return 0;
}