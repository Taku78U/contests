#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

ll N;

void read()
{
    cin >> N;
    cin.ignore();
}

bool solver()
{
    if (N == 1)
    {
        return true;
    }
    if (N == 2)
    {
        return true;
    }
    if (N == 3)
    {
        return true;
    }
    auto two = vector<ll>(64);
    two[0] = 1;
    for (int i = 1; i < 64; ++i)
    {
        two[i] = 2 * two[i - 1];
    }
    auto three = vector<ll>(64);
    three[0] = 1;
    for (int i = 1; i < 64; ++i)
    {
        three[i] = 3 * three[i - 1];
    }

    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            if (three[j] <= ULONG_LONG_MAX / two[i])
            {
                if (two[i] * three[j] == N)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    read();
    if (solver())
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}