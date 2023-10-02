#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    auto v = vector<int>();
    for (int i = 0; i < n; ++i)
    {
        int e = 0;
        cin >> e;
        v.emplace_back(e);
    }

    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i] < v[i + 1])
        {
            for (int j = v[i]; j < v[i + 1]; ++j)
            {
                cout << j << " ";
            }
        }
        else
        {
            for (int j = v[i]; j > v[i + 1]; --j)
            {
                cout << j << " ";
            }
        }
    }
    cout << v.back() << endl;
    return 0;
}