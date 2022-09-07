#include "bits/stdc++.h"
#include "unordered_map"

using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int> PII;

int ETV[N], LTV[N], ETE[N], LTE[N];

int keyans[N];

class Edge
{
public:
	int e, ne, w;
}edge[N],edge2[N];

int h[N], idx=1;
int d[N]; bool st[N];
int h2[N], idx2 = 1;

class Ed
{
public:
	int first, second, val;
}ed[N];

vector <int> topsortlist;
priority_queue < int,vector<int>,greater<int> > q;
stack <int> topstack;

inline void add(int a, int b, int c)
{
	edge[idx].e = b;
	edge[idx].ne = h[a];
	edge[idx].w = c;
	ed[idx].first = a;
	ed[idx].second = b;
	ed[idx].val = c;
	d[b]++;
	h[a] = idx++;
}

inline void add(int a, int b)
{
	edge2[idx2].e = b;
	edge2[idx2].ne = h2[a];
	h2[a] = idx2++;
}

unordered_map <int, string> hashm;
int node, edges;

inline bool topsort()
{
	for (int i = 0; i < node; i++)
	{
		if (d[i] == 0) q.push(i);
	}
	while (q.size() > 0)
	{
		int x = q.top();
		topsortlist.push_back(x);
		q.pop();
		for (int i = h[x]; i != -1; i = edge[i].ne)
		{
			int y = edge[i].e;
			if (d[y] == 0)continue;
			d[y]--;
			ETV[y] = max(ETV[y], ETV[x] + edge[i].w);
			if (d[y] == 0)
			{
				q.push(y);
			}
		}
	}
	if (topsortlist.size() < node) return false;
	else
	{
		for (int i = 0; i < topsortlist.size(); i++)
		{
			if (i != topsortlist.size() - 1)cout << hashm[topsortlist[i]] << "-";
			else cout << hashm[topsortlist[i]] << endl;
		}
		return true;
	}
}

string printans[N]; int cntstring=-1;

void dfs(int tmpnod,int tmpnum)
{
	if (tmpnod == node-1)
	{
		keyans[tmpnum]=node-1;
		cntstring++;
		for (int i = 0; i <= tmpnum; i++)
		{
			if (i == 0) printans[cntstring] += hashm[keyans[i]];
			else
			{
				printans[cntstring] += "-";
				printans[cntstring] += hashm[keyans[i]];
			}
		}
		return;
	}
	keyans[tmpnum]=tmpnod;
	for (int i = h2[tmpnod]; i != -1; i = edge2[i].ne)
	{
		int y = edge2[i].e;
		if (st[y]) continue;
		st[y] = true;
		dfs(y,tmpnum+1);
		st[y] = false;
	}
	return;
}

inline void keypath()
{
	for (int i = 0; i < node; i++)
	{
		LTV[i] = ETV[node-1];
		topstack.push(topsortlist[i]);
	}
	while (topstack.size() > 0)
	{
		int x=topstack.top();
		topstack.pop();
		for (int i = h[x]; i != -1; i = edge[i].ne)
		{
			int y = edge[i].e;
			LTV[x] = min(LTV[y] - edge[i].w, LTV[x]);
		}
	}
	for (int i = 1; i <= edges; i++)
	{
		ETE[i] = ETV[ed[i].first];
		LTE[i] = LTV[ed[i].second] - ed[i].val;
		if (ETE[i] == LTE[i])
		{
			PII temp;
			temp.first = ed[i].first;
			temp.second = ed[i].second;
			add(temp.first, temp.second);
			//cout << temp.first <<" "<< temp.second << endl;
		}
	}
	dfs(0,0);
	sort(printans, printans + cntstring + 1);
	for (int i = 0; i <= cntstring; i++)
	{
		cout << printans[i] << endl;
	}
}

int main()
{
	memset(h, -1, sizeof(h));
	memset(h2, -1, sizeof(h2));
	scanf("%d,%d", &node, &edges);
	cin.get();
	for (int i = 0; i < node; i++)
	{
		string temp;
		if (i != node - 1) getline(cin, temp, ',');
		else if (i == node - 1) getline(cin, temp);
		hashm.insert({ i,temp });
	}
	for (int i = 1; i <= edges; i++)
	{
		int a, b, c;
		scanf("<%d,%d,%d>", &a, &b, &c);
		add(a, b, c);
		cin.get();
	}
	if (!topsort())
	{
		cout << "NO TOPOLOGICAL PATH" << endl;
		return 0;
	}
	keypath();
	/*
	for (int i = 0; i < node; i++) cout << ETV[i] << " ";
	cout << endl;
	for (int i = 0; i < node; i++) cout << LTV[i] << " ";
	cout << endl;
	for (int i = 1; i <= edges; i++) cout << ETE[i] << " ";
	cout << endl;
	for (int i = 1; i <= edges; i++) cout << LTE[i] << " ";
	cout << endl;
	*/
	return 0;
}