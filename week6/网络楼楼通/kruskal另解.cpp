#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
const int M = N << 1;

int p[N];
class Edge
{
public:
	int a, b, w;
	friend bool operator<(const Edge& , const Edge& );
}edge[M];

bool operator<(const Edge& a, const Edge& b)
{
	return (a.w < b.w);
}

int n, m;

int find(int x)//路径压缩
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

inline void unioninit()
{
	for (int i = 0; i <= n; i++)
	{
		p[i] = i;
	}
}

inline int kruskal()
{
	sort(edge, edge + m);
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a = edge[i].a;
		int b = edge[i].b;
		if (find(a) != find(b))
		{
			p[p[b]] = p[a]; //并查集的合并集合操作
			cnt++;
			ans += edge[i].w;
		}
		if (cnt == n - 1) break;
	}
	if (cnt != n - 1) return -1;
	else return ans;
}
int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i].a = a;
		edge[i].b = b;
		edge[i].w = c;
	}
	unioninit();
	cout << kruskal() << endl;
}