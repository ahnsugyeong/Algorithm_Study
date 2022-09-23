#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct {
	int H[SIZE];
	int n;
}Heap;

void init(Heap *heap)
{
	heap->n = 0;
	for (int i = 0; i < SIZE; i++) //������ ���� �ֵ��� ���� 0���� �ʱ�ȭ���ֱ�
	{
		heap->H[i] = 0; //���߿� ũ�� �� �� �� �������ڽ��� ���� ��츦 ���� 0���� �ʱ�ȭ�ϴ� ����.
	}
}

void upHeap(Heap *heap)
{
	int i = heap->n; //���� �������� ���� �Ǿ����� �ε��� ���
	int k = heap->H[i]; //�����ؾߵǴ� ����ڰ� k�� �����

	while ((i != 1) && (k < heap->H[i / 2])) //i�� ��Ʈ�� �ƴϸ鼭(�θ� �����鼭) �θ𺸴� ���� �� 
	{
		heap->H[i] = heap->H[i / 2];//�� �ö󰡾ߵǴϱ� �θ� �� ��ġ�� ������
		i /= 2; //�� �ö�8���Ǵϳ���~
	}

	heap->H[i] = k;
}


void insertItem(Heap* heap, int k)
{
	heap->n++; //Ű�� �����Ǵ°Ŵϰ� ������ Ű���ֱ�, �׸��� �迭�̶� 1�� ��� ���� �����ϰ� ����
	heap->H[heap->n] = k; //�迭�� Ű�� �־���
	//upHeap(heap);

}

void downHeap(Heap *heap, int i)
{
	if (i * 2 > heap->n) //�ڽĳ�尡 ������ 
		return;

	if (heap->H[i] < heap->H[i * 2] || heap->H[i] < heap->H[i * 2 + 1]) //�����̳� ������ �ڽĺ��� ������ 
	{
		if (heap->H[i * 2] > heap->H[i * 2 + 1]) //���� �ڽ��� �� Ŭ �� 
		{
			int tmp;
			tmp = heap->H[i];
			heap->H[i] = heap->H[i * 2];
			heap->H[i * 2] = tmp;
			downHeap(heap, i * 2); //�����ڽ��� �ڽ��� �� ���� �� �����ϱ� downheap �� �� �� ����.
		}
		else
		{
			int tmp;
			tmp = heap->H[i];
			heap->H[i] = heap->H[i * 2 + 1];
			heap->H[i * 2 + 1] = tmp;
			downHeap(heap, i * 2 + 1); //�����ڽ��� �ڽ��� �� ���� �� �����ϱ� downheap �� �� �� ����.
		}
	}
	else
		return;


}

int removeMax(Heap *heap)
{
	int k = heap->H[1]; //��Ʈ�� k�� ����ֱ�
	heap->H[1] = heap->H[heap->n];
	heap->n--;
	downHeap(heap, 1);
	return k;
}

void buildHeap(Heap *heap)//remove �Ǿ��� �� �ٽ� �� �����ϴ� ����
{
	for (int i = heap->n / 2; i >= 1; i--)
	{
		downHeap(heap, i);
	}
}

void inPlacementSort(Heap *heap)
{
	int size = heap->n;
	int key;

	for (int i = 0; i < size; i++)
	{
		key = removeMax(heap);
		heap->H[heap->n + 1] = key;
	}
}

void rBuildHeap(Heap *heap, int i)
{
	if (i > heap->n)//�� ������� ũ�� ���� �Ѿ�Ŵϱ� �����ֱ�
		return;

	if (i * 2 <= heap->n)//���� �ڽ� ��尡 �� ������� �۰ų� ���� ���
		rBuildHeap(heap, i * 2);

	if (i * 2 + 1 <= heap->n)//������ �ڽ� ��尡 �� ������� �۰ų� ���� ���
		rBuildHeap(heap, i * 2 + 1);

	downHeap(heap, i);

}

void printArray(Heap *heap, int n)
{
	for (int i = 0; i <= n; i++)
	{
		printf(" %d", heap->H[i]);
	}
	printf("\n");
}

void printHeap(Heap *heap)
{
	for (int i = 1; i <= heap->n; i++)
	{
		printf("%d ", heap->H[i]);
	}
	printf("\n");

}
int main() {
	Heap heap;

	init(&heap);//�ʱ�ȭ�Լ� �ּ� ����

	char c;
	int key;

	while (1)
	{
		scanf("%c", &c);
		if (c == 'i')
		{
			getchar();
			scanf("%d", &key);
			getchar();
			insertItem(&heap, key);
			buildHeap(&heap);
			printf("0\n");
		}
		else if (c == 'd')
		{
			printf("%d\n", removeMax(&heap));
		}
		else if (c == 'p')
		{
			printHeap(&heap);
		}
		else if (c == 'q')
		{
			break;
		}
	}

	/*
	//rBuildHeap(&heap,1);
	buildHeap(&heap);
	printHeap(&heap);

	int n = heap.n;
	inPlacementSort(&heap);
	printArray(&heap,n);
	*/

}