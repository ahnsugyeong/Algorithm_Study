#include <stdio.h>
int H[100], n = 0;
void inPlaceHeapsort();
void downHeap();
void printArray();
void buildHeap();
void insertItem();
void upHeap();
int main() {
	int keycnt, input;
	scanf("%d", &keycnt);
	for (int i = 1; i <= keycnt; i++) {
		scanf("%d", &input);
		insertItem(input);

	}
	buildHeap();
	inPlaceHeapsort();
	printArray();
}
void inPlaceHeapsort() {
	int N = n, tmp;
	while (N > 1) {
		tmp = H[N];
		H[N] = H[1];
		H[1] = tmp;

		N--;
		downHeap(1, N);
	}
}

void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
}
void downHeap(int i, int last) {
	int tmp, bigger;
	if (i * 2 > last) return;
	bigger = i * 2;
	if (H[i * 2] < H[i * 2 + 1] && i * 2 + 1 <= last) bigger = i * 2 + 1;// not = -> score 70
	if (H[bigger] < H[i]) return;

	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] = tmp;

	downHeap(bigger, last);
}
void upHeap(int i) {
	int tmp;
	if (i == 1) return;
	if (H[i / 2] > H[i]) return;
	tmp = H[i];
	H[i] = H[i / 2];
	H[i / 2] = tmp;
	upHeap(i / 2);
}
void printArray() {
	for (int i = 1; i <= n; i++) { printf(" %d", H[i]); }
}
void buildHeap() {
	for (int i = n / 2; i > 0; i--) {
		downHeap(i, n);
	}
}
