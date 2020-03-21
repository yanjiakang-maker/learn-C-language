#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//����һ���ṹ�����, ����������Ϣ
typedef struct PersonInfo {
	char name[1024];
	char sex[20];
	char age[100];
	char phone[1024];
	char address[1024];
}PersonInfo;

#define MAX_SIZE 200

//����һ���ṹ�����, ����һ���ṹ������  ���ж�Ӧ���±�size
typedef struct AddressBook {
	PersonInfo person[MAX_SIZE];
	int size;
}AddressBook;



void Init(AddressBook* address_book) {
	//�ȸ�size��һ����ֵ0
	address_book->size = 0;
	//Ȼ��������е���Ϣ����ֵΪ��
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
	printf(" 1. ������ϵ��\n");
	printf(" 2. ɾ����ϵ��\n");
	printf(" 3. ������ϵ��\n");
	printf(" 4. �޸���ϵ��\n");
	printf(" 5. ��ӡȫ����ϵ��\n");
	printf(" 6. ���������ϵ��\n");
	printf(" 7. ������������ϵ��\n");
	printf(" 0. �˳�\n");
	printf("========================\n");

	int choice = 0;
	printf(" ����������ѡ�� : ");
	scanf("%d", &choice);
	return choice;
}


void AddPersonInfo(AddressBook* address_book) {
	printf(" ������ϵ��\n");
	if (address_book->size >= MAX_SIZE) {
		printf(" ͨѶ¼����, ����ʧ��!\n");
		return;
	}

	PersonInfo* info = &address_book->person[address_book->size];
	printf(" ��������ϵ������:");
	scanf("%s", info->name);
	//��������д�����ڷ���
	//scanf("%s",address_book->person[address_book->size].name)
	//���Ի�һ��д�� (����)

	//ע����������д��Ҳ�Ǵ��
	//��Ϊ�����Ǵ�����һ����ʱ����info Ȼ���������ʱ���������������  
	//�ȵ��������������ʱ�� �����ʱ�����ͻᱻ�ͷ� �����Ǵ����
	//����Ӧ��д�������  ָ����ʽ   ͨ��ָ��ֱ�Ӱ�ֵ���뵽�ṹ���в�����ȷ��
	//PersonInfo info = address_book->person[address_book->size];
	//scanf("%s", info.name);
	printf(" ��������ϵ���Ա�:");
	scanf("%s", info->sex);
	printf(" ��������ϵ������:");
	scanf("%s", info->age);
	printf(" ��������ϵ�˵绰:");
	scanf("%s", info->phone);
	printf(" ��������ϵ��סַ:");
	scanf("%s", info->address);

	//��Ҫ���Ǹı�size
	address_book->size++;
	printf(" ���ӳɹ�!\n\n");
}


void DelPersonInfo(AddressBook* address_book) {
	//������� ͨ�����ɾ�� �ķ�ʽ
	printf(" ɾ����ϵ��\n");
	if (address_book->size <= 0) {
		printf(" ͨѶ¼Ϊ��! ɾ��ʧ��!\n\n");
		return;
	}


	printf(" ������Ҫɾ����id\n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= address_book->size) {
		printf(" ������������!\n\n");
		return;
	}
	//�����ж��ַ�������ɾ��
	// ���Բ��� id �������Ԫ����ǰ�ƶ��ķ���
	// Ҳ������ ���һ��Ԫ�� �� Ҫɾ��Ԫ�� ���н��� Ȼ��size - 1����
	//������õڶ��ּ򵥵ķ���

	//ȡ�����һ��Ԫ��
	PersonInfo* last_info = &address_book->person[address_book->size - 1];
	//ȡ��Ҫɾ����Ԫ��
	PersonInfo* todel_info = &address_book->person[id];

	//�ṹ��֮�����ֱ�Ӹ�ֵ
	*todel_info = *last_info;
	//���ע�ⲻҪ���Ǹı�size
	address_book->size--;
	printf(" ɾ����ϵ�˳ɹ�!\n\n");
}


void FindPersonInfo(AddressBook* address_book) {
	printf(" ������ϵ�� \n");
	if (address_book->size <= 0) {
		printf("ͨѶ¼Ϊ��!����ʧ��!\n\n");
		return;
	}

	//����ͨ�� ���� ������ϵ��
	//���������Ͷ���ӡ
	printf(" ��������Ҫ��ѯ����ϵ������: ");
	char name[1024] = { 0 };

	//ע�����ﲻ��д &name
	//��Ϊ���� name �Ѿ�ת��Ϊ char* ����   
	//�������&�Ļ� �õ�����һ������ָ��, ���Ͳ�ƥ��  ��������Ч��һ��  ֻ��˵������
	scanf("%s", name);

	for (int i = 0; i < address_book->size; i++) {
		PersonInfo* info = &address_book->person[i];
		if (strcmp(info->name, name) == 0) {
			printf("  [%d] %s : %s  \t%s\t%s\t%s\n", i, info->name, info->sex, info->age,
				info->phone, info->address);
		}
	}
	printf(" ���ҳɹ�!\n\n");
}


void ModifyPersonInfo(AddressBook* address_book) {
	//���û�����Ҫ�޸ĵ���ϵ�����, Ȼ���޸�����Ϣ
	printf(" �޸���ϵ����Ϣ\n");
	if (address_book->size <= 0) {
		printf(" ͨѶ¼Ϊ��! �޸�ʧ��!\n\n");
		return;
	}

	int id = 0;
	printf(" ��������Ҫ�޸ĵ���ϵ����� : ");
	scanf("%d", &id);
	
	if (id < 0 || id >= address_book->size) {
		printf(" ������������! �޸�ʧ��!\n\n");
		return; 
	}

	PersonInfo* info = &address_book->person[id];

	char name[1024] = { 0 };
	printf(" �������޸ĺ������(*�����޸�) : ");
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}

	char sex[20] = { 0 };
	printf(" �������޸ĺ���Ա�(*�����޸�) : ");
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0) {
		strcpy(info->sex, sex);
	}

	char age[100] = { 0 };
	printf(" �������޸ĺ������(*�����޸�) : ");
	scanf("%s", age);
	if (strcmp(age, "*") != 0) {
		strcpy(info->age, age);
	}

	char phone[1024] = { 0 };
	printf(" �������޸ĺ�ĵ绰(*�����޸�) : ");
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}

	char address[1024] = { 0 };
	printf(" �������޸ĺ��סַ(*�����޸�) : ");
	scanf("%s", address);
	if (strcmp(address, "*") != 0) {
		strcpy(info->address, address);
	}
	printf(" �޸ĳɹ�!\n\n");
}


void PrintPersonInfo(AddressBook* address_book) {
	printf(" ��ӡ��ϵ�� : \n");

	//����Ϊ�˸��򵥵�д, Ҳ��ȡ�������д�� ����һ��ָ��
	//    /t��ˮƽ�Ʊ�� , �����˿�����������
	for (int i = 0; i < address_book->size; i++) {
		PersonInfo* info = &address_book->person[i];
		printf("  [%d] %s : %s \t%s\t%s\t%s\n", i, info->name, info->sex, info->age,
			info->phone, info->address);
	}
	printf(" ��ӡ�ɹ�,����ӡ%d����ϵ��!\n\n", address_book->size);
}


void ClearPersonInfo(AddressBook* address_book) {
	//�����ϵ����һ��Σ�ղ���, Ҫ���û�һ�������Ƿ����Ҫ���
	char choice[10] = { 0 };
	printf(" �����Ҫ�����ϵ����? Y/N \n");
	printf(" ����������ѡ�� : ");
	scanf("%s", choice);

	if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0) {
		address_book->size = 0;
		printf(" �����ϵ�˳ɹ�!\n\n");
		return;
	}
	else {
		printf(" �����ϵ�˲�����ȡ��! \n\n");
		return;
	}
}


void RankPersonInfo(AddressBook* address_book) {
	//������������ϵ��
	printf(" ������������ϵ��\n");
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
	printf(" ����ɹ�\n\n");

}


int main() {
	AddressBook address_book;
	Init(&address_book);

	//�� ת�Ʊ� ����������һϵ�к���, д����Ҫ��һֱif else Ҫ��������
	//��������ָ���� typedef
	//����ʹ�����һ������ָ�� Func  ���������� void(*)(AddressBook*)
	typedef void(*Func)(AddressBook*);
	//����һ��ת�Ʊ�
	Func addr_table[] = {
		NULL, //����ռλ�� , ��д����Ĵ���
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		ModifyPersonInfo,
		PrintPersonInfo,
		ClearPersonInfo,
		RankPersonInfo,
	};


	while (1) {
		//��һ������ѭ�����û����н���
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(addr_table) / sizeof(addr_table[0])) {
			printf(" ������������!\n\n");
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