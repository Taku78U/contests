#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> C;
vector<vector<bool>> A;
int X;

int main()
{
    cin >> N;
    cin.ignore();
    C.resize(N);
    A.resize(N);
    for (auto& elm : A)
    {
        elm.resize(37);
    }


    for (int i = 0; i < N; ++i)
    {
        cin >> C[i];
        cin.ignore();
        for (int j = 0; j < C[i]; ++j)
        {
            int a;
            cin >> a;
            A[i][a] = true;
        }
        cin.ignore();
    }

    cin >> X;
    cin.ignore();

    vector<int> idx_ans;
    int minim = INT_MAX;

    for (int i = 0; i < N; ++i)
    {
        if (A[i][X])
        {
            if (C[i] < minim)
            {
                minim = C[i];
                idx_ans.clear();
                idx_ans.emplace_back(i);
            }
            else if (C[i] == minim)
            {
                idx_ans.emplace_back(i);
            }
        }
    }

    cout << idx_ans.size() << endl;
    for (int i = 0; i < idx_ans.size(); ++i)
    {
        cout << idx_ans[i] + 1;
        if (i < idx_ans.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
