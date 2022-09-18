#include <stdio.h>
int H[100] = {0}, n = 0;

void print() {
	for (int i = 1; i <= n; i++) { printf(" %d", H[i]); }
}
void upheap(int i) {
	int tmp;
	if (i == 1) return;
	if (H[i] < H[i / 2]) return;
	tmp = H[i];
	H[i] = H[i / 2];
	H[i / 2] = tmp;
	upheap(i/2);
}
void downheap(int i) {
	int tmp,bigger;
	if (H[i * 2] == 0 && H[i * 2 + 1] == 0) { return; }
	bigger = i * 2;
	if (i * 2 > n) return;
	if (H[i * 2] < H[i * 2 + 1]) bigger = i * 2 + 1;
	if (H[bigger] < H[i]) return;
	tmp = H[bigger];
	H[bigger] = H[i];
	H[i] = tmp;
	downheap(bigger);
}
int remov() {
	int root;
	root = H[1];
	H[1] = H[n];
	n--;
	downheap(1);
	return root;
}
void insert(int key) {
	n++;
	H[n] = key;
	upheap(n);
}


int main() {
	char input;
	int key;
	while (1) {
		scanf("%c", &input);

		if (input == 'i') { scanf("%d", &key); insert(key); printf("0");}
		else if (input == 'd') { printf("%d", remov()); }
		else if (input == 'p') { print(); }
		else if (input == 'q') { break; }
		printf("\n");
	}
}