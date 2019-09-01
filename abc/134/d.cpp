#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n;
  cin >> n;
  cin.ignore();
  vector <ll> a;
  ll tmp = 0;
  bool allzero = true;
  for (ll i = 0; i < n; i++){
    cin >> tmp;
    if(tmp != 0){
      allzero = false;
    }
    a.push_back(tmp);
  }
  ll b[n] = {0};
  for(ll i = 0; i < n/2; i++){
    b[i] = 0;
  }
  for(ll i = n/2; i < n; i++){
    b[i] = a[i];
  }

  if(allzero == true){
    cout << 0 << endl;
    return 0;
  }

  // 後ろからあてはめていく
  ll sufi, sufj;
  ll sum;
  for (ll i = n/2; i >= 1; i--){
    sufi = i - 1;
    sum = 0;
    for(ll j = i * 2; j <= n; j += i){
      sufj = j - 1;
      sum += b[sufj];
    }
    sum = sum % 2;
    if(a[sufi] != sum){
      //cout << i << endl;
      b[sufi] =  1;
    } else {
      b[sufi] = 0;
    }
  }

  // ここから変数の意味が変わる
  sum = 0;
  for (ll i = 0; i < n; i++){
    if(b[i] == 1) ++sum;
  }

  cout << sum << endl;
  
  for (ll i = 0; i < n; i++){
    if(b[i] == 1){
      cout << (i + 1) << " " << flush;
    }
  }
  cout << endl;
  return 0;
}
      

  
