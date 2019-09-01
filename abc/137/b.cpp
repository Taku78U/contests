#include <bits/stdc++.h>

using namespace std;


int main (){
  int k, x;

  cin >> k >> x;
  cin.ignore();

  for (int i = x - (k - 1); i <= x + (k - 1); i++){
    cout << i << " " << flush;
  }
  cout << endl;
  return 0;
  
}
