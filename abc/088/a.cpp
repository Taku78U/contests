#include <bits/stdc++.h>

using namespace std;

int main (void) {
  int n, a;
  cin >> n;
  cin.ignore();
  cin >> a;
  int t;
  t = n % 500;
  if (a - t >= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
