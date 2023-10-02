#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int H, W;
std::vector<std::string> C;

// #define DBG

bool all_same_row(const vector<int> skip_col_idxs, const int row_idx){
    int ptr = 0;
    // 最初を見つける
    char first = 'a';
    int col_idx = 0;
    for (col_idx = 0; col_idx < W; ++col_idx)
    {
        if (ptr < skip_col_idxs.size() && skip_col_idxs[ptr] == col_idx)
        {
            ++ptr;
            continue;
        }
        first = C[row_idx][col_idx];
        break;
    }

    bool passed = false;
    ++col_idx;
    for (; col_idx < W; ++col_idx)
    {
        if (ptr < skip_col_idxs.size() && skip_col_idxs[ptr] == col_idx)
        {
            ++ptr;
            continue;
        }

        passed = true;
        if (first != C[row_idx][col_idx])
        {
            return false;
        }
    }
    return passed;
}

bool all_same_col(const vector<int> skip_col_idxs, const int row_idx){
    int ptr = 0;
    // 最初を見つける
    char first = 'a';
    int col_idx = 0;
    for (col_idx = 0; col_idx < H; ++col_idx)
    {
        if (ptr < skip_col_idxs.size() && skip_col_idxs[ptr] == col_idx)
        {
            ++ptr;
            continue;
        }
        first = C[col_idx][row_idx];
        break;
    }

    bool passed = false;
    ++col_idx;
    for (; col_idx < H; ++col_idx)
    {
        if (ptr < skip_col_idxs.size() && skip_col_idxs[ptr] == col_idx)
        {
            ++ptr;
            continue;
        }

        passed = true;
        if (first != C[col_idx][row_idx])
        {
            return false;
        }
    }
    return passed;
}

ll solve()
{
    ll sum = H * W;
    auto current_h = H;
    auto current_w = W;

    vector<int> skip_row_idxs;
    vector<int> skip_col_idxs;

#ifdef DBG
    int loop = 0;
    while(loop++ < 3)
#else
    while(1)
#endif
    {
        auto current_sum = sum;
        const auto previous_skip_row_idxs = skip_row_idxs;
#ifdef DBG
        cout << "ch: " << current_h << endl;
        cout << "c2: " << current_w << endl;
#endif
        // 行チェック
        int jogai_row = 0;
        if (current_h >= 2)
        {
            int ptr = 0;
            for (int i = 0; i < H; ++i)
            {
                if (ptr < previous_skip_row_idxs.size() && i == previous_skip_row_idxs[i])
                {
                    continue;
                }
#ifdef DBG
                cout << i << ": R " << all_same_row(skip_col_idxs, i) << endl;
#endif
                if (all_same_row(skip_col_idxs, i))
                {
                    sum -= current_w;
                    skip_row_idxs.emplace_back(i);
                    ++jogai_row;
                }
            }
        }
        current_h -= jogai_row;

        // 列チェック
        int jogai_col = 0;
        if (current_w >= 2)
        {
            int ptr = 0;
            for (int i = 0; i < W; ++i)
            {
                if (ptr < skip_col_idxs.size() && i == skip_col_idxs[i])
                {
                    continue;
                }
#ifdef DBG
                cout << i << ": C " << all_same_col(previous_skip_row_idxs, i) << endl;
#endif
                if (all_same_col(previous_skip_row_idxs, i))
                {
                    sum -= current_h;
                    skip_col_idxs.emplace_back(i);
                    ++jogai_col;
                }
            }
        }
        current_w -= jogai_col;

        sort(skip_row_idxs.begin(), skip_row_idxs.end());
        sort(skip_col_idxs.begin(), skip_col_idxs.end());
#ifdef DBG
        cout << sum << endl;
#endif

        if (sum == current_sum)
        {
            return sum;
        }
    }
    return sum;
}

int main()
{
    cin >> H >> W;
    cin.ignore();
    C.resize(H);

    for (int i = 0; i < H; ++i)
    {
        cin >> C[i];
        cin.ignore();
    }

    cout << solve() << endl;
}