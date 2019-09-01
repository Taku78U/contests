#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  cin.ignore();
  int k[10];
  int snum[10][10];
  int s[10];
  for(int i = 0; i < m; i++){
    cin >> k[i];
    for (int j = 0; j < k[i]; j++){
      cin >> snum[i][j];
    }
    cin.ignore();
  }

  int s[10] = {0};
  
