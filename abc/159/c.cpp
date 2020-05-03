#include <bits/stdc++.h>

using namespace std;

int l;
int main(){
  cin >> l;
  cin.ignore();

  long double a; // 1辺

  a = (long double) l / 3;
  printf("%.9Lf\n", a * a * a);
  return 0;
}
