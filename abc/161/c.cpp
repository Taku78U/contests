#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;
int main(){
  cin >> n >> k;
  cin.ignore();
  if(n == 0){
    cout << 0 << endl;
    return 0;
  }

  ll m = n % k;
  ll an_m = k - m;
  if(m < an_m){
    cout << m << endl;
    return 0;
  }
  cout << an_m << endl;
  return 0;
}
