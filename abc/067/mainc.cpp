#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void){
  int n;
  cin >> n;
  cin.ignore();
  ll a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  ll snuke = 0;
  ll arai = 0;
  snuke = a[0];
  
  for (int i = 1; i < n; i++){
    arai += a[i];
  }
  ll ans = abs(snuke - arai);
  ll tmpans;
  for (int i = 1; i < n - 1; i++){
    snuke += a[i];
    arai -= a[i];
    tmpans = abs(snuke - arai);
    if(tmpans < ans) ans = tmpans;
  }
  cout << ans << endl;
  return 0;
}
