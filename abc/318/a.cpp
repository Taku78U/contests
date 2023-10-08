#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, P;
    cin >> N >> M >> P;
    cin.ignore();

    if (N < M)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 + (N - M) / P << endl;
    return 0;
}