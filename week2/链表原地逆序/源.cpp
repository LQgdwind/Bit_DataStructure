#define _CRT_SECURE_NO_WARNINGS

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>

using namespace std;

typedef int ElemType;
typedef struct node
{
    ElemType    data;
    struct node* next;
} NODE;
typedef NODE* LinkList;

void output(LinkList);
void change(int, int, NODE*);
LinkList createList(ElemType);
void inverse(LinkList);

LinkList createList(ElemType finish)	//finish�����ݽ������ 
{
    ElemType x;
    NODE* newNode;
    LinkList first = new NODE;   // ����ͷ���
    first->next = NULL;
    first->data = finish;
    cin >> x;	      			// Լ����finish������������
    while (x != finish)
    {
        newNode = new NODE;      // �����½��
        newNode->data = x;
        newNode->next = first->next; // ��
        first->next = newNode;       // ��
        cin >> x;
    }
    return first;
}

void output(LinkList head)
{
    cout << "List:";
    while (head->next != NULL)
    {
        cout << head->next->data << ",";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    LinkList head;

    head = createList(-1);
    output(head);
    inverse(head);
    output(head);
    return 0;
}
/* ԭ����ת��
void inverse(LinkList head)
{
    LinkList rhead = new NODE;
    head = head->next;
    rhead->data = head->data;
    rhead->next = head->next;
    LinkList prev = rhead;
    LinkList p = rhead;
    while (rhead ->next!= NULL)
    {
        p = rhead->next;
        rhead->next = prev;
        prev = rhead;
        rhead = p;
    }
    if (head)
    {
        head->data = rhead->data;
        head->next = rhead->next;
    }
}
*/

// ��cpp�У�struct��ͬ��class ���˽�����ݳ�Ա����ָ�� ��û�����������������²�Ҫ����ʹ��=
//ͬ���� ���캯��Ҳ���ơ�

/* ������
void inverse(NODE* head)
{
    NODE* rhead = new NODE;
    rhead->data = -1;
    rhead->next = NULL;
    NODE* p = head;
    NODE* newnode;
    while (p != NULL)
    {
        if (p->data != -1)
        {
            newnode = new NODE;
            newnode->data = p->data;
            newnode->next = rhead->next;
            rhead->next = newnode;
        }
            p = p->next;
    }
    if (head)
    {
        head->next = rhead->next;
        head->data = rhead->data;
    }
}
*/
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */