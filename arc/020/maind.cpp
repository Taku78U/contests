#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using us = unsigned short;
using uint = unsigned int;


int main(void){
  us n, m, k;
  cin >> n >> m >> k;
  cin.ignore();
  us d[n-1];

  
  for(us i = 0; i < n-1; i++){
    cin >> d[i];
    cin.ignore();
  }

  // DPテーブル。ただし開始点が

  for (us i = 0; i < n - 1; i++){
    
