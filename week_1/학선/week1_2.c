#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treenode {
	struct treenode* le;
	struct treenode* ri;
	int r;
}tree;
void init(tree* x)
{
	x->le = NULL;
	x->ri = NULL;
}
void gettree(tree* x)
{

	int root, left, right;
	scanf("%d %d %d", &root, &left, &right);
	x->r = root;
	if (left != 0) {
		tree* y = (tree*)malloc(sizeof(tree));
		init(y);
		y->r = left;
		x->le = y;
		gettree(y);
	}
	if (right != 0) {
		tree* y = (tree*)malloc(sizeof(tree));
		init(y);
		y->r = right;
		x->ri = y;
		gettree(y);
	}
}
void findtree(tree* x, char* str, int s, int cnt)
{
	if (cnt > s) return;
	printf(" %d", x->r);
	if (str[cnt] == 'R') findtree(x->ri, str, s, cnt + 1);
	if (str[cnt] == 'L') findtree(x->le, str, s, cnt + 1);

}
int main()
{
	tree* x;
	x = (tree*)malloc(sizeof(tree));
	init(x);
	int n, s;
	char str[101];
	scanf("%d", &n);
	gettree(x);
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		getchar();
		scanf("%s", str);
		findtree(x, str, strlen(str), 0);
		printf("\n");
	}
	return 0;
}
/*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
RLL
LL
LR
*/