#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    std::string s;
    cin >> s;
    int t = 0;
    int a = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'T')
        {
            ++t;
        } else {
            ++a;
        }
        if (n % 2 == 0 && t == n / 2)
        {
            cout << "T" << endl;
            return 0;
        }
        if (n % 2 == 0 && a == n / 2)
        {
            cout << "A" << endl;
            return 0;
        }
    }
    if (t > n - t)
    {
        cout << "T" << endl;
        return 0;
    }
    else if (t < n - t) {
        cout << "A" << endl;
        return 0;
    }
    return 0;
}