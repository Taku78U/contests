#include <bits/stdc++.h>

using namespace std;

//#define DBG // デバッグ指定

// フォローテーブル
#define MAX_N 100
int f[MAX_N][MAX_N]; // 左が右をフォロー
int tmpbuf[MAX_N] =  {0};

int n, q;

// フォロー返し
void refollow(int a){
  for(int i = 0; i < n; i++){
    if(i == a) continue;
    if(f[i][a] == 1){
      if(f[a][i] == 1) continue;
      f[a][i] = 1;
    }
  }
}

// フォローのフォローをフォロー
void followfollow(int a){
  memcpy((void*)tmpbuf, (void*)f[a], n * sizeof(int));
  for(int x = 0; x < n; x++){
    if(a == x) continue;
    if(tmpbuf[x] == 1){
#ifdef DBG
      cout << a << "FOLLOWS" << x << endl;
#endif

      for (int j = 0; j < n; j++){
        if(a == j) continue;
        if(f[x][j] == 1){
          f[a][j] = 1;
#ifdef DBG
          cout << a << "HAVE FOLLOWED" << j << endl;
#endif
        }
      }
    }
  }
}

void printfollow(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(f[i][j] == 1){
        cout << "Y" << flush;
      } else if(f[i][j] == 0){
        cout << "N" << flush;
      } else {
        cout << "E" << flush;
      }
    }
    cout << endl;
  }
}

int main(){
  // フォローテーブル初期化
  for (int i = 0; i < MAX_N; i++){
    for(int j = 0; j < MAX_N; j++){
      f[i][j] = 0;
    }
  }

  cin >> n >> q;
  cin.ignore();
  vector<string> log;
  string s;
  for(int k = 0; k < q; k++){
    //cin >> s;
    getline(cin, s);
    //cin.ignore();
    log.push_back(s);
  }

#ifdef DBG
  // 入力文字列の表示
  for(int k = 0; k < q; k++){
    cout << log[k] << endl;
  }
#endif

  int cmd = 0; // コマンド
  int a, b;
  int tmp;
#ifdef DBG
  printf("DBGPRINT ISS ON\n");
#endif
  for(int k = 0; k < q; k++){
    s = log[k];
    cmd = s[0];
    if(cmd == '1'){
      istringstream iss(s);
      iss >> tmp >> a >> b;
#ifdef DBG
      printf("%d %d %d FOLLOW\n", tmp, a, b);
#endif
      --a;
      --b;
      f[a][b] = 1;
    } else if(cmd == '2'){
      // フォロー返し
      istringstream iss(s);
      iss >> tmp >> a;
      --a;
#ifdef DBG
      printf("%d %d REFOLLOW\n", tmp, a);
#endif
      refollow(a);
    } else if(cmd == '3'){
      // フォローのフォローをする
      istringstream iss(s);
      iss >> tmp >> a;
      --a;
#ifdef DBG
      printf("%d %d FOLLOWFOLLOW\n", tmp, a);      
#endif
      followfollow(a);
    }
#ifdef DBG
    printfollow();
    cout << endl;
#endif
  }
  printfollow();
  return 0;
}
  
  
