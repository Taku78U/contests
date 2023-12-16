#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N;

struct STTD
{
    ll t;
    ll d;
    STTD(const ll t_, const ll d_) : t(t_), d(d_) {}
    bool operator< (const STTD& another) const
    {
        return t == another.t ? d < another.d : t < another.t;
    }
    void rem(const ll tm)
    {
        t -= tm;
    }
};

vector<STTD> TD;

void read()
{
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i)
    {
        ll t, d;
        cin >> t >> d;
        cin.ignore();
        TD.emplace_back(t, d);
    }
    sort(TD.begin(), TD.end());
}

vector<map<ll, ll>> mps;

ll solve()
{
    mps.resize(N);
    mps[0][TD[0].t] = 0;
    mps[0][TD[0].t + TD[0].d + 1] = 1;

    for (int i = 1; i < N; ++i)
    {
        const auto& pre_mp = mps[i - 1];
        const auto& td = TD[i];
        mps[i][td.t] = 0;  // 今までも印字なくiにも印字しない
        mps[i][td.t + td.d + 1] = 1; // 今まで印字なく最初にiに印字する
        for (const auto& status : pre_mp)
        {
            if (status.first < td.t){
                if (mps[i][td.t] < status.second) // 印字できるけどしない場合の更新
                {
                    mps[i][td.t] = status.second;
                }
                if (mps[i][td.t + td.d + 1] < status.second + 1) // 印字する場合の更新
                {
                    mps[i][td.t + td.d + 1] = status.second + 1;
                }
            }
            else  // iに印字できない
            {
                mps[i][status.first] = status.second;
            }
        }
    }

    ll rtn = 0;
    for (const auto& status : mps[N - 1])
    {
        if (rtn < status.second)
        {
            rtn = status.second;
        }
    }
    return rtn;
}

ll solve2()
{
    priority_queue<ll, vector<ll>, greater<ll>> tmp;
    tmp.push(TD[0].t + TD[0].d - 1);
    int ptr = 0;
    for (int i = 1; i < N; ++i)
    {
        if (TD[i].t != TD[0].t)
        {
            break;
        }
        tmp.push(TD[i].t + TD[i].d - 1);
        ptr = i;
    }

    ++ptr;

    ll t = TD[0].t;

    int rtn = 0;
    while(!tmp.empty())
    {
        // 先頭tの時刻まで印字
        int num_out = 0;
        while(!tmp.empty())
        {
            const auto f = tmp.top();
            if (f < t)
            {
                tmp.pop();
                continue;
            }
            if (ptr < N && t >= TD[ptr].t)
            {
                break;
            }
            ++rtn;
            ++t;
            tmp.pop();
        }


        if (ptr >= N)
        {
            break;
        }

        t = TD[ptr].t;
        tmp.push(TD[ptr].t + TD[ptr].d - 1);
        ++ptr;
        for (; ptr < N; ++ptr)
        {
            if (TD[ptr].t == t)
            {
                tmp.push(TD[ptr].t + TD[ptr].d);
            }
        }
    }
    return rtn;
}

int main()
{
    read();
    cout << solve2() << endl;
    return 0;
}
