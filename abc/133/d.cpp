#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main(){
  ll n;
  cin >> n;
  cin.ignore();
  ll tmp;

  vector <ll> a;

  ll sum = 0;

  for (ll i = 0; i < n; ++i){
    cin >> tmp;
    a.push_back(tmp);
    sum += tmp;
  }

  // 最初
  ll m = sum;
  if(int i = 1; i < n; i += 2){
    m -= 2 * a[i];
  }

  cout << m << flush;
  cout << " " << flush;
  for(int i = 1; i < n; i++){
    m = 2 * a[i] - m;
    cout << m << " " << flush;
  }
  cout << endl;
  return 0;
}

