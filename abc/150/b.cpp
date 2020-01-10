#include <bits/stdc++.h>

using namespace std;



int main(){
  int n;
  string s;
  cin >> n;
  cin.ignore();
  cin >> s;
  cin.ignore();

  int cnt = 0;

  for (int i = 0; i < n - 2; i++){
    if(s[i] == 'A'){
      if(s.substr(i, 3) == "ABC"){
        ++cnt;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
