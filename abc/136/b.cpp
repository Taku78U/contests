#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;

  cin >> n;
  cin.ignore();

  int tmp = 1;
  int cnt = 0;

  for(tmp = 1; tmp <= n/10; tmp *= 100){
    cnt += (tmp * 10) - tmp;
  }


  //cout << tmp << endl;

  // 残り何桁？
  int rem_n;
  rem_n = n / tmp;
  if(rem_n == 0){
    cout << cnt << endl;
    return 0;
  }

  cnt += n - tmp + 1;
  cout << cnt << endl;
  return 0;
}
