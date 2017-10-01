#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main (void) {
  ull n;
  cin >> n;
  cin.ignore();
  ull a[n];
  ull b[n];
  for (ull i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    cin.ignore();
  }
  sort (a, a + n);
  sort (b, b + n);
  ull res = 0;
  res = a[n-1] + b[0];
  cout << res << endl;
  return 0;
}
