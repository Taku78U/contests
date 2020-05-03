#include <bits/stdc++.h>
//#define DBG

using namespace std;
using ll = long long;

int main(){
  ll h;
  cin >> h;
  cin.ignore();

  // 増殖しない場合

  ll h_cpy = h;
  ll cnt = 0;
  while(h_cpy != 0){
    h_cpy /= 2;
    ++cnt;
  }

  #ifdef DBG
  cout << "cnt = " << cnt << endl;
  #endif

  ll sum = 0;
  ll dam = 1;
  for(ll i = 0; i < cnt; i++){
    #ifdef DBG
    cout << "dam = " << dam << endl;
    #endif
    sum += dam;
    dam *= 2;
  }

  cout << sum << endl;
  return 0;
}
