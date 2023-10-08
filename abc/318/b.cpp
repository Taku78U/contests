#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<bool>> S;

int solver()
{
    for (int i = 0; i < N; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = c; j < d; ++j)  // Y
        {
            for (int k = a; k < b; ++k)  // X
            {
                S[j][k] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (S[i][j])
            {
                ++ans;
            }
        }
    }
    return ans;
}

int main()
{
    cin >> N;
    cin.ignore();
    S.resize(100);
    for (int i = 0; i < 100; ++i)
    {
        auto& s = S[i];
        s.resize(100, false);
    }

    cout << solver() << endl;
    return 0;
}