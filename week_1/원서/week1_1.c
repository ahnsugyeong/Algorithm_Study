#include <stdio.h>
typedef struct NODE {
	char elem;
	struct NODE* prev;
	struct NODE* next;
}NODE;
void getNode(NODE** p) {
	*p = (NODE*)malloc(sizeof(NODE));
	(*p)->next = NULL;
	(*p)->prev = NULL;
}


void add(NODE * list, int r, char e) {
	NODE* p, *q = list;
	getNode(&p);
	p->elem = e;
	for (int i = 0; i < r; i++) {
		q = q->next;
		if (q == NULL) {
			printf("invalid position");
			return 0;
		}
	}
	p->prev = q->prev;
	p->next = q;
	q->prev->next = p;
	q->prev = p;

}
void delete(NODE*list, int r) {
	NODE* p = list;
	for (int i = 0; i < r; i++) {
		p = p->next;
		if (p->next == NULL) {
			printf("invalid position");
			return 0;
		}
	}

	p->prev->next = p->next;
	p->next->prev = p->prev;
}
void get(NODE* list, int r) {
	NODE* p = list;
	for (int i = 0; i < r; i++) {
		p = p->next;
		if (p->next == NULL) {
			printf("invalid position");
			return 0;
		}
	}

	printf("%c", p->elem);
}

void print(NODE* list) {
	NODE* p = list;
	p = p->next;
	while (p->next != NULL) {
		printf("%c", p->elem);
		p = p->next;
	}
}

int main() {
	NODE* list = NULL, *T = NULL;
	char sign, ch;
	int N, gr;
	scanf("%d", &N);
	getchar();
	getNode(&list);
	getNode(&T);
	list->elem = '\0';
	T->elem = '\0';

	list->next = T;
	T->prev = list;
	for (int i = 0; i < N; i++) {
		scanf("%c", &sign);
		getchar();
		if (sign == 'A') {
			scanf("%d %c", &gr, &ch);
			add(list, gr, ch);
			getchar();
		}
		else if (sign == 'D') {
			scanf("%d", &gr);
			delete(list, gr);
			getchar();
		}
		else if (sign == 'G') {
			scanf("%d", &gr);
			getchar();
			get(list, gr);
		}
		else if (sign == 'P') { print(list); }
		printf("\n");
	}
}
/*
9
A 1 D
A 2 a
A 3 y
D 1

P
G 3
A 1 S
P
G 3
*/
