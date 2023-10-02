#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll Soumen[2 * 100000] = {0LL};
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;  // 

ll N, M;

vector<bool> NotStay(2 * 100000);

void solver()
{
    ll head = 0;
    for (ll i = 0; i < M; ++i)
    {
        ll t, w, s;
        cin >> t >> w >> s;
        cin.ignore();
        while (!Q.empty() && Q.top().first <= t)
        {
            const auto person = Q.top().second;
            Q.pop();
            NotStay[person] = false;
            if (person < head)
            {
                head = person;
            }
        }

        bool found = false;
        const auto pre_head = head;
        for (; head < N; ++head)
        {
            if (!NotStay[head])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            head = pre_head;
            continue;
        }
        Soumen[head] += w;
        NotStay[head] = true;
        Q.push(pair<ll, ll>(t + s, head));
        ++head;
        if (head >= N)
        {
            head = 0;
        }
    }
}

int main()
{
    cin >> N >> M;
    cin.ignore();

    solver();

    for (int i = 0; i < N; ++i)
    {
        cout << Soumen[i] << endl;
    }
    return 0;
}
