#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll w, h, x, y;
  cin >> w >> h >> x >> y;
  cin.ignore();

  // 要は、2等分でしかない
  double s;
  s = w * h / ((double) 2);
  printf("%.6f ", s);

  // 0は別
  if((w == 0) && (h == 0)){
    printf("0\n");
    return 0;
  } else if((w == 0) || (h == 0)){
    printf("1\n");
    return 0;
  }

  // x, yがそれぞれw, hの半分であればよさそう
  if(((x == w/2) && (w % 2 == 0)) && ((y == h / 2) && (h % 2 == 0))){
    printf("1\n");
  } else {
    printf("0\n");
  }
  return 0;
}
