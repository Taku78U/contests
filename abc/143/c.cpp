#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  string s;
  cin >> s;
  int spe = 1;
  cin.ignore();
  for (int i = 1; i < n; i++){
    if(s[i] != s[i-1]) ++spe;
  }
  cout << spe << endl;
  return 0;
}
