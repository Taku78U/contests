#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll h, w, k;

bool s[10][1000];
ll d[10][1000]; // ホワイトチョコレートのi, jまでの総数

ll dp[2][8]

int main(){
  cin >> h >> w >> k;
  cin.ignore();

  for (int i = 0; i < 10; i++){
    for(int j = 0; j < 1000; j++){
      s[i][j] = false;
      d[i][j] = 0;
    }
  }

  string tmp_s;
  for (int i = 0; i < h; i++){
    cin >> s;
    cin.ignore();
    for(int j = 0; j < w; j++){
      if(tmp_s[j] == '1'){
        s[i][j] = true;
      } else {
        s[i][j] = false;
      }
    }
  }

  for(int i = 0; i < w; i++){
    if(s[0][i] == true){
      d[0][i] = 1;
    } else {
      d[0][i] = 0;
    }
  }
  for(int i = 0; i < h; i++){
    if(s[i][0] == true){
      d[i][0] = 1;
    } else {
      d[i][0] = 0;
    }
  }
  
  
