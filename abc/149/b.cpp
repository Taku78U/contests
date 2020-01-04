#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll a, b, k;
  cin >> a >> b >> k;
  cin.ignore();

  ll cnt = 0;
  if(a < k){
    k -= a;

    if(b < k){
      cout << 0 << " " << 0 << endl;
      return 0;
    } else { // b >= k
      
      cout << 0 << " " << (b - k) << endl;
      return 0;
    }
  } else { // a >= k
    a -= k;
    cout << a << " " << b << endl;
  }
  return 0;
}
      
