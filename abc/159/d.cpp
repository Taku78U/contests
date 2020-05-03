#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200000

using ll = long long;
ll tbl[2 * 100000 +1] = {0};
vector <ll> v;

using ll = long long;
int main(){
  ll n;
  cin >> n;
  cin.ignore();

  

  ll tmp_a;
  for (ll i = 0; i < n; i++){
    cin >> tmp_a;
    ++tbl[tmp_a];
    v.push_back(tmp_a);
  }

  ll ans = 0;
  for(int i = 1; i <= n; i++){
    if(tbl[i] <= 1) continue;
    ans += (tbl[i] * (tbl[i]-1)) / 2;
  }

  ll ans_tmp;
  for(ll i = 0; i < v.size(); i++){
    tmp_a = v[i];
    if(tbl[tmp_a] <= 1){
      printf("%lld\n", ans);
      continue;
    }
    ans_tmp = ans - (tbl[tmp_a] * (tbl[tmp_a] - 1)) / 2 + ((tbl[tmp_a]-1) * (tbl[tmp_a]-2)) / 2;
    printf("%lld\n", ans_tmp);
  }

  return 0;
}
  
