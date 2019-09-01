#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n;
  vector <ll> a;
  cin >> n;
  cin.ignore();

  ll tmp;
  ll ma = 1; // 分子

  ll tmp_d; // tmpの逆数
  double sum = 0;

  for (ll i = 0; i < n; i++){
    cin >> tmp;
    //ma *= tmp;
    a.push_back(tmp);
    sum += ((double)1) / tmp;
  }

  double ans = 1 / sum;

  //double sum = 0; // 分母
  //for(ll i = 0; i < n; i++){
  //  sum += ma / ((double)a[i]);
  //}
  //double ans = ma / sum;
  printf("%f\n", ans);
  return 0;
}
  
