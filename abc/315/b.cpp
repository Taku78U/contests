#include <bits/stdc++.h>

using namespace std;

int M;
vector<int> D;
vector<int> SumD;

auto solve(const int mid)
{
    pair<int, int> rtn;
    // まず1月目
    if (mid <= SumD[0])
    {
        return pair<int, int>(1, mid);
    }
    for (int i = 1; i < M; ++i)
    {
        if (mid <= SumD[i])
        {
            rtn.first = i + 1;
            rtn.second = mid - SumD[i - 1];
            break;
        }
    }
    return rtn;
}

int main()
{
    cin >> M;
    cin.ignore();
    D.resize(M);
    SumD.resize(M);
    int sumd = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> D[i];
        sumd += D[i];
        SumD[i] = sumd;
    }
    cin.ignore();
    const auto mid = (SumD[SumD.size() - 1] + 1) / 2;
    // cout << mid << endl;
    // for (const auto& elm : SumD)
    // {
    //     cout << elm << " ";
    // }
    // cout << endl;
    const auto ans = solve(mid);
    cout << ans.first << " " << ans.second << endl;
}