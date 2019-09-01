#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(ll n, ll k){
  if (n < k) return 0;
  if (k == 0) return 1;
  if ((n == 0) && (k == 0)) return 1;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  COMinit();
  ll n, k;
  cin >> n >> k;
  cin.ignore();

  ll ans;

  for(ll i = 1; i <= k; i++){
    if(n - k >= i - 1){
      ans = COM(n - k + 1, i) * COM(k - 1, i - 1) % MOD;
      cout << ans << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}
  
