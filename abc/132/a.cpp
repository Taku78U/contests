#include <bits/stdc++.h>

using namespace std;

int main(){
  char c[5];
  cin >> c;
  cin.ignore();

  int buc[128] = {0};

  for (int i = 0; i < 128; i++){
    buc[i] = 0;
  }

  for(int i = 0; i < 4; i++){
    ++buc[c[i]];
    //cout << buc[c[i]] << endl;
  }

  bool flag = false;
  for (int i = 0; i < 128; i++){
    if((flag == false) && (buc[i] == 2)){
      flag = true;
    } else if((flag == true) && (buc[i] == 2)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
