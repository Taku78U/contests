#include <bits/stdc++.h>

using namespace std;

int k;

int main(){
  cin >> k;
  cin.ignore();

  long long sum = 0ll;
  for (int a = 1; a <= k; a++){
    for (int b = 1; b <= k; b++){
      for (int c = 1; c <= k; c++){
        sum += std::gcd(a, std::gcd(b, c));
      }
    }
  }

  cout << sum << endl;
  return 0;
}
