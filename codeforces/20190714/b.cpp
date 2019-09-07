#include <bits/stdc++.h>

using namespace std;

int main(){
  int q;
  cin >> q;
  cin.ignore();

  // Query loop

  int colcnt[5*10000];
  char row[50000];
  int rowcnt = 0;
  int rowmax = 0;
  int need_row = 0;
  int n, m;
  for (int i = 0; i < q; i++){
    for(int j = 0; j < 50000; j++){
      colcnt[j] = 0;
    }
    cin >> n >> m;
    cin.ignore();
    for (int j = 0; j < n; j++){
      cin >> row;
      rowcnt = 0;
      rowmax = 0;
      cin.ignore();

      for (int k = 0; k < m; k++){
        if(row[k] == '*'){
          ++rowcnt;
          ++colcnt[j];
        }
      }
      if(rowmax < rowcnt){
        rowmax = rowcnt;
      }
      need_row = m - rowmax;
