#include "bits/stdc++.h"
using std::cin; using std::cout; using std::min; using std::endl;
bool visit[2000];int dp[2000][3], leafmark[1505][1505];int n, s, t, k, r, cnt;
void dfs(int x)
{
	visit[x] = true;
	for (int i = 0; leafmark[x][i] != -1; i++)
		if (visit[leafmark[x][i]] == false) 
			dfs(leafmark[x][i]), dp[x][1] += dp[leafmark[x][i]][0], dp[x][0] += min(dp[leafmark[x][i]][0], dp[leafmark[x][i]][1]);
	dp[x][0]++;
}
int main() 
{
	while (cin>>n)
	{
		memset(dp, 0, sizeof(dp)),memset(visit, 0, sizeof(visit)),memset(leafmark, 0, sizeof(leafmark));
		for (int i = 0; i < n; i++)
		{
			scanf("%d:(%d)", &s, &t);
			if (!i) r = s;
			cnt = 0;
			for (int j = 0; j < t; j++)
				cin >> k, leafmark[s][cnt] = k, cnt++;
			leafmark[s][cnt] = -1;
		}
		dfs(r);int resul = min(dp[r][0], dp[r][1]); cout << resul << endl;
	}
	return 0;
}