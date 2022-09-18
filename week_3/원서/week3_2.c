#include <stdio.h>
int H[101] = { 0 }, n = 0;
void print() {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
}

void downheap(int i) {
	int tmp;
	while (1) {//자식값이 더 클동안
		if (H[i] > H[i * 2] && H[i] > H[i * 2 + 1]) break;
		else if (i * 2 > n) break;//0ㅣ거 때문0ㅔ 90점
		if (H[i * 2] >= H[i * 2 + 1]) {//왼쪽 자식 더 크면
			tmp = H[i];
			H[i] = H[i * 2];
			H[i * 2] = tmp;//swap
			i = i * 2;// 현재 노드 갱신	
		}
		else if (H[i * 2] < H[i * 2 + 1]) {//오른쪽 자식 더 클때
			tmp = H[i];
			H[i] = H[i * 2 + 1];
			H[i * 2 + 1] = tmp;//swap
			i = i * 2 + 1;// 현재 노드 갱신
		}
	}
}

void buildHeap() {
	for (int i = n / 2; i > 0; i--) {
		downheap(i);
	}
}


int main() {
	int keycnt;
	scanf("%d", &keycnt);
	for (int i = 1; i <= keycnt; i++) {
		scanf("%d", &H[i]);
		n++;
	}
	buildHeap();
	print();
}
