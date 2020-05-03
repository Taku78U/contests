#include <bits/stdc++.h>

using namespace std;
int n, x, y;

int min(int a, int b){
  if(a < b){
    return a;
  }
  return b;
}

int max(int a, int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(){
  cin >> n >> x >> y;
  printf("%d\n", n); // x + 1 < y より

  int base;
  int sp_dist = y - x;

  bool uchigawa = true;
  int addi;
  int side, left, right; // はしっこ
  for(int k = 2; k < n - 1; k++){
    base = n - k;
    uchigawa = y - x - (k - 1) > k;
    left = x - 1;
    left = (left <= 0) ? 0 : left;
    right = n - y;
    right = (right <= 0) ? 0 : left;
    side = min(left, right);
    side = min(side, k - 1);
    addi = side; // 小さい方の端と逆端
    if(uchigawa == true){
      addi += side; // 小さい方の端と内側
      addi += k - 1; // 内側同士
      int side_a = max(left, right);
      addi += side_a; // 内側から逆サイド
    }
    side = min(left, right);
      
  }

  cout << 0 << endl; // 距離n-1は存在しない(x+1<yより)
  return 0;
}
  // 1 から 1
