#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void){
  ll n, m, d;
  cin >> n >> m >> d;
  cin.ignore();

  double n1 = n;
  double m1 = m;
  double d1 = d;

  double p;
  if((d == 0) || (n <= 2 * d)){
    p = ((double)(m1 - 1)) / n1;
  } else {
    p = ((double)((m1 - 1) * (2 * (n1 - 2 * d1) + 2  * d1))) / (n1 * n1);
  }
  cout << p << endl;
  return 0;
}
