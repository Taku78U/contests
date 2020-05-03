#include <bits/stdc++.h>

using namespace std;

int main(){
  int s;
  int w;
  cin >> s >> w;
  cin.ignore();

  if(w >= s){
    cout << "unsafe" << endl;
    return 0;
  } else {
    cout << "safe" << endl;
    return 0;
  }
  return 0;
}
