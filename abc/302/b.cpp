#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm> // std::search, std::find_end
#include <iterator>  // std::distance

using namespace std;

const auto Snuke = std::string("snuke");

bool subsolver(const int h, const int w, const vector<string>& strs, const int i, const int j, const int k)
{
    if (i < 0)
    {
        return false;
    }
    if (j < 0)
    {
        return false;
    }
    if (i >= h)
    {
        return false;
    }
    if (j >= w)
    {
        return false;
    }
    if (strs[i][j] == Snuke[k])
    {
        return true;
    }
    return false;
}

auto solver(const int h, const int w, const vector<string>& strs)
{
    // // 右一文字
    auto rtn = vector<pair<int, int>>();
    rtn.reserve(Snuke.size());
    // for (int i = 0; i < h; ++i)
    // {
    //     const auto& str = strs[i];
    //     auto r = search(str.begin(), str.end(), Snuke.begin(), Snuke.end());
    //     if (r == str.end())
    //         continue;

    //     const auto start_idx = distance(str.begin(), r);
    //     for (int j = 0; j < Snuke.size(); ++j)
    //     {
    //         rtn.emplace_back(pair<int, int>(i + 1, start_idx + j + 1)); // 1-originに修正
    //     }
    //     return rtn;
    // }
    // // 左一文字
    // for (int i = 0; i < h; ++i)
    // {
    //     auto str = strs[i];
    //     reverse(str.begin(), str.end());
    //     auto r = search(str.begin(), str.end(), Snuke.begin(), Snuke.end());
    //     if (r == str.end())
    //         continue;

    //     const auto start_idx = w - 1 - distance(str.begin(), r);
    //     for (int j = 0; j < Snuke.size(); ++j)
    //     {
    //         rtn.emplace_back(pair<int, int>(i + 1, start_idx - j + 1)); // 1-originに修正
    //     }
    //     return rtn;
    // }

    // // 上下一文字
    // vector<string> strs_l;
    // for (int j = 0; j < w; ++j)
    // {
    //     auto str = string("");
    //     for (int i = 0; i < h; ++i)
    //     {
    //         str += strs[i][j];
    //     }
    //     strs_l.emplace_back(str);
    // }

    // for (int i = 0; i < w; ++i)
    // {
    //     const auto& str = strs_l[i];
    //     auto r = search(str.begin(), str.end(), Snuke.begin(), Snuke.end());
    //     if (r == str.end())
    //         continue;

    //     const auto start_idx = distance(str.begin(), r);
    //     for (int j = 0; j < Snuke.size(); ++j)
    //     {
    //         rtn.emplace_back(pair<int, int>(start_idx + j + 1, i + 1)); // 1-originに修正
    //     }
    //     return rtn;
    // }

    // for (int i = 0; i < w; ++i)
    // {
    //     auto str = strs_l[i];
    //     reverse(str.begin(), str.end());
    //     auto r = search(str.begin(), str.end(), Snuke.begin(), Snuke.end());
    //     if (r == str.end())
    //         continue;

    //     const auto start_idx = w - 1 - distance(str.begin(), r);
    //     for (int j = 0; j < Snuke.size(); ++j)
    //     {
    //         rtn.emplace_back(pair<int, int>(start_idx - j + 1, i + 1)); // 1-originに修正
    //     }
    //     return rtn;
    // }

    // 斜め
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            // 右
            {
                bool result = true;
                for (int k = 0; k < 5; ++k)
                {
                    result = subsolver(h, w, strs, i, j + k, k);
                    if (!result)
                    {
                        break;
                    }
                }
                if (result)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        rtn.emplace_back(i + 1, j + k + 1);
                    }
                    return rtn;
                }
            }
            // 左
            {
                bool result = true;
                for (int k = 0; k < 5; ++k)
                {
                    result = subsolver(h, w, strs, i, j - k, k);
                    if (!result)
                    {
                        break;
                    }
                }
                if (result)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        rtn.emplace_back(i + 1, j - k + 1);
                    }
                    return rtn;
                }
            }
            // 下
            {
                bool result = true;
                for (int k = 0; k < 5; ++k)
                {
                    result = subsolver(h, w, strs, i + k, j, k);
                    if (!result)
                    {
                        break;
                    }
                }
                if (result)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        rtn.emplace_back(i + k + 1, j + 1);
                    }
                    return rtn;
                }
            }
            // 上
            {
                bool result = true;
                for (int k = 0; k < 5; ++k)
                {
                    result = subsolver(h, w, strs, i - k, j, k);
                    if (!result)
                    {
                        break;
                    }
                }
                if (result)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        rtn.emplace_back(i - k + 1, j + 1);
                    }
                    return rtn;
                }
            }
            // 右斜め下
            {
                bool result = true;
                for (int k = 0; k < 5; ++k)
                {
                    result = subsolver(h, w, strs, i + k, j + k, k);
                    if (!result)
                    {
                        break;
                    }
                }
                if (result)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        rtn.emplace_back(i + k + 1, j + k + 1);
                    }
                    return rtn;
                }
            }

            // 左斜め下
            {
                bool result = true;
                for (int k = 0; k < 5; ++k)
                {
                    result = subsolver(h, w, strs, i + k, j - k, k);
                    if (!result)
                    {
                        break;
                    }
                }
                if (result)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        rtn.emplace_back(i + k + 1, j - k + 1);
                    }
                    return rtn;
                }
            }
            // 右斜め上
            {
                bool result = true;
                for (int k = 0; k < 5; ++k)
                {
                    result = subsolver(h, w, strs, i - k, j + k, k);
                    if (!result)
                    {
                        break;
                    }
                }
                if (result)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        rtn.emplace_back(i - k + 1, j + k + 1);
                    }
                    return rtn;
                }
            }
            // 左斜め上
            {
                bool result = true;
                for (int k = 0; k < 5; ++k)
                {
                    result = subsolver(h, w, strs, i - k, j - k, k);
                    if (!result)
                    {
                        break;
                    }
                }
                if (result)
                {
                    for (int k = 0; k < 5; ++k)
                    {
                        rtn.emplace_back(i - k + 1, j - k + 1);
                    }
                    return rtn;
                }
            }
        }
    }

    // dummy
    return rtn;
}

int main()
{
    int h, w;
    cin >> h >> w;
    cin.ignore();
    vector<string> strs;
    strs.reserve(h);
    for (int i = 0; i < h; ++i)
    {
        string s;
        cin >> s;
        cin.ignore();
        strs.emplace_back(s);
    }

    const auto results = solver(h, w, strs);
    for (const auto& result : results)
    {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}