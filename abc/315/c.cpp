#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<pair<ll, ll>> Cups; // おいしさと味のペア

ll solve()
{
    auto first = Cups[0];
    auto current_flavor = Cups[0].second;

    // 美味しさ最大+美味しさ2番目
    bool same_found = false;
    bool diff_found = false; // 先にこちらが見つかればその時点でreturn
    ll same_max = 0;
    ll diff_max = 0;
    for (int i = 1; i < Cups.size(); ++i)
    {
        const auto cup = Cups[i];
        if (!same_found && (current_flavor == cup.second))
        {
            same_max = first.first + cup.first / 2;
            same_found = true;
        }
        if (current_flavor != cup.second)
        {
            diff_max = first.first + cup.first;
            if (diff_max > same_max)  // 違う味が先に見つかれば、以降に見つかる同じ味との組み合わせよりは満足度は高いため見つかっているかは関係ない
            {
                diff_found = true;
                return diff_max;
            }
            else
            {
                return same_max; // 同じ味が先に見つかり、違う味だった場合と比べて満足度が高い
            }
        }
    }
    return same_max; // 違う味が見つからないことがある
}

int main()
{
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i)
    {
        ll f, s;
        cin >> f >> s;
        Cups.emplace_back(s, f);
    }
    sort(Cups.begin(), Cups.end(), std::greater<pair<ll, ll>>());
    cout << solve() << endl;

    return 0;
}