#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void){
  ll n, k;
  cin >> n >> k;
  cin.ignore();

  ll a[n];

  for (ll i = 0; i < n; i++){
    cin >> a[i];
  }

  // 1000程度なら大丈夫かな？
  // 合計は1001*500=500500要素、4004000Byte = 4MB-? OK!

  // 全部を列挙、大きい順にソート

  ll len = (n*(n+1))/2;
  ll sums[(n*(n+1))/2];
  ll idx = 0;
  for(ll i = 0; i < n; i++){
    sums[idx] = a[i];
    idx++;
    for(ll j  = i + 1; j < n; j++){
      sums[idx] = sums[idx-1] + a[j];
      //cout << sums[idx] << endl;
      idx++;
    }
  }
  sort(sums, sums + len, greater<long long>());
  for(ll i = 0; i < len; i++){
    cout << sums[i] << ' ' << flush;
  }
  cout << endl;
  return 0;
}
  
