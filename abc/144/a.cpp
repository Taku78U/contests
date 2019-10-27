#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b;

  cin >> a >> b;

  if((0 < a) && (a < 10) && (0 < b) && (b < 10)){
    cout << a * b << endl;

  } else {
    cout << -1 << endl;
  }
  return 0;
}
