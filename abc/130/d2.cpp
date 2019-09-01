#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n, k;
  cin >> n >> k;
  cin.ignore();

  vector<ll> a;
  ll tmp;
  ll sum = 0;

  for(ll i = 0; i < n; i++){
    cin >> tmp;
    sum += tmp;
    a.push_back(tmp);
  }
  cin.ignore();

  if(k > sum){
    cout << 0 << endl;
    return 0;
  } else if(k == sum){
    cout << 1 << endl;
    return 0;
  }

  tmp = 0;
  sum = 0;
  ll cnt = 0;
  for(ll i = 0; i < n; ++i){
    tmp += a[i];
    if(tmp >= k){
      cnt += n - i;
      tmp = 0;
    }
  }

  cout << cnt << endl;
  return 0;
}
