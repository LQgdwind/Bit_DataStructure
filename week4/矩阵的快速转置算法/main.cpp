#define _CRT_SECURE_NO_WARNINGS  
#define loop(i,a,b) for(int i=a;i<=b;i++)  

#include "iostream"
#include "cstring"

using namespace std;

const int N = 1000;
int rowsize[N];
int rowstart[N];

class Triple
{
public:
	int row, col, value;
};

class sparsematrix
{
public:
	int Rows, Cols, Terms;
	Triple elem[N];
	sparsematrix();
};

sparsematrix::sparsematrix()
{
	this->Cols = 0;
	this->Rows = 0;
	this->Terms = 1;
	memset(this->elem, 0, sizeof(this->elem));
}

void fasttranspos(sparsematrix& a, sparsematrix& b)
{
	b.Rows = a.Cols;
	b.Cols = a.Rows;
	b.Terms = a.Terms;
	if (a.Terms > 0)
	{
		loop(i, 1, a.Terms)
		{
				rowsize[a.elem[i].col]++;
		}
		rowstart[0] = 1;
		loop(i, 1, a.Cols)
		{
			rowstart[i] = rowstart[i - 1] + rowsize[i - 1];
		}
		loop(i, 1, a.Terms)
		{
			int j = rowstart[a.elem[i].col];
			b.elem[j].value = a.elem[i].value;
			b.elem[j].col = a.elem[i].row;
			b.elem[j].row = a.elem[i].col;
			rowstart[a.elem[i].col]++;
		}
	}
}

int main()
{
	sparsematrix s;
	cin >> s.Rows >> s.Cols >> s.Terms;
	int count = 1;
	while (cin >> s.elem[count].row >> s.elem[count].col >> s.elem[count].value)
	{
		count++;
	}
	count--;
	sparsematrix target;
	fasttranspos(s, target);
	cout << "num:";
	loop(i, 1, s.Cols)
	{
		cout << rowsize[i] << ",";
	}
	cout << endl;
	cout << "cpot:";
	loop(i, 0, s.Cols-1)
	{
		cout << rowstart[i] << ",";
	}
	cout << endl;
	loop(i, 1, target.Terms)
	{
		cout << target.elem[i].row << "," << target.elem[i].col << "," << target.elem[i].value << endl;
	}
	return 0;
}