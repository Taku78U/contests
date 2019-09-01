#include <bits/stdc++.h>

using namespace std;

int main(void){
  int a, b, c;
  cin >> a >> b >> c;
  cin.ignore();

  if(a + b >= c) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
