#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string S;

auto solver()
{
    std::size_t rtn = 1;
    for (int i = 0; i < S.size(); ++i)
    {
        for (int j = i; j < S.size(); ++j)
        {
            const auto sstr = S.substr(i, j + 1 - i);
            if (sstr == string(sstr.rbegin(), sstr.rend()))
            {
                if (rtn < sstr.size())
                {
                    rtn = sstr.size();
                }
            }
        }
    }
    return rtn; // dummy
}

int main()
{
    cin >> S;
    cout << solver() << endl;
    return 0;
}