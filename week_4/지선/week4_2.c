#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int Heap[100], N;

void downHeap(int ArrayIndex);

void buildHeap();

void inPlaceHeapSort();

void printArray();

int main() {
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &Heap[i]);

	buildHeap();
	inPlaceHeapSort();

	for (i = 1; i <= N; i++)
		printf(" %d", Heap[i]);

	return 0;
}

void downHeap(int ArrayIndex) {
	int LeftChilndex, RightChildIndex;
	int greater, tmp;

	LeftChilndex = 2 * ArrayIndex;
	RightChildIndex = 2 * ArrayIndex + 1;

	if (LeftChilndex > N) return;

	greater = LeftChilndex;
	if (RightChildIndex <= N)
		if (Heap[RightChildIndex] > Heap[greater]) greater = RightChildIndex;

	if (Heap[ArrayIndex] > Heap[greater]) return;

	tmp = Heap[ArrayIndex];
	Heap[ArrayIndex] = Heap[greater];
	Heap[greater] = tmp;

	downHeap(greater);
}

void buildHeap() {
	int i;

	for (i = N / 2; i >= 1; i--)
		downHeap(i);
}

void inPlaceHeapSort() {
	int i;
	int tmplen, tmp;

	tmplen = N;

	for (i = N; i >= 1; i--) {
		tmp = Heap[1];
		Heap[1] = Heap[i];
		Heap[i] = tmp;

		N--;
		downHeap(1);
	}

	N = tmplen;
}

void printArray() {
	int i;

	for (i = 1; i <= N; i++)
		printf(" %d", Heap[i]);
	printf("\n");
}