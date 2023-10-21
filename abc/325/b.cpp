#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> W, X;

int calc_local_hour(const int h, const int x)
{
    auto local_h = h + x;
    if (local_h >= 24)
    {
        local_h -= 24;
    }
    return local_h;
}

int solve()
{
    int rtn = 0;
    for (int hour = 0; hour < 24; ++hour)
    {
        int joins = 0;
        for (int i = 0; i < N; ++i)
        {
            const auto local_h = calc_local_hour(hour, X[i]);
            if (9 <= local_h && local_h < 18)
            {
                joins += W[i];
            }
        }
        if (rtn < joins)
        {
            rtn = joins;
        }
    }
    return rtn;
}

int main()
{
    cin >> N;
    W.resize(N);
    X.resize(N);

    cin.ignore();

    for (int i = 0; i < N; ++i)
    {
        cin >> W[i] >> X[i];
        cin.ignore();
    }

    cout << solve() << endl;
    return 0;
}