#include "bits/stdc++.h"

using namespace std;
const int N = 2e6 + 10;
class qujian
{
public:
    int l;
    int r;
    bool operator <(const qujian& a)const
    {
        return l < a.l;
    }
}range[N];
int n;
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &range[i].l, &range[i].r);
    }
    sort(range, range + n);
    priority_queue<int, vector<int>, greater<int> >heap;
    for (int i = 0; i < n; i++)
    {
        if (heap.empty() || heap.top() > range[i].l)
        {
            heap.push(range[i].r);
        }
        else
        {
            heap.pop();
            heap.push(range[i].r);
        }
    }
    cout << heap.size() << endl;
}