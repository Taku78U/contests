#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll N, M;
vector<ll> A;

int main()
{
    cin >> N >> M;
    cin.ignore();
    A.resize(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> A[i];
    }
    cin.ignore();

    std::size_t ptr = 0;
    for (ll i = 1; i <= N; ++i)
    {
        auto a = A[ptr];
        if (i < a)
        {
            cout << a - i << endl;
            continue;
        }
        if (i == a)
        {
            cout << 0 << endl;
        }
        // i >= a
        if (ptr < A.size() - 1)
        {
            ++ptr;
        }
    }

}
