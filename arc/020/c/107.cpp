#include <bits/stdc++.h>

using namespace std;

int main (void){

  unsigned long long b;
  b = pow(10, 9) + 7;
  for (int i=1;i<=100;i++){
    cout << b * i << " " << flush;
  }
  cout << endl;
  return 0;
}
