#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main(void){
  int n;
  cin >> n;
  cin.ignore();

  ull a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cin.ignore();

  sort(a, a + i);

  // Aiはすべて正整数。純粋に最大ひく最小。
  int dif;
  dif = a[n-1] - a[0];
  cout << dif << endl;
}
