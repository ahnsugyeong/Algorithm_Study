#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int H[100], n;
void downHeap(int i, int last) //손상된 힙을 위에서부터 아래로 힙정렬
{
	int larger = 2 * i;
	if (larger > last) return;
	if (2 * i + 1 <= last) {
		if (H[2 * i] < H[2 * i + 1]) {
			larger = 2 * i + 1;
		}
	}
	if (H[larger] > H[i]) {
		int tmp = H[larger];
		H[larger] = H[i];
		H[i] = tmp;
	}
		
	
	downHeap(larger, last);
}
void buildHeap()
{
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i, n);
	}
}
void rBuildHeap(int i)
{

}
void inPlaceHeapSort()
{
	buildHeap();
	for (int i = n; i >= 2; i--) {
		int tmp = H[i];
		H[i] = H[1];
		H[1] = tmp;
		downHeap(1, i - 1);
	}
}
void printArray()
{
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
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