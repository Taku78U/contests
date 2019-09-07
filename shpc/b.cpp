#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void) {
  string s;
  cin >> s;
  cin.ignore();

  ll w;
  cin >> w;
  cin.ignore();

  for (ll i = 0; i < s.length(); i = i + w){
    cout << s[i] << flush;
  }
  cout << endl;
  return 0;
}
