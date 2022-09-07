#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
class Edge
{
public:
	int e, ne;
}edge[N];
int h[N]; int idx = 0;

char node[N]; int nodecnt = 0;

inline void add(int a, int b)
{
	edge[idx].e = b;
	edge[idx].ne = h[a];
	h[a] = idx++;
}
bool st[N];
inline void bfs(int num)
{
	queue<int>q;
	q.push(num);
	st[num] = true;
	cout << node[num];
	while (q.size() > 0)
	{
		int x = q.front();
		q.pop();
		for (int i = h[x]; i != -1; i = edge[i].ne)
		{
			int y = edge[i].e;
			if (!st[y])
			{
				st[y] = true;
				q.push(y);
				cout << node[y];
			}
		}
	}
}

int main()
{
	memset(h, -1, sizeof(h));
	char op = '0';
	while (op != '*')
	{
		cin.get(op);
		if (op >= 'a' && op <= 'z')
		{
			node[nodecnt]= op;
			nodecnt++;
		}
	}
	cin.get();
	nodecnt--;
	string temp;
	while (true)
	{
		getline(cin, temp);
		if (temp[0] == '-') break;
		int a = temp[0] - '0';
		int b = temp[2] - '0';
		bool judge = false;
		for (int i = h[a]; i != -1; i = edge[i].ne)
		{
			int y = edge[i].e;
			if (b == y) 
			{
				judge = true;
				break;
			}
		}
		if (judge) continue;
		add(a, b), add(b, a);
	}
	cout << "the ALGraph is" << endl;
	for (int x = 0; x <= nodecnt; x++)
	{
		cout << node[x];
		memset(st, 0, sizeof(st));
		st[x] = true;
		for (int i = h[x]; i != -1; i = edge[i].ne)
		{
			int y = edge[i].e;
			if (!st[y])
			{
				cout << " " << y;
				st[y] = true;
			}
		}
		cout.put('\n');
	}
	cout << "the Breadth-First-Seacrh list:";
	memset(st, 0, sizeof(st));
	for (int i = 0; i <= nodecnt; i++)
	{
		if (!st[i])
		{
			bfs(i);
		}
	}
	cout.put('\n');
	return 0;
}