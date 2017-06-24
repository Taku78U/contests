#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void){
  int n;
  cin >> n;
  cin.ignore();

  int a[n] = {0};
  bool e[n] = {false};
  for (int i = 0; i< n; i++){
    cin>>a[i];
    cin.ignore();
  }
  int p = 0;
  int cnt = 0;
  while(1){
    if(e[p] == true){
      cout << -1 << endl;
      return 0;
    }
    e[p] = true;
    p = a[p] - 1;
    cnt++;
    if(p == 1){
      cout << cnt << endl;
      return 0;
    }
  }
}
