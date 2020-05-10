#include <bits/stdc++.h>

using namespace std;

long long n, m, k;

const long long MOD = 998244353;

int main(){
  cin >> n >> m >> k;
  cin.ignore();
  factgen();

  //cout << "mdtest " << modmult(998224352, 2) << endl;
  //cout << "mdtest " << modinv(2, MOD) * 2 << endl;

  long long ans = 0;
  long long sel; // n-1このしきりへの印の付け方
  long long grp;
  long long grp_p;
  while (k >= 0){
    // sel = {N-1}_C_k
    sel = compmod(n-1, k, MOD);
    //cout << "sel = " << sel << endl;
    grp = n - k - 1;
    grp_p =modmult(m, modfastpow(m-1, grp, MOD), MOD);
    ans += modmult(sel, grp_p, MOD);
    ans %= MOD;
    --k;
  }
  std::printf("%lld\n", ans);
  return 0;
}
        
