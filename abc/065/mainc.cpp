#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main (void){
  int n, m;

  cin >> n >> m;

  if(abs(n - m) > 1){
    cout << 0 << endl;
    return 0;
  }

  ll saru = 1;
  ll inu = 1;

  const ll md = 1000000007;
  for (int i = 1; i <= n; i++){
    inu *= i;
    if(inu >= md) inu %= md;
  }
  for (int i = 1; i <= m; i++){
    saru *= i;
    if(saru >= md) saru %= md;
  }
  if(n == m) cout << inu * 2 % md * saru % md << endl;
  else cout << inu * saru % md << endl;
  return 0;
}
  
