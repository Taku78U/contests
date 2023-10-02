#include <bits/stdc++.h>

using namespace std;

constexpr auto D = array<int, 6>{3, 1, 4, 1, 5, 9};
constexpr auto DSum = array<int, 7>{0, 3, 4, 8, 9, 14, 23};

int main()
{
    char p, q;
    cin >> p >> q;
    cin.ignore();

    int p_idx = p - 'A';
    int q_idx = q - 'A';

    if (p_idx > q_idx)
    {
        const auto tmp = q_idx;
        q_idx = p_idx;
        p_idx = tmp;
    }

    cout << DSum[q_idx] - DSum[p_idx] << endl;
}