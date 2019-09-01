#include <bits/stdc++.h>

using  namespace std;

int main(){
  int n, d;

  cin >> n >> d;
  cin.ignore();

  // 一人が2D+1本の林檎の木を監視する
  // 塀区間

  int range = 2 * d + 1;


  int ans;
  ans = n / range;

  if(n % range > 0){
    ++ans;
  }

  cout << ans << endl;
  return 0;
}
