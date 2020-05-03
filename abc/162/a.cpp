#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  if(n % 10 == 7){
    cout << "Yes" << endl;
    return 0;
  }

  n /= 10;
  if(n % 10 == 7){
    cout << "Yes" << endl;
    return 0;


  }

  n /= 10;
  if(n % 10 == 7){
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}
