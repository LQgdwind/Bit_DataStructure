#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "string"
#include "sstream"
#include "cstring"

using namespace std;

int n, k, m;

int* queue;
bool st[100000];

string ans;
stringstream ss;

int add(int x)
{
	if (x == n) x = 1;
	else x++;
	while (st[x])
	{
		if (x == n) x = 1;
		else x++;
	}
	return x;
}
int antiadd(int x)
{
	if (x == 1) x = n;
	else x--;
	while (st[x])
	{
		if (x == 1) x = n;
		else x--;
	}
	return x;
}
string tostring(int t)
{
	string target;
	ss << t;
	ss >> target;
	ss.clear();
	return target;
}
int main()
{
	bool t = scanf("%d,%d,%d", &n, &k, &m);
	while (t)
	{
		if (n == 0 || k == 0 || m == 0)
		{
			cout << "n,m,k must bigger than 0." << endl;
			return 0;
		}
		if (k > n)
		{
			cout << "k should not bigger than n." << endl;
			return 0;
		}
		queue = new int[n+1];
		memset(queue, 0, sizeof queue);
		int cnt = 0;
		loop(i, 1, n)
		{
			queue[i] = i;
		}
		int front = k;
		int end = k;
		if (m > 1)
		{
			front = add(k);
			end = antiadd(k);
		}
		loop(i, 1, m - 2)
		{
			front = add(front);
			end = antiadd(end);
		}
		while (cnt <= n-1)
		{
			string temp;
			if(cnt!=0)
				loop(i, 1, m)
			    {
				   front = add(front);
				   end = antiadd(end);
			    }
			if (front == end)
			{
				temp = tostring(queue[front]);
				st[front] = true;
				cnt++;
			}
			else
			{
				temp = tostring(queue[front]);
				temp += "-";
				temp.append(tostring(queue[end]));
				st[front] = true;
				st[end] = true;
				cnt = cnt + 2;
			}
			temp += ",";
			ans += temp;
		}
		cout << ans << endl;
		return 0;
	}
}

