#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void){
  int k, n;
  cin >> n >> k;
  cin.ignore();
  int a[n];
  ll c[200000] = {0};
  for(int i = 0; i < n; i++){
    cin >> a[i];
    c[a[i]-1]++;
  }
  cin.ignore();

  sort(c, c + 200000);
  ll sum;
  for(int i = 0; i < k; i++){
    sum += c[200000 - 1 - i];
  }
  cout << n - sum << endl;
  return 0;
}
  
