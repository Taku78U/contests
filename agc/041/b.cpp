#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  cin.ignore();

  vector <ll> a;
  ll tmp;
  for(ll i = 0; i < n; i++){
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());

  ll min = a[0];
  ll max = a[n-1];

  // m人全員が一つに投票する場合

  // まず、1位になる可能性のあるもの
  // v以上番目スコアの小さい問題に関しては、単にmaxとの差を見ればよい

  ll ans_simple = n - 1; // 0-origin
  LL nex_candidate = n - 1; // 全PLUSがmax以上になるもの
  for(ll i = v - 1; i < n - 1; i++){
    if (m<=max-a[i]){
      ans_simple = i;
      break;
    }
  }


  

  // 累積和
  vector <ll> sum_up (n) = {0};
  vector <ll> sum_down (n) = {0};
  sum_up[0] = 0;
  sum_down[n-1] = 0;

  for(ll i = 1; i < n; i++){
    sum_up[i] = sum_up[i-1] + (max - a[i-1]);
  }

  ll i_min = 0; // 0-origin
  for(ll i = n - 2; i >= 0; i--){
    sum_down[i] = sum_down[i+1] + (max - a[i+1]);
  }
    
  // ans_simpleまで まじめにやる
  
  
  
