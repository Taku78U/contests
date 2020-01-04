#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  cin.ignore();

  for(int i = 0; i < s.size(); i++){
    if((s[i] >= 'a') && (s[i] <= 'z')){
      cout << "error" << endl;
      return 0;
    }
  }

  int ans = stoi(s);
  ans *= 2;
  cout << ans << endl;
  return 0;
}
