#include <bits/stdc++.h>

using namespace std;

int n;

void dfs(string s, char mx){
  if(s.length() == n){
    cout << s << endl;
  } else {
    for(char c = 'a'; c <= mx; c++){
      //dfs(s + c, (char) mx + 1);
      dfs(s + c, (mx == c) ?  (char) mx + 1 : mx);
    }
  }
  return;
}

int main(){

  cin >> n;
  cin.ignore();
  dfs("", 'a');
  return 0;
}
