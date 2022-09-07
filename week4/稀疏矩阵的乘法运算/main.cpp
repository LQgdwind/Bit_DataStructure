#define _CRT_SECURE_NO_WARNINGS  
#define loop(i,a,b) for(int i=a;i<=b;i++)  

#include "iostream"
#include "cstring"

using namespace std;

const int N = 110;

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
	this->Terms = 0;
	memset(this->elem, 0, sizeof(this->elem));
}

int main()
{
	sparsematrix a;
	cin >> a.Rows >> a.Cols >> a.Terms;
	int count2 = 0;
	loop(i, 1, a.Terms)
	{
		count2++;
		cin >> a.elem[count2].row >> a.elem[count2].col >> a.elem[count2].value;
	}
	sparsematrix b;
	cin >> b.Rows >> b.Cols >> b.Terms;
	count2 = 0;
	loop(i, 1, b.Terms)
	{
		count2++;
		cin >> b.elem[count2].row >> b.elem[count2].col >> b.elem[count2].value;
	}
	sparsematrix c;
	c.Rows = a.Rows;
	c.Cols = b.Cols;
	count2 = 0;
	bool flag = false;
	bool flag2 = false;
	loop(i, 1, a.Terms)
	{
		loop(j, 1, b.Terms)
		{
			if (a.elem[i].col == b.elem[j].row)
			{
				flag = false;
				flag2 = false;
				if (c.Terms > 0)
				{
					loop(k, 1, c.Terms)
					{
						if (c.elem[k].row == a.elem[i].row && c.elem[k].col == b.elem[j].col)
						{
							c.elem[k].value += a.elem[i].value * b.elem[j].value;
							flag2 = true;
						}
						if (k == c.Terms && flag2==false)
						{
							count2++;
							c.elem[count2].row = a.elem[i].row;
							c.elem[count2].col = b.elem[j].col;
							c.elem[count2].value = a.elem[i].value * b.elem[j].value;
							flag = true;
						}
					}
					if (flag)c.Terms++;
				}
				else if (c.Terms == 0)
				{
					count2++;
					c.elem[count2].row = a.elem[i].row;
					c.elem[count2].col = b.elem[j].col;
					c.elem[count2].value = a.elem[i].value * b.elem[j].value;
					c.Terms++;
				}
			}
		}
	}
	sparsematrix result;
	result.Cols = c.Cols;
	result.Rows = c.Rows;
	count2 = 0;
	loop(i, 1, c.Terms)
	{
		if (c.elem[i].value != 0)
		{
			count2++;
			result.elem[count2].row = c.elem[i].row;
			result.elem[count2].col = c.elem[i].col;
			result.elem[count2].value = c.elem[i].value;
			result.Terms++;
		}
	}
	cout << result.Rows << endl << result.Cols << endl << result.Terms << endl;
	loop(i, 1, result.Terms)
	{
		cout << result.elem[i].row << "," << result.elem[i].col << "," << result.elem[i].value << endl;
	}
	return 0;
}