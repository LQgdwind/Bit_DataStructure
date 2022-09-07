#pragma GCC optimize(3,"Ofast","inline") 

#define loop(i,a,b) for(int i=a;i<=b;i++)
#define re register

#include "bits/stdc++.h"

using namespace std;

const int N = 15;
int p[N][N], q[N][N]; int n;
bool stmale[N], stfemale[N];
int maxmale[N];
int compared[N][N];

int ans = 0;

inline int read() 
{
    int X = 0, w = 1; char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') w = -1; c = getchar(); }
    while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
    return X * w;
}

void dfs(int male,int tempmax)
{
    if (male == n + 1)
    {
        ans = max(ans, tempmax);
        return;
    }
    int mark = tempmax;
    for (re int i = male; i <= n; i++)
    {
        mark += maxmale[i];
    }
    if (mark <= ans) return;
    for (re int j = 1; j <= n; j++)
    {
        if (stfemale[j])continue;
        stfemale[j] = true;
        dfs(male + 1, tempmax + p[male][j] * q[j][male]);
        stfemale[j] = false;
    }
}

int main()
{
    n = read();
    for (re int i = 1; i <= n; i++)
    {
        for (re int j = 1; j <= n; j++)
        {
            p[i][j] = read();
        }
    }
    for (re int i = 1; i <= n; i++)
    {
        for (re int j = 1; j <= n; j++)
        {
            q[i][j] = read();
        }
    }
    for (re int i = 1; i <= n; i++)
    {
        for (re int j = 1; j <= n; j++)
        {
            compared[i][j] = p[i][j] * q[j][i];
            maxmale[i] = max(maxmale[i], compared[i][j]);
        }
    }
    dfs(1, 0);
    cout << ans << endl;
	return 0;
}