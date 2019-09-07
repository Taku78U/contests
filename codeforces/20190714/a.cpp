#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  cin.ignore();

  int n[t];
  int x[t];

  for (int i = 0; i < t; i++){
    cin >> n[i] >> x[i];
    cin.ignore();
    cout << 2 * x[i] << endl;
    
  }

  return 0;
}

