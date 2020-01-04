#include <bits/stdc++.h>

using namespace std;

char chara_plus(char c, int n){
  char rtn = '\0';
  if(n > 'Z' - c){
    n -= 'Z' - c;
    rtn = 'A' + (char)(n - 1);
  } else {
    rtn = c + (char) n;
  }
  return rtn;
}
    
int main(){
  string s;
  int n;
  cin >> n;
  cin.ignore();
  cin >> s;
  cin.ignore();
  //cout << s << endl;
  for(int i = 0; i < s.length() ; i++){
    s[i] = chara_plus(s[i], n);
  }
  cout << s << endl;
  return 0;
}
  
