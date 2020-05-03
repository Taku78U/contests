#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main(){
  ll x;
  cin >> x;
  cin.ignore();

  ll x_1000 = x / 500;
  ll xp1000 = x % 500;
  ll xp1000_5 = xp1000 / 5;

  ll ans = 1000 * x_1000 + 5 * xp1000_5;
  cout << ans << endl;
  return 0;
}
