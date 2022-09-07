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

int n;

bool divideby=false;

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
vector<string> charstack;
vector<string> poland;

stack<int> polandlambda;

char haha[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int hahacnt = 0;

bool transferpoland()
{
	string lambda;
	string sicp;
	charstack.emplace_back("#");
	getline(cin, lambda);
	lambda.append("#");
	for (int i = 0; i <= lambda.size() - 2; i++)
	{
		char diao = (char)lambda.c_str()[i+1];
		char diao2= (char)lambda.c_str()[i];
		if (!((diao >= '0' && diao <= '9') || diao == '+' || diao == '-' || diao == '*' || diao == '/' || diao == '%' || diao == '^' || diao == '(' || diao == ')' || diao == '#'))
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
		if((diao2==')'&&(diao=='('||(diao>='0'&&diao<='9')))||(diao2=='('&&!((diao >= '0' && diao <= '9')||diao=='-' || diao == '(')))
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
		if ((diao2 == '+') && !((diao >= '0' && diao <= '9') || diao == '-' || diao == '(' || diao == ')'))
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
		if ((diao2 == '-') && !((diao >= '0' && diao <= '9') || diao == '-' || diao == '(' || diao == ')'))
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
		if ((diao2 == '*') && !((diao >= '0' && diao <= '9') || diao == '-' || diao == '(' || diao == ')'))
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
		if ((diao2 == '/') && !((diao >= '0' && diao <= '9') || diao == '-' || diao == '(' || diao == ')'))
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
		if ((diao2 == '^') && !((diao >= '0' && diao <= '9') || diao == '-' || diao == '(' || diao == ')'))
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
		if ((diao2 == '%') && !((diao >= '0' && diao <= '9') || diao == '-' || diao == '(' || diao == ')'))
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
		if ((diao2 >='0'&& diao2<='9') && diao == '(')
		{
			cout << "error." << endl;
			failuremark = true;
			return false;
		}
	}
	int cntleft=0;
	int cntright=0;
	for (int i = 0; i <= lambda.size() - 1; i++)
	{
		char cnmb = lambda[i];
		if (cnmb == '(') cntleft++;
		if (cnmb == ')') cntright++;
	}
	if (cntright != cntleft)
	{
		cout << "error." << endl;
		failuremark = true;
		return false;
	}
	for (int i = 0; i <= lambda.size()-1; i++)
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
	stringstream ss;
	char* backupstring = new char[lambda.size()+1];
	strcpy(backupstring, lambda.c_str());
	ss.clear();
	
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
			map3.insert({ haha[hahacnt],num});
			backupstring[numbermark] = haha[hahacnt++];
		}
	}
	lambda.clear();
	for (int i = 0; i < strlen(backupstring); i++)
	{
		if (backupstring[i] != '0')
		lambda += backupstring[i];
	}
	//cout << lambda << endl;
	//cout << map3['a'] << map3['b'] << endl;
	int cnt = 0;
	sicp = lambda[cnt++];
	while (charstack.size() != 0)
	{
		if ((char)sicp.c_str()[0] >= 'a' && (char)sicp.c_str()[0] <= 'z')
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
		if (!charstack.empty())
		{
			string nima = charstack.back();
			if (nima == ")")
			{
				cout << "error." << endl;
				failuremark = true;
				return false;
			}
		}
	}
	return true;
}

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
	char mycoperator =(char) myoperator.c_str()[0];
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
		if (right < 0)
		{
			return false;
		}
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
	cin >> n;
	cin.get();
	while (n--)
	{
		bool judge1 = false;
		hahacnt = 0;
		map3.clear();
		judge1=transferpoland();
		if (!judge1)
		{
			if(!charstack.empty())charstack.clear();
			if (!poland.empty())poland.clear();
			continue;
		}
		//if(!poland.empty())
		//for (vector<string>::iterator i = poland.begin(); i != poland.end(); i++)
		//{
			//cout << *i;
		//}
		//cout << endl;
		for (int i=0;i<=poland.size()-1;i++)
		{
			string temp = poland[i];
			char op = (char)temp.c_str()[0];
			if (op >= 'a' && op <= 'z')
			{
				polandlambda.push(map3[op]);
				//cout << map3[op];
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
					else
					{
						cout << "error." << endl;
						failuremark = true;
						break;
					}
				}
			}
		}
		//else if (poland.size() == 0 || poland.size() == 1)
		//{
			//cout << "error." << endl;
		//}
		if (!charstack.empty())charstack.clear();
		if (!poland.empty())poland.clear();
		if (polandlambda.size() != 1 && !failuremark)
		{
			cout << "error." << endl;
		}
		else if(polandlambda.size()==1 && !failuremark)
		{
			cout << polandlambda.top() << endl;
			polandlambda.pop();
		}
		else if (polandlambda.size() == 1 && failuremark)
		{
			polandlambda.pop();
		}
		else if(polandlambda.size()>1)
		{
			while (!polandlambda.empty())
			{
				polandlambda.pop();
			}
		}
	}
	return 0;
}