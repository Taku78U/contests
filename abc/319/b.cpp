#include <bits/stdc++.h>

using namespace std;

int N;

string solver()
{
    string rtn = "1";  // i == 0 のとき、必ず1 0は任意の自然数の倍数なので、その中で最小は1
    for (int i = 1; i <= N; ++i)
    {
        bool found = false;
        for (int j = 1; j <= 9; ++j)
        {
            if (N % j == 0)
            {
                if (i % (N / j) == 0)
                {
                    rtn += static_cast<char>(j + '0');
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            rtn += '-';
        }
    }
    return rtn;
}

int main()
{
    cin >> N;
    cin.ignore();

    cout << solver() << endl;
    return 0;
}