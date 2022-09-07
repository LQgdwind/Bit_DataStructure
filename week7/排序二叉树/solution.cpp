#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n, cnt, a[N]; int cenci = -1;
class treenode;typedef treenode* bintree;
class treenode
{
public:
	bintree rightchild, leftchild;
	int data;
	treenode(int k) :rightchild(NULL), leftchild(NULL), data(k) {};
};
inline void insert(bintree root,int k)
{
	if (root != NULL)
	{
		if (root->data > k)
		{
			if (root->leftchild == NULL)
			{
				bintree newnode = new treenode(k);root->leftchild = newnode;return;
			}
			else insert(root->leftchild, k);
		}
		else if (root->data < k)
		{
			if (root->rightchild == NULL)
			{
				bintree newnode = new treenode(k); root->rightchild = newnode; return;
			}
			else insert(root->rightchild, k);
		}
		else if (root->data == k) return;
	}
	
}
inline void printbintree(bintree root)
{
	if (root != NULL)
	{
		cenci++;
		printbintree(root->leftchild);
		{
			for (int i = 1; i <= cenci; i++) cout << "    ";
			cout << root->data << endl;
		}
		printbintree(root->rightchild);
		cenci--;
	}
}
inline void inordertraversal(bintree root)
{
	if (root != NULL)
	{
		inordertraversal(root->leftchild);
		cout << " " << root->data;
		inordertraversal(root->rightchild);
	}
}
int main()
{
	cin >> n; bintree root = new treenode(n);
	if(n!=0) while (cin >> n && n != 0) insert(root, n);
	printbintree(root);cout.put('\n');
	inordertraversal(root);cout.put('\n');
	return 0;
}