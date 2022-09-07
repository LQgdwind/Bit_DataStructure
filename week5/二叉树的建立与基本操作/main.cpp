#include "iostream"
#include "string"

using namespace std;

string input;

int cnt = -1;

class bintree
{
public:
	bintree* leftchild;
	bintree* rightchild;
	char data;
	bintree();
};

bintree::bintree()
{
	this->data = '0';
	this->leftchild = NULL;
	this->rightchild = NULL;
}

void createbintree(bintree* &t)
{
	if (cnt >= (int)input.size() - 1) return;
	char temp = input[++cnt];
	if (temp != '#')
	{
		t = new bintree;
		t->data = temp;
		createbintree(t->leftchild);
		createbintree(t->rightchild);
	}
	else t = NULL;
}
void pretraversal(bintree* t)
{
	if (t == NULL) return;
	else if(t!=NULL)
	{
		cout << t->data;
		pretraversal(t->leftchild);
		pretraversal(t->rightchild);
	}
}
void intraversal(bintree* t)
{
	if (t == NULL)return;
	else if (t != NULL)
	{
		intraversal(t->leftchild);
		cout << t->data;
		intraversal(t->rightchild);
	}
}
void posttraversal(bintree* t)
{
	if (t == NULL) return;
	else if (t != NULL)
	{
		posttraversal(t->leftchild);
		posttraversal(t->rightchild);
		cout << t->data;
	}
}

void createbintree2(bintree* &t)
{
	if (cnt >= (int)input.size() - 1) return;
	char temp = input[++cnt];
	if (temp != '#')
	{
		t = new bintree;
		t->data = temp;
		createbintree2(t->rightchild);
		createbintree2(t->leftchild);
	}
	else t = NULL;
}

void traversal(bintree* root)
{
	cout << "pre_sequence  : ";
	pretraversal(root);
	cout.put('\n');
	cout << "in_sequence   : ";
	intraversal(root);
	cout.put('\n');
	cout << "post_sequence : ";
	posttraversal(root);
	cout.put('\n');
}
int leafnum = 0;
void leafcount(bintree * t)
{
	if (t == NULL) return;
	else if(t!=NULL)
	{
		if (t->leftchild == NULL && t->rightchild == NULL)leafnum++;
		leafcount(t->leftchild);
		leafcount(t->rightchild);
	}
}
void printtree(bintree* t, int depth)
{
	if (t == NULL) return;
	else if (t != NULL)
	{
		for (int i = 1; i <= depth; i++) cout << "    ";
		cout << t->data << endl;
		depth++;
		printtree(t->leftchild, depth);
		printtree(t->rightchild, depth);
	}
}
int main()
{
	getline(cin, input); 
	cout << "BiTree" << endl;
	bintree* root = new bintree;
	createbintree(root);
	printtree(root, 0);
	traversal(root);
	leafcount(root);
	cout << "Number of leaf: " << leafnum << endl;
	cout << "BiTree swapped" << endl;
	cnt = -1;
	bintree* root2 = new bintree;
	createbintree2(root2);
	printtree(root2, 0);
	traversal(root2);
	return 0;
}