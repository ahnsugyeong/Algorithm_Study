#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int key;
	int height;
	struct NODE * l;
	struct NODE * r;
}NODE;


NODE * insertItem(NODE *R,int k);
NODE * Lrotation(NODE *R);
NODE * Rrotation(NODE *R);
int getBF(NODE*R);
int getHeight(NODE*R);
int maxx(int a, int b);

void PreprintTree(NODE* R);
void findelement(NODE* R,int key,int *flag);
int main() {
	char input;
	int key, flag = 0;
	NODE *R;

	R = (NODE*)malloc(sizeof(NODE));

	R = NULL;

	while (1) {
		scanf("%c", &input);
		getchar();
		if (input == 'i') {
			scanf("%d", &key);
			getchar();
			R = insertItem(R,key);
		}
		else if (input == 's') {
			scanf("%d", &key);
			getchar();
			findelement(R, key,&flag);
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
void PreprintTree(NODE* R) {
	if (R == NULL) return;
	printf(" %d", R->key);
	PreprintTree(R->l);
	PreprintTree(R->r);
}
void findelement(NODE*R, int key,int* flag) {
	if (R == NULL) {
		return;
	}
	if (key == R->key) {
		printf("%d", key);
		*flag = 1;
		return;
	}
	else if (key < R->key) findelement(R->l, key,flag);
	else findelement(R->r, key,flag);
}
NODE * insertItem(NODE* R,int k) {
	NODE * p;
	p = (NODE *)malloc(sizeof(NODE));
	p->l = NULL;
	p->r = NULL;
	p->key = k;
	//insert
	if (R == NULL) { 

		return p;
	}
	 if (R->key < k) {
		R->r = insertItem(R->r, k);
	}
	else if (R->key > k) {
		R->l = insertItem(R->l, k);
	}
	else return R;//같다면

	//height 새로고침

	int BF = getBF(R);//BF는 left 부트리, right부트리 height 차

	if (BF > 1) {//left 부트리가 클 때(L)
		if (k < R->l->key) {// input값 smaller -> left 로 들감.(LL)
			return Rrotation(R);
		}
		else {// input값 bigger -> right로 들감.(LR)
			R->l = Lrotation(R->l);
			return Rrotation(R);
		}
	}
	else if (BF < -1) {//right 부트리가 클 때(R)
		if (k < R->r->key) {// input값 smaller -> left 로 들감.(RL)
			R->r = Rrotation(R->r);
			return Lrotation(R);
			
		}
		else {// input값 bigger -> right로 들감.(RR)
			return Lrotation(R);
		}
	}

	return R;
}
NODE * Lrotation(NODE * R) {
	NODE *y = R->r;
	R->r = y->l; 
	y->l = R;
	return y;
}
NODE * Rrotation(NODE * R) {
	NODE *y = R->l;
	R->l = y->r;
	y->r = R;
	return y;
}

int getBF(NODE*R) {//left 부트리, right부트리 height 차
	if (R == NULL) return 0;

	return getHeight(R->l) - getHeight(R->r);
}

int getHeight(NODE*R) {
	int height=0;
	if (R != NULL) {
		height = 1 + maxx(getHeight(R->l),getHeight(R->r));
	}
	return height;
}
int maxx(int a, int b) {
	return (a > b) ? a : b;
}