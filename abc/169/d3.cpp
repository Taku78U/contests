#include <bits/stdc++.h>

using namespace std;


vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

long long fastpow(long long a, long long n){
  long long ans = 1;
  while(n > 0){
    if(n & 1){
      ans *= a;
    }
    a *= a;
    n = n >> 1;
  }
  return ans;
}


int main(){
  long long n;
  cin >> n;
  cin.ignore();

  vector<pair<long long, long long>> prime_fact = prime_factorize(n);
  queue<pair<long long, long long>> prime_fact_extra;

  vector<long long> extra;

  vector <long long> already;

  long long cnt = 0;
  long long rem = 1;
  long double sqrt_n = sqrt(n);
  for(int i = 0; i < prime_fact.size(); i++){
    //printf("e = %lld p = %lld\n", prime_fact[i].first, prime_fact[i].second);
    long long p = prime_fact[i].second;
    long double sqrt_p = sqrt(2 * p);
    // n(n+1)/2 <= Aとなるnを探る
    long long n_p = sqrt_p + 1;
    while(p < (n_p * (n_p + 1)) / 2){
      --n_p;
    }
    cnt += n_p;
  }

  cout << cnt << endl;
  
  return 0;
}
  
