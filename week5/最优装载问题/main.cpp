//�����Ľⷨ ������ΪҪ��¼���̣������������ı�������
//��û���뵽��ѧм��Ҫ�� 1e8��int���鿪������dp[1e2][1e6]ֱ��tle�޽��
//ֻ�ù���ȥ�����Լ���һά01�����İ���

//by ֣����
#pragma GCC optimize(3,"Ofast","inline")   

#include "bits/stdc++.h"

using namespace std;
const int N = 1e6+10;

int w[N], n, V, f[N];
vector<int> ans[N];

int main()
{
    cin >> V >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = V; j >= w[i]; j--)
        {
            if (f[j] < f[j - w[i]] + w[i])
            {
                ans[j] = ans[j - w[i]];     //���Ʒ���
                ans[j].push_back(i);    //���·���
                f[j] = f[j - w[i]] + w[i];
            }
            else if (f[j] == f[j - w[i]] + w[i])
            {
                vector<int> b = ans[j - w[i]]; b.push_back(i);
                if (b < ans[j])  ans[j] = b; //���·���
                //ʹ��vector�Դ����ֵ������������
            }
        }
    cout << f[V] << endl;
    for (int i = 0; i < ans[V].size(); i++)    //�������
    {
        cout << ans[V][i] << ' ';
    }
    cout.put('\n');
    return 0;
}
