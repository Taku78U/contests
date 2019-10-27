#include <bits/stdc++.h>

using namespace std;

int main(){
  double ret = 0;
  int a;
  cin >> a;
  cin.ignore();

  int tmp = a/2 + a%2;
  ret = ((double) tmp) / a;
  cout << ret << endl;

  return 0;
}
