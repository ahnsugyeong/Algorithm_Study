#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *getNode() {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *findData(Node *p, int data) {  //특정 data값을 가진 노드 탐색하기
    if (p != NULL) {
        if (p->data == data) return p;
        Node *q = NULL;
        q = findData(p->left, data);
        if (q != NULL) return q;
        q = findData(p->right, data);
        if (q != NULL) return q;
    }
    return NULL;
}

int main() {
    Node *root = getNode();
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int data, L, R;
        scanf("%d %d %d", &data, &L, &R);

        if (i == 0) {
            root->data = data;
            root->left = getNode();
            root->right = getNode();

            if (L != 0) root->left->data = L;
            if (R != 0) root->right->data = R;
        } else {
            Node *p = findData(root, data);

            p->data = data;
            p->left = getNode();
            p->right = getNode();

            if (L != 0) p->left->data = L;
            if (R != 0) p->right->data = R;
        }
    }

    int S;
    scanf("%d", &S);
    getchar();

    for (int i = 0; i < S; i++) {
        Node *p = root;
        char str[101];
        scanf("%s", str);

        for (int j = 0; j < strlen(str); j++) {
            printf(" %d", p->data);
            if (str[j] == 'L') {
                p = p->left;
            }
            if (str[j] == 'R') {
                p = p->right;
            }
        }
        printf(" %d\n", p->data);
    }

    return 0;
}