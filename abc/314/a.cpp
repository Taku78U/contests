#include <bits/stdc++.h>

using namespace std;

string pi = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    cout << "3.";
    for (int i = 0; i < N; ++i)
    {
        cout << pi[i];
    }
    cout << endl;
    return 0;


}