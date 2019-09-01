#include <bits/stdc++.h>

using namespace std;

using ll = long long;

static const ll MOD = 1000000007;

ll mod_mult(ll a,ll b)
{
  long long res = 0;
  long long mir = a%MOD;
  while (b) {
    if (b&1) {
      res += mir;
      if (res > MOD) {
        res -= MOD;
      }
    }
    mir <<= 1;
    if (mir > MOD) {
      mir -= MOD;
    }
    b >>= 1;
  }
  return res;
}

ll mod_exp(ll a,ll b)
{
  long long res = 1;
  long long mir = a%MOD;
  while (b) {
    if (b&1) {
      res = mod_mult(res, mir);
    }
    mir = mod_mult(mir, mir);
    b >>= 1;
  }
  return res;
}

int main(){
  ll n, m;
  vector <ll> a;
  cin >> n >> m;
  cin.ignore();

  ll tmp;

  vector <ll> lit;

  // 順次取り込み
  for(int i = 0; i < m; i++){
    cin >> tmp;
    cin.ignore();
    a.push_back(tmp);
  }
  
  // 2連続で穴が空いている場合はムリなのでガード
  if(m != 0){
    tmp = a[0];
    for(ll i = 1; i < m; i++){
      if(a[i] == tmp + 1){
        cout << 0 << endl;
        return 0;
      } else if(a[i] > tmp + 1){
        tmp = a[i];
      }
    }

    // 穴で区切る
    // 穴は、[0] ~ [a[0]], [a[0]] ~ [a[1]],..., [a[m-2]]~[a[m-1]], [a[m-1]] ~ [n-1]

    if(a[0] - 1 != 0){
      lit.push_back(a[0] - 1);
    }
    for(ll i = 0; i < m - 1; i++){
      if(a[i+1] > a[i] + 2) // 3個以上のみ
        lit.push_back(a[i+1] - a[i] - 2);
    }
    lit.push_back(n - a[m-1] - 1);

    sort(lit.begin(), lit.end());
  } else {
    lit.push_back(n);
  }
  
  ll f0 = 1;
  ll f1 = 1;
  ll f2;
  ll ans = 1;
  ll ptr = 0;
  ll fibptr = 1; // f1が何項目(1-origin)？
  while(ptr < lit.size()){
    // 今のf1、vecにあるだけかける

    //cout << lit.size() << endl;

    //cout << "fibptr = " << fibptr << endl;
    //cout << "f1 = " << f1 << endl;
    //cout << "ptr = " << ptr << endl;
    //cout << "lit_ptr = " << lit[ptr] << endl;

    // ヒットしたか？
    while(fibptr == lit[ptr]){
      ans *= f1;
      ans %= MOD;
      ptr++;
      if(ptr >= lit.size()){
        break;
      }
    }
      

    f2 = f0 + f1;
    f0 = f1 % MOD;
    f1 = f2 % MOD;
    fibptr += 1;
  }
  cout << ans << endl;

  return 0;
}
  





  
  
