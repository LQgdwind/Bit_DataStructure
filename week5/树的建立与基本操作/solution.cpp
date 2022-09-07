#pragma GCC optimize(3,"Ofast","inline")   

#define re register

#include "bits/stdc++.h"

using namespace std;

namespace tree
{
    char hhh[100];
    int hhhh = 0;
    int hhhhh[100], degreeee[100];
    int lalalal = -1;
}
namespace my
{
    int nb = 0;
}
int p[100];
int main() 
{
    char c;
    while (true)
    {
        cin.get(c);
        if (c == '\n') break;
        if (c == '(')
        {
            tree::lalalal++;
        }
        else if (c == ')')
        {
            tree::lalalal--;
        }
        else if (c == ',')
        {
            continue;
        }
        else
        {
            tree::hhhh++;
            tree::hhh[tree::hhhh] = c;
            tree::hhhhh[tree::hhhh] = tree::lalalal;
        }
    }
    for (re int i = 1; i <= tree::hhhh; i++)
    {
        for (re int j = 0; j < tree::hhhhh[i]; j++)
        {
            cout << "    ";
        }
        cout << tree::hhh[i] << endl;
    }
    for (re int i = 1; i <= tree::hhhh; i++)
    {
        for (re int j = i + 1; j <= tree::hhhh; j++)
        {
            if (tree::hhhhh[j] == tree::hhhhh[i]) break;
            if (tree::hhhhh[j] == tree::hhhhh[i] + 1) tree::degreeee[i]++;
        }
    }
    for (re int i = 1; i <= tree::hhhh; i++)
    {
        if (tree::degreeee[i] > my::nb)
        {
            my::nb = tree::degreeee[i];
        }
    }
    for (re int i = 1; i <= tree::hhhh; i++)
    {
        p[tree::degreeee[i]]++;
    }
    cout << "Degree of tree: " << my::nb << endl;
    for (re int i = 0; i <= my::nb; i++)
    {
        cout << "Number of nodes of degree " << i << ": " << p[i] << endl;
    }
    return 0;
}