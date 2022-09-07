#include "bits/stdc++.h"
#include "unordered_map"

using namespace std;

const int N = 1e5 + 10;
bool st[N];
int d[N];
class Edge
{
public:
	int e, ne, w;
}edge[N];
int h[N], idx;

inline void add(int a, int b, int c)
{
	edge[idx].e = b;
	edge[idx].ne = h[a];
	edge[idx].w = c;
	h[a] = idx++;
}

int n, m, yuan;
char s;

unordered_map <char, int>hashm;

inline void init()
{
	for (int i = 0; i <= 25; i++)
		hashm.insert({ 'a' + i, i });
	for (int i = 26; i <= 51; i++)
		hashm.insert({ 'A' + i - 26, i });
	memset(h, -1, sizeof(h));
	memset(d, 0x3f, sizeof(d));
}


void spfa()
{
	queue<int> q;
	q.push(yuan);
	st[yuan] = true;
	d[yuan] = 0;
	while (q.size() != 0)
	{
		int x = q.front();
		q.pop();
		st[x] = false;
		for (int i = h[x]; i != -1; i = edge[i].ne)
		{
			int y = edge[i].e;
			if (d[y] > d[x] + edge[i].w)//防止成环，不能直接求Min
			{
				d[y] = d[x] + edge[i].w;
				if (!st[y])
				{
					q.push(y);
					st[y] = true;
				}
			}
		}
	}
}
int main()
{
	init();
	scanf("%d,%d,%c", &n, &m, &s);
	cin.get();
	yuan = hashm[s];
	while (m--)
	{
		char s1, s2;
		int a, b, c;
		scanf("<%c,%c,%d>", &s1, &s2, &c);
		cin.get();
		a = hashm[s1], b = hashm[s2];
		add(a, b, c);
	}
	spfa();
	for (int i = 0; i < n; i++)
	{
		cout << (char)('a' + i) << ":" << d[i] << endl;
	}
}