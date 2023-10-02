#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll LLONG_INF = 1000000001;

vector<vector<ll>> Dp; // i番目までの区の中からいくつかの選挙区で寝返りを起こさせて獲得できる議席の数をjにするのに必要な裏切り者の最低人数

ll N;
ll NeededN = 0;
ll NeededChairs;
vector<pair<ll, ll>> Elec; // first: 議席数 second: takahashiに勝たせるために必要な寝返り数

void init_dp()
{
    for (ll i = 0; i < 100; ++i)
    {
        Dp.emplace_back(vector<ll>(100001, LLONG_INF));
    }
}

ll solve()
{
    Dp[0][0] = 0;
    for (ll i = 0; i < Elec.size(); ++i)
    {
        for (ll j = 0; j < 100001; ++j)
        {
            if (j >= Elec[i].first && Dp[i][j - Elec[i].first] != LLONG_INF)
            {
                if (Dp[i + 1][j] > Dp[i][j - Elec[i].first] + Elec[i].second)
                {
                    Dp[i + 1][j] = Dp[i][j - Elec[i].first] + Elec[i].second;
                    cout << "i " << i << " Elec[i] " << Elec[i].first << ", " << Elec[i].second <<  " j " << j << " Dp[i + 1][j] " << Dp[i + 1][j] << endl;
                }
            }
            else
            {
                Dp[i + 1][j] = Dp[i][j];
            }
        }
    }

    ll rtn = LLONG_INF;

    for (ll i = 0; i < Elec.size() + 1; ++i)
    {
        for (ll j = NeededChairs; j < 100001; ++j)
        {
            if (Dp[i][j] < rtn)
            {
                rtn = Dp[i][j];
                cout << "i " << i << " j " << j << " rtn " << rtn << endl;
            }
        }
    }

    return rtn;
}

int main()
{
    init_dp();
    cin >> N;
    cin.ignore();
    ll already_alloc = 0;
    ll sum = 0;
    for (ll i = 0; i < N; ++i)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        cin.ignore();
        sum += z;
        if (x > y)
        {
            already_alloc += z;
            continue;
        }
        ++NeededN;
        ll n_yuda = (x + y) / 2 + 1 - x;
        Elec.emplace_back(z, n_yuda);
    }

    // sort(Elec.begin(), Elec.end(), std::greater<>());
    NeededChairs = sum / 2 + 1 - already_alloc;

    cout << "sum " << sum << endl;
    cout << "alr " << already_alloc << endl;
    cout << "Needed " << NeededChairs << endl;

    if (NeededChairs <= 0)
    {
        cout << 0 << endl;
        return 0;
    }

    cout << solve() << endl;
    return 0;
}