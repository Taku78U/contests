#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main (){
  int n;
  cin >> n;
  cin.ignore();

  ll a[n];

  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  cin.ignore();

  ll sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }

  // 平均だと少数比較がめんどくさいので倍にしちゃう

  for(int i = 0; i < n; i++){
    a[i] *= n;

    a[i] = abs(a[i] - sum);
  }

  // ソートを使わない方法

  // 差は99より上にはならない
  ll MAX = 99;

  ll min = a[0];
  int idx = 0;
  
  for(int i = 1; i < n; i++){
    if(a[i] < min){
      min = a[i];
      idx = i;
    }
  }

  cout << idx << endl;
  return 0;
}
    
