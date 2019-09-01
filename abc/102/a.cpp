#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();

  // n と 2が互いに素であるか
  if(n%2 == 0){
    cout << n << endl;
  } else {
    cout << n * 2 << endl;
  }
  return 0;
}
