#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n;
  cin >> n;
  cin.ignore();
  ll max = 0;
  ll maxidx = 0;
  ll tmp = 0;
  ll secmax = 0;
  vector <ll> a;
  for (ll i = 0; i < n; i++){
    cin >> tmp;
    cin.ignore();
    a.push_back(tmp);
    if(max < tmp){
      secmax = max;
      maxidx = i;
      max = tmp;
    } else if(secmax < tmp){
      secmax = tmp;
    }
  }

  for(ll i = 0; i < n; i++){
    if(i != maxidx){
      cout << max << endl;
    } else {
      cout << secmax << endl;
    }
  }
  return 0;
}
