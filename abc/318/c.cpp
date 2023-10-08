#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

ll N, D, P;
vector<ll> F;

ll solver()
{
    sort(F.begin(), F.end(), greater<ll>());
    ll i = 0;
    ll ans = 0;
    for (i = 0; i < N; i += D)
    {
        ll fadd = 0;
        for (ll j = i; j < i + D && j < N; ++j)
        {
            fadd += F[j];
        }
        // cout << "fadd " << fadd << endl;
        if (fadd < P)
        {
            ans += fadd;
        }
        else
        {
            ans += P;
        }
    }

    // // 端数
    // ll fadd_final = 0;
    // for (; i < N; ++i)
    // {
    //     fadd_final += F[i];
    // }
    // if (fadd_final < P)
    // {
    //     ans += fadd_final;
    // }
    // else
    // {
    //     ans += P;
    // }
    return ans;
}

int main()
{
    cin >> N >> D >> P;
    cin.ignore();

    for (int i = 0; i < N; ++i)
    {
        ll f;
        cin >> f;
        F.emplace_back(f);
    }
    cin.ignore();

    cout << solver() << endl;
}