#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll N, X;
vector<ll> T;

void read()
{
    cin >> N >> X;
    cin.ignore();
    T.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> T[i];
    }
    cin.ignore();
    return;
}

class Progress
{
public:
    Progress(const ll N, const vector<ll>& musics, const ll X): t_(0), n_(N), x_(X)
    {
        remains_ = musics;
        musics_ = musics;
        dp_.resize(N);
        for (auto&& d : dp_)
        {
            d.resize(X, 0);
        }
    }

    ll update_X(const ll x)
    {
        for (ll i = 0; i < x; ++i)
        {
            
        }
    }

private:
    ll t_;
    ll n_;
    ll x_;
    vector<ll> remains_;
    vector<ll> musics_;
    vector<vector<ll>> dp_;

    void sub_update()
    {

    }
};

ll solve()
{

}

int main()
{
    read();
    cout << solve() << endl;
}