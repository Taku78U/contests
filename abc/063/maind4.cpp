#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bs(vector<ll> h, ll b, ll c, ll max, ll p){
  ll res = 0;
  
  return res;
}

int main (void){
  ll n, a, b;
  cin >> n >> a >> b;
  cin.ignore();

  vector<ll> h;
  ll tmp;

  for (int i = 0; i < n; i++){
    cin >> tmp;
    cin.ignore();
    h.push_back(tmp);
  }

  // 最初から一体だけ
  if(n == 1){
    cout << h[0] / a + 1 << endl;
    return 0;
  }

  sort(h.begin(), h.end());

  ll t = h.back() / b + (h.back() % b);
  ll c = a - b;
  

  return 0;
}
