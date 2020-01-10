#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MOD 1000000007

ll modmult(ll a, ll b){
  return (a * b) % MOD;
}

ll modpls(ll a, ll b){
  return (a + b) % MOD;
}

ll modmns(ll a, ll b){
  if(b > a){
    return (a + MOD - b) % MOD;
  }
  return (a - b) % MOD;
}

int main(){
  ll n;
  cin >> n;
  cin.ignore();

  vector<ll> c;
  ll tmp;
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    c.push_back(tmp);
  }

  ll ans = 0;
  for(ll i = 0; i < n; i++){
    
