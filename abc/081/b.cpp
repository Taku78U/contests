#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using ull = unsigned long long;

int main(void) {

  int n;

  cin >> n;

  cin.ignore();

  ll a[n];

  for (int i = 0; i < n; i++) cin >> a[i];

  cin.ignore();

  ll cnt = 0;

  bool flag = true;

  while(flag){
    for (int i = 0; i < n; i++){
      if(a[i] % 2 == 1) {
        flag = false;
        break;
      }
      a[i] /= 2;
    }
    if(flag) cnt ++;
  }

  cout << cnt << endl;
  return 0;
}
