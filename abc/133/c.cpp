#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll l, r;
  cin >> l >> r;
  cin.ignore();

  ll min = 2018;
  ll tmp;

  // 2019は3と673の合成数→あとで考える！
  for(ll k = 0; k < 2019; ++k){
    for (ll i = l + k + 1; i < (l + k + 2019) && i <= r; i++){
      tmp = (l + k) * i % 2019;
      if(tmp < min){
        min = tmp;
        //cout << min << endl;
      }
    }
  }
  cout << min << endl;
  return 0;
}

  
