#include <stdio.h>
#pragma warning(disable:4996)

void swap(int list[], int i, int Max){

	int tmp;
	tmp = list[i];
	list[i] = list[Max];
	list[Max] = tmp;

}

void inplacesort(int list[], int n)
{
	int max;

	for (int i = n - 1; i >= 1; i--)
	{
		max = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (list[j] > list[max])
			{
				max = j;
			}
		}
		swap(list, i, max);
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

	inplacesort(list, n);



}

/*
8
8 31 48 73 3 65 20 29*/