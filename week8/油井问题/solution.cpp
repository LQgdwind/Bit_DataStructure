#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
ll a[N], inpu; int inputcnt, mid;
int lumutopatition(int l,int r)
{
	ll p = a[l];int s = l;
	for (int i = l + 1; i <= r; i++)
		if (a[i] < p) s++, swap(a[i], a[s]);
	swap(a[s], a[l]);
	return s;
}
ll quickselect(int l, int r, int k)
{
	int s = lumutopatition(l, r);
	if (s == l + k - 1) return a[s];
	else if (s < l + k - 1) quickselect(s + 1, r, l + k - s - 1);
	else if (s > l + k - 1) quickselect(l, s - 1, k);
}
int main()
{
	while (scanf("%lld,%lld", &inpu, &a[inputcnt])!=EOF)
		inputcnt++;
	if (inputcnt & 1) mid = (inputcnt >> 1) + 1;
	else mid = inputcnt >> 1;
	ll res = quickselect(0, inputcnt - 1, mid);printf("%lld\n", res);
	return 0;
}