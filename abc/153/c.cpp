#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll n, k;
  vector <ll> h;
  ll tmp;
  cin >> n >> k;
  cin.ignore();
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    h.push_back(tmp);
  }
  sort(h.begin(), h.end());
  ll sum = 0;
  for(ll i = 0; i < n - k; i++){
    sum += h[i];
  }
  cout << sum << endl;
  return 0;
}
