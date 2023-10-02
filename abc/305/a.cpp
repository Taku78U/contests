#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    if (n >= 20 * 5)
    {
        cout << 100 << endl;
        return 0;
    }

    if (n % 5 == 0)
    {
        cout << n << endl;
        return 0;
    }

    const auto lower_point_idx = n / 5;
    const auto lower_point = 5 * lower_point_idx;
    const auto upper_point = lower_point + 5;
    if (n - lower_point < upper_point - n)
    {
        cout << lower_point << endl;
        return 0;
    }
    cout << upper_point << endl;
    return 0;
}