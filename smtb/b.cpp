#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  for (int i = 1; i <= 50000; i++){
    if(i * 108 / 100 == n){
      cout << i << endl;
      return 0;
    }
  }

  cout << ":(" << endl;
  return 0;
}
    
