#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "vector"
#include "string"
#include "cstring"
#include "unordered_map"
#include "stack"
#include "sstream"

using namespace std;

bool divideby = false;

bool failuremark = false;

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
	PSI p7(")", 10); map1.insert(p7);
	PSI p8("-", 3); map1.insert(p8);
	PSI p9("^", 6); map1.insert(p9);
	PSI p10("~", 9); map1.insert(p10);
	map2.insert(p1);
	p2.second = 10; map2.insert(p2);
	p3.second = 4; map2.insert(p3);
	p4.second = 4; map2.insert(p4);
	p5.second = 4; map2.insert(p5);
	p6.second = 2; map2.insert(p6);
	p7.second = 1; map2.insert(p7);
	p8.second = 2; map2.insert(p8);
	p9.second = 7; map2.insert(p9);
	p10.second = 8; map2.insert(p10);
}

unordered_map <char, int> map3;
unordered_map <string, int>map4;

vector<string> charstack;
vector<string> poland;

stack<int> polandlambda;

char haha[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
int hahacnt = 0;


bool caculatenum(string myoperator)
{
	divideby = false;
	int left;
	int right;
	if (polandlambda.empty()) return false;
	right = polandlambda.top();
	polandlambda.pop();
	if (polandlambda.empty()) return false;
	left = polandlambda.top();
	polandlambda.pop();
	char mycoperator = (char)myoperator.c_str()[0];
	switch (mycoperator)
	{
	case '+':polandlambda.push(left + right); break;
	case '-':polandlambda.push(left - right); break;
	case '*':polandlambda.push(left * right); break;
	case '/': {
		if (abs(right) < 0.001)
		{
			divideby = true;
			return false;
		}
		else polandlambda.push(left / right);
	} break;
	case '%': {
		if (abs(right) < 0.001)
		{
			divideby = true;
			return false;
		}
		else polandlambda.push(left % right);
	} break;
	case '^': {
		int nb = 1;
		for (int i = 1; i <= right; i++)
		{
			nb *= left;
		}
		polandlambda.push(nb);
	}
	default:
		break;
	}
}

int main()
{
	init();
	while (true)
	{
		hahacnt = 0;
		map3.clear();
		string lambda;
		string sicp;
		getline(cin, lambda);
		if (lambda[0] == '?')
		{
			string target;
			loop(i, 2, lambda.size() - 1)
			{
				target += lambda[i];
			}
			cout << target << "=" << map4[target] << endl;
			continue;
		}
		else if (lambda == "end")
		{
			break;
		}
		else
		{
			string valstring;
			int fenge = 0;
			loop(i, 0, lambda.size() - 1)
			{
				if (lambda[i] == '=')
				{
					fenge = i;
					break;
				}
				valstring += lambda[i];
			}
			if (map4.find(valstring) == map4.end())
				map4.insert({ valstring,0 });
			string lambdabackup;
			loop(i, fenge + 1, lambda.size() - 1) lambdabackup += lambda[i];
			lambda.clear();
			loop(i, 0, lambdabackup.size() - 1) lambda += lambdabackup[i];
			lambda.append("#");
			stringstream ss;
			string ziduanjie[100]; int ziduan = -1; int ziduancnt = 0;
			while (lambda[ziduancnt] != '#')
			{
				ziduan++;
				if (lambda[ziduancnt] >= 'a' && lambda[ziduancnt] <= 'z')
					while (lambda[ziduancnt] >= 'a' && lambda[ziduancnt] <= 'z')
					{
						ziduanjie[ziduan] += lambda[ziduancnt++];
					}
				else
				{
					ziduanjie[ziduan] += lambda[ziduancnt++];
				}
			}
			loop(i, 0, ziduan)
			{
				if (ziduanjie[i][0] >= 'a' && ziduanjie[i][0] <= 'z')
				{
					int ziduannum = map4[ziduanjie[i]];
					ziduanjie[i].clear();
					ss << ziduannum;
					ss >> ziduanjie[i];
					ss.clear();
				}
			}
			lambda.clear();
			loop(i, 0, ziduan)
			{
				lambda += ziduanjie[i];
			}
			lambda += '#';
			for (int i = 0; i <= lambda.size() - 1; i++)
			{
				if ((char)lambda.c_str()[i] == '-')
				{
					if (i == 0) lambda[i] = (char)'~';
					else if ((char)lambda.c_str()[i - 1] == '+' || (char)lambda.c_str()[i - 1] == '*' || (char)lambda.c_str()[i - 1] == '/' || (char)lambda.c_str()[i - 1] == '-' || (char)lambda.c_str()[i - 1] == '^' || (char)lambda.c_str()[i - 1] == '/' || (char)lambda.c_str()[i - 1] == '(')
					{
						lambda[i] = (char)'~';
					}
				}
			}
			ss.clear();
			char* backupstring = new char[lambda.size() + 1];
			strcpy(backupstring, lambda.c_str());
			for (int i = 0; i < strlen(backupstring); i++)
			{
				string number;
				bool ifnum = false;
				int num;
				int numbermark;
				while (backupstring[i] >= '0' && backupstring[i] <= '9')
				{
					if (!ifnum) numbermark = i;
					number += backupstring[i];
					backupstring[i++] = '0';
					ifnum = true;
				}
				if (ifnum)
				{
					ss << number;
					ss >> num;
					ss.clear();
					map3.insert({ haha[hahacnt],num });
					backupstring[numbermark] = haha[hahacnt++];
				}
			}
			lambda.clear();
			for (int i = 0; i < strlen(backupstring); i++)
			{
				if (backupstring[i] != '0')
					lambda += backupstring[i];
			}
			ss.clear();
			int cnt = 0;
			sicp = lambda[cnt++];
			charstack.emplace_back("#");
			while (charstack.size() != 0)
			{
				if ((char)sicp.c_str()[0] >= 'A' && (char)sicp.c_str()[0] <= 'Z')
				{
					poland.emplace_back(sicp);
					sicp = lambda[cnt++];
				}
				else
				{
					string sisp = charstack.back();
					int icp = map2[sicp];
					int isp = map1[sisp];
					if (isp < icp)
					{
						charstack.emplace_back(sicp);
						sicp = lambda[cnt++];
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
						if (temp == "(") sicp = lambda[cnt++];
					}
				}
			}
			for (int i = 0; i <= poland.size() - 1; i++)
			{
				string temp = poland[i];
				char op = (char)temp.c_str()[0];
				if (op >= 'A' && op <= 'Z')
				{
					polandlambda.push(map3[op]);
				}
				else if (temp == "~")
				{
					polandlambda.top() = -polandlambda.top();
				}
				else
				{
					if (!caculatenum(temp))
					{
						if (divideby)
						{
							cout << "Divide 0." << endl;
							failuremark = true;
							break;
						}
					}
				}
			}
			if (!charstack.empty())charstack.clear();
			if (!poland.empty())poland.clear();
			if (polandlambda.size() == 1)
			{
				map4[valstring] = polandlambda.top();
				polandlambda.pop();
			}
			if (polandlambda.size() > 1)
			{
				while (!polandlambda.empty())
				{
					polandlambda.pop();
				}
			}
		}
	}
	return 0;
}