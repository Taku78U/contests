#include <bits/stdc++.h>

using namespace std;

unsigned long long a, b, n;

int main(){
  cin >> a >> b >> n;
  cin.ignore();

  // xにて、mod bが一番大きいとき
  if(b - 1 <= n){
    cout << (a * (b - 1)) / b << endl;
  } else {
    cout << (a * n) / b << endl;
  }
  return 0;
}
