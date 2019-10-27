#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  cin.ignore();
  int ans = a - (b * 2);
  if(ans <= 0){
    cout << 0 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
