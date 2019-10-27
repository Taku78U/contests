#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  for (int i = 1; i <= 9; i++){
    if((n % i == 0) && (n / i <= 9) && (n / i >= 0)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
    
