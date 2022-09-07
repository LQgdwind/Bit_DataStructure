#define _CRT_SECURE_NO_WARNINGS  
#define loop(i,a,b) for(int i=a;i<=b;i++)  

#include "iostream"
#include "string"
#include "cstdio"

using namespace std;

int t;

int res = 0; 

typedef long long ll;

int sum[10010];

void yuchuli()
{
	sum[0] = 1;
	loop(i, 1, 50)
	{
		sum[i] = sum[i - 1] * 2;
	}
}

void countnum(int n,int m)
{
	int cnt = 0;
	while (true)
	{
		cnt++;
		n = n - sum[cnt] + 1;
		//cout << cnt << endl;
		if (n > 0)
		{
			res += sum[cnt - 1];
		}
		else break;
	}
	if (n == 0)
	{
		res += sum[cnt - 1];
		return;
	}
	else if (n < 0)
	{
		n = n + sum[cnt] - 1;
		if (n < cnt) return;
		else if (n == cnt)
		{
			res += 1;
			return;
		}
		else
		{
			res += 1;
			countnum(n - cnt, cnt);
		}
	}
}

int main()
{
	cin >> t;
	yuchuli();
	while (t--)
	{
		int n; int m;
		cin >> n >> m;
		m++;
		if (n < m)
		{
			cout << "0" << endl;
		}
		else if (n == m)
		{
			cout << "1" << endl;
		}
		else if (m < 24)
		{
			if (n >= sum[m] - 1)
			{
				cout << sum[m - 1] << endl;
			}
			else
			{
				n = n - m;  res = 1;
				countnum(n, m);
				cout << res << endl;
			}
		}
		else
		{
			n = n - m;  res = 1;
			countnum(n, m);
			cout << res << endl;
		}
	}
	return 0;
}