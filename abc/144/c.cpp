#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main(){
  ll n;
  cin >> n;

  double routen = sqrt((double)n);

  //n平方根から、割り切れる最小を見つける

  ll a, b;
  for (ll i = (ll)(routen + 1); i > 0; i--){
    if(n % i == 0){
      a = n / i;
      b = i;
      break;
    }
  }

  ll ans = (a - 1) + (b - 1);
  cout << ans << endl;
  return 0;
}
  
    
