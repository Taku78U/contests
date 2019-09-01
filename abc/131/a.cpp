#include <bits/stdc++.h>

using namespace std;

int main(){
  char c[4];
  cin >> c;
  cin.ignore();

  for (int i = 0; i < 3; i++){
    if(c[i] == c[i + 1]){
      cout << "Bad" << endl;
      return 0;
    }
  }
  cout << "Good" << endl;
  return 0;

}
