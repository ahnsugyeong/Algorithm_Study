#include <stdio.h>
#pragma warning(disable:4996)

void insertsort(int list[], int n)
{
	int key;

	for (int i = 1; i < n; i++)
	{
		key = list[i];
		int j = i - 1;
		while (j >= 0 && list[j] > key) //틀린부분
		{
			list[j+1] = list[j]; //틀린부분
			j--;
		}
		list[j + 1] = key;
	}

	for (int i = 0; i < n; i++)
	{
		printf(" %d", list[i]);
	}
	
}


int main()
{
	
	int n;
	scanf("%d", &n);
	
	int *list;
	list = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}

	insertsort(list, n);



}

/*
7
3 73 48 31 8 11 20*/