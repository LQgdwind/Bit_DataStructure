//֮ǰд��һ������ջ��ֱ���ù�����
//by zlq

#pragma GCC optimize(3,"Ofast","inline")   

#define re register

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int n;
ll ans;
vector<ll> s;

ll w[100010];  //��¼ÿһ����Ч���εĿ��(�������ľ��α�ǰ��ľ��εͣ���ôǰ���������Ч���Σ�����ľ��ο���ۼ�)

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