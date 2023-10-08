#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int p1;
    vector<int> vp; // P_2以降

    cin >> n;
    cin.ignore();
    cin >> p1;
    for (int i = 0; i < n-1; i++)
    {
        int p;
        cin >> p;
        vp.emplace_back(p);
    }
    if (p1 > *max_element(vp.begin(), vp.end()))
    {
        cout << 0 << endl;
        return 0;
    }
    const auto x = *max_element(vp.begin(), vp.end()) - p1 + 1;
    cout << x << endl;
    return 0;
}