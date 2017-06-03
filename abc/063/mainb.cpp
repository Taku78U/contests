#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main (void){
  char s[26] = {'\0'};
  int n[26] = {0};
  for (int i = 0; i < 26; i++){
    s[i] = '\0';
    n[i] = 0;
  }

  cin >> s;
  //cout << s << endl;

  for (int i = 0; i < 26 && s[i] != '\0'; i++){
    s[i] -= 97;
    n[s[i]]++;
    //cout << n[s[i]] << endl;
    if(n[s[i]] >= 2){
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}
