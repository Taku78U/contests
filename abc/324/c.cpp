#include <bits/stdc++.h>

// #define DBG

using namespace std;

using ll = long long;

ll N;
string TD;
vector<string> S;

void read()
{
    cin >> N;
    cin >> TD;
    cin.ignore();

#ifdef DBG
    // cout << "TD = " << TD << endl;
#endif

    S.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
        cin.ignore();
    }
}

bool sub_solve(const int idx)
{
    auto s = S[idx];
#ifdef DBG
    cout << "sub_solve " << idx << endl;
#endif
    if (s == TD)
    {
        return true;
    }
    if (s.size() == TD.size() - 1)
    {
#ifdef DBG
        cout << s << endl;
        cout << TD.substr(1) << endl;
        cout << (s == TD.substr(1)) << endl;
#endif
        int TD_ptr = 0;
        bool step = false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == TD[TD_ptr])
            {
                ++TD_ptr;
                continue;
            }
            if (step)
            {
                return false;
            }
            ++TD_ptr;
            step = true;
            if (s[i] != TD[TD_ptr])
            {
                return false;
            }
            ++TD_ptr;
        }
        return true;
    }
    if (s.size() == TD.size() + 1)
    {
        int s_ptr = 0;
        bool step = false;
        for (int i = 0; i < TD.size(); ++i)
        {
            if (TD[i] == s[s_ptr])
            {
                ++s_ptr;
                continue;
            }
            if (step)
            {
                return false;
            }
            ++s_ptr;
            step = true;
            if (TD[i] != s[s_ptr])
            {
                return false;
            }
            ++s_ptr;
        }
        return true;
    }
    // for (char head = 'a'; head <= 'z'; ++head)
    // {
    //     if (TD == string() + head + s)
    //     {
    //         return true;
    //     }
    // }
    // for (char tail = 'a'; tail <= 'z'; ++tail)
    // {
    //     if (TD == s + tail)
    //     {
    //         return true;
    //     }
    // }

    if (TD.size() == s.size())
    {
        if (TD.size() == 1)
        {
            return true;
        }
        bool diff = false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == TD[i])
            {
                continue;
            }
            if (diff)
            {
                return false;
            }
            diff = true;
        }
        return true;
    }
    return false;
}

void solve()
{
    int k = 0;
    vector<int> results;
    for (int i = 0; i < N; ++i)
    {
        if (sub_solve(i))
        {
            ++k;
            results.emplace_back(i + 1);
        }
    }
    cout << k << endl;
    for (int i = 0; i < k; ++i)
    {
        cout << results[i];
        if (i != k - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    read();
    solve();
}