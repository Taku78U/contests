#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<vector<int>> P;  // P[a][b] == true: aはbより強い false: 関係性なし
vector<int> strength;

// baseを起点に最強人間の番号を出力する
void tansaku(const int base, const int point)
{
    strength[base] = point;
    for (int i = 0; i < N; ++i)
    {
        if (P[base][i] && strength[i] == INT_MIN)
        {
            tansaku(i, point - 1);
        }
        if (P[i][base] && strength[i] == INT_MIN)
        {
            tansaku(i, point + 1);
        }
    }
}

int saikyo(const int base)
{
    tansaku(base, 0);
    int point = 0;
    int saikyoperson = base;
    for (int i = 0; i < N; ++i)
    {
        if (i == base)
        {
            continue;
        }
        if (strength[i] > point)
        {
            saikyoperson = i;
            point = strength[i];
        }
    }
    return saikyoperson + 1;
}

int solve()
{
    // 起点を探す
    bool base_found = false;
    int saikyoperson = -1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // iを起点に探索開始 iが未探索の場合
            if (P[i][j] && (!base_found) && strength[i] == INT_MIN)
            {
                base_found = true;
                saikyoperson = saikyo(i);
            }
            else if (P[i][j] && strength[i] == INT_MIN)
            {
                // 起点が複数ある場合は特定不可能
                return -1;
            }
        }
    }

    if (!base_found)
    {
        return -1;
    }

    // 未探索の人がいる場合も特定不可能
    for (const auto& elm : strength)
    {
        if (elm == INT_MIN)
        {
            return -1;
        }
    }

    // 最強が複数いる場合は特定不可能
    for (int i = 0; i < N; ++i)
    {
        if (i == saikyoperson - 1)
        {
            continue;
        }
        if (strength[i] == strength[saikyoperson - 1])
        {
            return -1;
        }
    }
    return saikyoperson;
}

int main()
{
    cin >> N >> M;
    P.resize(N);
    for (auto& elm : P)
    {
        elm.resize(N, false);
    }
    strength.resize(N, INT32_MIN);
    cin.ignore();

    int person = 0;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cin.ignore();
        P[a][b] = true;
    }

    cout << solve() << endl;
}