#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using uint = unsigned int;

struct vertex{
  uint num;
  ll z;

  bool operator<(const vertex& right) const{
    return z == right.z ? num < right.num : z < right.z;
  }
};

int main (void){
  uint n;
  cin >> n;
  cin.ignore();
  vertex x[n];
  veretex y[n];

  for(uint i = 0; i < n; i++){
    cin >> x[i].z >> y[i].z;
    x[i].num = i;
    y[i].num = i;
    cin.ignore();
  }

  sort(x, x + n);
  sort(y, y + n);

  // 隣接店グラフ構築
  ll e[n][n];
  for(uint i = 0; i < n; i++){
    for (uint j = 0; j < n; j++){
      e[i][j] = 0;
      

  return 0;
}
