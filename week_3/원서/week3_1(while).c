#include <stdio.h>
int H[101] = { 0 }, n = 0;
void print() {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
}
void upheap(int i) {
	int tmp;
	while (1) {//��Ʈ or �� �۰ų� ������ break
		if (i == 1)break;
		else if (H[i] <= H[i / 2]) break;
		tmp = H[i];
		H[i] = H[i / 2];
		H[i / 2] = tmp;//swap
		i = i / 2;// ���� ��� ����	

	}
}

void downheap(int i) {
	int tmp;
	while (1) {//�ڽİ��� �� Ŭ����
		if (H[i] > H[i * 2] && H[i] > H[i * 2 + 1]) break;
		else if (i * 2 > n) break;
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

void in(int key) {
	n += 1;
	H[n] = key;
	upheap(n);
	printf("0");
}
int remov() {
	int key;
	key = H[1];
	H[1] = H[n];
	n -= 1;
	downheap(1);
	return key;
}


int main() {
	char input;
	int key;
	while (1) {
		scanf("%c", &input);
		if (input == 'i') {
			scanf("%d", &key);
			in(key);
		}
		else if (input == 'd') { printf("%d", remov()); }
		else if (input == 'p') { print(); }
		else if (input == 'q') { break; }
		printf("\n");
	}
}
/*
i 5
i 15
i 10
i 20
i 30
i 25
p
d
i 31
i 29
d
p
q
*/