#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  int sum = 0;
  vector <int> d;
  int tmp;
  for (int i = 0; i < n; i++){
    cin >> tmp;
    sum += tmp;
    d.push_back(tmp);
  }

  ll ans = 0;
  for (int i = 0; i < n - 1; i++){
    tmp = d[i];
    sum -= d[i];
    ans += tmp * sum;
  }
  cout << ans << endl;
  return 0;
}
