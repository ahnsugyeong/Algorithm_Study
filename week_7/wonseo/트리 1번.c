#include <stdio.h>
#include <stdlib.h>
typedef struct NODE {
	int key;
	struct NODE * l;
	struct NODE * r;
}NODE;
void findElement(NODE *R, int k,int* flag);
NODE * insertItem(NODE *R, int k);
void PreprintTree(NODE *T);
void getNode(NODE**p, int k);
NODE* deleteNode(NODE* root, int key);
NODE* minValueNode(NODE* root);

int main() {
	char input;
	int key,flag = 0;
	NODE *R;

	R = (NODE*)malloc(sizeof(NODE));

	R = NULL;

	while (1) {
		scanf("%c", &input);
		getchar();
		if (input == 'i') {
			scanf("%d", &key);
			getchar();
			R = insertItem(R, key);
		}
		else if (input == 'd') {
			scanf("%d", &key);
			getchar();
			findElement(R, key, &flag);
			if (flag == 0) printf("X");
			else
			R = deleteNode(R, key);
			flag = 0;

		}
		else if (input == 's') {
			scanf("%d", &key);
			getchar();
			findElement(R, key,&flag);
			if (flag == 0) printf("X");
			flag = 0;
		}
		else if (input == 'p') {
			PreprintTree(R);
		}
		else if (input == 'q') {
			break;
		}
	}
	printf("\n");
}


void getNode(NODE **p, int k) {
	(*p) = (NODE*)malloc(sizeof(NODE));
	(*p)->key = k;
	(*p)->l = NULL;
	(*p)->r = NULL;
}
NODE* minValueNode(NODE* root)
{
	NODE* current = root;
	while (current->l != NULL)
		current = current->l;
	return current;
}

void findElement(NODE *R, int k,int* flag) {
	NODE *p = R;
	if (p) {
		if (p->key == k) {
			*flag = 1;
			printf("%d", k);
			return;
		}
		 findElement(p->l, k,flag);
		 findElement(p->r, k,flag);
	}
}

NODE * insertItem(NODE *R, int k) {
	NODE *p;
	getNode(&p, k);

	if (R == NULL) {
		return p;
	}	
		if (k >= R->key) {
			R->r = insertItem(R->r, k);
		}
		else if (k < R->key) {
			R->l = insertItem(R->l, k);

		}
	
		return R;
}

NODE * deleteNode(NODE* R, int key)
{
	NODE * root = R;
	int cnt=0;
	if (root == NULL) {
		return root;
	}

	if (key < root->key)
		root->l = deleteNode(root->l, key);
	else if (key > root->key)
		root->r = deleteNode(root->r, key);
	else
	{
		if (root->l == NULL)
		{
			NODE* temp = root->r;
			free(root);
			return temp;
		}
		else if (root->r == NULL)
		{
			NODE* temp = root->l;
			free(root);
			return temp;
		}
		else
		{
			NODE* temp = minValueNode(root->r);
			root->key = temp->key;
			root->r = deleteNode(root->r, temp->key);
		}
	}
	return root;
}


void PreprintTree(NODE *T) {
	if (T == NULL) return;
	printf(" %d", T->key);
	PreprintTree(T->l);
	PreprintTree(T->r);
}

/*
i 9
i 2
i 15
i 1
i 7
i 11
i 5
i 8
i 3
i 4
d 2
*/

/*i 4
i 5
i 6
i 7
p
i 1
i 2
i 3
d 1
d 2
i 77
s 2
s 4
p
i 11*/

//parent를 만들고 삭제할 때 parent값 고려 X 50점 time limit.
//parent로 root까지 가는거 대신 재귀 씀.