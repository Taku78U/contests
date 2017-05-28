#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main (void){
  ull ba, bb;
  cin >> ba;
  cin.ignore();
  cin >> bb;
  cin.ignore();

  if (ba == bb) {
    cout << 1 << endl;
    return 0;
  }

  bool a[61] = {0}, b[61] = {0};

  for (int i = 0; i < 64; i++){
    a[i] = ba % 2;
    ba = ba / 2;
    b[i] = bb % 2;
    bb = bb / 2;
  }

  // どちらも1になるまで上位桁から調べる
  // そこから異なる部分だけ2をかけていく
  bool sw = 0;
  for (int i = 60; i >= 0; i--){
    

  return 0;
}
