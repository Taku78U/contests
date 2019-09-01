#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;

int main(void) {
  ll x, y, z;
  cin >> x >> y >> z;
  cin.ignore();

  ll w = y + z;

  ll n;
  n = (x - z) / w;
  cout << n << endl;
  return 0;
}
