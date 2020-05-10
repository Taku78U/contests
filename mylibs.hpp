#include <bits/stdc++.h>

using namespace std;

long long modmult(long long a, long long b, long long m){
  return (a * b) % m;
}

long long modpls(long long a, long long b, long long m){
  return (a + b) % m;
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

long long modfact_tbl[2*100000+1] = {0};

void modfactgen(){
  modfact_tbl[1] = modfact_tbl[0] = 1;
  for(long long i = 2; i <= 2*100000; i++){
    modfact_tbl[(int)i] = modmult(i, modfact_tbl[(int)i - 1]);
    //if(i < 19){
    //  cout << fact_tbl[i] << " " << flush;
    //}
    
  }
  //cfcout << endl;
  return;
}

long long modcomp(long long a, long long b, long long m){
  return modmult(modmult(modfact_tbl[(int)a], modinv(modfact_tbl[(int)(a - b)], m), m), modinv(modfact_tbl[(int)b], m), m);
}

long long modfastpow(long long a, long long n, long long m){
  long long ans = 1;
  while(n > 0){
    if(n & 1){
      ans = modmult(ans, a, m);
    }
    a *= a;
    a %= m;
    n = n >> 1;
  }
  return ans;
}

vector<long long> factgen(int n){
  vector<long long> rtn;
  rtn.push_back(1);
  rtn.push_back(1);
  for(long long i = 2; i <= n + 1; i++){
    rtn.push_back(i * rtn[i-1]);
  }
  return rtn;
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

long long comp(long long a, long long b){
  return fact_tbl[(int)a] / fact_tbl[(int)(a - b)] / fact_tbl[(int)b];
}

