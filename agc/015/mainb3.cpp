#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (void){
  string str;
  cin >> str;
  if(str.length() < 2 || str.length() > 100000){
    return 0;
  }
  ll len = str.length();
  char s[str.length()];
  str.copy(s, str.size());
  //cout << s[0] << endl;
  ll sum = 0;

  // 戻り点を確認
  ll retu, retd;
  for (ll i = 0; i < len; i++){
    if(s[i] == 'U'){
      retu = i;
      break;
    }
  }
  for (ll i = len - 1; i >= 0; i--){
    if(s[i] == 'D'){
      retd = i;
      break;
    }
  }

  for (ll i = 0; i < len; i++){
    if(s[i] == 'U') {
      sum += len - 1 - i;
      if (i <= retd) sum += 2 * i;
    }
    else if(s[i] == 'D'){
      sum += i;
      if(i >= retu) sum += 2 * (len - 1 - i);
    }
  }
  cout << sum << endl;
  return 0;
  
}
