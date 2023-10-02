#include <bits/stdc++.h>

using namespace std;
using ll = std::int64_t;

class Solver{
public:
    Solver(const int n) : N_(n) {}

    void Read()
    {
        for (int i = 0; i < N_; ++i)
        {
            ll a;
            cin >> a;
            A_.emplace_back(a);
        }
        cin.ignore();
    }

    auto Execute(const ll l, const ll r)
    {
        const auto lower_bound_l = lower_bound(A_.begin(), A_.end(), l);
        if (lower_bound_l == A_.end())
        {
            return ll{0};
        }
        if (*lower_bound_l == l && lower_bound_l + 1 == A_.end())
        {
            return ll{0};
        }

        // cout << "L " << *lower_bound_l << endl;
        const auto lower_bound_l_idx = distance(A_.begin(), lower_bound_l);
        // cout << "Lidx " << lower_bound_l_idx << endl;

        // 開始時点で寝ていた場合
        ll start_sleep = 0;
        auto next_itr = lower_bound_l;  // 次に区切り 寝ている状態(=このイテレータは起床)からスタート
        if (lower_bound_l_idx % 2 == 0)
        {
            start_sleep = l;
        }
        else
        { // 開始時点で起きていた場合
            // 次のidxからになる
            start_sleep = *(lower_bound_l);
            if (r <= start_sleep) // 寝るより前に測定を終了する場合
            {
                return ll{0};
            }
            ++next_itr;
        }

        auto current_sleep = start_sleep;
        ll rtn = 0;

        while(1)
        {
            // cout << "C1 " << current_sleep << endl;
            // 寝ている時間の計算
            if (r <= *next_itr)
            {
                rtn += r - current_sleep;
                return rtn;
            }

            rtn += *next_itr - current_sleep;

            current_sleep = *next_itr;
            ++next_itr;
            // cout << "C2 " << current_sleep << endl;
            // cout << "rtn " << rtn << endl;
            if (next_itr == A_.end())
            {
                return rtn;
            }

            // 起きている最中に測定が終了するかのチェック

            if (r <= *next_itr)
            {
                return rtn;
            }

            current_sleep = *next_itr;
            ++next_itr;
            // cout << "C3 " << current_sleep << endl;
            if (next_itr == A_.end())
            {
                return rtn;
            }
        }

        return rtn; // dummy
    }

private : const int N_;
    vector<ll> A_;
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    auto slv = Solver(n);
    slv.Read();
    int q;
    cin >> q;
    cin.ignore();
    vector<ll> anss;
    anss.reserve(q);
    for (int i = 0; i < q; ++i)
    {
        ll l, r;
        cin >> l >> r;
        cin.ignore();
        const auto ans = slv.Execute(l, r);
        anss.emplace_back(ans);
        // cout << ans << endl;
    }
    for (const auto& elm : anss)
    {
        cout << elm << endl;
    }
    return 0;
}