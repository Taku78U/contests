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

  for (int i = 0; i < b; i++){
    for(int j = 0; j < a; j++){
      cout << "1" << flush;
    }
    for(int j = a; j < w; j++){
      cout << "0" << flush;
    }
    cout << endl;
  }
  for (int i = b; i < h; i++){
    for(int j = 0; j < a; j++){
      cout << "0" << flush;
    }
    for(int j = a; j < w; j++){
      cout << "1" << flush;
    }
    cout << endl;
  }
  
  return 0;
}
