#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  cin.ignore();
  int n = s.length();
  

  // 回文？
  bool ans = true;
  for(int i = 0; i < n / 2; i++){
    //cout << "i = " << i << " s[i] = " << s[i] << " s[n-1-i] = " << s[n-1-i] << flush;
    if(s[i] != s[n-1-i]){
      cout << "No" << endl;
      return 0;
    }
  }
  //cout << "a" << endl;

  // 条件2？
  int c; // 相手の番号
  n /= 2;
  for(int i = 0; i < n / 2; i++){
    if(s[i] != s[n-1-i]){
      cout << "No" << endl;
      return 0;
    }
  }

  //cout << "b" << endl;
  
  /*
  for (int i = (n+3)/2 - 1; i < ((n + 3) / 2 + n) - 1; i++){
    if(s[i] != s[n-1-(i- ((n+3)/2-1))]){
      cout << "No" << endl;
      return 0;
    }
  }
  */

  cout << "Yes" << endl;
  return 0;
}
