#include <bits/stdc++.h>

using namespace std;

int  n;
string s;

// 6
// 0: R-G
// 1: R-B
// 2: G-R
// 3: G-B
// 4: B-R
// 5: B-G
// 2つめの添字n: 距離
// 3つめの添字n: カウント開始位置
long long tbl_acc [6][n][n];
bool tbl[6][n][n];

int main(){
  cin >> n;
  cin.ignore();
  cin >> s;
  cin.ignore();
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        tbl_acc[i][j][k] = 0ll;
        tbl[i][j][k] = false;
      }
    }
  }

  for (int i = 1; i < n; i++){ // 距離ごとに走査
    for(int j = 0; j < n - i; j++){
      switch(s[j]){
        case'R':
          switch(s[j+i]){
            case 'G':
              tbl[0][i][j] = true;
              break;
            case 'B':
              tbl[1][i][j] = true;
              break;
            default:
              break;
          }
          break;
        case 'G':
          switch(s[j+1]){
            case 'R':
              tbl[2][i][j] = true;
              break;
            case 'B':
              tbl[3][i][j] = true;
              break;
          }
          break;
        case 'B':
          switch(s[j+1]){
            case 'R':
              tbl[4][i][j] = true;
              break;
            case 'G':
              tbl[5][i][j] = true;
              break;
          }
        default:
          break;
      }
    }
  }

  for (int i = 1; i <= n - 1; i++){ // 距離
    if(tbl[0][i][n - 1 - i] == true) tbl_acc[0][i][j] = 1;
    if(tbl[1][i][n - 1 - i] == true) tbl_acc[1][i][j] = 1;
    if(tbl[2][i][n - 1 - i] == true) tbl_acc[2][i][j] = 1;
    if(tbl[3][i][n - 1 - i] == true) tbl_acc[3][i][j] = 1;
    if(tbl[4][i][n - 1 - i] == true) tbl_acc[4][i][j] = 1;
    if(tbl[5][i][n - 1 - i] == true) tbl_acc[5][i][j] = 1;

  }
  
  for (int i = 1; i <= n - 1; i++){ // 距離
    for (int j = n - 1 - i - 1; j >= 0; j--){ // カウント開始位置
      if(tbl[0][i][j] == true) tbl_acc[0][i][j] = tbl_acc[0][i][j] + 1; else tbl_acc[0][i][j] = tbl_acc[0][i][j+1];
      if(tbl[1][i][j] == true) tbl_acc[1][i][j] = tbl_acc[1][i][j] + 1; else tbl_acc[1][i][j] = tbl_acc[1][i][j+1];
      if(tbl[2][i][j] == true) tbl_acc[2][i][j] = tbl_acc[2][i][j] + 1; else tbl_acc[2][i][j] = tbl_acc[2][i][j+1];
      if(tbl[3][i][j] == true) tbl_acc[3][i][j] = tbl_acc[3][i][j] + 1; else tbl_acc[3][i][j] = tbl_acc[3][i][j+1];
      if(tbl[4][i][j] == true) tbl_acc[4][i][j] = tbl_acc[4][i][j] + 1; else tbl_acc[4][i][j] = tbl_acc[4][i][j+1];
      if(tbl[5][i][j] == true) tbl_acc[5][i][j] = tbl_acc[5][i][j] + 1; else tbl_acc[5][i][j] = tbl_acc[5][i][j+1];
    }
  }

  // 相異なるパターン、距離の違うものを足せばいい
  for (int i = 0; i < 5; i++){ // 色
    for (int j = 0; j < n - 1

  
