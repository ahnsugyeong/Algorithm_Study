#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int H[100] = { 0 }, n;
void downHeap(int i, int last) //���������� �������鼭 ������
{
	int la = 2 * i;
	if (la > last) return;
	if (2 * i + 1 <= last) {
		if (H[la] < H[2 * i + 1]) la = 2 * i + 1;
	}
	if (H[la] > H[i]) {
		int tmp = H[i];
		H[i] = H[la];
		H[la] = tmp;
	}
	downHeap(la, last);
}
void rBuildHeap(int i) //��ͽ� ����� ��
{
	
}
void buildHeap() //����ͽ� ����� ��
{
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i, n);
	}
}
void printArray()
{
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}
void inPlaceHeapSort()
{
	buildHeap();
	printArray();
	for (int i = n; i >= 2; i--) {
		int tmp = H[i];
		H[i] = H[1];
		H[1] = tmp;
		downHeap(1, i - 1);
	}
}


int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", H + i);
	}
	inPlaceHeapSort();
	printArray();
	return 0;
}