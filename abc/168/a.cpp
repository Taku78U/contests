#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  n %= 10;
  if(n == 2 || n == 4 || n == 5 || n == 7 || n == 9){
    cout << "hon" << endl;
    return 0;
  } else if(n == 0 || n == 1 || n == 6 || n == 8){
    cout << "pon" << endl;
    return 0;
  } else {
    cout << "bon" << endl;
    return 0;
  }
  return 0;
}
