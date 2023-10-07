#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A;
vector<string> S;
vector<int> ASum;

void read()
{
    cin >> N >> M;
    cin.ignore();
    A.resize(M);
    S.resize(N);
    for (int i = 0; i < M; ++i)
    {
        cin >> A[i];
    }
    cin.ignore();
    // cout << "AR" << endl;

    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
        cin.ignore();
    }
}

int subsolver(const int idx, const int max_point, const vector<int>& SSum, const vector<pair<int, int>>& ASorted)
{
    const auto ssum = SSum[idx];
    if (ssum >= max_point)
    {
        return 0;
    }

    // 貪欲法
    auto current_ssum = ssum;
    int count = 0;
    for (int i = 0; i < ASorted.size(); ++i)
    {
        const auto& asorted = ASorted[i];
        const int j = asorted.second;  // 問題インデックス
        if (S[idx][j] == 'x')
        {
            ++count;
            current_ssum += asorted.first;
            if (current_ssum > max_point)
            {
                return count;
            }
        }
    }
    return count; // dummy
}

void solve()
{
    auto ASorted = vector<pair<int, int>>(A.size());
    for (int i = 0; i < A.size(); ++i)
    {
        ASorted.emplace_back(A[i], i);
    }
    sort(ASorted.begin(), ASorted.end(), greater<pair<int, int>>());

    // これまで解いた和
    auto SSum = vector<int>(S.size(), 0);
    for (int i = 0; i < S.size(); ++i)
    {
        auto s = S[i];
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] == 'o')
            {
                SSum[i] += A[j];
            }
        }
    }

    // ボーナス点加算
    for (int i = 0; i < S.size(); ++i)
    {
        SSum[i] += i + 1; // 問題文では1-originであることに注意(しなくてもよいかも)
    }

    // 最大得点
    auto max_point = *max_element(SSum.begin(), SSum.end());

    for (int i = 0; i < S.size(); ++i)
    {
        auto result = subsolver(i, max_point, SSum, ASorted);
        cout << result << endl;
    }
}

int main()
{
    read();
    solve();
}