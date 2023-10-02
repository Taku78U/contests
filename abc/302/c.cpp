#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int str_diffs(const string& str1, const string& str2)
{
    if (str1.size() != str2.size())
    {
        return -1;
    }
    int rtn = 0;
    for (int i = 0; i < str1.size(); ++i)
    {
        if (str1[i] != str2[i])
        {
            ++rtn;
        }
        // if (rtn >= 2)
        // {
        //     return rtn;  // 問題を満たすのは差が1だけなので、2になった時点でオワリ
        // }
    }
    return rtn;
}

bool solver(vector<string> strs)
{
    sort(strs.begin(), strs.end());
    do {
        bool result = true;
        for (int i = 0; i < strs.size() - 1; ++i)
        {
            if (str_diffs(strs[i], strs[i + 1]) != 1)
            {
                result = false;
                break;
            }
        }
        if (result)
        {
            return true;
        }
    } while (next_permutation(strs.begin(), strs.end()));
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<string> strs;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        cin.ignore();
        strs.emplace_back(str);
    }
    if (solver(strs))
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}