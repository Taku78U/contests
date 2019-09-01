#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, l;
  cin >> n >> l;
  cin.ignore();

  int sum;
  sum = n * l + (n * (n - 1)) / 2;

  int i;

  // いきなり正の場合
  if(l - 1 >= 0){
    cout << sum - l << endl;
    return 0;
  } else if(l + n - 1 <= 0){ // 最後まで負
    cout << sum - (l + n - 1) << endl;
    return 0;
  } else { // 途中から正負が変わる場合 -> 必ず0がいる
    i = 1 - l;
    cout << sum << endl;
  }
  return 0;
}   
    
