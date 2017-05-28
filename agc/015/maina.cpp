#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
  ll n, a, b;
  cin >> n >> a >> b;
  if(a > b || n == 0 || ((a != b) && (n == 1))){
    cout << 0;
    return 0;
  }

  ll sum;
  sum = (n - 2) * (b - a) + 1;
  cout << sum << endl;
  return 0;
}
