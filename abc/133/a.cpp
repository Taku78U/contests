#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, a, b;

  cin >> n >> a >> b;

  cin.ignore();

  int feea;
  feea = n * a;
  if(feea < b){
    cout << feea << endl;
  } else {
    cout << b << endl;
  }

  return 0;

}
