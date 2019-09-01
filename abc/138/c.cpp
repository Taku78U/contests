#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  vector <int> v;
  int tmp;
  cin >> n;
  cin.ignore();
  for(int i = 0; i < n; i++){
    cin >> tmp;
    v.push_back(tmp);
  }

  sort(v.begin(), v.end()); // 平均化は小さい方から？

  double ans = (double) v[0];
  for(int i = 1; i < n; i++){
    ans = (ans + v[i]) / 2;
  }
  cout << ans << endl;
  return 0;
}
    
