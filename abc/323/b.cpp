#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> S;
vector<int> W;

struct Score
{
    int score;
    int idx;
    Score(int score_in, int idx_in) : score(score_in), idx(idx_in){}
    bool operator>(const Score& another) const
    {
        return (score == another.score) ? idx < another.idx : score > another.score;
    }
};

void solve()
{
    // i < j の範囲で比較すればよい
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (S[i][j] == 'x')
            {
                ++W[j];
            }
            else
            {
                ++W[i];
            }
        }
    }

    // 勝数、プレイヤー番号のペアに入れてソート
    vector<Score> pairs;
    for (int i = 0; i < N; ++i)
    {
        pairs.emplace_back(W[i], i);
    }
    sort(pairs.begin(), pairs.end(), greater<Score>());
    for (int i = 0; i < N; ++i)
    {
        const auto &pair = pairs[i];
        cout << pair.idx + 1;
        if (i == N - 1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}

int main()
{
    cin >> N;
    cin.ignore();
    S.resize(N);
    W.resize(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
        cin.ignore();
    }

    solve();
    return 0;
}
