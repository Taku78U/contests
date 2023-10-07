#include <bits/stdc++.h>

using namespace std;

string S;

int main()
{
    cin >> S;
    cin.ignore();

    for (int i = 1; i < S.size(); i = i + 2)
    {
        if (S[i] == '1')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
