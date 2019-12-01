#include <bits/stdc++.h>

using namespace std;

int s[300][300];

void color_s(int wp_l, int hp_u, int wp_r, int hp_d, int num){
  for(int i = hp_u; i < hp_d; i++){
    for (int j = wp_l; j < wp_r; j++){
      s[i][j] = num;
    }
  }
  return;
}

int main(){
  for(int i = 0; i < 300; i++){
    for (int j = 0; j < 300; j++){
      s[i][j] = 0;
    }
  }

  int h, w, k;
  cin >> h >> w >> k;
  cin.ignore();
  char tmp_s;
  int num = 1;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> tmp_s;
      if(tmp_s == '#'){
        s[i][j] = num;
        ++num;
      }
    }
    cin.ignore();
  }


  bool first_found = false;

  int wp_l = 0, hp_u = 0;
  int wp_r = 1, hp_d = 1;

  int tmp_num = 1;
  bool colored = false;
  for (int i = 0; i < h; i++){
    colored = false;
    wp_l = 0;
    for(int j = 0; j < w; j++){
      if(s[i][j] != 0){
        tmp_num = s[i][j];
        color_s(wp_l, hp_u, j + 1, i + 1, tmp_num);
        wp_l = j + 1;
        colored = true;
      } else if ((j == w - 1) && (colored == true)){ // 最終列の場合かつ塗が出た場合、それまでで塗りつぶす
        color_s(wp_l, hp_u, w, i + 1, tmp_num);
      }
    }
    if(colored == true){
      hp_u = i + 1;
    }
  }

  for (int i = hp_u; i < h; i++){
    for(int j = 0; j < w; j++){
      s[i][j] = s[i-1][j];
    }
  }

L_END:
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      printf("%3d ", s[i][j]);
    }
    cout << endl;
  }

  return 0;
}
