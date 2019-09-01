#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main (void){
  int n;
  cin >> n;

  ull a = 2;
  ull b = 1;

  if (n == 0) {
    cout << a << endl;
    return 0;
  }
  if(n == 1){
    cout << b << endl;
    return 0;
  }

  ull tmp;
  for (int i = 0; i <= n-2; i++){
    tmp = a + b;
    a = b;
    b = tmp;
  }

  cout << b << endl;
  return 0;
}
