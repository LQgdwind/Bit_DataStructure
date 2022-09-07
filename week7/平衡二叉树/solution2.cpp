#include "bits/stdc++.h"
using namespace std; string input;
typedef struct Avnode
{
	char data;
	struct Avnode* left, * right;
}node, * pnode;pnode root = NULL;
int Height(pnode P)
{
	int hl, hr; if (P == NULL) return 0;
	else
	{
		hl = Height(P->left),hr = Height(P->right);
		return (hl > hr ? hl + 1 : hr + 1);
	}
}
void Inorder(pnode head)
{
	if (head->left) Inorder(head->left);
	cout<<head->data;
	if (head->right) Inorder(head->right);
}
void Preorder(pnode head)
{
	cout<<head->data;
	if (head->left) Preorder(head->left);
	if (head->right) Preorder(head->right);
}
void Postorder(pnode head)
{
	if (head->left) Postorder(head->left);
	if (head->right) Postorder(head->right);
	cout<<head->data;
}
pnode SingleRotationLeft(pnode K)
{
	pnode P;
	P = K->left,K->left = P->right,P->right = K;
	return P;
}
pnode SingleRotationRight(pnode K)
{
	pnode P;
	P = K->right,K->right = P->left,P->left = K;
	return P;
}
pnode DoubleRotationLR(pnode K3)
{
	pnode K2, K1;
	K1 = K3->left,K2 = K1->right,K1->right = K2->left,K3->left = K2->right,K2->left = K1,K2->right = K3;
	return K2;
}
pnode DoubleRotationRL(pnode K1)
{
	pnode K2, K3;
	K3 = K1->right,K2 = K3->left,K1->right = K2->left,K3->left = K2->right,K2->left = K1,K2->right = K3;
	return K2;
}
pnode Insert(char c, pnode T)
{
	if (T == NULL) T = (pnode)malloc(sizeof(node)),T->data = c,T->left = T->right = NULL;
	else
		if (c < T->data)
		{
			T->left = Insert(c, T->left);
			if (Height(T->left) - Height(T->right) == 2)
				if (c < T->left->data)T = SingleRotationLeft(T);
				else T = DoubleRotationLR(T);
		}
		else
			if (c > T->data)
			{
				T->right = Insert(c, T->right);
				if (Height(T->right) - Height(T->left) == 2)
					if (c > T->right->data) T = SingleRotationRight(T);
					else T = DoubleRotationRL(T);
			}
	return T;
}
void Turn(pnode cur, int deep)
{
	if (cur->right) Turn(cur->right, deep + 1);
	for (int i = 1; i < deep; i++) printf("    ");
	cout << cur->data << endl;
	if (cur->left) Turn(cur->left, deep + 1);
}
int main()
{
	getline(cin, input);
	for(int i=0;i<input.size();i++) root = Insert(input[i], root);
	cout << "Preorder: ", Preorder(root);
	cout << "\nInorder: ", Inorder(root);
	cout << "\nPostorder: ", Postorder(root);
	cout << "\nTree:\n", Turn(root, 1);
	return 0;
}