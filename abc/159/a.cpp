#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  cin.ignore();

  int ans_n;
  if(n <= 1){
    ans_n = 0;
  } else {
    ans_n = n * (n - 1) / 2;
  }

  int ans_m;
  if(m <= 1){
    ans_m = 0;
  } else {
    ans_m = m * (m - 1) / 2;
  }

  int ans = ans_n + ans_m;
  cout << ans << endl;
  return 0;
}
