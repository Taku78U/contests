#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll memo[20][20];

//#define DBG
//#define DBG2
//#define DBG3

#define MAX 999999999

struct axis{
  int x;
  int y;
  int cnt; // それまでの移動距離
  char dir; // どこから来たか？
};

bool mei[20][20]; //盤面

void print_memo(int h, int w){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << memo[i][j] << " " << flush;
    }
    cout << endl;
  }
  cout << endl;
  return;
}

int main(){
  ll h, w;
  cin >> h >> w;
  cin.ignore();

  for(int k = 0; k < 20; k++){
    for(int l = 0; l < 20; l++){
      mei[k][l] = false;
      memo[k][l] = MAX;
    }
  }

  stack<axis> stk;
  char tmp_c;
  string s;

  for(ll i = 0; i < h; i++){
    cin >> s;
    for(ll j = 0; j < w; j++){
      if(s[j] == '.'){
        mei[i][j] = true;
      }
    }
    cin.ignore();
  }

#ifdef DBG3
  for(ll i = 0; i < h; i++){
    for(ll j = 0; j < w; j++){
      if(mei[i][j] == true){
        cout << "." << flush;
      } else {
        cout << "#" << flush;
      }
    }
    cout << endl;
  }
#endif

  axis ax;
  axis tmp_ax;
  int max = 0; // 最大値
  for(int i = 0; i < h; i++){
    for(int j = 0; j <  w; j++){
      if(mei[i][j] == false) continue; // 壁からはムリ
      ax.x = j;
      ax.y = i;
      ax.cnt = 0;
      ax.dir = 's';

      for(int k = 0; k < 20; k++){
        for(int l = 0; l < 20; l++){
          memo[k][l] = MAX;
        }
      }

      memo[i][j] = 0;
#ifdef DBG
      cout << "A" << endl;
      cout << "ax.x = " << ax.x << endl;
      cout << "ax.y = " << ax.y << endl;
#endif
      stk.push(ax);
      while(stk.empty() == false){
        ax = stk.top();
        memo[ax.y][ax.x] =ax.cnt;
#ifdef DBG
        cout << "POP" << endl;
        cout << "ax.x = " << ax.x << endl;
        cout << "ax.y = " << ax.y << endl;
#endif
        stk.pop();
        // 上
        if(ax.y != 0){
          if(mei[ax.y-1][ax.x] == true){
            tmp_ax.x = ax.x;
            tmp_ax.y = ax.y - 1;
            tmp_ax.cnt = ax.cnt + 1;
            if(memo[tmp_ax.y][tmp_ax.x] > tmp_ax.cnt){
              #ifdef DBG
              cout << "UP" << endl;
              #endif
              stk.push(tmp_ax);
            }
          }
        }
        // 右
        if(ax.x <= w - 2){
          if(mei[ax.y][ax.x+1] == true){
            tmp_ax.x = ax.x + 1;
            tmp_ax.y = ax.y;
            tmp_ax.cnt = ax.cnt + 1;
            if(memo[tmp_ax.y][tmp_ax.x] > tmp_ax.cnt){
              #ifdef DBG
              cout << "R" << endl;
              #endif
              stk.push(tmp_ax);
            }
          }
        }

        // 左
        if(ax.x != 0){
          if(mei[ax.y][ax.x-1] == true){
            tmp_ax.x = ax.x - 1;
            tmp_ax.y = ax.y;
            tmp_ax.cnt = ax.cnt + 1;
            if(memo[tmp_ax.y][tmp_ax.x] > tmp_ax.cnt){
              #ifdef DBG
              cout << "L" << endl;
              #endif
              stk.push(tmp_ax);
            }
          }
        }

        // 下
        if(ax.y <= h - 2){
          if(mei[ax.y+1][ax.x] == true){
            tmp_ax.x = ax.x;
            tmp_ax.y = ax.y + 1;
            tmp_ax.cnt = ax.cnt + 1;
            if(memo[tmp_ax.y][tmp_ax.x] > tmp_ax.cnt){
              #ifdef DBG
              cout << "D" << endl;
              #endif
              stk.push(tmp_ax);
            }
          }
        }
      }

      // 最大値探索
      for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
          if(mei[i][j] == true){
            if((max < memo[i][j]) && (memo[i][j] < MAX)){
              max = memo[i][j];
            }
          }
        }
      }
      #ifdef DBG2
      print_memo(h, w);
      #endif
    }
  }

  cout << max << endl;
  return 0;
}
