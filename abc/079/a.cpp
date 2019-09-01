#include <bits/stdc++.h>

using namespace std;

int main (void){
  int n;
  cin >> n;
  int r = 0;
  int pre = 0;
  int cur = 0;
  for (int i = 0; i < 4; i++){
    pre = cur;
    cur = n % 10;
    n = n / 10;
    if(cur == pre) {
      r += 1;
      if(r == 3) {
        cout << "Yes" << endl;
        return 0;
    }
    } else {
      r = 1;
    }
  }

  cout << "No" << endl;
  return 0;
}
