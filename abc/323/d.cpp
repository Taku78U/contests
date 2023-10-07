#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N;
map<ll, ll> SC;

ll two_pwr[63];

// 参照 https://wandbox.org/permlink/6MbRkLx6Yh17zK5c
// mapのforループ中で新たな要素を挿入する

// void init()
// {
//     two_pwr[0] = 1;
//     for (int i = 1; i < 63; ++i)
//     {
//         two_pwr[i] = 2 * two_pwr[i];
//     }
// }

void read()
{
    cin >> N;
    cin.ignore();
    for (ll i = 0; i < N; ++i)
    {
        ll s, c;
        cin >> s >> c;
        cin.ignore();
        SC[s] = c;
    }
}

ll solver()
{
    ll rtn = 0;
    for (const auto &elm : SC)
    {
        auto s = elm.first;
        auto c = elm.second;

        if (c <= 1)
        {
            // cout << s << ", " << SC[s] << endl;
            rtn += c;
            continue;
        }

        auto new_s = s * 2;
        auto new_c = c / 2;
        SC[s] = c % 2;
        SC[new_s] += new_c;

        // cout << s << ", " << SC[s] << endl;

        rtn += SC[s];
    }
    return rtn;
}

int main()
{
    // init();
    read();
    cout << solver() << endl;
}
