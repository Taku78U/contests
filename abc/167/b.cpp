#include <bits/stdc++.h>

using namespace std;

int a, b, c, k;
int main(){
  cin >> a >> b >> c >> k;
  cin.ignore();

  if (k < a){
    cout << k << endl;
    return 0;
  }

  if((a <= k) && (k <= a + b)){
    cout << a << endl;
    return 0;
  }

  cout << a - (k - (a + b)) << endl;
  return 0;
}
