#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll k, n;
vector<ll> a, dif;
int main (){
  cin >> k >> n;
  cin.ignore();
  ll tmp;
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp);
  }

  // 最大の差をひけばいい！
  for(ll i = 0; i < n - 1; i++){
    tmp = a[i+1] - a[i];
    dif.push_back(tmp);
  }
  tmp = a[0] + k - a[n-1];
  dif.push_back(tmp);

  ll max = 0;
  for(ll i = 0; i < n; i++){
    tmp = dif[i];
    if(max < tmp){
      max = tmp;
      //      cout << "max =" << max << endl;
    }
  }

  cout << k - max << endl;
  return 0;
}


  
  
