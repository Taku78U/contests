#include <bits/stdc++.h>

using namespace std;

int N, M;
string S;
vector<int> C;
vector<vector<int>> CIDX; // S内の色ごとのインデックス集 これ自身のidxは色番号-1


int main()
{
    cin >> N >> M;
    cin.ignore();
    cin >> S;
    cin.ignore();
    C.resize(N);
    CIDX.resize(M);
    for (int i = 0; i < N; ++i)
    {
        cin >> C[i];
        CIDX[C[i] - 1].emplace_back(i);
    }
    cin.ignore();

    // 出力を2番目のインデックスから順に行えばよいだけである
    vector<int> cp;
    cp.resize(M, 0);
    // 2つ以上あるものは1より出力する
    for (int i = 0; i < CIDX.size(); ++i)
    {
        if (CIDX[i].size() > 1)
        {
            cp[i] = CIDX[i].size() - 1;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        auto& idx_ptr = cp[C[i] - 1];
        const auto idx = CIDX[C[i] - 1][idx_ptr];
        cout << S[idx];
        ++idx_ptr;
        if (idx_ptr >= CIDX[C[i] - 1].size())
        {
            idx_ptr = 0;
        }
    }
    cout << endl;
    return 0;
}