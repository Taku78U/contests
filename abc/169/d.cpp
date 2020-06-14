#include <bits/stdc++.h>

using namespace std;

long long n;

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
    long double sqrt_p = sqrt(p);
    cout << "first = " << prime_fact[i].first << endl;

    // n(n+1)/2 <= Aとなるnを探る
    long long n_p = sqrt_p + 1;
    while(p < (n_p * (n_p + 1)) / 2){
      printf("loop n_p = %lld\n", n_p);
      --n_p;
    }
    printf("n_p = %lld\n", n_p);
    long long x = 1;
    for(long long j = 1; j <= prime_fact[i].second; j++){
      x *= prime_fact[i].first;
      cout << "x = " << x << endl;
      already.push_back(x);
    }
    cnt += n_p;
    cout << "n_p = " << n_p << endl;
    cout << "rempow = " << p - (n_p * (n_p + 1)) / 2 << endl;
    rem *= fastpow(prime_fact[i].first, p - (n_p * (n_p + 1)) / 2);
    cout << "rem = " << rem << endl;
  }
  
  sort(already.begin(), already.end());

  int alr_ptr = 0;

  for(long long i = 2; i <= rem; i++){
    if(alr_ptr < already.size()){
      cout << "alr[alr_ptr] = " << already[alr_ptr] << endl;
      if(already[alr_ptr] == i){
        alr_ptr++;
        continue;
      }
    }
    if(rem % i == 0){
      cout << i << endl;
      rem /= i;
      ++cnt;
    }
  }
  cout << cnt << endl;
  
  return 0;
}
  
