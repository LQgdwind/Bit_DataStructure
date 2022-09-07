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

LinkList createList(ElemType finish)	//finish：数据结束标记 
{
    ElemType x;
    NODE* newNode;
    LinkList first = new NODE;   // 建立头结点
    first->next = NULL;
    first->data = finish;
    cin >> x;	      			// 约定以finish结束连续输入
    while (x != finish)
    {
        newNode = new NODE;      // 建立新结点
        newNode->data = x;
        newNode->next = first->next; // ①
        first->next = newNode;       // ②
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
/* 原地逆转法
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

// 在cpp中，struct等同于class 如果私有数据成员含有指针 在没有重载运算符的情况下不要随意使用=
//同样的 构造函数也类似。

/* 新链表法
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