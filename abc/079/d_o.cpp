#include <bits/stdc++.h>

using namespace std;

int c[10][10]; // c[from][to]
int h, w;

// 末端判定
bool allzero (vector<int> n){
  for (int i = 0; i < 10; i++){
    if(i == 1) continue;
    if(n[i] > 0) return false;
  }
  return true;
}

bool incl (int i, vector<int> donelist){
  for(auto itr = donelist.begin(); itr!= donelist.end(); itr++){
    if(*itr == i) return true;
  }
  return false;
}

// a: 数の配列
//  donelist 
int dp(int* a, vector<int> n, vector<int> donelist, int tmprk){
  int tmpr = tmprk;
  if(allzero(n)) return tmpr;
  // to
  for (int i = 0; i < 10; i++){
    if(!incl(i, donelist)){
      // from
      for(int j = 0; j < 10; j++){
        if(n[j] != 0){
          r = dp
        }
      }
    }
  }
}

int main (void){
  cin >> h >> w;
  cin.ignore();
  int a[h*w];
  vector<int> n(10, 0);

  for (int j = 0; j < 10; j++){
    for (int i = 0; i < 10; i++){
      cin >> c[j][i];
      cin.ignore();
    }
  }

  for (int j = 0; j < h; j++){
    for (int i = 0; i < w; i++){
      cin >> a[j*w+i];
      cin.ignore();
      if(a[j*w+i] != -1){
        n[a[j*w+i]]++;
      }
    }
  }
  
}
