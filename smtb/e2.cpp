#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modadd(ll a, ll b){
  return (a + b) % MOD;
}
ll modmult(ll a, ll b){
  return (a * b) % MOD;
}

int main(){
  ll n;
  cin >> n;
  cin.ignore();
  vector <ll> a;
  ll tmp;
  ll kinds = 0; // 色の種類数
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp);
    if(tmp == 0){
      ++kinds;
    }
  }

 // x_i >= y_i >= z_i 割り当て方3通り
  ll x = 0, y = 0, z = 0;
  ll ans = 1;
  tmp = 0;
  
  for(ll i = 0; i < n; i++){
    tmp = 0;
    if(a[i] == x){
      ++tmp;
      ++x;
      if(a[i] == y){
        ++tmp;
      }
      if(a[i] == z){
        ++tmp;
      }
    } else if(a[i] == y){
      ++tmp;
      ++y;
      if(a[i] == z){
        ++tmp;
      }
    } else if(a[i] == z){
      ++tmp;
      ++z;
    }
    ans = modmult(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
    
