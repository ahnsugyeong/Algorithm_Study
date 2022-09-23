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
	for (int i = 0; i < SIZE; i++) //힙으로 사용될 애들을 전부 0으로 초기화해주기
	{
		heap->H[i] = 0; //나중에 크기 비교 할 때 오른쪽자식이 없는 경우를 위해 0으로 초기화하는 거임.
	}
}

void upHeap(Heap *heap)
{
	int i = heap->n; //제일 마지막에 삽입 되어진애 인덱스 기억
	int k = heap->H[i]; //업힙해야되는 대상자가 k에 저장됌

	while ((i != 1) && (k < heap->H[i / 2])) //i가 루트가 아니면서(부모가 있으면서) 부모보다 작을 때 
	{
		heap->H[i] = heap->H[i / 2];//나 올라가야되니까 부모 내 위치로 내려줌
		i /= 2; //난 올라강8ㅑ되니끼ㅏ~
	}

	heap->H[i] = k;
}


void insertItem(Heap* heap, int k)
{
	heap->n++; //키가 생성되는거니가 사이즈 키워주기, 그릭고 배열이라서 1번 노드 부터 시작하게 해줌
	heap->H[heap->n] = k; //배열에 키값 넣었음
	//upHeap(heap);

}

void downHeap(Heap *heap, int i)
{
	if (i * 2 > heap->n) //자식노드가 없으면 
		return;

	if (heap->H[i] < heap->H[i * 2] || heap->H[i] < heap->H[i * 2 + 1]) //왼쪽이나 오른쪽 자식보다 작으면 
	{
		if (heap->H[i * 2] > heap->H[i * 2 + 1]) //왼쪽 자식이 더 클 때 
		{
			int tmp;
			tmp = heap->H[i];
			heap->H[i] = heap->H[i * 2];
			heap->H[i * 2] = tmp;
			downHeap(heap, i * 2); //왼쪽자식의 자식이 또 있을 수 있으니까 downheap 한 번 더 해줌.
		}
		else
		{
			int tmp;
			tmp = heap->H[i];
			heap->H[i] = heap->H[i * 2 + 1];
			heap->H[i * 2 + 1] = tmp;
			downHeap(heap, i * 2 + 1); //왼쪽자식의 자식이 또 있을 수 있으니까 downheap 한 번 더 해줌.
		}
	}
	else
		return;


}

int removeMax(Heap *heap)
{
	int k = heap->H[1]; //루트를 k에 집어넣기
	heap->H[1] = heap->H[heap->n];
	heap->n--;
	downHeap(heap, 1);
	return k;
}

void buildHeap(Heap *heap)//remove 되었을 때 다시 힙 생성하는 ㄴ거
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
	if (i > heap->n)//힙 사이즈보다 크면 범위 넘어간거니까 끝내주기
		return;

	if (i * 2 <= heap->n)//왼쪽 자식 노드가 힙 사이즈보다 작거나 같은 경우
		rBuildHeap(heap, i * 2);

	if (i * 2 + 1 <= heap->n)//오른쪽 자식 노드가 힙 사이즈보다 작거나 같은 경우
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

	init(&heap);//초기화함수 주소 전달

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