#include <bvits/stdc++.h>

using namespace std;

using ll = long long;

using ull = unsigned long long;

int main (void){

  ll n, z, w;
  cin >> n >> z >> w;
  vector<ll> a;
  ll tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    a.push_back(tmp);
  }

  ll ans;
  if(n == 1) {
    ans = abs(a[0] - w);
    cout << ans << endl;
    return 0;
  }

  // 引けるのは最後のカードのみ
  // もはやYにはXが漁った残飯を屠る以外にない
  // 1枚は必ず引かなければならないため、最後尾が全て

  
  

  return 0;
}
