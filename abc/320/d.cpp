#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N, M;

struct Distance
{
    ll x = 0;
    ll y = 0;
    Distance() = default;
    Distance(const ll in_x, const ll in_y) : x(in_x), y(in_y) {}
    bool operator< (const Distance& another) const {
        return x == another.x ? y < another.y : x < another.x;
    }
    bool operator== (const Distance& another) const {
        return x == another.x && y == another.y;
    }
};

using Axis = Distance;

// pair は、相手と距離のペア
vector<vector<pair<ll, Distance>>> G(2 * 100000);

const auto NO_AXIS = Axis(LLONG_MIN, LLONG_MIN);
vector<Axis> Axes(2 * 100000, NO_AXIS);

// 相手の座標を決定する
void decider(ll idx)
{
    const auto& g = G[idx];
    const auto &current_axis = Axes[idx];
    if (g.empty())
    {
        return;
    }
    for (const auto& opp: g)
    {
        if (!(Axes[opp.first] == NO_AXIS))
        {
            continue; // 矛盾はないので、既に有効な値が書かれていたら無視(既に探索済み)
        }
        const auto d = opp.second;
        Axes[opp.first] = Axis(current_axis.x + d.x, current_axis.y + d.y);
        decider(opp.first);
    }
    return;
}

void solver()
{
    Axes[0] = Axis(0, 0);

    // 0からたどる
    decider(0);
}

int main()
{
    cin >> N >> M;
    for (ll i = 0; i < M; ++i)
    {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        cin.ignore();
        --a;
        --b;
        G[a].emplace_back(b, Distance(x, y));
        G[b].emplace_back(a, Distance(-1 * x, -1 * y));
    }

    // とりあえず並べ替えておく
    // for (ll i = 0; i < N; ++i)
    // {
    //     sort(G[i].begin(), G[i].end());
    // }

    solver();

    for (ll i = 0; i < N; ++i)
    {
        // cout << i + 1 << " ";
        const auto &axis = Axes[i];
        if (axis == NO_AXIS)
        {
            cout << "undecidable" << endl;
            continue;
        }
        cout << axis.x << " " << axis.y << endl;
    }
    return 0;
}