
//血的教训
//在写链表时千万不要用string
//因为string无法得出确切的sizeof 

#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "cstring"
#include "string"

using namespace std;

const int S = 0;
const int E = -1;

class listnode;
typedef listnode* list;

class listnode
{
public:
	char name[100];
	int id;
	listnode* next;
	listnode* pre;
};

class checklist
{
public:
	list head;
	list tail;
};

void init(checklist &l)
{
	l.head= (listnode*)malloc(sizeof(listnode));
	l.tail = (listnode*)malloc(sizeof(listnode));
	l.head->next = l.tail;
	l.head->pre = l.tail;
	l.tail->next = l.head;
	l.tail->pre = l.head;
	l.head->id = S;
	l.tail->id = E;
}

void list_emplace_back(checklist &l, int e,const char * n)
{
	list temp = (list)malloc(sizeof(listnode));
	strcpy(temp->name, n);
	temp->id = e;
	l.tail->pre->next = temp;
	temp->pre = l.tail->pre;
	temp->next = l.tail;
	l.tail->pre = temp;
}

bool list_find(checklist &l, int e, const char* n)
{
	list p = l.head;
	while (p->id != E)
	{
		p = p->next;
		if (p->id == e && strcmp(p->name,n) == 0 ) break;
	}
	if (p->id == E) return false;
	else return true;
}

int n, m;

int main()
{
	checklist l;
	init(l);
	cin >> n;
	loop(i,1,n)
	{
		int tempid;
		string tempname;
		cin >> tempid;
		getline(cin, tempname);
		list_emplace_back(l,tempid,tempname.c_str());
	}
	int cnt = 0;
	cin >> m;
	if (m == 0)
	{
		cout << "the LIST2 is NULL." << endl;
		return 0;
	}
	loop(i,1,m)
	{
		int tempid;
		string tempname;
		cin >> tempid;
		getline(cin, tempname);
		if (!list_find(l, tempid, tempname.c_str()))
		{
			cout << tempid << tempname << " " << "is not in LIST1." << endl;
		}
		else cnt++;
	}
	if (cnt == m) cout << "the records of LIST2 are all in the LIST1." << endl;
	return 0;
}