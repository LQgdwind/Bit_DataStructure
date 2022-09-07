#pragma GCC optimize(3,"Ofast","inline")
#define loop(i,a,b) for(long long i=a;i<=b;i++)  
#include "bits/stdc++.h"

using namespace std;

typedef long double ld;
typedef pair<double, double> PII;

const int N = 1e5 + 10;
PII p[N], q[N];
//typedef vector<PII>::iterator Iter;

long long n;

inline bool cmp1(PII x, PII y)
{
	return x.first < y.first;
}
inline bool cmp2(PII x, PII y)
{
	return x.second < y.second;
}

inline double getdistance(PII x, PII y)
{
	double temp = sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
	return temp;
}

inline void calculate(int l, int r, double& d)
{
	if (r - l <= 1)
	{
		return;
	}
	int mid = l + (r - l) / 2;
	double midx = p[mid].first;
	calculate(l, mid, d);
	calculate(mid, r, d);
	inplace_merge(p + l, p + mid, p + r, cmp2);
	int num = 0;
	for (int i = l; i != r; i++)
	{
		if (midx >= p[i].first - d && midx <= d + p[i].first)
		{
			q[num++] = p[i];
		}
	}
	for (int i = 0, j = 0; i != num; i++)
	{
		while (j != num && q[j].second <= q[i].second + d)
			j++;
		for (int k = i + 1; k != j; k++)
			d = min(d, getdistance(q[i], q[k]));
	}
}

int main()
{
	//bool read = freopen("1.in", "r+", stdin);
	//bool write = freopen("1.out", "a+", stdout);
	while (scanf("%d",&n) && n != 0)
	{
		loop(i, 0, n - 1)
		{
			scanf("%lf", &p[i].first);
			scanf("%lf", &p[i].second);
		}
		sort(p, p + n, cmp1);
		double d = 1e18;
		calculate(0, n, d);
		d = d / 2.0;
		printf("%.2f\n", d);
	}
	return 0;
}
