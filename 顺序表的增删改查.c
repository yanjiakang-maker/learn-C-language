#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct SqList
{
	DataType* arr;
	int size;
	int capacity;
}SqList;


//˳����ʼ��
void SqListInit(SqList* sl) {
	//size������ǵ�ǰԪ�ظ���
	sl->size = 0;
	//capacity����ǰ�������
	sl->capacity = 10;
	sl->arr = (DataType*)malloc(sizeof(DataType) * sl->capacity);

	//����������Ϣ����ֵ
	for (int i = 0; i < sl->capacity; i++) {
		sl->arr[i] = 0;
	}
}


//����
void SqListDestory(SqList* sl) {
	assert(sl != NULL);
	free(sl->arr);
	sl->arr = NULL;
	sl->size = 0;
	sl->capacity = 0;
}


//��ӡ
void SqListPrint(SqList* sl) {
	assert(sl != NULL);
	for (int i = 0; i < sl->size; i++) {
		printf("%d  ", sl->arr[i]);
	}
	printf("\n");
}


//˳������Ƿ���Ҫ����
void SqListChack(SqList* sl) {
	assert(sl != NULL);
	if (sl->size >= sl->capacity) {
		sl->capacity += 10;
		realloc(sl->arr, sizeof(DataType) * sl->capacity);
	}
}


//β��
void SqListPushBack(SqList* sl, DataType val) {
	assert(sl != NULL);
	//�����㷨��Ҫ���м���Ƿ�Ҫ����
	SqListChack(sl);
	sl->arr[sl->size] = val;
	sl->size++;
}


//βɾ
void SqListPopBack(SqList* sl) {
	assert(sl != NULL);
	if (sl->size == 0) {
		printf("˳���Ϊ��, ɾ��ʧ��!\n");
		return;
	}
	sl->arr[sl->size - 1] = 0;
	sl->size--;
}


//ͷ��
void SqListPushFront(SqList* sl, DataType val) {
	assert(sl != NULL);
	SqListChack(sl);

	int start = sl->size;
	while (start > 0) {
		sl->arr[start] = sl->arr[start - 1];
		start--;
	}
	sl->arr[0] = val;
	sl->size++;
}


//ͷɾ
void SqListPopFront(SqList* sl) {
	assert(sl != NULL);

	int start = 1;
	while (start < sl->size) {
		sl->arr[start - 1] = sl->arr[start];
		start++;
	}
	sl->size--;
}


//����
void SqListFind(SqList* sl, DataType val) {
	for (int i = 0; i < sl->size; i++) {
		if (sl->arr[i] == val) {
			printf("\n�ҵ���! Ԫ�ص��±���%d \n\n",i);
			return;
		}
	}
	printf("\nû�ҵ�!\n\n");
}


//��posλ�ò���
void SqListInsert(SqList* sl, int pos, DataType val) {
	assert(sl != NULL);
	if (pos < 0 || pos > sl->size) {
		printf("ָ����posλ������! ����ʧ��!\n\n");
		return;
	}
	SqListChack(sl);

	int start = sl->size;
	while (start > pos) {
		sl->arr[start] = sl->arr[start - 1];
		start--;
	}
	sl->arr[pos] = val;
	sl->size++;
}


//��posλ��ɾ��
void SqListdelete(SqList* sl, int pos) {
	assert(sl != NULL);
	if (pos < 0 || pos >= sl->size) {
		printf("ָ����posλ������! ɾ��ʧ��!\n\n");
		return;
	}

	int start = pos + 1;
	while (start < sl->size) {
		sl->arr[start - 1] = sl->arr[start];
		start++;
	}
	sl->size--;
}


int main() {
	SqList sl;
	SqListInit(&sl);

	SqListPushFront(&sl, 1);
	SqListPrint(&sl);
	SqListPushFront(&sl, 2);
	SqListPrint(&sl);
	SqListPushFront(&sl, 3);
	SqListPrint(&sl);
	SqListPushFront(&sl, 5);
	SqListPrint(&sl);
	SqListPushFront(&sl, 6);
	SqListPrint(&sl);

	SqListInsert(&sl, 2, 4);
	SqListPrint(&sl);

	SqListdelete(&sl, 7);
	SqListPrint(&sl);

	system("pause");
	return 0;
}