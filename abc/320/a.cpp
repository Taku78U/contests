#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a, b;

int my_pow_simple(const int a, const int b)
{
    int rtn = 1;
    for (int i = 0; i < b; ++i)
    {
        rtn *= a;
    }
    return rtn;
}

int main()
{
    cin >> a >> b;
    cin.ignore();

    cout << my_pow_simple(a, b) + my_pow_simple(b, a) << endl;

    return 0;
}