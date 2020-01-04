#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000

// true:1 false:0
static bool s[MAX_SIZE][MAX_SIZE];

int main(){

  // 初期化
  for (int i = 0; i < MAX_SIZE; i++){
    for (int j = 0; j < MAX_SIZE; j++){
      s[i][j] = false;
    }
  }
  
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  cin.ignore();

  // 両方ゼロは、片方で全梅
  if((a == 0) && (b == 0)){
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        cout << "0" << flush;
      }
      cout << endl;
    }
    return 0;
  }

  // どちらかゼロのケースを除外

  if(a == 0){
    // b行目までゼロ、そっから1
    for (int i = 0; i < b; i++){
      for (int j = 0; j < w; j++){
        cout << "0" << flush;
      }
      cout << endl;
    }
    for (int i = 0; i < h - b; i++){
      for (int j = 0; j < w; j++){
        cout << "1" << flush;
      }
      cout << endl;
    }
    return 0;
  }
    
  if(b == 0){
    // a列目までゼロ、そっから1
    for (int i = 0; i < h; i++){
      for (int j = 0; j < a; j++){
        cout << "0" << flush;
      }
      for (int j = a; j < w; j++){
        cout << "1" << flush;
      }
      cout << endl;
    }
    return 0;
  }


  // 等しい場合
  int cnt = w / a;
  if((w / a == 2) && (((h / b == 3) && (h % b == 0)) || (h / b == 2))){
    for (int i = 0; i < h; i++){
      cnt = i / b;
      if(cnt == 0){
        for (int j = 0; j < a; j++){
          s[i][j] = true;
        }
        for (int j = a; j < w; j++){
          s[i][j] = false;
        }
      } else {
        for (int j = 0; j < a; j++){
          s[i][j] = false;
        }
        for (int j = a; j < w; j++){
          s[i][j] = true;
        }
      }
    } 
  } else if(((w / a == 3) && (w % a == 0) || (w / a == 3)) && (h / b == 2)){
    for (int i = 0; i < h; i++){
      cnt = i / b;
      if(cnt == 0){
        for (int j = 0; j < 2 * a; j++){
          s[i][j] = true;
        }
        for (int j = 2 * a; j < w; j++){
          s[i][j] = false;
        }
      } else {
        for (int j = 0; j < 2 * a; j++){
          s[i][j] = false;
        }
        for (int j = 2 * a; j < w; j++){
          s[i][j] = true;
        }
      }
    }
  } else   if((w / a == h / b)){
  // まずWがAの、HがBの倍数じゃないとアウト
    if((w%a>0) || (h%b>0)){
      cout << "No" << endl;
      return 0;
    }
    for(int i = 0; i < h; i++){
      cnt = i / b;
      for(int j = 0; j < w; j++){
        if((a * cnt <= j) && (j < a * (cnt + 1))){
          s[i][j] = true;
        } else {
          s[i][j] = false;
        }
      }
    }
  } else {
    cout << "No" << endl;
    return 0;
  }

  // 配列吐き出し
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if(s[i][j] == true){
        cout << "1" << flush;
      } else {
        cout << "0" << flush;
      }
    }
    cout << endl;
  }
  
  return 0;
}
