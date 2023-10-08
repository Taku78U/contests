#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N;
string S;
ll Q;

bool is_low(const char c)
{
    if ('a' <= c && c <= 'z')
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> N;
    cin.ignore();
    cin >> S;
    cin.ignore();
    cin >> Q;
    cin.ignore();

    bool current_low = true; // true: 最後が小文字指令 false: 最後が大文字指令
    vector<bool> non_related;  // current_low==true: 大文字のidx current_low==false: 小文字のidx
    non_related.resize(N);
    ll last_t = 2;
    ll last_t_idx = 0;
    vector<ll> X, CS, T;
    for (ll i = 0; i < N; ++i)
    {
        if (!is_low(S[i]))
        {
            non_related[i] = true;
        }
    }
    for (ll i = 0; i < Q; ++i)
    {
        ll t, x;
        char c;
        cin >> t >> x >> c;
        cin.ignore();
        X.emplace_back(x - 1);
        CS.emplace_back(c);
        T.emplace_back(t);
        switch(t)
        {
            case 1:
                S[x - 1] = c;
                non_related[x - 1] = true;
                break;
            case 2:
                current_low = true;
                last_t = 2;
                last_t_idx = i;
                break;
            case 3:
                current_low = false;
                last_t = 3;
                last_t_idx = i;
                break;
            default:
                break;
        }
    }
    current_low = (last_t == 2);
    if (last_t_idx != 0)
    {
        for (int i = 0; i < non_related.size(); ++i)
        {
            non_related[i] = false;
        }
    }
    for (int i = last_t_idx; i < Q; ++i)
    {
        if (T[i] == 1)
        {
            S[X[i]] = CS[i];
            non_related[X[i]] = true;
        }
    }


    for (int i = 0; i < N; ++i)
    {
        char c = S[i];
        if (non_related[i])
        {
            cout << c;
        }
        else if (current_low && !is_low(c))
        {
            cout << (char)(c + ('a' - 'A'));
        }
        else if (!current_low && is_low(c))
        {
            cout << (char)(c - ('a' - 'A'));
        }
        else
        {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}