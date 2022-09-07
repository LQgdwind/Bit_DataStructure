#define _CRT_SECURE_NO_WARNINGS  
#define loop(i,a,b) for(int i=a;i<=b;i++)  

#include "iostream"
#include "string"
#include "sstream"

using namespace std;

string input;
int query;
bool ed = false;
int cnt = 0;
int main()
{
	//bool read = freopen("1.in", "r+", stdin);
	//bool write = freopen("1.out", "a+", stdout);
	getline(cin, input);
	cout << "generic list: " << input << endl;
	while (cin >> query)
	{
		if (query == 1)
		{
			cout << "destroy tail" << endl << "free list node" << endl << "generic list: ";
			cnt = 0;
			if (input[1] != '(')
			{
				input = input.substr(1, 1);
				ed = true;
			}
			else if (input[1] == '(')
			{
				loop(j, 1, input.size() - 1)
				{
					if (input[j] == '(')
					{
						cnt++;
					}
					else if (input[j] == ')')
					{
						cnt--;
					}
					if (cnt == 0)
					{
						input = input.substr(1, j);
						break;
					}
				}
			}
			cout << input << endl;
			if (ed) return 0;
		}
		else if (query == 2)
		{
			cout << "free head node" << endl << "free list node" << endl << "generic list: ";
			int cnt = 0;
			if (input[1] != '(')
			{
				input.erase(input.begin()+1);
				if (input[1] == ',')
				{
					input.erase(input.begin() + 1);
				}
			}
			else if (input[1] == '(')
			{
				if (input[2] != ')')
				{
					loop(j, 1, input.size() - 1)
					{
						if (input[j] == '(')
						{
							cnt++;
						}
						else if (input[j] == ')')
						{
							cnt--;
						}
						if (cnt == 0)
						{
							input.erase(input.begin() + 1, input.begin() + j + 1);
							if (input[1] == ',')
							{
								input.erase(input.begin() + 1);
							}
							break;
						}
					}
				}
				else if (input[2] == ')')
				{
					return 0;
				}
			}
			cout << input << endl;
		}
	}
	return 0;
}
