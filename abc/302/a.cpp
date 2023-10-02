#include <iostream>
using namespace std;

int main()
{
    std::int64_t a, b;
    cin >> a >> b;
    cin.ignore();

    std::int64_t ans = a / b;
    if (a % b > 0)
    {
        ++ans;
    }
    cout << ans << endl;
    return 0;
}