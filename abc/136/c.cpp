#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n;
  cin >> n;
  cin.ignore();

  vector <ll> h;

  ll tmp;

  for(ll i = 0; i < n; i++){
    cin >> tmp;
    h.push_back(tmp);

  }

  if(n == 1){
    cout << "Yes" << endl;
    return 0;
  }

  h[0] -= 1;
  
  for (ll i = 0; i < n - 1; i++){
    tmp = h[i];
    if(h[i + 1] > tmp){
      h[i+1] -= 1;
    }
    if(h[i + 1] < tmp){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
