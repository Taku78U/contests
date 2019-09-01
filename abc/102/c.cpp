#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(void){
  ll n;
  cin >> n;

  cin.ignore();
  ll a[n];
  ll tmp, min, max;
  ll sum = 0;
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    //cout << tmp << endl;
    //cout << i << endl;
    a[i] = tmp - (i + 1);
    //cout << a[i] << endl;
    if(i == 0){
      min = a[i];
      max = a[i];
    } else {
      if(max < a[i]) max = a[i];
      if(min > a[i]) min = a[i];
    }
    sum += a[i];
  }
  ll mean = sum / n;
  cin.ignore();
  sort(a, a + n);
  ll mid;
  if(a[n/2] < a[n/2 + 1]){
    mid = a[n/2];
  } else {
    mid = a[n/2 + 1];
  }
  ll ssum = 0;
  for(ll i = 0; i < n; i++){
    ssum += a[i] - mid;
  }
  cout << ssum << endl;
  return 0;
}
