#include <bits/stdc++.h>

using namespace std;

int N, K;

void print2darr(const vector<vector<int>>& a)
{
    for (const auto& elm : a)
    {
        for (const auto& eelm : elm)
        {
            cout << eelm << " ";
        }
        cout << endl;
    }
}

void gausshakixor(vector<vector<int>>& a)
{
    for (int i = 0; i < K + 1; i++) {
        for (int j = 0; j < K + 1; j++) {
            if (i != j) {
                int d = a[j][i];

                for (int k = i; k < K + 2; k++) {
                    a[j][k] = a[j][k] ^ (d * a[i][k]);
                }
            }
        }
    }
}

int main(int argc, char* argv[])
{
    cin >> N >> K;
    cin.ignore();

    vector<vector<int>> a(K + 1);
    for (int i = 0; i < K + 1; ++i)
    {
        a[i] = vector<int>(K + 2, 1);  // 排他的論理和結果を末尾に格納するためK+2
        a[i][K - i] = 0;
    }

    for (int i = 0; i < K + 1; ++i)
    {
        if (argc == 1)
        {
            for (int j = 0; j < K + 1; ++j)
            {
                if (a[i][j] == 1)
                {
                    cout << j;
                }
                if (j < K)
                {
                    cout << " ";
                }
                else
                {
                    cout << endl
                        << flush;
                }
            }
        }
        else // Debug mode
        {
            cin >> a[i][K + 1];
            cin.ignore();
        }
    }

    if (argc != 1)
    {
        print2darr(a);
        cout << endl
             << flush;
    }

    gausshakixor(a);
    if (argc != 1)
    {
        print2darr(a);
    }
}