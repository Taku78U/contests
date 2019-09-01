#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll tmp;
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cin.ignore();

  ll x;
  x = c * d;

  if(c<d){
    tmp = c;
    c = d;
    d = tmp;
  }

  /* ユークリッドの互除法 */

  ll r;
  r = c % d;

  ll org_c = c;
  ll org_d = d;

  while(r != 0){
    c = d;
    d = r;
    r = c % d;

  }

  ll gcd;
  gcd = d;

  ll lcm;
  lcm = x / gcd;

  ll nc = (lcm - 1) / org_c;
  ll nd = (lcm - 1) / org_d;

  ll ncd = nc + nd + 1;

  // Bについて求める
  ll sumb = 0;
  ll n_b_lcm = b / lcm;

  sumb += ncd * n_b_lcm;

  //cout << ncd << endl;

  // Bについて、余り分
  ll m_b_lcm = b % lcm;
  sumb += m_b_lcm / org_c;
  sumb += m_b_lcm / org_d;

  // A-1について求める
  ll suma_ = 0;
  ll n_a_lcm = (a-1) / lcm;

  suma_ += ncd * n_a_lcm;

  // Bについて、余り分
  ll m_a_lcm = (a-1) % lcm;
  suma_ += m_a_lcm / org_c;
  suma_ += m_a_lcm / org_d;

  ll sum;
  sum = sumb - suma_;

  ll ans;
  ans = b - a + 1 - sum;
  cout << ans << endl;
  return 0;
}
  
