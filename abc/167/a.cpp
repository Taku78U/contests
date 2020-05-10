#include <bits/stdc++.h>

using namespace std;

string s;
string t;

int main(){
  cin >> s;
  cin.ignore();
  cin >> t;
  cin.ignore();

  string tmp = s;
  for(char i = 'a'; i <= 'z'; i++){
    if(t == s + i){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
