#include <bits/stdc++.h>
//#define DBG
#define MOD 1000000007
//#define DBG
//#define DBG2
using namespace std;

using ll = long long;


ll modpls(ll a, ll b){
  return (a + b) % MOD;
}

ll modminus(ll a, ll b){
  ll tmp_a, tmp_b;
  if(a < b){
    tmp_a = b;
    tmp_b = a;
  } else {
    tmp_a = a;
    tmp_b = b;
  }
  return (a - b) % MOD;
}

ll modmult(ll a, ll b){
  return (a * b) % MOD;
}

ll f(ll max, ll min){
  return modminus(max, min);
}

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

#define MAX_N 100000
ll modinv_tbl[MAX_N] = {0};

int main(){
  ll n, k;
  cin >> n >> k;
  cin.ignore();

  vector <ll> a;
  ll tmp;
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());

  ll min, max, num;
  ll comb = 1;
  ll sum = 0;

  // 逆元初期化
  for(ll i = 0; i < MAX_N; i++){
    modinv_tbl[i] = modinv(i+1, MOD);
  }
  
  for(ll i = 0; i < n - k + 1; i++){
    min = a[i];
#ifdef DBG
    cout << "i = " << i << endl;
#endif
    comb = 1;
    for(ll j = i + k - 1; j < n; j++){
      max = a[j];
      num = j - i + 1 - 2; // 両端は除く
#ifdef DBG
      cout << "j = " << j << endl;
      cout << "num = " << num << endl;
#endif
      if(num > k - 2){
#ifdef DBG
        cout << "modinv(num - (k - 2), MOD) = " << modinv(num - (k - 2), MOD) << endl;
#endif
        comb = modmult(comb, modmult(num, modinv_tbl[(num-(k-2))-1]));
      }
#ifdef DBG
      cout << "comb = " << comb << endl;
      cout << "max = " << max << endl;
      cout << "min = " << min << endl;
      cout << endl;
#endif
      sum = modpls(modmult(f(max, min), comb), sum);
    }
  }
      
  cout << sum << endl;
  return 0;
}
