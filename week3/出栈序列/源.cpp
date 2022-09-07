#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "vector"
#include "iostream"

using namespace std;

vector<int> v;

int main()
{
	int n, m;
	cin >> n >> m;
	while (true)
	{
		while (m--)
		{
			bool mark = true;
			v.emplace_back(0);
			for (int i = 1; i <= n; i++)
			{
				int num;
				cin >> num;
				v.emplace_back(num);
			}
			for (int i = 1; i <= n - 2; i++)
			{
				for (int j = i + 1; j <= n - 1; j++)
				{
					for (int k = j + 1; k <= n; k++)
					{
						if (v[i] > v[j] && v[i] > v[k] && v[j] < v[k]) mark = false;
						if (!mark) break;
					}
					if (!mark) break;
				}
				if (!mark) break;
			}
			if (!mark) cout << "No" << endl;
			else cout << "Yes" << endl;
			v.clear();
		}
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		else cout << endl;
	}
	return 0;
}