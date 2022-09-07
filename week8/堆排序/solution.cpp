#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;int h[N]; int n;
void heapdown(int i)
{
	int k = i; int v = h[k]; bool heap = false;
	while (!heap && k <= n)
	{
		int j = k << 1;
		if (j < n)
			if (h[j] < h[j + 1])
				j++;
		if (h[j] > v)
			h[k] = h[j], k = j;
		else
			heap = true;
	}
	h[k] = v;
}
inline void bottomtoup()
{
	for (int i = n >> 1; i >= 1; i--) heapdown(i);
}
void deletetop()
{
	h[1] = h[n], n--,heapdown(1);
}
int main()
{
	cin >> n;for (int i = 1; i <= n; i++) scanf("%d", h + i);
	bottomtoup();for (int i = 1; i <= n; i++) cout << h[i] << " "; cout.put('\n');
	deletetop();for (int i = 1; i <= n; i++) cout << h[i] << " "; cout.put('\n');
	deletetop();for (int i = 1; i <= n; i++) cout << h[i] << " "; cout.put('\n');
	return 0;
}