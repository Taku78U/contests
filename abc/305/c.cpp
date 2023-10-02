#include <bits/stdc++.h>

using namespace std;

class Solver {
public:
    Solver(const int h, const int w) : h_(h), w_(w) {}

    void Read()
    {
        for (int i = 0; i < h_; ++i)
        {
            string s;
            cin >> s;
            cin.ignore();
            S_.emplace_back(s);
            h_min_ = h_ - 1;
            w_min_ = w_ - 1;
            h_max_ = 0;
            w_max_ = 0;
        }
    }

    void CalcRect()
    {

        for (int i = 0; i < h_; ++i)
        {
            for (int j = 0; j < w_; ++j)
            {
                if (S_[i][j] == '#')
                {
                    if (i < h_min_)
                    {
                        h_min_ = i;
                    }
                    if (i > h_max_)
                    {
                        h_max_ = i;
                    }
                    if (j < w_min_)
                    {
                        w_min_ = j;
                    }
                    if (j > w_max_)
                    {
                        w_max_ = j;
                    }
                }
            }
        }
    }

    auto CalcSunuke()
    {
        for (int i = h_min_; i <= h_max_; ++i)
        {
            for (int j = w_min_; j <= w_max_; ++j)
            {
                if (S_[i][j] == '.')
                {
                    return pair<int, int>{i, j};
                }
            }
        }
        return pair<int, int>{0, 0};
    }

private:
    const int h_;
    const int w_;
    vector<string> S_;

    int h_min_;
    int h_max_;
    int w_min_;
    int w_max_;
};

int main()
{
    int h, w;
    cin >> h >> w;
    cin.ignore();

    auto slv = Solver(h, w);
    slv.Read();
    slv.CalcRect();
    const auto result = slv.CalcSunuke();
    cout << result.first + 1 << " " << result.second + 1 << endl;
    return 0;
}