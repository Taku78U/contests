#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  cin.ignore();

  y = y - 2 * x;
  if(y < 0){
    cout << "No" << endl;
    return 0;
  }

  int y_d = y / 2;
  int y_m = y % 2;
  if(y_m == 1){
    cout << "No" << endl;
    return 0;
  }

  if(y_d > x){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}
