#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned long long x;
  cin >> x;
  cin.ignore();

  unsigned long long a = 100;
  if(a == x){
    cout << 0 << endl;
    return 0;
  }
  unsigned long long cnt = 0;
  while (true) {
    a += a / 100;
    ++cnt;
    if(a >= x){
      cout << cnt << endl;
      return 0;
    }
    //cout << a << endl;
  }
  return 0;
}
