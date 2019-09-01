#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n, k;
  cin >> n >> k;
  cin.ignore();

  ll a[n];
  for (ll i = 0; i < n; i++){
    cin >> a[i];
  }
  cin.ignore();

  // i番目までの和の列
  ll s[n];
  ll cnt = 0;
  s[0] = a[0];
  for (ll i = 1; i < n; i++){
    s[i] = s[i - 1] + a[i];
  }

  // S自たい
  for (ll i = 0; i < n; i++){
    if(s[i] >= k){
      cnt = n - i;
    }
  }

  if(s[n-1] < k){
    cout << 0 << endl;
    return 0;
  }

  for(ll i = 0; i < n; i++){
    for(ll j = i + 1; j < n; j++){
      if(s[j] - s[i] >= k){
        cnt += n - j;
        break;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
  
