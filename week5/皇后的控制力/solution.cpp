#pragma GCC optimize(3,"Ofast","inline")   

#define re register

#include "bits/stdc++.h"

using namespace std;

int n, m;

bool strow[50],col[50], dg[50], udg[50];

bool control[50][50];

int res;
inline bool judge()
{
	bool flag = true;
	for (re int i = 1; i <= n; i++)
	{
		for (re int j = 1; j <= n; j++)
		{
			if (!(strow[i] || col[j] || dg[i + j] || udg[n + j - i]))
			{
				flag = false;
			}
		}
	}
	return flag;
}

inline void dfs(int row, int queen)
{
	if (queen == m)
	{
		if (judge())
		{
			res++;
			return;
		}
		else return;
	}
	if (row == n + 1)
	{
		return;
	}
	for (re int i = 1; i <= n; i++)
	{
		if (col[i] == false && dg[i + row] == false && udg[n + i - row] == false)
		{
			strow[row] = col[i] = dg[i + row] = udg[n + i - row] = true;
			dfs(row + 1, queen + 1);
			strow[row] = col[i] = dg[i + row] = udg[n + i - row] = false;
		}
	}
	dfs(row + 1, queen);
}
int main()
{
	cin >> n >> m;
	dfs(1, 0);
	cout << res << endl;
	return 0;
}