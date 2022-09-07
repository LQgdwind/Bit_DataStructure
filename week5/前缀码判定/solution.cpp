#pragma GCC optimize(3,"Ofast","inline")   

#define re register

#include "bits/stdc++.h"

using namespace std;

class treenode
{
public:
    int d;
    treenode* left, * right;
};

string s;

int n, judge, l;

inline void createnewnode(treenode* & p,int i)
{
    p->left = p->right = NULL;
    p->d = (i == l - 1) ? 1 : 0;
}

int main() 
{
    treenode * root;
    root = new treenode;
    createnewnode(root, -1);
    cin >> n;
    while (n--)
    {
        treenode * p = root;   
        cin >> s;
        l = s.size();
        for (re int i = 0; i < l; i++)
        {
            if (s[i] == '0')
            {
                if (p->left == NULL)
                {
                    p->left = new treenode;
                    p = p->left;
                    createnewnode(p, i);
                }
                else
                {
                    if (p->left->d == 1 || i == l - 1) 
                    {
                         cout << s << endl;
                         return 0;
                    }
                    else p = p->left;
                }
            }
            else if (s[i] == '1')
            {
                if (p->right == NULL)
                {
                    p->right = new treenode;
                    p = p->right;
                    createnewnode(p, i);
                }
                else
                {
                    if (p->right->d == 1 || i == l - 1)
                    {
                        cout << s << endl;
                        return 0;
                    }
                    else p = p->right;
                }
            }
        } 
    }
    cout << "YES" << endl;
    return 0;
}