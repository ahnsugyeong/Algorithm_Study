#include <stdio.h>
int H[101] = { 0 }, n = 0;
void print() {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
}

void downheap(int i) {
	int tmp;
	while (1) {//�ڽİ��� �� Ŭ����
		if (H[i] > H[i * 2] && H[i] > H[i * 2 + 1]) break;
		else if (i * 2 > n) break;//0�Ӱ� ����0�� 90��
		if (H[i * 2] >= H[i * 2 + 1]) {//���� �ڽ� �� ũ��
			tmp = H[i];
			H[i] = H[i * 2];
			H[i * 2] = tmp;//swap
			i = i * 2;// ���� ��� ����	
		}
		else if (H[i * 2] < H[i * 2 + 1]) {//������ �ڽ� �� Ŭ��
			tmp = H[i];
			H[i] = H[i * 2 + 1];
			H[i * 2 + 1] = tmp;//swap
			i = i * 2 + 1;// ���� ��� ����
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
