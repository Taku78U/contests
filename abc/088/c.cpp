#include <bits/stdc++.h>

using namespace std;

int main (void) {
  int c[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c[i][j];
    }
    cin.ignore();
  }

  // 予め定まっているなら、同じ行/列で差は等しいはず
  // b判定                                                                                                       
  bool cor = true;
  int difb[2];
  difb[0] = c[0][1] - c[0][0];
  difb[1] = c[0][2] - c[0][1];
  for (int i = 1; i < 3; i++) {
    if(cor == true && difb[0] != c[i][1] - c[i][0]){
      cor = false;
    }
    if(cor == true && difb[1] != c[i][2] - c[i][1]){
      cor = false;
    }
  }
  if(cor == false) {
    cout << "No" << endl;
    return 0;
  }
  // a判定                                                                                                       
  bool cor = true;
  int difa[2];
  difa[0] = c[1][0] - c[0][0];
  difa[1] = c[2][0] - c[1][0];
  for (int i = 1; i < 3; i++) {
    if(cor == true && difb[0] != c[1][i] - c[0][i]){
      cor = false;
    }
    if(cor == true && difb[1] != c[2][i] - c[1][i]){
      cor = false;
    }
  }
  if(cor == false) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
