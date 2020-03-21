#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//创建一个结构体变量, 包含所需信息
typedef struct PersonInfo {
	char name[1024];
	char sex[20];
	char age[100];
	char phone[1024];
	char address[1024];
}PersonInfo;

#define MAX_SIZE 200

//创建一个结构体变量, 包含一个结构体数组  还有对应的下标size
typedef struct AddressBook {
	PersonInfo person[MAX_SIZE];
	int size;
}AddressBook;



void Init(AddressBook* address_book) {
	//先给size赋一个初值0
	address_book->size = 0;
	//然后给数组中的信息赋初值为空
	for (int i = 0; i < MAX_SIZE; i++) {
		strcpy(address_book->person[i].name, "");
		strcpy(address_book->person[i].sex, "");
		strcpy(address_book->person[i].age, "");
		strcpy(address_book->person[i].phone, "");
		strcpy(address_book->person[i].address, "");
	}
}


int Menu() {
	printf("========================\n");
	printf(" 1. 新增联系人\n");
	printf(" 2. 删除联系人\n");
	printf(" 3. 查找联系人\n");
	printf(" 4. 修改联系人\n");
	printf(" 5. 打印全部联系人\n");
	printf(" 6. 清空所有联系人\n");
	printf(" 7. 按姓名排序联系人\n");
	printf(" 0. 退出\n");
	printf("========================\n");

	int choice = 0;
	printf(" 请输入您的选择 : ");
	scanf("%d", &choice);
	return choice;
}


void AddPersonInfo(AddressBook* address_book) {
	printf(" 增加联系人\n");
	if (address_book->size >= MAX_SIZE) {
		printf(" 通讯录已满, 新增失败!\n");
		return;
	}

	PersonInfo* info = &address_book->person[address_book->size];
	printf(" 请输入联系人姓名:");
	scanf("%s", info->name);
	//下面这种写法过于繁琐
	//scanf("%s",address_book->person[address_book->size].name)
	//所以换一种写法 (上面)

	//注意下面这种写法也是错的
	//因为这样是创建了一个临时变量info 然后往这个临时变量里存入了姓名  
	//等到这个函数结束的时候 这个临时变量就会被释放 所以是错误的
	//这里应该写成上面的  指针形式   通过指针直接把值输入到结构体中才是正确的
	//PersonInfo info = address_book->person[address_book->size];
	//scanf("%s", info.name);
	printf(" 请输入联系人性别:");
	scanf("%s", info->sex);
	printf(" 请输入联系人年龄:");
	scanf("%s", info->age);
	printf(" 请输入联系人电话:");
	scanf("%s", info->phone);
	printf(" 请输入联系人住址:");
	scanf("%s", info->address);

	//不要忘记改变size
	address_book->size++;
	printf(" 增加成功!\n\n");
}


void DelPersonInfo(AddressBook* address_book) {
	//这里采用 通过序号删除 的方式
	printf(" 删除联系人\n");
	if (address_book->size <= 0) {
		printf(" 通讯录为空! 删除失败!\n\n");
		return;
	}


	printf(" 请输入要删除的id\n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= address_book->size) {
		printf(" 您的输入有误!\n\n");
		return;
	}
	//这里有多种方法进行删除
	// 可以采用 id 后的所有元素向前移动的方法
	// 也可以用 最后一个元素 和 要删除元素 进行交换 然后size - 1即可
	//这里采用第二种简单的方法

	//取到最后一个元素
	PersonInfo* last_info = &address_book->person[address_book->size - 1];
	//取到要删除的元素
	PersonInfo* todel_info = &address_book->person[id];

	//结构体之间可以直接赋值
	*todel_info = *last_info;
	//最后注意不要忘记改变size
	address_book->size--;
	printf(" 删除联系人成功!\n\n");
}


void FindPersonInfo(AddressBook* address_book) {
	printf(" 查找联系人 \n");
	if (address_book->size <= 0) {
		printf("通讯录为空!查找失败!\n\n");
		return;
	}

	//这里通过 姓名 查找联系人
	//出现重名就都打印
	printf(" 请输入您要查询的联系人姓名: ");
	char name[1024] = { 0 };

	//注意这里不能写 &name
	//因为这里 name 已经转化为 char* 类型   
	//如果加上&的话 得到的是一个数组指针, 类型不匹配  尽管最终效果一样  只能说是碰巧
	scanf("%s", name);

	for (int i = 0; i < address_book->size; i++) {
		PersonInfo* info = &address_book->person[i];
		if (strcmp(info->name, name) == 0) {
			printf("  [%d] %s : %s  \t%s\t%s\t%s\n", i, info->name, info->sex, info->age,
				info->phone, info->address);
		}
	}
	printf(" 查找成功!\n\n");
}


void ModifyPersonInfo(AddressBook* address_book) {
	//让用户输入要修改的联系人序号, 然后修改其信息
	printf(" 修改联系人信息\n");
	if (address_book->size <= 0) {
		printf(" 通讯录为空! 修改失败!\n\n");
		return;
	}

	int id = 0;
	printf(" 请输入您要修改的联系人序号 : ");
	scanf("%d", &id);
	
	if (id < 0 || id >= address_book->size) {
		printf(" 您的输入有误! 修改失败!\n\n");
		return; 
	}

	PersonInfo* info = &address_book->person[id];

	char name[1024] = { 0 };
	printf(" 请输入修改后的姓名(*代表不修改) : ");
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}

	char sex[20] = { 0 };
	printf(" 请输入修改后的性别(*代表不修改) : ");
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0) {
		strcpy(info->sex, sex);
	}

	char age[100] = { 0 };
	printf(" 请输入修改后的年龄(*代表不修改) : ");
	scanf("%s", age);
	if (strcmp(age, "*") != 0) {
		strcpy(info->age, age);
	}

	char phone[1024] = { 0 };
	printf(" 请输入修改后的电话(*代表不修改) : ");
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}

	char address[1024] = { 0 };
	printf(" 请输入修改后的住址(*代表不修改) : ");
	scanf("%s", address);
	if (strcmp(address, "*") != 0) {
		strcpy(info->address, address);
	}
	printf(" 修改成功!\n\n");
}


void PrintPersonInfo(AddressBook* address_book) {
	printf(" 打印联系人 : \n");

	//这里为了更简单的写, 也采取了上面的写法 创建一个指针
	//    /t是水平制表符 , 会让人看起来更舒适
	for (int i = 0; i < address_book->size; i++) {
		PersonInfo* info = &address_book->person[i];
		printf("  [%d] %s : %s \t%s\t%s\t%s\n", i, info->name, info->sex, info->age,
			info->phone, info->address);
	}
	printf(" 打印成功,共打印%d个联系人!\n\n", address_book->size);
}


void ClearPersonInfo(AddressBook* address_book) {
	//清空联系人是一个危险操作, 要给用户一次提醒是否真的要清空
	char choice[10] = { 0 };
	printf(" 您真的要清空联系人吗? Y/N \n");
	printf(" 请输入您的选择 : ");
	scanf("%s", choice);

	if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
		address_book->size = 0;
		printf(" 清空联系人成功!\n\n");
		return;
	}
	else {
		printf(" 清空联系人操作已取消! \n\n");
		return;
	}
}


void RankPersonInfo(AddressBook* address_book) {
	//按姓名排序联系人
	printf(" 按姓名排序联系人\n");
	for (int i = 0; i < address_book->size; i++) {
		for (int j = address_book->size - 1; j > i; j--) {
			PersonInfo* info1 = &address_book->person[j];
			PersonInfo* info2 = &address_book->person[j - 1];
			if (strcmp(info1->name, info2->name) < 0) {
				PersonInfo tmp = *info1;
				*info1 = *info2;
				*info2 = tmp;
			}
		}
	}
	printf(" 排序成功\n\n");

}


int main() {
	AddressBook address_book;
	Init(&address_book);

	//用 转移表 来调用上述一系列函数, 写下来要比一直if else 要简单且美观
	//遇到函数指针先 typedef
	//这里就创建了一个函数指针 Func  他的类型是 void(*)(AddressBook*)
	typedef void(*Func)(AddressBook*);
	//创建一个转移表
	Func addr_table[] = {
		NULL, //纯属占位置 , 方写下面的代码
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		ModifyPersonInfo,
		PrintPersonInfo,
		ClearPersonInfo,
		RankPersonInfo,
	};


	while (1) {
		//整一个无限循环与用户进行交互
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(addr_table) / sizeof(addr_table[0])) {
			printf(" 您的输入有误!\n\n");
			continue;
		}
		if (choice == 0) {
			printf(" goodbye~\n\n");
			break;
		}
		addr_table[choice](&address_book);
	}

	system("pause");
	return 0;
}