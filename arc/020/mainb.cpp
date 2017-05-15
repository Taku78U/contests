#include <bits/stdc++.h>

using namespace std;

int countsameclr(int* a, int i, int n){
  int cnt = 0;
  while (i < n - 1){
    if(a[i] != a[i+1]) break;
    cnt++;
    i++;
  }
  return cnt; // 実際のカウントより1つ小さい数が返る
}

int main (void) {
  unsigned int n, c;
  cin >> n >> c;
  cin.ignore();
  int a[n];
  string s;
  int i = 0;
  for(i=0; i<n ; i++){
    if(getline(cin, s)){
      a[i] = stoi(s);
    }
  }

  int b[n];
  // 1番に使う色と2番に使う色を決めて探索
  int j = 0;
  int k = 0;
  int minc = 0;
  int cost = 0;
  for (i = 1; i <= 10; i++){
    for (j = 1; j <= 10; j++){
      if(i==j) continue;
      for (k = 0; k < n; k+=2){
        b[k] = i;
      }
      for (k = 1; k < n; k+=2){
        b[k] = j;
      }
      // 不一致数を計算
      for (k = 0; k < n; k++){
        if(a[k] != b[k]) cost++;
      }
      if(minc > cost || (i == 1 && j == 2)) minc = cost;
      cost = 0;
    }
  }
  int sum;
  sum = minc * c;
  cout << sum << endl;
  return 0;

}
  
    
 
