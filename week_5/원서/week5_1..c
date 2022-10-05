#include <stdio.h>
#include <stdlib.h>
typedef struct NODE {
	int data;
	struct NODE *next;
}NODE;
NODE *merge(NODE *L1, NODE *L2);
NODE *partition(NODE *L, int k);
NODE *mergesort(NODE *L,int n);
void getNode(NODE **L);
void addNode(NODE *p, int data);
void print(NODE *p);
int main() {
	int n, input;
	NODE *L, *p;
	scanf("%d", &n);
	getNode(&L);
	p = L;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		addNode(p,input);
	}
	L = mergesort(L->next,n);//반환값 = 0ㅓㅄ0ㅓㅆ0ㅡㅁ

	print(L);
}
NODE *merge(NODE *L1, NODE *L2) {
	NODE *L,*p;
	if (L1->data <= L2->data) {//맨 첨값 헤드로 만들기 싫기 때문0ㅔ
	L = L1;
	L1 = L1->next;
		}
	else if (L1->data > L2->data) {
	L = L2;
	L2 = L2->next;
		}
	p = L;

	while (1) {
		if (L1 == NULL && L2 == NULL) break;
		else if (L1 == NULL) {
			L->next = L2;
			L2 = L2->next;
		}
		else if (L2 == NULL) {
			L->next = L1;
			L1 = L1->next;
		}
		else if (L1->data <= L2->data) {
			L->next = L1;
			L1 = L1->next;
		}
		else if ( L1->data > L2->data) {
			L->next = L2;
			L2 = L2->next;
		}
		L = L->next;
	}
	return p;
}
NODE *partition(NODE *L, int k) {//반으로 나누고 우측 값 리턴
	NODE *L1,*L2;
	L1 = L;
	for (int i = 1; i < k/2; i++) {//한번 해줘쓰므로
		L1 = L1->next;
	}
	L2 = L1->next;
	L1->next = NULL;
	return L2;
}
NODE *mergesort(NODE *L,int n) {
	NODE *L1, *L2;

	if (n == 1) return L;
	L1 = L;
	L2 = partition(L, n);//분할

	
	L1 = mergesort(L1, n / 2);

	L2 = mergesort(L2, (n+1)/ 2); //+1 해주는 까닭?

	return merge(L1, L2);
}
void getNode(NODE **L) {
	(*L) = (NODE *)malloc(sizeof(NODE));
	(*L)->next = NULL;
}
void addNode(NODE *p, int data) {
	NODE *q;
	getNode(&q);
	q->data = data;
	while (p->next != NULL) { p = p->next; }
	p->next = q;
}
void print(NODE*p) {
	 
	while (1) {
		if (p == NULL) break;

		printf(" %d", p->data);
		p = p->next;

	}
}