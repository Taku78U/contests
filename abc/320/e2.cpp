#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll Soumen[2 * 100000] = {0LL};
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
priority_queue<ll, vector<ll>, greater<ll>> Persons;

ll N, M;

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
            Persons.push(person);
        }

        if (Persons.empty())
        {
            continue;
        }
        const auto head = Persons.top();
        Persons.pop();
        Soumen[head] += w;
        Q.push(pair<ll, ll>(t + s, head));
    }
}

int main()
{
    cin >> N >> M;
    cin.ignore();

    for (ll i = 0; i < N; ++i)
    {
        Persons.push(i);
    }

    solver();

    for (int i = 0; i < N; ++i)
    {
        cout << Soumen[i] << endl;
    }
    return 0;
}
