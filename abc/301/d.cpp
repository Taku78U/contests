#include <iostream>
#include <string>

using namespace std;

auto pow_int(const std::int64_t base, const std::int64_t p)
{
    std::int64_t rtn = 1;
    for (std::int64_t i = 0; i < p; ++i)
    {
        rtn *= base;
    }
    return rtn;
}

int main()
{
    string s;
    cin >> s;
    std::int64_t n;
    cin.ignore();
    cin >> n;
    const auto len = s.size();
    std::int64_t num = 0;
    std::int64_t t = 1;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '1')
        {
            num += t;
        }
        t *= 2;
    }

    if (num > n)
    {
        cout << -1 << endl;
        return 0;
    }

    // 前から?を探す 仮に1にしたときにそれ以下であればプラス
    t = pow_int(2, len - 1);
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '?')
        {
            if (num + t <= n)
            {
                num += t;
            }
        }
        t /= 2;
    }
    cout << num << endl;
    return 0;
}
