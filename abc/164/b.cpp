#include <bits/stdc++.h>

using namespace std;

int main (){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cin.ignore();

  int t_cnt, a_cnt;
  t_cnt = c / b + ((c % b != 0) ? 1 : 0);
  a_cnt = a / d + ((a % d != 0) ? 1 : 0);

  if(t_cnt <= a_cnt){
    cout << "Yes" << endl;
    return 0;
  } else {
    cout << "No" << endl;
    return 0;
  }
  return 0;
}
