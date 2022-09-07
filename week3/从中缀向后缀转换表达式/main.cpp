#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "sstream"

using namespace std;

int n;

unordered_map <string, int> map1;
unordered_map <string, int> map2;

typedef pair<string, int> PSI;

void init()
{
	PSI p1("#", 0); map1.insert(p1);
	PSI p2("(", 1); map1.insert(p2);
	PSI p3("*", 5); map1.insert(p3);
	PSI p4("/", 5); map1.insert(p4);
	PSI p5("%", 5); map1.insert(p5);
	PSI p6("+", 3); map1.insert(p6);
	PSI p7(")", 8); map1.insert(p7);
	PSI p8("-", 3); map1.insert(p8);
	PSI p9("^", 6); map1.insert(p9);
	map2.insert(p1);
	p2.second = 8; map2.insert(p2);
	p3.second = 4; map2.insert(p3);
	p4.second = 4; map2.insert(p4);
	p5.second = 4; map2.insert(p5);
	p6.second = 2; map2.insert(p6);
	p7.second = 1; map2.insert(p7);
	p8.second = 2; map2.insert(p8);
	p9.second = 7; map2.insert(p9);
}


vector<string> charstack;
vector<string> poland;

int main()
{
	init();
	cin >> n;
	while (n--)
	{
		charstack.emplace_back("#");
		string sicp;
		cin.get();
		sicp = cin.get();
		while (charstack.size()!=0)
		{
			if ((char)sicp.c_str()[0] >= 'A' && (char)sicp.c_str()[0] <= 'Z' || (char)sicp.c_str()[0] >= 'a' && (char)sicp.c_str()[0] <= 'z')
			{
				poland.emplace_back(sicp);
				sicp = cin.get();
			}
			else
			{
				string sisp = charstack.back();
				int icp = map2[sicp];
				int isp = map1[sisp];
				if (isp < icp)
				{
					charstack.emplace_back(sicp);
					sicp = cin.get();
				}
				else if (isp > icp)
				{
					poland.emplace_back(charstack.back());
					charstack.pop_back();
				}
				else if (isp == icp)
				{
					string temp = charstack.back();
					charstack.pop_back();
					if(temp=="(") sicp = cin.get();
				}
			}
		}
		for (vector<string>::iterator i = poland.begin(); i != poland.end(); i++)
		{
			cout << *i;
		}
		cout << endl;
		charstack.clear();
		poland.clear();
	}
	return 0;
}