#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cin.ignore();
    if (s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA" || s == "EGB" || s == "FAC" || s == "GBD")
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}