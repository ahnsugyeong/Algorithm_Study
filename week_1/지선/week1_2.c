#include <stdio.h>
#pragma warning(disable:4996)
typedef struct Tree {
	int data;
	struct Tree* left, *right;
}Tree;

void traversal(Tree *node, char *str)
{
	printf(" %d", node->data);
	if (*str)
	{
		if (*str == 'R')
		{
			traversal(node->right, str + 1);
		}
		else if (*str == 'L')
		{
			traversal(node->left, str + 1);
		}
	}
}
Tree* getnode()
{
	Tree* p = malloc(sizeof(Tree));
	p->left = NULL;
	p->right = NULL;
}

void getLeft(Tree** root, Tree* left)
{
	(*root)->left = left;
}
void getRight(Tree** root, Tree* right)
{
	(*root)->right = right;
}
void addTree(Tree** root)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	(*root)->data = a;
	if (b != 0)
	{
		Tree* left = getnode();
		getLeft(root, left);
		addTree(&left);
	}
	if (c != 0)
	{
		Tree* right = getnode();
		getRight(root, right);
		addTree(&right);
	}
}

int main()
{
	int n;
	int a, b, c;
	Tree *root = getnode();

	scanf("%d", &n);
	addTree(&root);

	char str[101];
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", str);
		traversal(root, str);
		printf("\n");
	}
}