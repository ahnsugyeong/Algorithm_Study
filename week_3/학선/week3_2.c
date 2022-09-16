#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int H[100], n = 0;

void downHeap(int i)
{
	if (2 * i > n) return;
	if (H[i] >= H[2 * i] && H[i] >= H[2 * i + 1]) return;
	int si = 2 * i;
	if (2 * i + 1 <= n) {
		if (H[2 * i] < H[2 * i + 1]) {
			if (H[i] < H[2 * i + 1]) {
				si = 2 * i + 1;
			}
		}
	}
	if (H[i] >= H[si]) return;
	int tmp = H[i];
	H[i] = H[si];
	H[si] = tmp;
	downHeap(H[si]);
}
void buildHeap()
{
	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}
void printHeap()
{
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", H + i);
	}
	buildHeap();
	printHeap();
	return 0;
}
