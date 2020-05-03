#include <bits/stdc++.h>
const int MOD = 1000000007;
using namespace std;

int main(){
  long long tenhun = 1;
  for (int i = 0; i < 100; i++){
    tenhun *= 10;
    tenhun %= MOD;
  }

  cout << tenhun << endl;
  return 0;
}
