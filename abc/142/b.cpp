#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;
  cin.ignore();
  int cnt = 0;
  int h;
  for(int i = 0; i < n; i++){
    cin >> h;
    if(h >= k) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
