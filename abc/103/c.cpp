#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// 最大公約数、ユークリッドの互除法
ll gcd2(ll a, ll b){
  // 値渡し引数はここで処理しようが書き換わらないが、
  // ここで新たにおいておく

  ll at, bt; // at >= bt
  if(a < b){
    at = b;
    bt = a;
  } else {
    at = a;
    bt = b;
  }

  if(bt <= 0){
    return -1; // 異常値
  }
  ll r;
  r = at % bt;
  if(r == 0){
    return b;
  }

  while(r != 0){
    bt %= r;
    r = at % bt;
  }
  return bt;
}

// GCM(a, b) = a * b / GCD(a, b)
ll gcm2(ll a, ll b){
  ll r;
  r = (a / gcd2(a, b) * b);
  return r;
}

// 2個以上の数のGCD
ll gcd(ll* a, ll n){
  ll b;
  b = a[0];
  for (ll i = 1; i < n; i++){
    b = gcd2(b, a[i]);
  }
  return b;
}

ll gcm(ll* a, ll n){
  ll r;
  r = a[0];
  for (ll i = 1; i < n; i++){
    r = gcm2(r, a[i]);
  }
  return r;
}
int main(void){
  ll n;
  cin >> n;
  cin.ignore();
  ll a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin.ignore();

  ll r;
  r  = gcd2(a[0], a[1]);
  cout << r << endl;

  return 0;
}
