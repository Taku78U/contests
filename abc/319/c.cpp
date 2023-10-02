#include <bits/stdc++.h>

using namespace std;

using ld = double;

using ll = long long;

int C[3][3];

void InitC()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> C[i][j];
        }
        cin.ignore();
    }
}

ld solver()
{
    auto v = vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8};
    // auto v = vector<int>{6, 3, 0, 1, 4, 5, 2, 7, 8};

    const ll lsum = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
    ll gakkari = 0;

    do
    {
        bool known[3][3];
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                known[i][j] = false;
            }
        }

        for (int k = 0; k < v.size(); ++k)
        {
            const int row = v[k] / 3;
            const int col = v[k] % 3;
            // known[row][col] = true;

            // 縦
            // 既に知ってる2マスの数字が同じで、今回だけ異なればがっかり
            vector<int> already_known;
            for (int i = 0; i < 3; ++i)
            {
                if(known[i][col])
                {
                    already_known.emplace_back(C[i][col]);
                }
            }

            // for (const auto& elm : already_known)
            // {
            //     cout << elm << " ";
            // }
            // cout << endl;
            if (already_known.size() == 2)
            {
                if (already_known[0] == already_known[1] && already_known[0] != C[row][col])
                {
                    ++gakkari;
                    break;
                }
            }

            already_known.clear();

            // 横
            for (int i = 0; i < 3; ++i)
            {
                if(known[row][i])
                {
                    already_known.emplace_back(C[row][i]);
                }
            }
            if (already_known.size() == 2)
            {
                if (already_known[0] == already_known[1] && already_known[0] != C[row][col])
                {
                    ++gakkari;
                    break;
                }
            }

            already_known.clear();

            // 右斜め 特定の行・列位置の場合しかチェックしない
            if (v[k] == 0 || v[k] == 4 || v[k] == 8)
            {
                if(known[0][0])
                {
                    already_known.emplace_back(C[0][0]);
                }
                if(known[1][1])
                {
                    already_known.emplace_back(C[1][1]);
                }
                if(known[2][2])
                {
                    already_known.emplace_back(C[2][2]);
                }
                if (already_known.size() == 2)
                {
                    if (already_known[0] == already_known[1] && already_known[0] != C[row][col])
                    {
                        ++gakkari;
                        break;
                    }
                }
            }

            already_known.clear();

            // 左斜め 特定の行・列位置の場合しかチェックしない
            if (v[k] == 2 || v[k] == 4 || v[k] == 6)
            {
                if(known[0][2])
                {
                    already_known.emplace_back(C[0][2]);
                }
                if(known[1][1])
                {
                    already_known.emplace_back(C[1][1]);
                }
                if(known[2][0])
                {
                    already_known.emplace_back(C[2][0]);
                }
                if (already_known.size() == 2)
                {
                    if (already_known[0] == already_known[1] && already_known[0] != C[row][col])
                    {
                        ++gakkari;
                        break;
                    }
                }
            }

            known[row][col] = true;
        }
    }
    while (next_permutation(v.begin(), v.end()));

    // cout << gakkari << endl;
    // cout << lsum << endl;

    return (lsum - gakkari) / static_cast<ld>(lsum);
}

int main()
{
    InitC();
    printf("%.13lf\n", solver());
}