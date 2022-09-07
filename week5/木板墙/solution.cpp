//之前写过一道单调栈，直接拿过来了
//by zlq

#pragma GCC optimize(3,"Ofast","inline")   

#define re register

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int n;
ll ans;
vector<ll> s;

ll w[100010];  //记录每一个有效矩形的宽度(如果后面的矩形比前面的矩形低，那么前面矩形是无效矩形，后面的矩形宽度累加)

int main()
{
	while (cin >> n && n)
	{
		ans = 0;
		n++;
		int cnt = 0;
		memset(w, 0, sizeof w);
		while (n--)
		{
			ll h;
			if (n != 0) cin >> h;
			else h = 0;
			if (s.empty() || h >= s.back())
			{
				s.push_back(h);
				w[++cnt] = 1;
			}
			else
			{
				int width = 0;
				while (!s.empty() && h < s.back())
				{
					int temp = s.back();
					width += w[cnt--];
					s.pop_back();
					ans = max(ans, (ll)width * temp);
				}
				s.push_back(h);
				w[++cnt] = width + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}