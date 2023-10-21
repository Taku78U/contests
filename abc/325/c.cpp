#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<vector<bool>> S;

// どのマスを起点としたセンサにつながれているか
// 数は、W*行番号+列番号
vector<vector<int>> T;

void read()
{
    cin >> H >> W;
    cin.ignore();

    S.resize(H);
    for (auto&& s : S)
    {
        s.resize(W, false);
    }

    for (int i = 0; i < H; ++i)
    {
        string s;
        cin >> s;
        cin.ignore();
        for (int j = 0; j < W; ++j)
        {
            if (s[j] == '#')
            {
                S[i][j] = true;
            }
        }
    }

    T.resize(H);
    for (auto&& t : T)
    {
        t.resize(W, -1);
    }
}

void mark(const int i, const int j, const int num)
{
    T[i][j] = num;
    // 左上
    if (i - 1 >= 0 && j - 1 >= 0)
    {
        if (S[i - 1][j - 1] && T[i - 1][j - 1] == -1)
        {
            mark(i - 1, j - 1, num);
        }
    }

    // 左
    if (j - 1 >= 0)
    {
        if (S[i][j - 1] && T[i][j - 1] == -1)
        {
            mark(i, j - 1, num);
        }
    }

    // 左下
    if (i + 1 < H && j - 1 >= 0)
    {
        if (S[i + 1][j - 1] && T[i + 1][j - 1] == -1)
        {
            mark(i + 1, j - 1, num);
        }
    }
    // 下
    if (i + 1 < H)
    {
        if (S[i + 1][j] && T[i + 1][j] == -1)
        {
            mark(i + 1, j, num);
        }
    }
    // 右下
    if (i + 1 < H && j + 1 < W)
    {
        if (S[i + 1][j + 1] && T[i + 1][j + 1] == -1)
        {
            mark(i + 1, j + 1, num);
        }
    }
    // 右
    if (j + 1 < W)
    {
        if (S[i][j + 1] && T[i][j + 1] == -1)
        {
            mark(i, j + 1, num);
        }
    }
    // 右上
    if (i - 1 >= 0 && j + 1 < W)
    {
        if (S[i - 1][j + 1] && T[i - 1][j + 1] == -1)
        {
            mark(i - 1, j + 1, num);
        }
    }
    // 上
    if (i - 1 >= 0)
    {
        if (S[i - 1][j] && T[i - 1][j] == -1)
        {
            mark(i - 1, j, num);
        }
    }
}

int solve()
{
    int rtn = 0;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (!S[i][j])
            {
                continue;
            }

            // すでに番号付けされていた
            if (T[i][j] != -1)
            {
                continue;
            }

            ++rtn;
            mark(i, j, W * i + j);
        }
    }
    return rtn;
}

int main()
{
    read();
    cout << solve() << endl;
}