#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "map"
#include "iostream"

using namespace std;

map<int, int> pa;
map<int, int> pb;
map<int, int> pc;

typedef pair<int, int> PII;

bool judge;

int record[10001]; int cnt;

int main()
{
	cin >> judge;
	if (!judge)
	{
		return 0;
	}
	else
	{
		int n1 = 0, n2 = 0, n3 = 0;
		cin >> n1;
		if (n1 == 0)
		{
			pa.insert({ 0,0 });
		}
		else
		{
			loop(i, 1, n1)
			{
				int key, value;
				cin >> value >> key;
				PII xiang(key, value);
				pa.insert(xiang);
			}
		}
		cin >> n2;
		if (n2 == 0)
		{
			pb.insert({ 0,0 });
		}
		loop(i, 1, n2)
		{
			int key, value;
			cin >> value >> key;
			PII xiang(key, value);
			pb.insert(xiang);
		}
		cin >> n3;
		if (n3 == 0)
		{
			pc.insert({ 0,0 });
		}
		loop(i, 1, n3)
		{
			int key, value;
			cin >> value >> key;
			PII xiang(key, value);
			pc.insert(xiang);
		}
		for (map<int, int>::iterator i = pa.begin(); i != pa.end(); i++)
		{
			cout << "<" << i->second << "," << i->first << ">";
			i++;
			if (i == pa.end())
			{
				cout << endl;
				i--;
			}
			else
			{
				cout << ",";
				i--;
			}
		}
		for (map<int, int>::iterator i = pb.begin(); i != pb.end(); i++)
		{
			cout << "<" << i->second << "," << i->first << ">";
			i++;
			if (i == pb.end())
			{
				cout << endl;
				i--;
			}
			else
			{
				cout << ",";
				i--;
			}
		}
		for (map<int, int>::iterator i = pc.begin(); i != pc.end(); i++)
		{
			cout << "<" << i->second << "," << i->first << ">";
			i++;
			if (i == pc.end())
			{
				cout << endl;
				i--;
			}
			else
			{
				cout << ",";
				i--;
			}
		}
		pa.erase(0);
		pb.erase(0);
		pc.erase(0);
		for (map<int, int>::iterator i = pb.begin(); i != pb.end(); i++)
		{
			map<int, int>::iterator j = pa.find(i->first);
			if (j != pa.end())
			{
				j->second += i->second;
				if (j->second == 0)
				{
					record[cnt++] = i->first;
				}
			}
			else
			{
				PII temp(i->first, i->second);
				pa.insert(temp);
			}
		}
		for (int i = 0; i <= cnt; i++)
		{
			pa.erase(record[i]);
		}
		if (pa.empty()) pa.insert({ 0,0 });
		int cnt2 = cnt + 1;
		for (map<int, int>::iterator i = pa.begin(); i != pa.end(); i++)
		{
			cout << "<" << i->second << "," << i->first << ">";
			i++;
			if (i == pa.end())
			{
				cout << endl;
				i--;
			}
			else
			{
				cout << ",";
				i--;
			}
		}
		pa.erase(0);
		for (map<int, int>::iterator i = pc.begin(); i != pc.end(); i++)
		{
			map<int, int>::iterator j = pa.find(i->first);
			if (j != pa.end())
			{
				j->second += i->second;
				if (j->second == 0)
				{
					record[cnt2++] = i->first;
				}
			}
			else
			{
				PII temp(i->first, i->second);
				pa.insert(temp);
			}
		}
		for (int i = cnt + 1; i <= cnt2; i++)
		{
			pa.erase(record[i]);
		}
		if (pa.empty()) pa.insert({ 0,0 });
		for (map<int, int>::iterator i = pa.begin(); i != pa.end(); i++)
		{
			cout << "<" << i->second << "," << i->first << ">";
			i++;
			if (i == pa.end())
			{
				cout << endl;
				i--;
			}
			else
			{
				cout << ",";
				i--;
			}
		}
	}
	return 0;
}