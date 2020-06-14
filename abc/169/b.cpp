#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  long long ans = 1;
  long double ans_d = 1;
  long long tmp;
  // ゼロサーチもする
  bool min1 = false;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    ans *= tmp;
    ans_d *= tmp;
    if(ans_d > 1000000000000000000){
      if(ans != 1000000000000000000){
        min1 = true;
      }
    }
    if(tmp == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  if(min1 == true){
    cout << "-1" << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
