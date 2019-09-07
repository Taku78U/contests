#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  int n;
  vector <ll> b;
  ll tmp;
  cin >> n;
  cin.ignore();
  for(int i = 0; i < n - 1; i++){
    cin >> tmp;
    b.push_back(tmp);
  }

  ll sum_a = b[0];

  ll tmp_a;
  for (int i = 1; i <= n - 2; i++){
    if(b[i-1] < b[i]){
      sum_a += b[i-1];
    } else {
      sum_a += b[i];
    }

  }
  sum_a += b[n-2];
  cout << sum_a << endl;
  return 0;
}
