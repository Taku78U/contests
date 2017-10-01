#include <bits/stdc++.h>

using namespace std;

int main(void){
  string s;
  cin >> s;

  char c[201] = {'\0'};
  bool sw = false;
  s.copy(c, s.size());
  for(int i = s.size() - 2; i > 0; i--){
    if(i %2 == 0) continue;
    for (int j = 0; j <= i / 2; j++){
      if(c[j] != c[i / 2 + 1 + j]) break;
      if (j == i / 2) sw = true;
    }
    if(sw){
      /*
      for(int j = 0; j <= i; j++){
        cout << c[j] << flush;
      }
      cout << endl;
      */
      cout << i + 1 << endl;
      return 0;
    }
  }

  //cout << c[0] << endl;
  cout << 1 << endl;

  return 0;
}
