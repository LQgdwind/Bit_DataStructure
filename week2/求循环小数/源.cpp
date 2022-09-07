#define _CRT_SECURE_NO_WARNINGS
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>  
#include <stdlib.h>  
typedef struct node
{
	int         data;
	struct node* next;
} NODE;

NODE* find(NODE*, int*);
void outputring(NODE*);
void change(int, int, NODE*);
void outputring(NODE* pring)
{
	NODE* p;
	p = pring;
	if (p == NULL)
		printf("NULL");
	else
		do {
			printf("%d", p->data);
			p = p->next;
		} while (p != pring);
		printf("\n");
		return;
}

int main()
{
	int n, m;
	NODE* head, * pring;

	scanf("%d%d", &n, &m);
	head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	head->data = -1;

	change(n, m, head);
	pring = find(head, &n);
	printf("ring=%d\n", n);
	outputring(pring);

	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
int cnt;
int length;
bool st;
void change(int n, int m, NODE* head)
{
	int xiaoshu[11011];
	int yushu[11011];
	int mymod = n % m;
	cnt = 0;
	length = 0;
	for (int i = 1; i <= 11009; i++)
	{
		xiaoshu[i] = 0;
		yushu[i] = 0;
	}
	for (int i = 1; i <= 11009; i++)
	{
		xiaoshu[i] = (mymod * 10) / m;
		yushu[i] = (mymod * 10) % m;
		mymod = (mymod * 10) % m;
		for (int j = 1; j < i; j++)
		{
			if (xiaoshu[i] == xiaoshu[j] && yushu[i] == yushu[j])
			{
				cnt = j;
				length = i - j;
				break;
			}
		}
		if (cnt != 0) break;
	}
	st = false;
	if(length==1&&xiaoshu[cnt]==0) st = true;
	if (!st)
	{
		NODE* p1 = head;
		NODE* p2 = head;
		for (int i = cnt + length - 1; i >= 1; i--)
		{
			p1 = (NODE*)malloc(sizeof(NODE));
			p1->data = xiaoshu[i];
			p1->next = head->next;
			head->next = p1;
		}
		for (int i = 1; i <= cnt; i++)
		{
			p2 = p2->next;
		}
		p1 = head;
		for (int i = 1; i < cnt + length; i++)
		{
			p1 = p1->next;
		}
		p1->next = p2;
	}
	else
	{
		NODE* p1 = head;
		for (int i = cnt  - 1; i >= 1; i--)
		{
			p1 = (NODE*)malloc(sizeof(NODE));
			p1->data = xiaoshu[i];
			p1->next = head->next;
			head->next = p1;
		}
	}
}

NODE* find(NODE* head, int* n)
{
	if (st)
	{
		*n = 0;
		return NULL;
	}
	NODE* p = head;
	for (int i = 1; i <= cnt; i++)
	{
		if(head)
		p=p->next;
	}
	*n = length;
	return p;
}