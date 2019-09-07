#include <bits/stdc++.h>

using namespace std;

static const char maru = 'o';
static const char batu = 'x';

int main(){
  string s;
  cin >> s;
  cin.ignore();

  int sum = 0;

  for (int i = 0; i < s.length(); i++){
    if(s[i] == maru){
      sum++;
    }
  }

  // 残り何日？

  if(8 - sum <= 0){
    cout << "YES" << endl;
    return 0;
  }

  int left = 15 - s.length();

  // 残り勝ち数

  int win = 8 - sum;

  if(win <= left){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
