#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n;
  vector <ll> d;
  cin >> n;
  cin.ignore();
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    d.push_back(temp);
  }
  cin.ignore();

  sort(d.begin(), d.end());

  // d[n/2] と d[n/2 - 1]の差

  cout << d[n/2] -  d[n/2 - 1] << endl;
  return 0;
}
