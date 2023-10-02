#include <bits/stdc++.h>

using namespace std;

string S;

int main()
{
    cin >> S;
    cin.ignore();

    for (int i = 0; i < S.size(); ++i)
    {
        char c = S[i];
        if (!(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'))
        {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}