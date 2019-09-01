#include <bits/stdc++.h>

using namespace std;


using ll = long long;
static const ll MOD = 1000000007;

int main(){

  ll n, m;
  cin >> n >> m;
  cin.ignore();

  vector <bool> a(n+1, true);
  ll tmp;
  for(int i = 0; i < m; i++){
    cin >> tmp;
    a[tmp] = false;
    cin.ignore();
  }

  ll f[n+1] = {0};
  f[0] = 1;

  for(ll i = 0; i < n; ++i){
    for(int next = i + 1; next <= min(i + 2, n); ++next){
      if(a[next]){
        //cout << "SSS" << endl;
        f[next] += f[i];
        f[next] %= MOD;
      }
    }
  }

  cout << f[n] << endl;

  return 0;
}
  
