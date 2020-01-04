#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 200000
//#define MAX_NUM 6

int tabl[MAX_NUM] = {0};

int main(){
  for (int i = 0; i < MAX_NUM; i++){
    tabl[i] = 0;
  }

  int n;
  cin >> n;
  cin.ignore();

  // まずAに格納
  int tmp;
  int ans1 = 0; // 書き換え前
  int ans2 = 0; // 書き換え後
  for (int i = 0; i < n; i++){
    cin >> tmp;
    --tmp;
    cin.ignore();
    if(tabl[tmp] == 1){
      ans2 = tmp;
    } else if(tabl[tmp] == 0){
      tabl[tmp] = 1;
    } else {
      cout << "i = " << i << ", tmp = " << tmp << " but tabl[tmp] = " <<tabl[tmp] << " ERR!" << endl;
      return 0;
    }
  }

  // 未だに0のところが書き換え前
  for (int i = 0; i < n; i++){
    if(tabl[i] == 0){
      ans1 = i;
      cout << ans2 + 1 << " " << ans1 + 1 << endl;
      return 0;
    }
  }

  cout << "Correct" << endl;
  return 0;
}
  
