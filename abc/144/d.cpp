#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  int a, b, x;
  double theta;
  cin >> a >> b >> x;
  cin.ignore();

  int full = a * a * b;
  double ans_rad, ans;
  double tang;

  double h; // 高さ どっちかは場合による

  if(x * 2 == full){
    tang = b / (double) a;
    ans_rad = atan(tang);
    //cout << "ans_rad = " << ans_rad << endl;
    ans = ans_rad * 180 / M_PI;
    printf("%.10f\n", ans);
  } else if(x * 2 > full){ // 半分以上

    //高さa
    //三角形の面積を求める
    h = (full - x) / (double)a * 2 / (double)a;
    ans_rad = atan(h / (double) a);
    ans = ans_rad * 180 / M_PI;
    printf("%.10f\n", ans);
  } else { // 半分未満
    h = x / (double)a * 2 / (double)b;
    ans_rad = atan((double)b / h);
    ans = ans_rad * 180 / M_PI;
    printf("%.10f\n", ans);
  }
  return 0;
}
