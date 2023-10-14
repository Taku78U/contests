#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int main()
{
    cin >> N;
    cin.ignore();
    A.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    cin.ignore();

    const auto first = A[0];
    for (int i = 1; i < N; ++i)
    {
        if (A[i] != first)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}