#include <bits/stdc++.h>
// #define DBG

using namespace std;

using ll = long long;

int M;
vector<string> S(3);

int solver()
{
    int rtn = -1;
    // 0から9まで全部仮定して試す
    for (char num = '0'; num <= '9'; num += 1)
    {
        auto v = vector<int>{0, 1, 2};  // 順番をとりあえず全部試す
        do
        {
            int t = 0;
            int s_ptr = 0;
            bool not_found = false; // 目的の数字がそもそもない
            while (s_ptr < 3)
            {
                // 目的の数字がそもそもあるか
                if (S[v[s_ptr]].find(num) == string::npos)
                {
                    not_found = true;
                    break;
                }

                // ある場合はMAXでM
                for (int i = 0; i < M; ++i)
                {
                    auto current_position = t % M;
                    if (S[v[s_ptr]][current_position] == num)
                    {
                        // 次をたどるときはtもs_ptrも進んでいる
                        // ただしs_ptrが最後のときはtは進まない
                        ++s_ptr;
                        if (s_ptr < 3)
                        {
                            ++t;
                        }
                        break;
                    }
                    ++t;
                }
            }
            if (not_found)
            {
                continue;
            }

            // tが最小か比較する
            if (rtn == -1 || rtn > t)
            {
                rtn = t;

#ifdef DBG
                cout << num << ", " << v[0] << ", " << v[1] << ", " << v[2] << endl;
#endif
            }
        } while (next_permutation(v.begin(), v.end()));
    }
    return rtn;
}

int main()
{
    cin >> M;
    for (int i = 0; i < 3; ++i)
    {
        cin >> S[i];
    }
    auto ans = solver();
    cout << ans << endl;

    return 0;
}