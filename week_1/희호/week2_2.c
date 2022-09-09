//
//  main.c
//  week1_2
//
//  Created by 정희호 on 2022/09/09.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
}NODE;

int Empty(NODE* root)
{
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return 0;
}
void init(NODE* root)
{
    root->left = NULL;
    root->right = NULL;
}

void findNode(NODE* root, NODE** p, int num)
{
    if (root == NULL)    return;
    if (root->data == num)    *p = root;
    findNode(root->left, p, num);
    findNode(root->right, p, num);
}
void makeTree(NODE* root, int n1, int n2, int n3)
{
    NODE* tmp;
    NODE* newnode1;
    NODE* newnode2;
    if (Empty(root) == 1)
    {
        root->data = n1;

        newnode1 = (NODE*)malloc(sizeof(NODE));
        newnode2 = (NODE*)malloc(sizeof(NODE));

        init(newnode1);
        init(newnode2);

        newnode1->data = n2;
        newnode2->data = n3;

        root->left = newnode1;
        root->right = newnode2;
    }

    else
    {
        tmp = (NODE*)malloc(sizeof(NODE));
        findNode(root, &tmp, n1);

        if (n2 != 0)
        {
            newnode1 = (NODE*)malloc(sizeof(NODE));
            init(newnode1);
            newnode1->data = n2;
            tmp->left = newnode1;
        }
        else tmp->left = NULL;

        if (n3 != 0)
        {
            newnode2 = (NODE*)malloc(sizeof(NODE));
            init(newnode2);
            newnode2->data = n3;
            tmp->right = newnode2;
        }
        else tmp->right = NULL;
    }
}

void printSearch(NODE* root, char a[100])
{
    int i = 0;
    while (a[i] != NULL)
    {
        printf(" %d", root->data);
        if (a[i] == 'R')    root = root->right;
        else root = root->left;
        i++;
    }
    printf(" %d\n", root->data);
}
int main()
{
    NODE* root = (NODE*)malloc(sizeof(NODE));
    int n1, n2, n3, N;
    char a[100];
    scanf("%d", &N);
    init(root);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &n1, &n2, &n3);
        makeTree(root, n1, n2, n3);
    }
    scanf("%d", &N);
    for (int j = 0; j < N; j++)
    {
        scanf("%s", a);
        printSearch(root, a);
    }
    free(root);
    return 0;
}
