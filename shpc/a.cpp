#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int main(void){
  ll a, b;
  cin >> a >> b;
  cin.ignore();

  if(a + b == 15){
    cout << '+' << endl;
  } else if (a * b == 15) {
    cout << '*' << endl;
  } else {
    cout << 'x' << endl;
  }

  return 0;
}
