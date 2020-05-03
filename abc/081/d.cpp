#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  vector<ll> a;
  ll tmp;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp);
  }

  // 正負混在の場合は非負のみにする
  
