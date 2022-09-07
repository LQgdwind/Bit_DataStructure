#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++) 

#include "iostream"; 
#include "vector"; 
#include "cstdio"; 

using namespace std;

int n, k, m;

vector<int> v;

int main()
{
    bool t = scanf("%d,%d,%d", &n, &k, &m);
    if (t)
    {
        if (n < 1 || k < 1 || m < 1)
        {
            cout << "n,m,k must bigger than 0." << endl;
            return 0;
        }
        if (k > n)
        {
            cout << "k should not bigger than n." << endl;
            return 0;
        }
        loop(i, 1, n)
        {
            v.push_back(i);
        }
        int cnt = (k + m - 2) % n;
        int ans = 0;
        while (v.size())
        {
            cout << v[cnt]; ans++;
            v.erase(v.begin() + cnt);
            for (int i = 1; i < m; i++)
            {
                cnt++;
                if (cnt >= v.size() - 1 && v.size() != 1) cnt %= v.size();
                else if (v.size() == 1) cnt = 0;
            }
            if (v.size() == 0 || ans%10==0) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}