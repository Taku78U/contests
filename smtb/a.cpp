#include <bits/stdc++.h>

using namespace std;

int main(){
  int m1, m2;
  int d1, d2;
  cin >> m1 >> d1;
  cin.ignore();
  cin >> m2 >> d2;
  cin.ignore();

  if((m2 == 1) && (m1 == 12)){
    cout << 1 << endl;
    return 0;
  } else if(m2 == m1 + 1){
    cout << 1 << endl;
    return 0;
  }
  cout << 0 << endl;
  return 0;
}
