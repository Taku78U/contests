#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m, d;
    cin >> n >> m >> d;
    cin.ignore();
    vector<long long> a, b;
    for (long long i = 0; i < n; ++i)
    {
        long long t;
        cin >> t;
        a.push_back(t);
    }
    cin.ignore();
    for (long long i = 0; i < m; ++i)
    {
        long long t;
        cin >> t;
        b.push_back(t);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans_a = -1;
    long long ans_b = -1;
    long long ans_sum = -1;
    int a_ptr = 0;
    int b_ptr = 0;
    while(1)
    {
        const auto diff = abs(a[a_ptr] - b[b_ptr]);
        if (a[a_ptr] > b[b_ptr])
        {
            if (diff <= d)
            {
                ans_sum = a[a_ptr] + b[b_ptr];
                if (b_ptr < m - 1)
                {
                    ++b_ptr;
                }
            }
        }
        if (a[a_ptr] <= b[b_ptr])
        {
            if (diff <= d)
            {
                ans_sum = a[a_ptr] + b[b_ptr];
                ++a_ptr;
            }
        }
        if (a_ptr == n  && b_ptr == m - 1)
        {
            break;
        }
    }
    cout << ans_sum << endl;
}