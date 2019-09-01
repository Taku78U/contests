#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void) {
  int n;
  cin >> n;
  cin.ignore();

  char s[n];

  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  cin.ignore();
  // 結局黄色だけを調べれば解決
  for (int i = 0; i < n; i++) {
    if(s[i] == 'Y') {
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;
  return 0;
}
