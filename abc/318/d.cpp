#include <bits/stdc++.h>

using namespace std;

using ll = long long;
ll N;
vector<vector<ll>> D;
vector<ll> V; // 0～N-1までの順列

ll solver()
{
    ll ans = 0;
    do {
        // 2つずつ区切り、小さい順にし、順次足しこむ
        ll dsum = 0;
        for (int i = 0; i < N; i += 2)
        {
            if (i + 1 >= N)
            {
                break;
            }
            ll first = V[i];
            ll second = V[i + 1];
            if (first > second)
            {
                ll tmp = first;
                first = second;
                second = first;
            }
            // cout << first << " " << second << endl;
            dsum += D[first][second];
        }
        if (dsum > ans)
        {
            ans = dsum;
        }
    } while (next_permutation(V.begin(), V.end()));
    return ans;
}
map<ll, map<ll>> mp;
ll solver2()
{
    ll ans = 0;

    
}

int main()
{
    cin >> N;

    V.resize(N, 0);
    for (ll i = 0; i < N; ++i)
    {
        V[i] = i;
    }
    D.resize(N - 1);
    for (auto& elm : D)
    {
        elm.resize(N, 0);
    }

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            cin >> D[i][j];
        }
        cin.ignore();
    }

    cout << solver() << endl;
}