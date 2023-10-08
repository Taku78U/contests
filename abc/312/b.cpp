#include <bits/stdc++.h>

using namespace std;

int N, M;
bool S[100][100];

bool issqblack(const int row_idx, const int col_idx, const int len)
{
    if (col_idx + len > M || row_idx + len > N)
    {
        return false;
    }
    for (int i = row_idx; i < row_idx + len; ++i)
    {
        for (int j = col_idx; j < col_idx + len; ++j)
        {
            if (!S[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool isTak(const int row_idx, const int col_idx)
{
    if (col_idx + 9 > M || row_idx + 9 > N)
    {
        return false;
    }
    if (!issqblack(row_idx, col_idx, 3))
    {
        return false;
    }
    if (!issqblack(row_idx + 6, col_idx + 6, 3))
    {
        return false;
    }
    
    for (int i = row_idx; i < row_idx + 4; ++i)
    {
        if (S[i][col_idx + 3])
        {
            return false;
        }
    }
    for (int i = row_idx + 5; i < row_idx + 9; ++i)
    {
        if (S[i][col_idx + 5])
        {
            return false;
        }
    }
    for (int j = col_idx; j < col_idx + 4; ++j)
    {
        if (S[row_idx + 3][j])
        {
            return false;
        }
    }
    for (int j = col_idx + 5; j < col_idx + 9; ++j)
    {
        if (S[row_idx + 5][j])
        {
            return false;
        }
    }
    return true;
}

auto solve()
{
    vector<pair<int, int>> rtn;
    for (int row_idx = 0; row_idx < N; ++row_idx)
    {
        for (int col_idx = 0; col_idx < M; ++col_idx)
        {
            if (isTak(row_idx, col_idx))
            {
                rtn.emplace_back(row_idx + 1, col_idx + 1);
            }
        }
    }
    return rtn;
}

int main()
{
    cin >> N >> M;
    cin.ignore();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                S[i][j] = true;
            }
            else
            {
                S[i][j] = false;
            }
        }
        cin.ignore();
    }
    const auto ans = solve();
    for (const auto& elm : ans)
    {
        cout << elm.first << " " << elm.second << endl;
    }
    return 0;
}