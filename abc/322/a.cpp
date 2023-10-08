#include <bits/stdc++.h>

using namespace std;

int N;
string S;

int main()
{
    cin >> N;
    cin.ignore();
    cin >> S;
    cin.ignore();

    int pos = S.find("ABC");

    if (pos == string::npos)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << pos + 1 << endl;
}