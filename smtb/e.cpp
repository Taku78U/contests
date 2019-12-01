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

  if(kinds == 1){
    cout << 3 << endl;
    return 0;
  }


  ll i = 0;
  ll cnt = 0; // 数値が同じ箇所
  while(i < n - 2){
    if(a[i] == a[i+1]){
      if(a[i] == a[i+2]){
        i += 2;
        ++cnt;
        continue;
      }
      ++cnt;
    }
    ++i;
  }

  ll ans = 3;
  for(i = 0; i < cnt; i++){
    ans = modmult(ans, 2);
  }
  cout << ans << endl;
  return 0;
}
    
