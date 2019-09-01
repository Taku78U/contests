#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using ull = unsigned long long;

int main(void){

  ll x;

  cin >> x;

  cin.ignore();

  ll sum = 0;

  for (ll m = x; m > 0; m /= 10){
    sum += m % 10;
  }

  if(x % sum == 0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
