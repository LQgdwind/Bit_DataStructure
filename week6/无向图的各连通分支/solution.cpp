#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
int st[N];

class Edge
{
public:
	int e, ne;
}edge[N];

int h[N], idx;
inline void add(int a, int b)
{
	edge[idx].e = b;
	edge[idx].ne = h[a];
	h[a] = idx++;
}

int n;

vector <int>v;
inline void bfs(int num)
{
	queue<int>q;
	q.push(num);
	st[num] = true;
	cout << num;
	while (q.size() > 0)
	{
		int x = q.front();
		q.pop();
		v.clear();
		for (int i = h[x]; i != -1; i = edge[i].ne)
		{
			int y = edge[i].e;
			if (!st[y])
			{
				v.push_back(y);
				q.push(y);
				st[y] = true;
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			cout << "-" << v[i];
		}
	}
}

int main()
{
	memset(h, -1, sizeof(h));
	cin >> n;
	while (true)
	{
		int a, b;
		cin >> a;
		if (a == -1) break;
		cin >> b;
		add(a, b), add(b, a);
	}
	for (int i = 0; i < n; i++)
	{
		if (!st[i])
		{
			bfs(i);
			cout.put('\n');
		}
	}
	return 0;
}