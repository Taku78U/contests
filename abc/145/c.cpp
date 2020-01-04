#include <bits/stdc++.h>

using namespace std;

using ll = long long;

double len[8][8];

int main(){
  int n;
  vector <ll> x;
  vector <ll> y;

  cin >> n;
  cin.ignore();

  ll tmp_x, tmp_y;
  for(int i = 0; i < n; i++){
    cin >> tmp_x >> tmp_y;
    cin.ignore();
    x.push_back(tmp_x);
    y.push_back(tmp_y);
  }
  // 初期化
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      len[i][j] = 0;
    }
  }
  double ans = 0;
  if(n == 2){
    ans = sqrt(pow(x[0] - x[1], 2.0) + pow(y[0] - y[1], 2.0));
    printf("%.12f\n", ans);
    return 0;
  }

  // とにかく記憶していく
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      len[i][j] = sqrt(pow(x[i] - x[j], 2.0) + pow(y[i] - y[j], 2.0));
    }
  }

  // 特定の2点を除いた階乗
  ll fact_2 = 1;
  for(int i = 1; i <= n - 2; i++){
    fact_2 *= i;
  }

  ll fact = 1;
  for(int i = 1; i <= n; i++){
    fact *= i;
  }
  
  ll line_n = (n - 1) * fact_2; // 特定の1辺が入る通り方の数

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans += line_n * len[i][j];
    }
  }

  printf("%.12f\n", ans/fact);
  return 0;
}


    
