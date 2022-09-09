
#include<stdio.h>
#pragma warning(disable:4996)
typedef struct ListNode {
	char data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

void addNodeBefore(ListNode* ori, char ele)
{
	ListNode* q = (ListNode*)malloc(sizeof(ListNode));
	q->data = ele;
	q->prev = ori->prev;
	q->next = ori;
	(ori->prev)->next = q;
	ori->prev = q;
}
void add(ListNode* x, int idx, char ele)
{
	ListNode* p;
	p = x;
	for (int i = 0; i < idx; i++)
	{
		p = p->next;
	}
	//여기부턴 addNodeBefore함수
	addNodeBefore(p, ele);

}
void deleteNode(ListNode* ori)
{
	(ori->prev)->next = ori->next;
	(ori->next)->prev = ori->prev;
}
void delete(ListNode* x, int idx)
{
	ListNode* p;
	p = x;

	for (int i = 0; i < idx; i++)
	{
		p = p->next;
	}
	deleteNode(p);
}

void get(ListNode* x, int idx)
{

	ListNode* p;
	p = x;
	for (int i = 1; i <= idx; i++)
	{
		p = p->next;
	}
	printf("%c\n", p->data);
}

int main()
{
	int n, idx;
	int sum = 0;

	ListNode* H = (ListNode*)malloc(sizeof(ListNode));
	ListNode* T = (ListNode*)malloc(sizeof(ListNode));
	H->next = T;
	T->prev = H;
	scanf("%d", &n);

	char ch, ele;
	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &ch);
		if (ch == 'A')
		{
			getchar();
			scanf("%d", &idx);
			getchar();
			scanf("%c", &ele);
			if (idx > sum + 1)
			{
				printf("invalid position\n");
			}
			else
			{
				add(H, idx, ele);
				sum += 1;
			}
		}
		else if (ch == 'D')
		{
			scanf("%d", &idx);
			if (idx > sum)
			{
				printf("invalid position\n");
			}
			else if (idx > 0)
			{
				delete(H, idx);
				sum -= 1;
			}
		}
		else if (ch == 'G')
		{
			scanf("%d", &idx);
			if (idx >= sum + 1)
			{
				printf("invalid position\n");
			}
			else if (idx > 0)
				get(H, idx);
		}
		else if (ch == 'P')
		{
			ListNode* p = (ListNode*)malloc(sizeof(ListNode));
			p = H->next;
			while (p != T)
			{
				printf("%c", p->data);
				p = p->next;
			}
			printf("\n");
		}
	}


}