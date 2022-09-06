//
//  main.c
//  prac
//
//  Created by 정희호 on 2022/09/06.
//

#include<stdio.h>
#include<stdlib.h>
//
//각 노드에 저장되는 정보
typedef struct _node
{
    char elem;  //원소
    struct _node* next; //이전 노드를 가리키는 링크
    struct _node* prev; //다음 노드를 가리키는 링크
} Node;

Node* p;
//헤더 및 트레일러 노드
typedef struct _LinkedList
{
    Node* head;
    Node* tail;
    int NumOfData;
}list;

//이중연결리스트 초기화
void ListInit(list* plist)
{
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));
    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;
    plist->NumOfData = 0;
}

//plist 의 순위 r에 위치한 원소를 반환
void get(list* plist, int rank)
{
    p = plist->head;
    if (rank > plist->NumOfData || rank < 1)
    {
        printf("invalid position\n");
        return;
    }
    for (int i = 0; i < rank; i++)
        p = p->next;
    printf("%c\n", p->elem);
}
//plist의 순위 rank에 원소 e를 추가한다.
void add(list* plist, int rank, char element)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (rank - 1 > plist->NumOfData || rank < 1)
    {
        printf("invalid position\n");
        return;
    }
    p = plist->head;
    for (int i = 0; i < rank; i++)
        p = p->next;
    newNode->elem = element;
    newNode->prev = p->prev;
    newNode->next = p;
    (newNode->prev)->next = newNode;
    p->prev = newNode;

    (plist->NumOfData)++;
}
//plist의 순위 rank에 위치한 원소를 삭제한다.
void del(list* plist, int rank)
{
    if (rank > plist->NumOfData || rank < 1)
    {
        printf("invalid position\n");
        return;
    }
    p = plist->head;

    for (int i = 0; i < rank; i++)
        p = p->next;

    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    free(p);
    (plist->NumOfData)--;
}

void print(list* list)
{
    if ((list->NumOfData) == 0)
        return;

    p = list->head;
    for (int i = 0; i < list->NumOfData; i++)
    {
        p = p->next;
        printf("%c", p->elem);
    }
    printf("\n");
}

int main()
{
    list list;
    int n, k;
    char c, c2;
    ListInit(&list);
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf(" %c", &c);
        switch(c){
            case 'A':
                scanf("%d %c",&k, &c2);
                add(&list, k, c2);
                break;
            case 'P':
                print(&list);
                break;
            case 'D':
                scanf("%d", &k);
                del(&list, k);
                break;
            case 'G':
                scanf(" %d", &k);
                get(&list, k);
                break;
                
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        scanf(" %c", &c);
        if (c == 'P')
        {
            Print(&list);
            continue;
        }

        if (c == 'A')
        {
            scanf("%d %c", &k, &c2);
            add(&list, k, c2);
            continue;
        }

        else if (c == 'D')
        {
            scanf("%d", &k);
            del(&list, k);
            continue;
        }
        else if (c == 'G')
        {
            scanf(" %d", &k);
            Get(&list, k);
            continue;
        }
    }*/
    return 0;
}
