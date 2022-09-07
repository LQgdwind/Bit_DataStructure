#include "bits/stdc++.h"
using namespace std;
int n; const int N = 1e6 + 10; int a[N]; int cnt = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i); if (a[i] == i) cout << i << " ", cnt++;
	}
	if (cnt == 0) cout << "No ";
	cout.put('\n');
	return 0;
}