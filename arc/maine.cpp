#include <bits/stdc++.cpp>

using namespace std;
using ll = long long;

int main (void){
  ll n, k;
  cin >> n >> k;
  cin.ignore();
  ll a[n];
  for(ll i = 0; i < n; i++){
    cin >> a[i];
    cin.ignore();
  }

  // まず最左を見つける

  ll meanl = 0;
  ll suml = 0;
  ll l = 0;
  while(meanl < k && l < n){
    suml+=a[l];
    l++;
    meanl = suml / l;
  }

  if (l == n && meanl < k) {
    cout << 0 << endl;
    return 0;
  }

  ll res = 0;
  res += n - r + 1;

  ll mean = 0;
  ll sumr= 0;
  ll sum += 0;
  ll r = 0;
  ll kl = k * l;
  ll kr = 0;
  while (r < n){
    sumr += a[r];
    r++;
    kr += k;
    l++;
    suml += a[l];
  }

  cout << res << endl;

  return 0;
}
