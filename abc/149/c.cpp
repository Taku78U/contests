#include <bits/stdc++.h>
#define MAX_PRIME 100003
//#define DBG
using namespace std;

using ll = long long;

int main(){
  ll x;
  cin >> x;
  cin.ignore();

  double maxpr_sq = sqrt((double) MAX_PRIME);
  ll maxpr_sq_ll = ((ll) maxpr_sq) + 1;

  bool is_prime = true;
  ll max_j;
  for(ll i = x; i < MAX_PRIME; i++){
    is_prime = true;
    max_j = (maxpr_sq_ll < i - 1) ? maxpr_sq_ll : i - 1;
    #ifdef DBG
    printf("i:%lld max_j:%lld maxpr_sq_ll:%lld\n", i, max_j, maxpr_sq_ll);
    #endif
    for(ll j = 2; j <= max_j; j++){
      if(i % j == 0){
        is_prime = false;
    #ifdef DBG
        printf("i is not prime i:%lld j:%lld max_j:%lld maxpr_sq_ll:%lld\n", i, j, max_j, maxpr_sq_ll);
    #endif
        break;
      }
    }
    if(is_prime == true){
      cout << i << endl;
      return 0;
    }
  }

  // 全部falseで抜けた場合(10000が来たときとか)は10007
  
  cout << (MAX_PRIME) << endl;
  return 0;
}
