#include "bits/stdc++.h"
using namespace std;
int pm , pmi , numb, n ;string input;
int main()
{
    cin >> n; cin.get();
    while (n--)
    {
        numb = 0,pm = 0,pmi = 0;getline(cin, input);
        for(int i=0;i<input.size();i++)
        {
            if (input[i] == '+')  numb++, ((numb > pm) ? (pm = numb) : (pm = pm));
            else  numb--, ((numb < pmi) ? (pmi = numb) : (pmi = pmi));
        }
        cout << pm - pmi << endl;
    }
    return 0;
}