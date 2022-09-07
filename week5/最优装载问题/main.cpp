//背包的解法 本来因为要记录过程（方案数依赖的背包板子
//但没有想到乐学屑的要命 1e8的int数组开不出来dp[1e2][1e6]直接tle无结果
//只好滚回去改我自己的一维01背包的板子

//by 郑乐祺
#pragma GCC optimize(3,"Ofast","inline")   

#include "bits/stdc++.h"

using namespace std;
const int N = 1e6+10;

int w[N], n, V, f[N];
vector<int> ans[N];

int main()
{
    cin >> V >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = V; j >= w[i]; j--)
        {
            if (f[j] < f[j - w[i]] + w[i])
            {
                ans[j] = ans[j - w[i]];     //复制方案
                ans[j].push_back(i);    //更新方案
                f[j] = f[j - w[i]] + w[i];
            }
            else if (f[j] == f[j - w[i]] + w[i])
            {
                vector<int> b = ans[j - w[i]]; b.push_back(i);
                if (b < ans[j])  ans[j] = b; //更新方案
                //使用vector自带的字典序运算符重载
            }
        }
    cout << f[V] << endl;
    for (int i = 0; i < ans[V].size(); i++)    //输出方案
    {
        cout << ans[V][i] << ' ';
    }
    cout.put('\n');
    return 0;
}
