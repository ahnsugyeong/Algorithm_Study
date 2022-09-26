#include <stdio.h>
#include <stdlib.h>
int H[100], n = 0;
void downHeap();
void printArray();
void upHeap();
void insertItem();
void buildHeap();
void inPlaceHeapSort();
int main() {
	int keycnt, key;
	scanf("%d", &keycnt);
	for (int i = 0; i < keycnt; i++) {
		scanf("%d", &key);
		insertItem(key);
	}
	buildHeap();
	inPlaceHeapSort();
	printArray();
}
void inPlaceHeapSort() {
	int tmp,N = n;
	while (N>1) {
		tmp = H[1];
		H[1] = H[N];
		H[N] = tmp;
		N--;
		

		downHeap(1,N);
	}


}
void downHeap(int i,int size) {
	int tmp, bigger;
	if (i * 2 > size) return;
	bigger = i * 2;
	if (H[i * 2] < H[i * 2 + 1] && i * 2 + 1 <= size) bigger = i * 2 + 1;
	if (H[bigger] < H[i]) return;

	tmp = H[bigger];
	H[bigger] = H[i];
	H[i] = tmp;

	downHeap(bigger,size);
}
void upHeap(int i) {
	int tmp;
	if (i == 1) return;
	if (H[i / 2] > H[i]) return;

	tmp = H[i / 2];
	H[i / 2] = H[i];
	H[i] = tmp;
	upHeap(i / 2);
}
void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
}
void printArray() {
	for (int i = 1; i <= n; i++) printf(" %d", H[i]);
	printf("\n");
}


void buildHeap() {
	for (int i = n / 2; i > 0; i--) {
		downHeap(i,n);
	}
}

/*
6
24 17 33 50 60 70
*/