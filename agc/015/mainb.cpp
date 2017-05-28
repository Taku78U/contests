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
  for (ll i = 0; i < len; i++){
    for (ll j = 0; j < len; j++){
      if(i == j) continue;
      if(i < j){
        if(s[i] == 'U') sum++;
        else if(s[i] == 'D'){
          for (ll k = i - 1; k >= 0; k--){
            if(s[k] == 'U'){
              sum += 2;
              break;
            }
          }
        }
      }else{
        if(s[i] == 'U'){
          for (ll k = i + 1; k < len; k++){
            if(s[k] == 'D'){
              sum += 2;
              break;
            }
          }
        } else if(s[i] == 'D') {
          sum++;
        }
      }
    }
  }
  cout << sum << endl;
  return 0;
}
