#include "bits/stdc++.h"
using namespace std;
class treenode; typedef treenode* bintree; int cnt = -1;
class treenode
{
public:
	bintree rightchild, leftchild;
	char data;
	treenode(char k) :rightchild(NULL), leftchild(NULL), data(k) {};
};
inline void R()
{

}
inline void L()
{

}
inline void avlinsert(bintree root,char k)
{

}
inline void preordertravelsal(bintree root)
{
	if (root)
	{
		cout << root->data;
		preordertravelsal(root->leftchild);
		preordertravelsal(root->rightchild);
	}
}
inline void inordertraversal(bintree root)
{
	if (root)
	{
		inordertraversal(root->leftchild);
		cout << root->data;
		inordertraversal(root->rightchild);
	}
}
inline void postordertraversal(bintree root)
{
	if (root)
	{
		postordertraversal(root->leftchild);
		postordertraversal(root->rightchild);
		cout << root->data;
	}
}
inline void printtree_anti_inoder(bintree root)
{
	if (root)
	{
		cnt++;
		printtree_anti_inoder(root->rightchild);
		for (int i = 1; i <= cnt; i++) cout << "    ";
		cout << root->data << endl;
		printtree_anti_inoder(root->leftchild);
		cnt--;
	}
}
int main()
{
	string input; getline(cin, input); bintree root = new treenode(input[0]);
	for (int i = 1; i < input.size(); i++)
		avlinsert(root, input[i]);
	cout << "Preorder: "; preordertravelsal(root); cout.put('\n');
	cout << "Inorder: "; inordertraversal(root); cout.put('\n');
	cout << "Postorder: "; postordertraversal(root); cout.put('\n');
	cout << "Tree:" << endl;
	printtree_anti_inoder(root);
	return 0;
}