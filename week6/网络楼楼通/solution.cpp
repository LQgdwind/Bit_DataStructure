#include "bits/stdc++.h"
using namespace std;

const int M = 1e5 + 10;
typedef pair<int, int> PII;
int n, m;
int d[M];
bool st[M];

class Edge
{
public:
	int e, ne, w;
}edge[M];

int h[M], idx;

inline void add(int a, int b, int c)
{
	edge[idx].e = b;
	edge[idx].ne = h[a];
	edge[idx].w = c;
	h[a] = idx++;
}

inline int prim()
{
	memset(d, 0x3f, sizeof(d));
	d[1] = 0;
	priority_queue <PII, vector<PII>, greater<PII> >q;
	q.push({ 0,1 });
	int res = 0;
	int cnt = 0;
	while (q.size() > 0)
	{
		PII x = q.top();
		q.pop();
		if (st[x.second]) continue;
		st[x.second] = true, cnt++;
		res += x.first;
		for (int i = h[x.second]; i != -1; i = edge[i].ne)
		{
			int y = edge[i].e;
			if (!st[y])
			{
				if (d[y] > edge[i].w)//不要用min来松弛，防止一大堆没有更新的无效点进入队列增加时间复杂度
				{
					d[y] = edge[i].w;
					q.push({ d[y], y });
				}
			}
		}
	}
	if (cnt < n) return -1;
	return res;
}

int main()
{
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	cout << prim() << endl;
	return 0;
}