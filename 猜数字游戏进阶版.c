#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


//time_t time(time_t *);


void slashCard(int arr[])

{
	srand((unsigned int)time(NULL));
	int pool[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int s;
	int i;
	for (i = 0; i < 4; i++)
	{
		s = rand() % 10;
		while (pool[s] == -1)
		{
			s++;
			if (s == 10)
			{
				s = 0;
			}
		}

		arr[i] = pool[s];
		pool[s] = -1;
	}
}



void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}



int judgeAns(int ans[], int arr[])
{
	int i, j;
	int countB = 0;
	int countA = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (ans[i] == arr[j])
			{
				countB++;
				break;
			}
		}
	}


	for (i = 0; i < 4; i++)
	{
		if (ans[i] == arr[i])
		{
			countA++;
		}
	}


	countB -= countA;
	printf("%dA%dB\n", countA, countB);
	if (countA == 4)
	{
		return 1;
	}
	return 0;
}



int main()
{
	int arr[4];
	slashCard(arr);
	int ans[4];
	int i, j;

	for (i = 1; i <= 8; i++)
	{
		printf("��%d�Σ�", i);

		for (j = 0; j < 4; j++)
		{
			scanf("%d", &ans[j]);
		}

		if (judgeAns(ans, arr))
		{
			break;
		}
	}

	if (i == 9)
	{
		printf("�����ˣ����ǣ�\n");
		printArray(arr, 4);
	}
	else
	{
		printf("��Ӯ�ˣ�\n");
	}
	return 0;
}



int d5p1()
{
	srand((unsigned int)time(NULL));
	int s = rand() % 100 + 1;
	int tmp = 0;
	while (tmp != s)
	{
		scanf("%d", &tmp);
		if (tmp < s)
		{
			printf("��С��\n");
		}
		else if (tmp > s)
		{
			printf("�´���\n");
		}
	}
	printf("�¶���\n");
	return 0;
}