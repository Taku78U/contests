#include <bits/stdc++.h>

using namespace std;

int main(){
  int k;
  string s;
  cin >> k;
  cin.ignore();
  cin >> s;
  cin.ignore();

  if(s.size() <= k){
    cout << s << endl;
    return 0;
  }

  for (int i = 0; i < k; i++){
    cout << s[i] << flush;
  }
  cout << "..." << endl;
  return 0;
}
