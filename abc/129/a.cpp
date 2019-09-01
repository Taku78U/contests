#include <bits/stdc++.h>

using namespace std;

int main (){
  int p, q, r;
  cin >> p >> q >> r;
  cin.ignore();

  // 最大のものを抽出
  int max_ = p;
  if(max_ < q) max_ = q;
  if(max_ < r) max_ = r;

  if(max_ == q){
    cout << p + r << endl;
    return 0;
  }

  if(max_ == p){
    cout << q + r << endl;
    return 0;
  }

  if(max_ == r){
    cout << p + q << endl;
    return 0;
  }
  return 0;
}
