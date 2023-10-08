#include <bits/stdc++.h>

using namespace std;

int N, M;
string S, T;

int main()
{
    cin >> N >> M;
    cin.ignore();
    cin >> S;
    cin.ignore();
    cin >> T;
    cin.ignore();

    int pos = T.find(S);
    bool is_prefix = (pos == 0);
    auto T_suffix = T.substr(M - N, N);
    bool is_suffix = (S == T_suffix);
    
    if (is_prefix && is_suffix)
    {
        cout << 0 << endl;
        return 0;
    }
    if (is_prefix)
    {
        cout << 1 << endl;
        return 0;
    }
    if (is_suffix)
    {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
    return 0;
}