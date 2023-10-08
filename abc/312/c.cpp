#include <bits/stdc++.h>

using namespace std;

int N, M;
struct Price
{
    int v;
    bool is_sell;
    Price(const int v_, const bool is_sell_)
    {
        v = v_;
        is_sell = is_sell_;
    }

    bool operator< (const Price& another) const
    {
        return (v == another.v) ? is_sell < another.is_sell : v < another.v;
    }
};

vector<Price> AB;

int solve()
{
    int buyer = M;
    int seller = 0;
    int x = 0;
    for (const auto& elm : AB)
    {
        x = elm.v;
        if (elm.is_sell)
        {
            ++seller;
        }
        else
        {
            --buyer;
        }
        if (seller >= buyer)
        {
            return x;
        }
    }
    return x;
}

int main()
{
    cin >> N >> M;
    cin.ignore();
    bool is_sell = true;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        AB.emplace_back(a, is_sell);
    }
    cin.ignore();
    is_sell = false;
    for (int i = 0; i < M; ++i)
    {
        int b;
        cin >> b;
        AB.emplace_back(b + 1, is_sell);  // b + 1円で買えなくなる
    }
    cin.ignore();

    sort(AB.begin(), AB.end());

    cout << solve() << endl;
    return 0;
}