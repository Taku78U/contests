#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    int s_nchars['z' - 'a' + 2] = {0};
    int t_nchars['z' - 'a' + 2] = {0};
    constexpr int idx_at = 'z' - 'a' + 1;
    for (int i = 0; i < 'z' - 'a' + 2; ++i)
    {
        s_nchars[i] = 0;
        t_nchars[i] = 0;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '@')
        {
            ++(s_nchars[idx_at]);
        }
        else if ('a' <= s[i] && s[i] <= 'z')
        {
            ++(s_nchars[s[i] - 'a']);
        }
    }
    for (int i = 0; i < t.size(); ++i)
    {
        if (t[i] == '@')
        {
            ++(t_nchars[idx_at]);
        }
        else if ('a' <= t[i] && t[i] <= 'z')
        {
            ++(t_nchars[t[i] - 'a']);
        }
    }

    constexpr auto arr = array<char, 7>{'a', 't', 'c', 'o', 'd', 'e', 'r'};
    for (int i = 0; i <= 'z' - 'a'; ++i)
    {
        const char ch = 'a' + i;
        const auto find_result = find(arr.begin(), arr.end(), ch);
        if (find_result != arr.end())
        {
            if (s_nchars[i] > t_nchars[i])
            {
                const auto diff = s_nchars[i] - t_nchars[i];
                if (diff > t_nchars[idx_at])
                {
                    cout << "No" << endl;
                    return 0;
                }
                t_nchars[idx_at] -= diff;
            }
            else
            {
                const auto diff = t_nchars[i] - s_nchars[i];
                if (diff > s_nchars[idx_at])
                {
                    cout << "No" << endl;
                    return 0;
                }
                s_nchars[idx_at] -= diff;
            }
            continue;
        }

        if (s_nchars[i] != t_nchars[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}