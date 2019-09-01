#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

using ll = long long;

int main (void){
  ll n, m;
  cin >> n >> m;
  cin.ignore();

  //if(m > 5) m = 5;

  ll x; // 1回あたりの実行時間
  x = 1900 * m + 100 * (n - m);

  // 式
  // 成功確率 1/2^M

  // ans = x + (1-p) * ans
  // ans = x / p

  ll ans;
  ans = x * pow(2, m);
  cout << ans << endl;
  return 0;
}
