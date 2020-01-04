#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  string s;
  cin >> n;
  cin.ignore();
  cin >> s;
  cin.ignore();
  
  if(n % 2 == 1){
    cout << "No" << endl;
    return 0;
  }

  bool match = true;
  for(int i = 0; i < n / 2; i++){
    if(s[i] != s[n/2 + i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
