#include "iostream";
#include "string";
#include "algorithm";
using namespace std;
int main()
{
	string temp; getline(cin, temp); reverse(temp.begin(), temp.end());
	for(string::iterator i=temp.begin();i!=temp.end();i++)
	{
		if (*i == '(') *i = ')';
		else if (*i == ')') *i = '(';
	}
	cout << temp << endl;
}