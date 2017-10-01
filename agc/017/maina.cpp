#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main (void){
  int n, p;
  cin >> n >> p;

  cin.ignore();

  int a[i];

  int odd = 0, even = 0;

  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] % 2 == 1) odd;
    else even++;
  }

  ll te = 0;
  ll to = 0;
  te = pow(2, even);
  int t;

  int q = 1, r = 1; // to = q / r

  for(int i = p; i <= odd; i = i + 2){
    if(i == 0) {
      to = 1;
      r = 1;
      q = 1;
    } else if(i == 1){
      to = odd;
      q = odd;
      r = 1;
    }else if (i == 2){
      to = to + odd * (odd - 1) / 2;
      q = odd * (odd - 1);
      r = 2;
    } else{
      to = to + to * q * (q + 1)
    }
  
