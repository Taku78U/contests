#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX_N 10
#define DBG

ll a[MAX_N][MAX_N];

int b[10] = {0}; // 社員の所属グループ

int n = 0;

using ull = unsigned long long;

int b2_incl_sub(int i, int incl){
  if((b[i]== 2) && (incl == 1)){
    b[i] = 0;
    return 1;
  } else {
    b[i] += incl;
    return 0;
  }
  return 0;
}

void b2_incl(){
  int incl = 1;
  for(int i = 0; i < n; i++){
    incl = b2_incl_sub(i, incl);
  }
  return;
}

bool b2_all_two(){
  for(int i = 0; i < n; i++){
    if(b[i] != 2){
      return false;
    }
  }
  return true;
}

void b2_init(){
  for(int i = 0; i < 10; i++){
    b[i] = 0;
  }
  return;
}


// 全探索でいける
int main(){
  cin >> n;
  cin.ignore();

  // a初期化
  for (int i = 0; i < MAX_N; i++){
    for (int j = 0; j < MAX_N; j++){
      a[i][j] = 0;
    }
  }
  // a入力
  for (int i = 0; i < n - 1; i++){
    for (int j = i + 1; j < n; j++){
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
    cin.ignore();
  }

  // 全部一緒の場合
  ll tmp = 0;
  for (int i = 0; i < n - 1; i++){
    for (int j = i + 1; j < n; j++){
      tmp += a[i][j];
    }
  }

  ll max_kofuku = tmp;
  // 2つ以上に分ける場合
  // ビット全探索応用編！

  vector<int> v0, v1, v2;
  ll kofuku0, kofuku1, kofuku2, sum_kofuku;
  
  for(b2_init(); b2_all_two() == false; b2_incl()){
    kofuku0 = 0;
    kofuku1 = 0;
    kofuku2 = 0;
    v0.clear();
    v1.clear();
    v2.clear();
    for(int i = 0; i < n; i++){
      if(b[i] == 0){
        v0.push_back(i);
      } else if(b[i] == 1){
        v1.push_back(i);
      } else if(b[i] == 2){
        v2.push_back(i);
      }
    }
    // 幸福度を求める(ここは不要かも)
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // v0
    for(int i = 0; i < v0.size(); i++){
      for(int j = i + 1; j < v0.size(); j++){
        kofuku0 += a[v0[i]][v0[j]];
      }
    }

    // v1
    for(int i = 0; i < v1.size(); i++){
      for(int j = i + 1; j < v1.size(); j++){
        kofuku1 += a[v1[i]][v1[j]];
      }
    }

    // v0
    for(int i = 0; i < v2.size(); i++){
      for(int j = i + 1; j < v2.size(); j++){
        kofuku2 += a[v2[i]][v2[j]];
      }
    }
    sum_kofuku = kofuku0 + kofuku1 + kofuku2;
    if(max_kofuku < sum_kofuku) max_kofuku = sum_kofuku;
  }

  cout << max_kofuku << endl;

  return 0;
}
  
  
  
