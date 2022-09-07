#include "iostream"
#include "string"
#include "queue"

using namespace std;
string inorder, postorder;

class bintree
{
public:
	char data;
	bintree* righttree;
	bintree* lefttree;
	bintree();
};
queue<bintree*> q;
bintree::bintree()
{
	data = '0';
	this->lefttree = NULL;
	this->righttree = NULL;
}
void createtree(bintree*& t, int l1, int r1, int l2, int r2)
{
	if (l2 <= r2)
	{
		t = new bintree;
		t->data = postorder[r2], t->lefttree = NULL, t->righttree = NULL;
		int i = 0; for (i = l1; i != r1; i++)
		{
			if (inorder[i] == postorder[r2]) break;
		}
		createtree(t->lefttree, l1, i - 1, l2, r2 - r1 + i - 1);
		createtree(t->righttree, i + 1, r1, r2 - r1 + i, r2 - 1);
	}
	else return;
}

void traversal(bintree* t)
{
	q.push(t);
	while (!q.empty())
	{
		bintree* temp = q.front();
		q.pop();
		cout << temp->data;
		if (temp->lefttree != NULL) q.push(temp->lefttree);
		if (temp->righttree != NULL) q.push(temp->righttree);
	}
	cout.put('\n');
}
int main()
{
	getline(cin, inorder), getline(cin, postorder);
	bintree* root = new bintree;
	createtree(root,0,(int)inorder.size()-1,0,(int)postorder.size()-1);
	traversal(root);
	return 0;
}