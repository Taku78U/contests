#include <bits/stdc++.h>
//#define DBG

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
bool tbl[6][4000][4000];
// 2つ目の添字: カウント開始位置
// 1つ目の添字は一緒
long long tbl_acc [6][4000];

int main(){
  cin >> n;
  cin.ignore();
  cin >> s;
  cin.ignore();
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < n; j++){
      tbl_acc[i][j] = 0ll;
      for(int k = 0; k < n; k++){
        tbl[i][j][k] = false;
      }
    }
  }

#ifdef DBG
  std::string filename = "test.txt";
  std::ofstream writing_file;
  writing_file.open(filename, std::ios::out);
#endif

  for (int i = 1; i < n; i++){ // 距離ごとに走査 i: 距離
    for(int j = 0; j < n - i; j++){ // j: 開始位置
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
          switch(s[j+i]){
            case 'R':
              tbl[2][i][j] = true;
              break;
            case 'B':
              tbl[3][i][j] = true;
              break;
          }
          break;
        case 'B':
          switch(s[j+i]){
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

  #ifdef DBG
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        if(tbl[i][j][k] == true)
        printf("tbl[%d][%d][%d]: %d\n", i, j, k, (int)tbl[i][j][k]);
      }
    }
  }
  #endif
  // 色ごと 開始位置の総和を求めておく
  for (int i = 0; i < 6; i++){ // 色
    for (int j = 0; j < n - 1; j++){ // 開始位置
      for (int k = 1; k < n; k++){ // 距離 
        tbl_acc[i][j] += (long long)tbl[i][k][j];
      }
    }
  }

  #ifdef DBG
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < n; j++){
      //printf("tbl_acc[%d][%d]: %lld\n", i, j, tbl_acc[i][j]);
      writing_file << "tbl_acc[" << i << "][" << j << "]: " << tbl_acc[i][j] << endl;
    }
  }
  #endif
  long long sum = 0ll;
  int pattern = 0; // siとsjのパターン
  // 相異なるパターン、距離の違うものを足せばいい
  long long adden = 0ll;
  for (int i = 0; i < n -3; i++){ // 文中i
    for(int ji = 1; ji < n; ji++){ // 文中 j-i (距離)
      int j = i + ji;
      int p;
      if(j >= n) continue;
      if(s[i] == 'R' && s[j] == 'G') pattern = 3;
      else if(s[i] == 'R' && s[j] == 'B') pattern = 5;
      else if(s[i] == 'G' && s[j] == 'R') pattern = 1;
      else if(s[i] == 'G' && s[j] == 'B') pattern = 4;
      else if(s[i] == 'B' && s[j] == 'R') pattern = 0;
      else if(s[i] == 'B' && s[j] == 'G') pattern = 2;
      else continue; // どれでもない場合はスルー

      adden = tbl_acc[pattern][j] - ((j + ji < n) ? (long long) tbl[pattern][ji][j] : 0);
      sum += adden;
      #ifdef DBG
      writing_file << "(i, j) = (" << i << ", " << j << "), " << flush;
      writing_file << "pattern = " << pattern << endl;
      writing_file << "tbl_acc[pattern][j] = " << tbl_acc[pattern][j] << endl;
      writing_file << "tbl[pattern][ji][j] = " << tbl[pattern][ji][j] << endl;
      writing_file << "adden = " << adden << endl;
      writing_file << "sum = " << sum << endl;
      #endif
    }
  }
  cout << sum << endl;
  return 0;
}

  
