#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char elem;
    struct Node *next;
    struct Node *prev;
} Node;

Node *getNode() {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void initialize(Node **header, Node **trailer) {
    *header = getNode();
    *trailer = getNode();
    (*header)->next = *trailer;
    (*trailer)->prev = *header;
}

void add(Node *header, int r, char e) {
    Node *newNode = getNode();
    newNode->elem = e;

    Node *p = header;
    while (r--) p = p->next;

    newNode->prev = p->prev;
    newNode->next = p;
    p->prev->next = newNode;
    p->prev = newNode;
}

void delete(Node *header, int r) {
    Node *p = header;
    while (r--) p = p->next;
    Node *tmp = p;

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(tmp);
}

char get(Node *header, int r) {
    Node *p = header;
    while (r--) p = p->next;
    return p->elem;
}

void print(Node *header, Node *trailer) {
    Node *p = header->next;
    while (p != trailer) {
        printf("%c", p->elem);
        p = p->next;
    }
    printf("\n");
}

void printInvalidPosition() {
    printf("invalid position\n");
}

int main() {
    Node *header;
    Node *trailer;
    initialize(&header, &trailer);

    int N;
    scanf("%d", &N);
    getchar();

    char order;
    int r;
    char e;
    int size = 0;
    for (int i = 0; i < N; i++) {
        scanf("%c", &order);
        if (order == 'A') {     // add
            scanf("%d %c", &r, &e);
            if (size + 1 < r) printInvalidPosition();
            else {
                add(header, r, e);
                size++;
            }
        } else if (order == 'D') {    // delete
            scanf("%d", &r);
            if (size < r) printInvalidPosition();
            else {
                delete(header, r);
                size--;
            }
        } else if (order == 'G') {    // get
            scanf("%d", &r);
            if (size < r) printInvalidPosition();
            else {
                printf("%c\n", get(header, r));
            }
        } else if (order == 'P') {    // print
            print(header, trailer);
        }
        getchar();
    }


    return 0;
}