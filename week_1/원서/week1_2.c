#include <stdio.h>
#include <string.h>
typedef struct NODE {
	int elem;
	struct NODE* left;
	struct NODE* right;
}NODE;
void getNode(NODE** p) {
	*p = (NODE*)malloc(sizeof(NODE));
	(*p)->left = NULL;
	(*p)->right = NULL;
}
void input(NODE *root, int n) {
	if (n == 0) return 0;
	NODE *L,*R;
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	root->elem = a;
	if (b == 0 && c == 0) {
		root->left = NULL;
		root->right = NULL;
		return 0;
	}
	else if (b == 0) {
		getNode(&R);
		root->right = R;
		root->left = NULL;
		R->elem = c;
		input(root->right, n - 1);
	}
	else if (c == 0) {
		getNode(&L);
		root->left = L;
		root->right = NULL;
		L->elem = b;
		input(root->left, n - 1);

	}
	else {
		getNode(&L); getNode(&R);
		root->right = R;
		R->elem = c;
		root->left = L;
		L->elem = b;
		input(root->left, n - 1);
		input(root->right, n - 1);

	}
}

int main() {
	int N,s;
	char str[101];
	NODE *tree,*T;
	getNode(&tree);
	getNode(&T);
	scanf("%d", &N);
	input(tree, N);
	scanf("%d",&s);
	for (int i = 0; i < s; i++) {
		T = tree;
		scanf("%s", str);
		printf(" %d", T->elem);
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == 'R') { T = T->right; }
			if (str[j] == 'L') { T = T->left; }
			printf(" %d", T->elem);
		}
		printf("\n");
	}
}