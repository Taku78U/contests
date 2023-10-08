#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// vector<vector<vector<bool>>> P;

// void init()
// {
//     P.resize(3);
//     for (auto& elm : P)
//     {
//         elm.resize(4);
//         for (auto& eelm : elm)
//         {
//             eelm.resize(4, false);
//         }
//     }
// }

// void read()
// {
//     for (auto& elm : P)
//     {
//         for (auto& eelm : elm)
//         {
//             for (int i = 0; i < eelm.size(); ++i)
//             {
//                 char c;
//                 cin >> c;
//                 if (c == '#')
//                 {
//                     eelm[i] = true;
//                 }
//             }
//             cin.ignore();
//         }
//     }
// }

vector<vector<pair<int, int>>> P;

void init()
{
    P.resize(3);
}

void read()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                char c;
                cin >> c;
                if (c == '#')
                {
                    P[i].emplace_back(j, k);
                }
            }
            cin.ignore();
        }
    }
}

auto rotation(const vector<pair<int, int>>& pairs, const int rot)
{
    if (rot == 0)
    {
        return pairs;
    }
    auto rtn = vector<pair<int, int>>();
    if (rot == 1) // right 90 deg
    {
        for (auto& p : pairs)
        {
            auto row = p.second;
            auto col = 3 - p.first;
            rtn.emplace_back(row, col);
        }
        return rtn;
    }
    if (rot == 2) // right 180 deg
    {
        for (auto& p : pairs)
        {
            auto row = 3 - p.first;
            auto col = 3 - p.second;
            rtn.emplace_back(row, col);
        }
        return rtn;
    }
    // if (rot == 3) // right 180 deg
    {
        for (auto& p : pairs)
        {
            auto row = 3 - p.second;
            auto col = p.first;
            rtn.emplace_back(row, col);
        }
    }
    return rtn;
}

bool put(const int pnum, const vector<vector<bool>>&  tbl)
{
    const auto& pairs_org = P[pnum];
    for (int rot = 0; rot < 4; ++rot)
    {
        auto pairs = rotation(pairs_org, rot);
        for (int w = -3; w <= 3; ++w)
        {
            for (int h = -3; h <= 3; ++h)
            {
                auto new_tbl = tbl;
                bool ok = true;
                for (const auto& p : pairs)
                {
                    const auto row = p.first + h;
                    const auto col = p.second + w;
                    if (row < 0 || row >= 4)
                    {
                        ok = false;
                        break;
                    }
                    if (col < 0 || col >= 4)
                    {
                        ok = false;
                        break;
                    }
                    if (new_tbl[row][col])
                    {
                        ok = false;
                        break;
                    }
                    new_tbl[row][col] = true;
                }
                if (!ok)
                {
                    continue;
                }
                if (pnum == 2)
                {
                    return true;
                }
                return put(pnum + 1, new_tbl);
            }
        }
    }
    return false;
}

auto solve()
{
    vector<vector<bool>> tbl;
    tbl.resize(4);
    for (auto& t : tbl)
    {
        t.resize(4, false);
    }

    if (put(0, tbl))
    {
        return string("Yes");
    }
    return string("No");
}

int main()
{
    init();
    read();
    cout << solve() << endl;

}