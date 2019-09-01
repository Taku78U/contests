#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  cin.ignore();

  // 1人のときは、分けるもくそもない
  if(k == 1){
    cout << 0 << endl;
    return 0;
  }

  // 均等に配った余りがそれ

  int ans = n - k;
  cout << ans << endl;
  return 0;
}
