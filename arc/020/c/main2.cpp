#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ullong;

ullong mod_minus(ullong a, ullong b, ullong m){
  ullong na, nb;
  nb = b % m;
  return (a + m - nb) % m; 
}

ullong mypow_mod(ullong x, ullong n, ullong m){
  // 繰り返し２乗法
  ullong res = 1;
  while (n>0){
    if((n & 1) == 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}

ullong doubling_mod(ullong r, ullong n, ullong m){
  if (n == 1) return 1;
  else if((n & 1) == 1) return (1 + r * doubling_mod(r, n-1, m)) % m;
  else return (1 + mypow_mod(r % m, n/2, m)) * doubling_mod(r, n/2, m) % m;
}

int main(void){
  // 読み込み

  ullong n;

  cin >> n;
  cin.ignore();
  ullong a[n], l[n];
  for (ullong i = 0;i<n;i++){
    cin >> a[i] >> l[i];
    cin.ignore();
  }

  ullong b;
  cin >> b;


  //r^n
  // ただn乗すると死ぬので都度割っていく
  ullong rl = 0;
  
  ullong i = 0, j = 0;
  ullong r = 0;
  // 等比数列の和 (初項1) (r^n-1)/(r-1) r=(aの桁数)
  ullong numerator = 0;
  ullong invr = 1;
  ullong sigma = 0;
  ullong sig_a = 0;
  ullong log_r = 0;

  //cout << "mypow_test:" << mypow_mod(3, 6, 6) << endl;
  for (i = 0; i < n; i++){
    //a[i]の桁数を算出
    log_r = (ullong) log10((double) a[i]) + 1;
    //    cout << "log_r = " << log_r << endl;
    // sigma修正
    if (i == 0) sigma = 0;
    else sigma= sigma * mypow_mod(10, (log_r * l[i]), b) % b;
    //a[i]
    r = (ullong) pow(10, log_r) % b;
    /*
    //cout << "r = " << r << endl;
    // r-1の逆元をフェルマーの小定理x^{p-1}=1(mod p)により求める
    // ただしやはりそのままでは死ぬので都度割る
    // 求めるは(r-1)^{b-2}(mod b)
    invr = mypow_mod(mod_minus(r, 1, b), b-2, b);
    //cout << "invr = " << invr << endl;
    ullong s;
    s = (r - 1) * invr %b;
    if (s != 1) {
      cout << s << endl;
    }
    // 分子numerator (mod b) = r^l-1(mod b)
    numerator = mypow_mod(r, l[i], b);
    numerator = mod_minus(numerator, 1, b);
    sig_a = (a[i] * numerator) % b;
    sigma = (sigma + (sig_a * invr)) % b;
    */
    ullong dblng;
    dblng = doubling_mod(r, l[i], b) * a[i] % b;
    sigma = (sigma + dblng) % b;
    //    cout << "doubling_mod:" << dblng << endl;
  }

  cout << sigma << endl;

  return 0;
}
