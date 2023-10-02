#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, M;
vector<ll> L;

ll solver()
{
    ll right = *max_element(L.begin(), L.end());
    ll left = accumulate(L.begin(), L.end(), 0LL) + L.size() - 1;
}

int main()
{
    cin >> N >> M;
    cin.ignore();

    L.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> L[i];
        ++L[i];
    }
    cin.ignore();

    cout << solver() << endl;
    return 0;
}