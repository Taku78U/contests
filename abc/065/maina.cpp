#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main(void){
  ll x, a, b;
  cin >> x >> a >> b;

  ll c = -a + b;
  if(c <= 0){
    cout << "delicious" << endl;
  }else if(c <= x){
    cout << "safe" << endl;
  } else cout << "dangerous" << endl;

  return 0;

}
