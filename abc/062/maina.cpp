#include <bits/stdc++.h>

using namespace std;

int main (void){
  int x, y;
  cin >> x >> y;

  int a[7] = {1, 3, 5, 7, 8, 10, 12};
  int b[4] = {4, 6, 9, 11};
  int c = 2;

  int xg = 0, yg = 0;
  for (int i = 0; i< 7; i++){
    if(a[i] == x) xg = 0;
    if(a[i] == y) yg = 0;
  }
  for (int i = 0; i< 4; i++){
    if(b[i] == x) xg = 1;
    if(b[i] == y) yg = 1;
  }
  if(x == c) xg = 2;
  if(y == c) yg = 2;

  if(xg == yg) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
