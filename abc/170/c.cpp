#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, n;
  cin >> x >> n;
  cin.ignore();

  vector<int> p;
  int tmp;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    p.push_back(tmp);
  }
  if(n != 0){
    cin.ignore();
  }
  sort(p.begin(), p.end());

  int p_ptr = 0;
  int min = INT_MAX;
  int ans = -1;
  for(int i = 0; i <= 101; i++){
    if(p_ptr < p.size() && i == p[p_ptr]){
      ++p_ptr;
      continue;
    }
    int ab = abs(x - i);
    if(ab < min){
      ans = i;
      min = ab;
    }
  }
  cout << ans << endl;
  return 0;
}
