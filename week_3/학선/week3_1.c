#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int H[100], n = 0;
void upHeap(int i)//�ؿ������� ������ ���԰� ��Ʈ
{
	if (i == 1) return;
	if (H[i] <= H[i / 2]) return;
	int tmp = H[i];
	H[i] = H[i / 2];
	H[i / 2] = tmp;
	upHeap(i / 2);
}
void downHeap(int i)//���������� ������ ������ ��Ʈ
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
	downHeap(si);
}

void insertItem(int key)//���� ����
{
	n++;
	H[n] = key;
	upHeap(n);	
	printf("0\n");
}
int removeMax()//�����κ��� ��ƮŰ�� ����
{
	int rkey = H[1];
	H[1] = H[n];
	n--;
	downHeap(1);
	return rkey;
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
	char ch;
	int key;
	scanf("%c %d", &ch, &key);
	insertItem(key);
	while (1) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'i') {
			scanf("%d", &key);
			insertItem(key);
		}
		else if (ch == 'd' && n > 0) {
			printf("%d\n", removeMax());
		}
		else if (ch == 'p' && n > 0) printHeap();
		else if (ch == 'q') break;
	}
	return 0;
}
