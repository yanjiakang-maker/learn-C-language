#include <stdio.h>
#include <stdlib.h>



//题目如下:
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

int Isdiff(int a, int b, int c, int d, int e) {
	//查重函数
	//直接列出所有不等关系
	if (a != b && a != c && a != d && a != e && b != c
		&& b != d && b != e && c != d && c != e && d != e) {
		return 1;
	}
	return 0;
}


int Isdiffplus(int a, int b, int c, int d, int e) {
	//查重函数plus


	char tem = 0;        // 0000 0000
	tem |= 1 << (a - 1); // 0000 0001 左移0位          如果5给数字都不一样的话
	tem |= 1 << (b - 1); // 0000 0010 左移1位          最后tem应该是0001 1111  
	tem |= 1 << (c - 1); // 0000 0100 左移2位           也就是2^5 - 1 == 31
	tem |= 1 << (d - 1); // 0000 1000 左移3位           也就是说如果最后tem == 31
	tem |= 1 << (e - 1); // 0001 0000 左移4位            就没有重复的数字
	if (tem == 31) {
		return 1;
	}
	return 0;
}



int main() {
	//直接5重循环遍历一遍所有情况,5的5次方种情况,对计算机来说还是小意思的


	for (int a = 1; a <= 5; a++) {
		for (int b = 1; b <= 5; b++) {
			for (int c = 1; c <= 5; c++) {
				for (int d = 1; d <= 5; d++) {
					for (int e = 1; e <= 5; e++) {

						//两句话说对一半,即一真一假
						//即两句话逻辑与运算结果为0,逻辑或结果为1
						//或者 两句话相加等于 1 (即一真一假)

						if ((b == 2) + (a == 3) == 1 &&
							(b == 2) + (e == 4) == 1 &&
							(c == 1) + (d == 2) == 1 &&
							(c == 5) + (d == 3) == 1 &&
							(e == 4) + (a == 1) == 1 &&
							Isdiffplus(a, b, c, d, e)) {
							printf("A第%d\nB第%d\nC第%d\nD第%d\nE第%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}