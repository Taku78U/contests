#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void){

  int c;

  cin >> c;

  int a[3];
  a[0] = c / 100;
  a[1] = (c % 100) / 10;
  a[2] = c % 10;

  int sum;

  sum = a[0] + a[1] + a[2];

  cout << sum << endl;

  return 0;
}
