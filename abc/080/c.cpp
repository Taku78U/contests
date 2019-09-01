#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main (void){
  ll n;
  cin >> n;
  cin.ignore();

  vector <ll> f;
  vector <ll> p;
  ll tmp;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < 10; j++){
      cin >> tmp;
      f.push_back(tmp);
    }
    cin.ignore();
  }
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < 10; j++){
      cin >> tmp;
      p.push_back(tmp);
    }
    cin.ignore();
  }
  

  return 0;
}
